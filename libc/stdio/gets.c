#include "stdio.h"

char *gets(char *s) {
	int c;
	char *p = s;
	if ((c = getchar()) == EOF)
		return NULL;
	while (c != EOF && c != '\n') {
		*p++ = (char) c;
		c = getchar();
	}
	*p = '\0';
	if (ferror(stdin))
		return NULL;
	return s;
}
