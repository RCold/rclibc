#include "internal.h"
#include "stdio.h"

int fputc(int c, FILE *stream) {
	if (stream->_ptr + 1 < stream->_wend)
		return *(unsigned char *) stream->_ptr++ = (unsigned char) c;
	if ((stream->_flag & _IOSTRG) || !(stream->_flag & (_IOWRT | _IORW))
			|| ((stream->_flag & _IOREAD) && !(stream->_flag & _IOEOF))) {
		stream->_flag |= _IOERR;
		return EOF;
	}
	if (stream->_ptr == NULL)
		_allocbuf(stream);
	if (stream->_flag & _IOREAD)
		stream->_flag &= ~_IOREAD;
	stream->_flag |= _IOWRT;
	*stream->_ptr++ = (char) c;
	if ((stream->_ptr >= stream->_end || ((stream->_flag & _IOLBF) && c == '\n'))
			&& fflush(stream) == EOF)
		return EOF;
	if (stream->_flag & _IOLBF)
		stream->_wend = stream->_ptr + 1;
	else
		stream->_wend = stream->_end;
	return (unsigned char) c;
}
