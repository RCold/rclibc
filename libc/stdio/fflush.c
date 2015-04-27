#include "internal.h"
#include "stdio.h"
#include "syscall.h"

int fflush(FILE *stream) {
	int i;
	int ret;
	if (stream == NULL) {
		ret = 0;
		for (i = 0; i < FOPEN_MAX; i++)
			if (_piob[i] != NULL && (_piob[i]->_flag & _IOWRT)
					&& fflush(_piob[i]) == EOF)
				ret = EOF;
		return ret;
	}
	if ((stream->_flag & _IOWRT) && stream->_ptr > stream->_base
			&& write(stream->_file, stream->_base, stream->_ptr
			- stream->_base) == -1) {
		stream->_flag |= _IOERR;
		return EOF;
	}
	if (stream->_flag & _IORW)
		stream->_flag &= ~_IOWRT;
	stream->_ptr = stream->_base;
	stream->_wend = stream->_base;
	return 0;
}
