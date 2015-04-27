#include "internal.h"
#include "stdlib.h"

void _freebuf(FILE *stream) {
	if (stream->_flag & _IODBF) {
		free(stream->_base);
		stream->_flag &= ~_IODBF;
	}
	stream->_flag &= ~(_IOFBF | _IOLBF | _IONBF);
	stream->_base = NULL;
	stream->_end = NULL;
	stream->_ptr = NULL;
	stream->_rend = NULL;
	stream->_wend = NULL;
	return;
}
