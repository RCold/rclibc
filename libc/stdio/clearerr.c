#include "internal.h"
#include "stdio.h"

void clearerr(FILE *stream) {
	stream->_flag &= ~(_IOERR | _IOEOF);
	return;
}
