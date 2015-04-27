#include "internal.h"
#include "stdio.h"

char *tmpnam(char *s) {
	static unsigned long int seed = 0;
	static char namebuf[L_tmpnam];
	if (s == NULL)
		s = namebuf;
	if (_tmpnam(s, &seed) == NULL)
		return NULL;
	return s;
}
