#include "internal.h"
#include "syscall.h"

static char buf[_BUFSIZ];

FILE _iob[3] = { {
		STDIN_FILENO,                   /* _file */
		_IOREAD,                        /* _flag */
		0,                              /* _charbuf */
		buf,                            /* _base */
		buf + _BUFSIZ,                  /* _end */
		buf,                            /* _ptr */
		buf,                            /* _rend */
		buf,                            /* _wend */
		NULL                            /* _tmpfname */
	}, {
		STDOUT_FILENO,                  /* _file */
		_IOWRT,                         /* _flag */
		0,                              /* _charbuf */
		(char *) &_iob[1]._charbuf,     /* _base */
		(char *) &_iob[1]._charbuf + 1, /* _end */
		(char *) &_iob[1]._charbuf,     /* _ptr */
		(char *) &_iob[1]._charbuf,     /* _rend */
		(char *) &_iob[1]._charbuf,     /* _wend */
		NULL                            /* _tmpfname */
	}, {
		STDERR_FILENO,                  /* _file */
		_IOWRT,                         /* _flag */
		0,                              /* _charbuf */
		(char *) &_iob[2]._charbuf,     /* _base */
		(char *) &_iob[2]._charbuf + 1, /* _end */
		(char *) &_iob[2]._charbuf,     /* _ptr */
		(char *) &_iob[2]._charbuf,     /* _rend */
		(char *) &_iob[2]._charbuf,     /* _wend */
		NULL                            /* _tmpfname */
	}
};
