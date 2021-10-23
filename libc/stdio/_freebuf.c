#include "_stdio.h"
#include "stdlib.h"

void _freebuf(FILE *fp) {
    if (fp->_flag & __IODBF)
        free(fp->_base);
    fp->_flag &= ~(__IODBF | __IOFBF | __IOLBF | __IONBF);
    fp->_base = NULL;
    fp->_end = NULL;
    fp->_ptr = NULL;
    fp->_rend = NULL;
    fp->_wend = NULL;
}
