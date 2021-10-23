#include "_stdio.h"

FILE *freopen(const char *filename, const char *mode, FILE *fp) {
    _fclose(fp);
    return _fopen(filename, mode, fp);
}
