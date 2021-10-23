#include "_stdio.h"
#include "stdlib.h"

FILE *_allocfile(void) {
    int i;
    FILE *fp = NULL;
    for (i = 0; i < FOPEN_MAX; i++)
        if (_piob[i] == NULL) {
            if ((fp = malloc(sizeof(FILE))) == NULL)
                return NULL;
            _finit(fp, NULL, NULL);
            _piob[i] = fp;
            break;
        }
    return fp;
}
