#include "stdio.h"

int (getc)(FILE *fp) {
    return fp->_ptr < fp->_rend ? *(unsigned char *) fp->_ptr++ : fgetc(fp);
}
