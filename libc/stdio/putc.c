#include "stdio.h"

int (putc)(int c, FILE *fp) {
    return fp->_ptr + 1 < fp->_wend ? (*(unsigned char *) fp->_ptr++ = (unsigned char) c) : fputc(c, fp);
}
