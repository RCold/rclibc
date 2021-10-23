#include "_stdio.h"

int fflush(FILE *fp) {
    int i;
    int ret = 0;
    if (fp != NULL) {
        ret = _fflush(fp);
        if (ret != EOF)
            fp->_wend = fp->_base;
        return ret;
    }
    if (stdout != NULL && fflush(stdout) == EOF)
        ret = EOF;
    if (stderr != NULL && fflush(stderr) == EOF)
        ret = EOF;
    for (i = 0; i < FOPEN_MAX; i++)
        if (_piob[i] != NULL && fflush(_piob[i]) == EOF)
            ret = EOF;
    return ret;
}
