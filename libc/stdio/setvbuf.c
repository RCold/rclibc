#include "internal.h"
#include "stdio.h"
#include "stdlib.h"

int setvbuf(FILE *stream, char *buf, int mode, size_t size) {
	if (stream->_rend != stream->_base || stream->_wend != stream->_base)
		return -1;
	if (mode == _IONBF) {
		buf = (char *) &stream->_charbuf;
		size = 1;
	} else if (mode == _IOFBF || mode == _IOLBF) {
		if (size < 2 || (buf == NULL && (buf = malloc(size)) == NULL))
			return -1;
		stream->_flag |= _IODBF;
	} else
		return -1;
	_freebuf(stream);
	stream->_flag |= mode;
	stream->_base = buf;
	stream->_end = buf + size;
	stream->_ptr = buf;
	stream->_rend = buf;
	stream->_wend = buf;
	return 0;
}
