#include "_stdio.h"
#include "_unistd.h"

int _fflush(FILE *fp) {
    if (!__is_valid(fp))
        return EOF;
    if (__is_writable(fp) && __is_writing(fp) && fp->_ptr > fp->_base) {
        if (write(fp->_file, fp->_base, fp->_ptr - fp->_base) < 0)
            return EOF;
        fp->_ptr = fp->_base;
        if (fp->_flag & __IOLBF)
            fp->_wend = fp->_ptr + 1;
    }
    return 0;
}
