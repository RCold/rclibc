#ifndef __STDIO_H
#define __STDIO_H

#define __IOREAD        0x0001
#define __IOWRT         0x0002
#define __IOAPPD        0x0004
#define __IOUPDT        0x0008
#define __IOBIN         0x0010
#define __IOEOF         0x0020
#define __IOERR         0x0040
#define __IOSTR         0x0080
#define __IODBF         0x0100
#define __IOFBF         0x0200
#define __IOLBF         0x0400
#define __IONBF         0x0800

#define __is_open(fp)       ((fp)->_flag & (__IOREAD | __IOWRT | __IOAPPD))
#define __is_valid(fp)      (__is_open(fp) && !((fp)->_flag & __IOSTR))
#define __is_readable(fp)   ((fp)->_flag & (__IOREAD | __IOUPDT))
#define __is_writable(fp)   ((fp)->_flag & (__IOWRT | __IOAPPD | __IOUPDT))
#define __is_reading(fp)    ((fp)->_rend > (fp)->_base)
#define __is_writing(fp)    ((fp)->_wend > (fp)->_base)

#include <stdio.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

extern FILE *_piob[];

void _allocbuf(FILE *);

FILE *_allocfile(void);

int _fclose(FILE *);

int _fflush(FILE *);

void _finit(FILE *, char *, char *);

FILE *_fopen(const char *, const char *, FILE *);

void _freebuf(FILE *);

void _freefile(FILE *);

int _tmpdir(char *, size_t);

char *_tmpnam(char *, size_t);

__END_DECLS

#endif /* __STDIO_H */
