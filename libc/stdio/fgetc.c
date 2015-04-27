#include "internal.h"
#include "stdio.h"
#include "syscall.h"

int fgetc(FILE *stream) {
	ssize_t result;
	if (stream->_ptr < stream->_rend)
		return *(unsigned char *) stream->_ptr++;
	if ((stream->_flag & _IOSTRG) || !(stream->_flag & (_IOREAD | _IORW))
			|| (stream->_flag & _IOWRT)) {
		stream->_flag |= _IOERR;
		return EOF;
	}
	if (stream->_ptr == NULL)
		_allocbuf(stream);
	stream->_flag |= _IOREAD;
	if (stream->_end <= stream->_base || (result = read(stream->_file,
			stream->_base, stream->_end - stream->_base)) == -1) {
		stream->_flag |= _IOERR;
		return EOF;
	}
	stream->_ptr = stream->_base;
	stream->_rend = stream->_base + result;
	if (result == 0) {
		stream->_flag |= _IOEOF;
		return EOF;
	}
	return *(unsigned char *) stream->_ptr++;
}
