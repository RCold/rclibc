#include "_stdio.h"

int ungetc(int c, FILE *fp) {
    if (!__is_valid(fp) || !__is_readable(fp) || __is_writing(fp))
        return EOF;
    if (c == EOF || (__is_reading(fp) && fp->_ptr <= fp->_base))
        return EOF;
    if (fp->_ptr == NULL)
        _allocbuf(fp);
    if (fp->_ptr > fp->_base) {
        *--fp->_ptr = (char) c;
    } else {
        *fp->_ptr = (char) c;
        fp->_rend = fp->_ptr + 1;
    }
    fp->_flag &= ~__IOEOF;
    return (unsigned char) c;
}
