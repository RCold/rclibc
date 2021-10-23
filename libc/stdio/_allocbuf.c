#include "_stdio.h"
#include "stdlib.h"

void _allocbuf(FILE *fp) {
    char *buf;
    int size;
    if ((buf = malloc(BUFSIZ)) != NULL) {
        fp->_flag |= __IODBF;
        size = BUFSIZ;
    } else {
        buf = (char *) &fp->_charbuf;
        size = 1;
    }
    fp->_base = buf;
    fp->_end = buf + size;
    fp->_ptr = buf;
    fp->_rend = buf;
    fp->_wend = buf;
}
