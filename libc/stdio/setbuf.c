#include "stdio.h"

void setbuf(FILE *stream, char *buf) {
	if (buf == NULL)
		setvbuf(stream, NULL, _IONBF, 0);
	else
		setvbuf(stream, buf, _IOFBF, BUFSIZ);
	return;
}
