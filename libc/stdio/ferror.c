#include "internal.h"
#include "stdio.h"

int ferror(FILE *stream) {
	return stream->_flag & _IOERR;
}
