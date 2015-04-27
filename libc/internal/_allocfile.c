#include "internal.h"
#include "stdio.h"
#include "stdlib.h"

FILE *_allocfile(void) {
	int i;
	FILE *stream = NULL;
	for (i = 3; i < FOPEN_MAX; i++)
		if (_piob[i] == NULL) {
			if ((stream = malloc(sizeof(FILE))) == NULL)
				return NULL;
			stream->_flag = 0;
			stream->_file = -1;
			stream->_charbuf = 0;
			stream->_base = NULL;
			stream->_end = NULL;
			stream->_ptr = NULL;
			stream->_rend = NULL;
			stream->_wend = NULL;
			stream->_tmpfname = NULL;
			_piob[i] = stream;
			break;
		}
	return stream;
}
