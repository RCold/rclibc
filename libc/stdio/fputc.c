#include "_stdio.h"

int fputc(int c, FILE *fp) {
    if (fp->_ptr + 1 < fp->_wend)
        return *(unsigned char *) fp->_ptr++ = (unsigned char) c;
    if (!__is_valid(fp) || !__is_writable(fp) || __is_reading(fp))
        return EOF;
    if (fp->_ptr == NULL)
        _allocbuf(fp);
    *fp->_ptr++ = (char) c;
    if (fp->_flag & __IOFBF)
        fp->_wend = fp->_end;
    else if (fp->_flag & __IOLBF)
        fp->_wend = fp->_ptr + 1;
    else if (fp->_flag & __IONBF || !__is_writing(fp))
        fp->_wend = fp->_ptr;
    if ((fp->_ptr >= fp->_wend || fp->_ptr >= fp->_end || (fp->_flag & __IOLBF && c == '\n')) && _fflush(fp) == EOF) {
        fp->_flag |= __IOERR;
        return EOF;
    }
    return (unsigned char) c;
}
