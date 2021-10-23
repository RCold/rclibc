#include "_stdio.h"

int feof(FILE *fp) {
    return fp->_flag & __IOEOF;
}
