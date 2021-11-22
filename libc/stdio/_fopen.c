#include "_stdio.h"
#include "_fcntl.h"

FILE *_fopen(const char *filename, const char *mode, FILE *fp) {
    int oflag;
    int oprot = 0666;
    switch (*mode++) {
        case 'r':
            fp->_flag = __IOREAD;
            break;
        case 'w':
            fp->_flag = __IOWRT;
            break;
        case 'a':
            fp->_flag = __IOAPPD;
            break;
        default:
            return NULL;
    }
    while (*mode != '\0') {
        switch (*mode++) {
            case '+':
                fp->_flag |= __IOUPDT;
                break;
            case 'b':
                fp->_flag |= __IOBIN;
                break;
            default:
                return NULL;
        }
    }
    if (fp->_flag & __IOUPDT)
        oflag = O_RDWR;
    else if (fp->_flag & __IOREAD)
        oflag = O_RDONLY;
    else
        oflag = O_WRONLY;
    if (fp->_flag & __IOWRT)
        oflag |= O_TRUNC;
    if (fp->_flag & __IOAPPD)
        oflag |= O_APPEND;
    if (fp->_flag & (__IOWRT | __IOAPPD))
        oflag |= O_CREAT;
    if (fp->_flag & __IOBIN)
        oflag |= O_BINARY;
    fp->_file = open(filename, oflag, oprot);
    if (fp->_file < 0) {
        fp->_flag = 0;
        _freefile(fp);
        return NULL;
    }
    return fp;
}
