#include "stdarg.h"
#include "stdio.h"
#include "string.h"

#define BUFFERSIZE      512         /* size of conversion buffer */
#define MAXPRECISION    BUFFERSIZE  /* ANSI-specified minimum is 509 */
#define NUMSTATES       8           /* number of STATE members */

#define FLAG_SIGN       0x0001      /* put plus or minus in front */
#define FLAG_SIGNSPACE  0x0002      /* put space or minus in front */
#define FLAG_LEFT       0x0004      /* left justify */
#define FLAG_LEADZERO   0x0008      /* pad with leading zeros */
#define FLAG_LONG       0x0010      /* long int value given */
#define FLAG_SHORT      0x0020      /* short int value given */
#define FLAG_LONGDOUBLE 0x0040      /* long double value given */
#define FLAG_SIGNED     0x0080      /* signed data given */
#define FLAG_CAPITAL    0x0100      /* capital form requested */
#define FLAG_ALTERNATE  0x0200      /* alternate form requested */
#define FLAG_NEGATIVE   0x0400      /* value is negative */

#define charclass(c) \
    ((c) < ' ' || (c) > 'x' ? CHAR_OTHER : sctab[(c) - ' '] & 0x0f)

#define curstate(class, state) \
    (sctab[(class) * NUMSTATES + (state)] >> 4)

typedef struct {
	int type;
	int flags;
	int radix;
	int width;
	int precision;
	int textlen;
	int prefixlen;
	int charsout;
	char *text;
	char prefix[2];
	union {
		long int vlong;
		unsigned long int vulong;
		long double vldouble;
		int *pint;
		short int *pshort;
		long int *plong;
	} value;
} FMT;

enum STATE {
	STATE_NORMAL,   /* normal state */
	STATE_PERCENT,  /* just read '%' */
	STATE_FLAG,     /* just read flag character */
	STATE_WIDTH,    /* just read width specifier */
	STATE_DOT,      /* just read '.' */
	STATE_PRECIS,   /* just read precision specifier */
	STATE_SIZE,     /* just read size specifier */
	STATE_TYPE      /* just read type specifier */
};

enum CHARCLASS {
	CHAR_OTHER,     /* character with no special meaning */
	CHAR_PERCENT,   /* '%' */
	CHAR_DOT,       /* '.' */
	CHAR_STAR,      /* '*' */
	CHAR_ZERO,      /* '0' */
	CHAR_DIGIT,     /* '1'..'9' */
	CHAR_FLAG,      /* ' ','+','-','#' */
	CHAR_SIZE,      /* 'h','l','L' */
	CHAR_TYPE       /* 'c','d','e','f','g', ... */
};

static const char sctab[] = {
	/* ' ' */ 0x06,
	/* '!' */ 0x00,
	/* '"' */ 0x00,
	/* '#' */ 0x06,
	/* '$' */ 0x00,
	/* '%' */ 0x01,
	/* '&' */ 0x00,
	/* ''' */ 0x00,
	/* '(' */ 0x10,
	/* ')' */ 0x00,
	/* '*' */ 0x03,
	/* '+' */ 0x06,
	/* ',' */ 0x00,
	/* '-' */ 0x06,
	/* '.' */ 0x02,
	/* '/' */ 0x10,
	/* '0' */ 0x04,
	/* '1' */ 0x45,
	/* '2' */ 0x45,
	/* '3' */ 0x45,
	/* '4' */ 0x05,
	/* '5' */ 0x05,
	/* '6' */ 0x05,
	/* '7' */ 0x05,
	/* '8' */ 0x05,
	/* '9' */ 0x35,
	/* ':' */ 0x30,
	/* ';' */ 0x00,
	/* '<' */ 0x50,
	/* '=' */ 0x00,
	/* '>' */ 0x00,
	/* '?' */ 0x00,
	/* '@' */ 0x00,
	/* 'A' */ 0x20,
	/* 'B' */ 0x20,
	/* 'C' */ 0x30,
	/* 'D' */ 0x50,
	/* 'E' */ 0x58,
	/* 'F' */ 0x00,
	/* 'G' */ 0x08,
	/* 'H' */ 0x00,
	/* 'I' */ 0x30,
	/* 'J' */ 0x30,
	/* 'K' */ 0x30,
	/* 'L' */ 0x57,
	/* 'M' */ 0x50,
	/* 'N' */ 0x00,
	/* 'O' */ 0x00,
	/* 'P' */ 0x00,
	/* 'Q' */ 0x20,
	/* 'R' */ 0x20,
	/* 'S' */ 0x00,
	/* 'T' */ 0x00,
	/* 'U' */ 0x00,
	/* 'V' */ 0x00,
	/* 'W' */ 0x00,
	/* 'X' */ 0x08,
	/* 'Y' */ 0x60,
	/* 'Z' */ 0x60,
	/* '[' */ 0x60,
	/* '\' */ 0x60,
	/* ']' */ 0x60,
	/* '^' */ 0x60,
	/* '_' */ 0x00,
	/* '`' */ 0x00,
	/* 'a' */ 0x70,
	/* 'b' */ 0x70,
	/* 'c' */ 0x78,
	/* 'd' */ 0x78,
	/* 'e' */ 0x78,
	/* 'f' */ 0x78,
	/* 'g' */ 0x08,
	/* 'h' */ 0x07,
	/* 'i' */ 0x08,
	/* 'j' */ 0x00,
	/* 'k' */ 0x00,
	/* 'l' */ 0x07,
	/* 'm' */ 0x00,
	/* 'n' */ 0x08,
	/* 'o' */ 0x08,
	/* 'p' */ 0x08,
	/* 'q' */ 0x00,
	/* 'r' */ 0x00,
	/* 's' */ 0x08,
	/* 't' */ 0x00,
	/* 'u' */ 0x08,
	/* 'v' */ 0x00,
	/* 'w' */ 0x00,
	/* 'x' */ 0x08
};

