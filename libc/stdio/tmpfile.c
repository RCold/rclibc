#include "internal.h"
#include "stdio.h"
#include "stdlib.h"

FILE *tmpfile(void) {
	static unsigned long int seed = 0;
	char *s;
	FILE *stream;
	if ((s = malloc(L_tmpnam)) == NULL)
		return NULL;
	if (_tmpnam(s, &seed) == NULL || (stream = fopen(s, "wb+")) == NULL) {
		free(s);
		return NULL;
	}
	stream->_tmpfname = s;
	return stream;
}
