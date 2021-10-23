#include "_stdio.h"

int ferror(FILE *fp) {
    return fp->_flag & __IOERR;
}