static char buffer[BUFFERSIZE];
static char *nullstring = "(null)";

static size_t strnlen(const char *s, size_t n) {
	const char *p;
	for (p = s; n > 0 && *p != '\0'; p++, n--)
		;
	return p - s;
}

static void writechar(int c, FILE *stream, FMT *fmt) {
	if (putc(c, stream) == EOF)
		fmt->charsout = -1;
	else
		fmt->charsout++;
	return;
}

static void writechars(int c, int n, FILE *stream, FMT *fmt) {
	while (fmt->charsout >= 0 && n-- > 0)
		writechar(c, stream, fmt);
	return;
}

static void writestr(char *s, int n, FILE *stream, FMT *fmt) {
	while (fmt->charsout >= 0 && n-- > 0)
		writechar(*s++, stream, fmt);
	return;
}

static void fmtint(FMT *fmt) {
	int digit;
	int hexadd;
	if (fmt->flags & FLAG_CAPITAL)
		hexadd = 'A' - '9' - 1;
	else
		hexadd = 'a' - '9' - 1;
	fmt->text = buffer + BUFFERSIZE;
	while (fmt->precision-- > 0 || fmt->value.vulong != 0) {
		digit = fmt->value.vulong % fmt->radix + '0';
		fmt->value.vulong /= fmt->radix;
		if (digit > '9')
			digit += hexadd;
		*--fmt->text = (char) digit;
	}
	fmt->textlen = (int) (buffer + BUFFERSIZE - fmt->text);
	if (fmt->flags & FLAG_SIGNED) {
		if (fmt->flags & FLAG_NEGATIVE) {
			fmt->prefix[0] = '-';
			fmt->prefixlen = 1;
		} else if (fmt->flags & FLAG_SIGN) {
			fmt->prefix[0] = '+';
			fmt->prefixlen = 1;
		} else if (fmt->flags & FLAG_SIGNSPACE) {
			fmt->prefix[0] = ' ';
			fmt->prefixlen = 1;
		}
	}
	if (fmt->flags & FLAG_ALTERNATE) {
		if (fmt->type == 'o' && *fmt->text != '0') {
			fmt->prefix[0] = '0';
			fmt->prefixlen = 1;
		} else if (fmt->type == 'x') {
			fmt->prefix[0] = '0';
			if (fmt->flags & FLAG_CAPITAL)
				fmt->prefix[1] = 'X';
			else
				fmt->prefix[1] = 'x';
			fmt->prefixlen = 2;
		}
	}
	return;
}

static void output(FILE *stream, FMT *fmt) {
	int padding;
	if (fmt->type == 'n') {
		if (fmt->flags & FLAG_LONG)
			*fmt->value.plong = (long int) fmt->charsout;
		else if (fmt->flags & FLAG_SHORT)
			*fmt->value.pshort = (short int) fmt->charsout;
		else
			*fmt->value.pint = fmt->charsout;
		return;
	}
	padding = fmt->width - fmt->textlen - fmt->prefixlen;
	if (!(fmt->flags & (FLAG_LEFT | FLAG_LEADZERO)))
		writechars(' ', padding, stream, fmt);
	writestr(fmt->prefix, fmt->prefixlen, stream, fmt);
	if ((fmt->flags & FLAG_LEADZERO) && !(fmt->flags & FLAG_LEFT))
		writechars('0', padding, stream, fmt);
	writestr(fmt->text, fmt->textlen, stream, fmt);
	if (fmt->flags & FLAG_LEFT)
		writechars(' ', padding, stream, fmt);
	return;
}

