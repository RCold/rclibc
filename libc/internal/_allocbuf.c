#include "internal.h"
#include "stdlib.h"
#include "syscall.h"

void _allocbuf(FILE *stream) {
	char *buf;
	int size;
	if (stream->_ptr != NULL)
		return;
	if ((!isatty(stream->_file) || (stream->_flag & _IOREAD))
			&& (buf = malloc(_BUFSIZ)) != NULL) {
		stream->_flag |= _IODBF;
		size = _BUFSIZ;
	} else {
		buf = (char *) &stream->_charbuf;
		size = 1;
	}
	stream->_base = buf;
	stream->_end = buf + size;
	stream->_ptr = buf;
	stream->_rend = buf;
	stream->_wend = buf;
	return;
}
