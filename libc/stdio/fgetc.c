#include "_stdio.h"
#include "_unistd.h"

int fgetc(FILE *fp) {
    ssize_t n;
    if (fp->_ptr < fp->_rend)
        return *(unsigned char *) fp->_ptr++;
    if (!__is_valid(fp) || !__is_readable(fp) || __is_writing(fp))
        return EOF;
    if (fp->_ptr == NULL)
        _allocbuf(fp);
    if ((n = read(fp->_file, fp->_base, fp->_end - fp->_base)) < 0) {
        fp->_flag |= __IOERR;
        return EOF;
    }
    fp->_ptr = fp->_base;
    fp->_rend = fp->_base + n;
    if (n == 0) {
        fp->_flag |= __IOEOF;
        return EOF;
    }
    return *(unsigned char *) fp->_ptr++;
}
