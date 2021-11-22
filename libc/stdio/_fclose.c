#include "_stdio.h"
#include "_unistd.h"
#include "stdlib.h"

int _fclose(FILE *fp) {
    int ret = _fflush(fp);
    _freebuf(fp);
    if (!__is_open(fp) || close(fp->_file) != 0)
        ret = EOF;
    if (fp->_tmpfname != NULL) {
        if (remove(fp->_tmpfname) != 0)
            ret = EOF;
        free(fp->_tmpfname);
    }
    _finit(fp, NULL, NULL);
    return ret;
}
