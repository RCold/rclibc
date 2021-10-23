#include "_stdio.h"

FILE *fopen(const char *filename, const char *mode) {
    FILE *fp = _allocfile();
    if (fp == NULL)
        return NULL;
    return _fopen(filename, mode, fp);
}
