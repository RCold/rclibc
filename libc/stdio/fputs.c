#include "stdio.h"

int fputs(const char *s, FILE *stream) {
	while (*s != '\0')
		if (putc(*s++, stream) == EOF)
			return EOF;
	return 0;
}
