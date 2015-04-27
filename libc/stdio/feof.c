#include "internal.h"
#include "stdio.h"

int feof(FILE *stream) {
	return stream->_flag & _IOEOF;
}
