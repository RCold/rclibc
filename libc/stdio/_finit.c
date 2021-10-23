#include "_stdio.h"

void _finit(FILE *fp, char *base, char *end) {
    fp->_file = -1;
    fp->_flag = 0;
    fp->_charbuf = 0;
    fp->_base = base;
    fp->_end = end;
    fp->_ptr = base;
    fp->_rend = base;
    fp->_wend = base;
    fp->_tmpfname = NULL;
}
