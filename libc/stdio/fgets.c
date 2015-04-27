#include "stdio.h"

char *fgets(char *s, int n, FILE *stream) {
	int c;
	char *p = s;
	if (n <= 0 || (c = getc(stream)) == EOF)
		return NULL;
	while (p - s < n - 1 && c != EOF) {
		*p++ = (char) c;
		if (c == '\n')
			break;
		c = getc(stream);
	}
	*p = '\0';
	if (ferror(stdin))
		return NULL;
	return s;
}
