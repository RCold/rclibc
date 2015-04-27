#include "internal.h"
#include "stdio.h"

FILE *freopen(const char *filename, const char *mode, FILE *stream) {
	_fclose(stream);
	return _fopen(filename, mode, stream);
}
