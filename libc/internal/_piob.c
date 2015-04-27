#include "internal.h"
#include "stdio.h"

FILE *_piob[FOPEN_MAX] = { &_iob[0], &_iob[1], &_iob[2] };
