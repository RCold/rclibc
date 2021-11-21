#include "_stdint.h"
#include "_stdio.h"
#include "_stdlib.h"
#include "ctype.h"
#include "stdarg.h"
#include "string.h"

#define INT_BUFSIZE         24          /* output buffer size for integers */

#define FLAG_LEFT           0x0001      /* left justify */
#define FLAG_SIGN           0x0002      /* put plus or minus in front */
#define FLAG_SPACE          0x0004      /* put space or minus in front */
#define FLAG_ALTERNATE      0x0008      /* alternate form requested */
#define FLAG_ZERO           0x0010      /* pad with leading zeros */
#define FLAG_SHORT          0x0020      /* short int value given */
#define FLAG_LONG           0x0040      /* long int value given */
#define FLAG_LONGDOUBLE     0x0080      /* long double value given */
#define FLAG_SIGNED         0x0100      /* signed data given */
#define FLAG_NEGATIVE       0x0200      /* value is negative */

#define find_char(s, c)     ((c) == '\0' ? NULL : strchr((s), (c)))

struct print_data {
    char spec;              /* conversion specifier */
    int flag;               /* flags */
    int width;              /* width */
    int prec;               /* precision */
    int size;               /* size of converted field or string */
    int padding;            /* number of padding characters */
    int ret;                /* return value accumulator */
    char prefix;            /* prefix, "+/-/space" or "0/x/X" */
};

static int print_char(FILE *fp, struct print_data *data, int c) {
    if (putc(c, fp) == EOF) {
        data->ret = -1;
        return -1;
    }
    data->ret++;
    return 0;
}

static int print_chars(FILE *fp, struct print_data *data, int c, int n) {
    while (n-- > 0)
        if (print_char(fp, data, c) != 0)
            return -1;
    return 0;
}

static int print_string(FILE *fp, struct print_data *data, const char *s, int size) {
    if (fwrite(s, size, 1, fp) < 1) {
        data->ret = -1;
        return -1;
    }
    data->ret += size;
    return 0;
}

static int print_prefix(FILE *fp, struct print_data *data) {
    int n = 0;
    char prefix[2];
    if (find_char("+- 0", data->prefix) != NULL) {
        prefix[n++] = data->prefix;
    } else if (find_char("xX", data->prefix) != NULL) {
        prefix[n++] = '0';
        prefix[n++] = data->prefix;
    }
    data->padding = data->width - data->size - n;
    if (!(data->flag & (FLAG_LEFT | FLAG_ZERO)) && print_chars(fp, data, ' ', data->padding) != 0)
        return -1;
    if (print_string(fp, data, prefix, n) != 0)
        return -1;
    if (data->flag & FLAG_ZERO && !(data->flag & FLAG_LEFT) && print_chars(fp, data, '0', data->padding) != 0)
        return -1;
    return 0;
}

static int print_suffix(FILE *fp, struct print_data *data) {
    if (data->flag & FLAG_LEFT && print_chars(fp, data, ' ', data->padding) != 0)
        return -1;
    return 0;
}

static int print_float(FILE *fp, struct print_data *data, va_list *ap) {
    /* TODO: Function `print_float' needs to be implemented. */
    (void) fp;
    data->flag & FLAG_LONGDOUBLE ? va_arg(*ap, long double) : va_arg(*ap, double);
    return 0;
}

static int print_int(FILE *fp, struct print_data *data, va_list *ap) {
    int buflen;
    unsigned int base;
    char *digs = "0123456789abcdef";
    char buf[INT_BUFSIZE];
    union {
        intptr_t i;
        uintptr_t u;
    } val;
    switch (data->spec) {
        case 'd':
        case 'i':
            data->flag |= FLAG_SIGNED;
            /* fallthrough */
        case 'u':
            base = 10;
            break;
        case 'o':
            base = 8;
            break;
        case 'X':
            digs = "0123456789ABCDEF";
            /* fallthrough */
        case 'p':
        case 'x':
            base = 16;
            break;
        default:
            return -1;
    }
    if (data->spec == 'p') {
        val.u = (uintptr_t) va_arg(*ap, void *);
    } else if (data->flag & FLAG_SIGNED) {
        val.i = data->flag & FLAG_SHORT ? (short int) va_arg(*ap, int) :
                data->flag & FLAG_LONG ? va_arg(*ap, long int) : va_arg(*ap, int);
        if (val.i < 0) {
            val.i = -val.i;
            data->flag |= FLAG_NEGATIVE;
        }
    } else {
        val.u = data->flag & FLAG_SHORT ? (unsigned short int) va_arg(*ap, unsigned int) :
                data->flag & FLAG_LONG ? va_arg(*ap, unsigned long int) : va_arg(*ap, unsigned int);
    }
    if (data->prec < 0)
        data->prec = 1;
    else
        data->flag &= ~FLAG_ZERO;
    buflen = (int) _ultoa(val.u, buf, base, digs);
    data->size = buflen > data->prec ? buflen : data->prec;
    if (data->spec == 'p') {
        data->prefix = 'x';
    } else if (data->flag & FLAG_SIGNED) {
        if (data->flag & FLAG_NEGATIVE)
            data->prefix = '-';
        else if (data->flag & FLAG_SIGN)
            data->prefix = '+';
        else if (data->flag & FLAG_SPACE)
            data->prefix = ' ';
    } else if (data->flag & FLAG_ALTERNATE) {
        if (data->spec == 'o' && data->size <= buflen)
            data->prefix = '0';
        else if ((data->spec == 'x' || data->spec == 'X') && val.u != 0)
            data->prefix = data->spec;
    } else {
        data->prefix = '\0';
    }
    if (print_prefix(fp, data) != 0)
        return -1;
    if (print_chars(fp, data, '0', data->size - buflen) != 0)
        return -1;
    if (print_string(fp, data, buf, buflen) != 0)
        return -1;
    if (print_suffix(fp, data) != 0)
        return -1;
    return 0;
}

