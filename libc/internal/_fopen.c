#include "internal.h"
#include "syscall.h"

FILE *_fopen(const char *filename, const char *mode, FILE *stream) {
	int flags;
	flags = 0;
	switch (*mode++) {
	case 'r':
		stream->_flag |= _IOREAD;
		flags |= O_RDONLY;
		break;
	case 'w':
		stream->_flag |= _IOWRT;
		flags |= O_WRONLY | O_CREAT | O_TRUNC;
		break;
	case 'a':
		stream->_flag |= _IOWRT;
		flags |= O_WRONLY | O_CREAT | O_APPEND;
		break;
	default:
		return NULL;
	}
	while (*mode != '\0')
		switch (*mode++) {
		case 'b':
			flags |= O_BINARY;
			break;
		case '+':
			stream->_flag &= ~(_IOREAD | _IOWRT);
			stream->_flag |= _IORW;
			flags &= ~(O_RDONLY | O_WRONLY);
			flags |= O_RDWR;
			break;
		}
	stream->_file = open(filename, flags);
	if (stream->_file == -1) {
		_freefile(stream);
		return NULL;
	}
	return stream;
}
