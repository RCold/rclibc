#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>

static void prclass(const char *name, int (*fn)(int)) {
	int c;
	printf("%s: ", name);
	for (c = 0; c <= UCHAR_MAX; c++)
		if ((*fn)(c))
			putchar(c);
	putchar('\n');
	return;
}

int main(void) {
	unsigned char *s;
	int c;
	prclass("ispunct", &ispunct);
	prclass("isdigit", &isdigit);
	prclass("islower", &islower);
	prclass("isupper", &isupper);
	prclass("isalpha", &isalpha);
	prclass("isalnum", &isalnum);
	for (s = (unsigned char *) "0123456789"; *s; s++)
		assert(isdigit(*s) && isxdigit(*s));
	for (s = (unsigned char *) "abcdefABCDEF"; *s; s++)
		assert(isxdigit(*s));
	for (s = (unsigned char *) "abcdefghijklmnopqrstuvwxyz"; *s; s++)
		assert(islower(*s));
	for (s = (unsigned char *) "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; s++)
		assert(isupper(*s));
	for (s = (unsigned char *) "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; s++)
		assert(ispunct(*s));
	for (s = (unsigned char *) "\f\n\r\t\v"; *s; s++)
		assert(isspace(*s) && iscntrl(*s));
	assert(isspace(' ') && isprint(' '));
	assert(iscntrl('\a') && iscntrl('\b'));
	for (c = EOF; c <= UCHAR_MAX; c++) {
		if (isdigit(c))
			assert(isalnum(c));
		if (isupper(c))
			assert(isalpha(c));
		if (islower(c))
			assert(isalpha(c));
		if (isalpha(c))
			assert(isalnum(c) && !isdigit(c));
		if (isalnum(c))
			assert(isgraph(c) && !ispunct(c));
		if (ispunct(c))
			assert(isgraph(c));
		if (isgraph(c))
			assert(isprint(c));
		if (isspace(c))
			assert(c==' ' || !isprint(c));
		if (iscntrl(c))
			assert(!isalnum(c));
	}
	for (s = (unsigned char *) "0123456789"; *s; s++)
		assert((isdigit)(*s) && (isxdigit)(*s));
	for (s = (unsigned char *) "abcdefABCDEF"; *s; s++)
		assert((isxdigit)(*s));
	for (s = (unsigned char *) "abcdefghijklmnopqrstuvwxyz"; *s; s++)
		assert((islower)(*s));
	for (s = (unsigned char *) "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; s++)
		assert((isupper)(*s));
	for (s = (unsigned char *) "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; s++)
		assert((ispunct)(*s));
	for (s = (unsigned char *) "\f\n\r\t\v"; *s; s++)
		assert((isspace)(*s) && (iscntrl)(*s));
	assert((isspace)(' ') && (isprint)(' '));
	assert((iscntrl)('\a') && (iscntrl)('\b'));
	for (c = EOF; c <= UCHAR_MAX; c++) {
		if ((isdigit)(c))
			assert((isalnum)(c));
		if ((isupper)(c))
			assert((isalpha)(c));
		if ((islower)(c))
			assert((isalpha)(c));
		if ((isalpha)(c))
			assert((isalnum)(c) && !(isdigit)(c));
		if ((isalnum)(c))
			assert((isgraph)(c) && !(ispunct)(c));
		if ((ispunct)(c))
			assert((isgraph)(c));
		if ((isgraph)(c))
			assert((isprint)(c));
		if ((isspace)(c))
			assert(c == ' ' || !(isprint)(c));
		if ((iscntrl)(c))
			assert(!(isalnum)(c));
	}
	puts("SUCCESS testing <ctype.h>");
	return 0;
}
