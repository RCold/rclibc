#include "_stdio.h"
#include "_unistd.h"

static char buf[BUFSIZ];

static FILE f = {
        STDIN_FILENO,               /* _file */
        __IOREAD,                   /* _flag */
        0,                          /* _charbuf */
        buf,                        /* _base */
        buf + BUFSIZ,               /* _end */
        buf,                        /* _ptr */
        buf,                        /* _rend */
        buf,                        /* _wend */
        NULL                        /* _tmpfname */
};

FILE *_stdin = &f;
