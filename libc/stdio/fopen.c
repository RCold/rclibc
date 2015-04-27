#include "internal.h"
#include "stdio.h"

FILE *fopen(const char *filename, const char *mode) {
	FILE *stream;
	if ((stream = _allocfile()) == NULL)
		return NULL;
	return _fopen(filename, mode, stream);
}