int vfprintf(FILE *stream, const char *format, va_list arg) {
	int c;
	enum STATE state;
	enum CHARCLASS class;
	FMT fmt;
	fmt.textlen = 0;
	fmt.prefixlen = 0;
	fmt.charsout = 0;
	state = STATE_NORMAL;
	while (fmt.charsout >= 0 && (c = *format++) != '\0') {
		class = charclass(c);
		state = curstate(class, state);
		switch (state) {
		case STATE_NORMAL:
			writechar(c, stream, &fmt);
			break;
		case STATE_PERCENT:
			fmt.flags = 0;
			fmt.width = 0;
			fmt.precision = -1;
			break;
		case STATE_FLAG:
			switch (c) {
			case '-':
				fmt.flags |= FLAG_LEFT;
				break;
			case '+':
				fmt.flags |= FLAG_SIGN;
				break;
			case ' ':
				fmt.flags |= FLAG_SIGNSPACE;
				break;
			case '#':
				fmt.flags |= FLAG_ALTERNATE;
				break;
			case '0':
				fmt.flags |= FLAG_LEADZERO;
				break;
			}
			break;
		case STATE_WIDTH:
			if (c != '*')
				fmt.width = fmt.width * 10 + (c - '0');
			else {
				fmt.width = va_arg(arg, int);
				if (fmt.width < 0) {
					fmt.flags |= FLAG_LEFT;
					fmt.width = -fmt.width;
				}
			}
			break;
		case STATE_DOT:
			fmt.precision = 0;
			break;
		case STATE_PRECIS:
			if (c != '*')
				fmt.precision = fmt.precision * 10 + (c - '0');
			else {
				fmt.precision = va_arg(arg, int);
				if (fmt.precision < 0)
					fmt.precision = -1;
			}
			break;
		case STATE_SIZE:
			switch (c) {
			case 'l':
				fmt.flags |= FLAG_LONG;
				break;
			case 'h':
				fmt.flags |= FLAG_SHORT;
				break;
			case 'L':
				fmt.flags |= FLAG_LONGDOUBLE;
				break;
			}
			break;
		case STATE_TYPE:
			fmt.type = c;
			switch (c) {
			case 'c':
				fmt.value.vlong = va_arg(arg, int);
				fmt.text = (char *) &fmt.value.vlong;
				fmt.textlen = 1;
				break;
			case 's':
				fmt.text = va_arg(arg, char *);
				if (fmt.text == NULL)
					fmt.text = nullstring;
				if (fmt.precision < 0)
					fmt.textlen = (int) strlen(fmt.text);
				else
					fmt.textlen = (int) strnlen(fmt.text, fmt.precision);
				break;
			case 'n':
				if (fmt.flags & FLAG_LONG)
					fmt.value.plong = va_arg(arg, long int *);
				else if (fmt.flags & FLAG_SHORT)
					fmt.value.pshort = va_arg(arg, short int *);
				else
					fmt.value.pint = va_arg(arg, int *);
				break;
			case 'E':
			case 'G':
				fmt.flags |= FLAG_CAPITAL;
				fmt.type += 'a' - 'A';
				/* DROP THROUGH */
			case 'e':
			case 'f':
			case 'g':
				fmt.flags |= FLAG_SIGNED;
				if (fmt.flags & FLAG_LONGDOUBLE)
					fmt.value.vldouble = va_arg(arg, long double);
				else
					fmt.value.vldouble = va_arg(arg, double);
				if (fmt.precision < 0)
					fmt.precision = 6;
				else if (fmt.type == 'g' && fmt.precision == 0)
					fmt.precision = 1;
				else if (fmt.precision > MAXPRECISION)
					fmt.precision = MAXPRECISION;
				break;
			case 'd':
			case 'i':
				fmt.flags |= FLAG_SIGNED;
				/* DROP THROUGH */
			case 'u':
				fmt.radix = 10;
				goto INT_COMMON;
			case 'o':
				fmt.radix = 8;
				goto INT_COMMON;
			case 'p':
				fmt.flags |= FLAG_LONG;
				fmt.precision = sizeof(void *) * 2;
				fmt.radix = 16;
				goto INT_COMMON;
			case 'X':
				fmt.flags |= FLAG_CAPITAL;
				fmt.type += 'a' - 'A';
				/* DROP THROUGH */
			case 'x':
				fmt.radix = 16;
				/* DROP THROUGH */
			INT_COMMON:
				if (fmt.flags & FLAG_SIGNED) {
					if (fmt.flags & FLAG_LONG)
						fmt.value.vlong = va_arg(arg, long int);
					else
						fmt.value.vlong = va_arg(arg, int);
					if (fmt.value.vlong < 0) {
						fmt.flags |= FLAG_NEGATIVE;
						fmt.value.vlong = -fmt.value.vlong;
					}
				} else {
					if (fmt.flags & FLAG_LONG)
						fmt.value.vulong = va_arg(arg, unsigned long int);
					else
						fmt.value.vulong = va_arg(arg, unsigned int);
				}
				if (fmt.value.vulong == 0)
					fmt.flags &= ~FLAG_ALTERNATE;
				if (fmt.precision < 0)
					fmt.precision = 1;
				else {
					fmt.flags &= ~FLAG_LEADZERO;
					if (fmt.precision > MAXPRECISION)
						fmt.precision = MAXPRECISION;
				}
				fmtint(&fmt);
				break;
			}
			output(stream, &fmt);
			break;
		}
	}
	return fmt.charsout;
}
