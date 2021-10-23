#include "_stdio.h"
#include "stdlib.h"

int setvbuf(FILE *fp, char *buf, int mode, size_t size) {
    int bflag;
    if (__is_reading(fp) || __is_writing(fp))
        return -1;
    switch (mode) {
        case _IOFBF:
            bflag = __IOFBF;
            break;
        case _IOLBF:
            bflag = __IOLBF;
            break;
        case _IONBF:
            bflag = __IONBF;
            buf = (char *) &fp->_charbuf;
            size = 1;
            break;
        default:
            return -1;
    }
    if (size < 1)
        return -1;
    if (buf == NULL) {
        if ((buf = malloc(size)) == NULL)
            return -1;
        bflag |= __IODBF;
    }
    _freebuf(fp);
    fp->_flag |= bflag;
    fp->_base = buf;
    fp->_end = buf + size;
    fp->_ptr = buf;
    fp->_rend = buf;
    fp->_wend = buf;
    return 0;
}
