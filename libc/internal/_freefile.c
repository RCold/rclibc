#include "internal.h"
#include "stdio.h"
#include "stdlib.h"

void _freefile(FILE *stream) {
	int i;
	for (i = 3; i < FOPEN_MAX; i++)
		if (_piob[i] == stream) {
			_piob[i] = NULL;
			free(stream);
			break;
		}
	return;
}