static int print(FILE *fp, struct print_data *data, va_list *ap) {
    char *s, *p;
    if (find_char("eEfgG", data->spec) != NULL)
        return print_float(fp, data, ap);
    else if (find_char("diouxXp", data->spec) != NULL)
        return print_int(fp, data, ap);
    data->prefix = '\0';
    switch (data->spec) {
        case 'c':
            data->size = 1;
            if (print_prefix(fp, data) != 0)
                return -1;
            if (print_char(fp, data, va_arg(*ap, int)) != 0)
                return -1;
            break;
        case 's':
            s = va_arg(*ap, char *);
            if (data->prec < 0)
                data->size = (int) strlen(s);
            else if ((p = memchr(s, '\0', data->prec)) != NULL)
                data->size = (int) (p - s);
            else
                data->size = data->prec;
            if (print_prefix(fp, data) != 0)
                return -1;
            if (print_string(fp, data, s, data->size) != 0)
                return -1;
            break;
        case 'n':
            if (data->flag & FLAG_SHORT)
                *va_arg(*ap, short int *) = (short int) data->ret;
            else if (data->flag & FLAG_LONG)
                *va_arg(*ap, long int *) = data->ret;
            else
                *va_arg(*ap, int *) = data->ret;
            return 0;
        case '\0':
            return -1;
        default:
            data->size = 1;
            if (print_prefix(fp, data) != 0)
                return -1;
            if (print_char(fp, data, data->spec) != 0)
                return -1;
            break;
    }
    if (print_suffix(fp, data) != 0)
        return -1;
    return 0;
}

int vfprintf(FILE *fp, const char *format, va_list arg) {
    int n;
    const char *fmt = format;
    const char *p;
    const char *flag_chars;
    va_list ap;
    struct print_data data;
    __va_copy(ap, arg);
    data.ret = 0;
    while (1) {
        p = fmt;
        for (; *fmt != '\0' && *fmt != '%'; fmt++);
        if ((n = (int) (fmt - p)) > 0)
            if (print_string(fp, &data, p, n) != 0)
                break;
        if (*fmt == '\0')
            break;
        fmt++;
        data.flag = 0;
        data.width = 0;
        data.prec = -1;
        flag_chars = "-+ #0";
        for (; (p = find_char(flag_chars, *fmt)) != NULL; fmt++)
            data.flag |= (FLAG_LEFT << (p - flag_chars));
        if (*fmt == '*') {
            data.width = va_arg(ap, int);
            if (data.width < 0) {
                data.width = -data.width;
                data.flag |= FLAG_LEFT;
            }
            fmt++;
        } else if (isdigit(*fmt)) {
            data.width = (int) strtol(fmt, (char **) &fmt, 10);
        }
        if (*fmt == '.') {
            fmt++;
            if (*fmt == '*') {
                data.prec = va_arg(ap, int);
                if (data.prec < 0)
                    data.prec = -1;
                fmt++;
            } else if (isdigit(*fmt)) {
                data.prec = (int) strtol(fmt, (char **) &fmt, 10);
            }
        }
        flag_chars = "hlL";
        if ((p = find_char(flag_chars, *fmt)) != NULL) {
            data.flag |= (FLAG_SHORT << (p - flag_chars));
            fmt++;
        }
        data.spec = *fmt++;
        if (print(fp, &data, &ap) != 0)
            break;
    }
    va_end(ap);
    return data.ret;
}
