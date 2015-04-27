#include "internal.h"
#include "stdio.h"

int ungetc(int c, FILE *stream) {
	if ((stream->_flag & _IOSTRG) || !(stream->_flag & (_IOREAD | _IORW))
			|| (stream->_flag & _IOWRT)) {
		stream->_flag |= _IOERR;
		return EOF;
	}
	if (c == EOF || (stream->_rend > stream->_base
			&& stream->_ptr <= stream->_base))
		return EOF;
	if (stream->_ptr == NULL)
		_allocbuf(stream);
	stream->_flag |= _IOREAD;
	if (stream->_ptr > stream->_base)
		*--stream->_ptr = (char) c;
	else {
		*stream->_ptr = (char) c;
		stream->_rend = stream->_ptr + 1;
	}
	return (unsigned char) c;
}
