#include "_stdio.h"

void clearerr(FILE *fp) {
    fp->_flag &= ~(__IOEOF | __IOERR);
}
