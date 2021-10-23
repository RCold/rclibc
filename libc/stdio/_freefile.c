#include "_stdio.h"
#include "stdlib.h"

void _freefile(FILE *fp) {
    int i;
    for (i = 0; i < FOPEN_MAX; i++)
        if (_piob[i] == fp) {
            _piob[i] = NULL;
            free(fp);
            break;
        }
}
