#include "internal.h"
#include "stdio.h"
#include "stdlib.h"
#include "syscall.h"

int _fclose(FILE *stream) {
	int ret;
	ret = fflush(stream);
	_freebuf(stream);
	if (close(stream->_file) == -1)
		ret = EOF;
	stream->_flag = 0;
	stream->_file = -1;
	stream->_charbuf = 0;
	if (stream->_tmpfname != NULL) {
		if (remove(stream->_tmpfname))
			ret = EOF;
		free(stream->_tmpfname);
		stream->_tmpfname = NULL;
	}
	return ret;
}
