#include "internal.h"
#include "stdio.h"

int fclose(FILE *stream) {
	int ret;
	if (!(stream->_flag & (_IOREAD | _IOWRT | _IORW)))
		return EOF;
	ret = _fclose(stream);
	_freefile(stream);
	return ret;
}
