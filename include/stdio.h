#ifndef _STDIO_H
#define _STDIO_H

#define __need_va_list
#define __need_size_t
#define __need_NULL

#include <stdarg.h>
#include <stddef.h>

#define _IOFBF          0
#define _IOLBF          1
#define _IONBF          2

#define BUFSIZ          1024
#define EOF             (-1)
#define FOPEN_MAX       20
#define FILENAME_MAX    260
#define L_tmpnam        255

#define SEEK_SET        0
#define SEEK_CUR        1
#define SEEK_END        2

#define TMP_MAX         32767

#define stdin           _stdin
#define stdout          _stdout
#define stderr          _stderr

#define getc(s)         ((int) ((s)->_ptr < (s)->_rend ? *(unsigned char *) (s)->_ptr++ : fgetc(s)))
#define getchar()       getc(stdin)
#define putc(c, s)      ((int) ((s)->_ptr + 1 < (s)->_wend ? \
    (*(unsigned char *) (s)->_ptr++ = (unsigned char) (c)) : fputc(c, s)))
#define putchar(c)      putc(c, stdout)

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef struct {
    int _file;
    int _flag;
    int _charbuf;
    char *_base;
    char *_end;
    char *_ptr;
    char *_rend;
    char *_wend;
    char *_tmpfname;
} FILE;

__extension__ typedef __int64 fpos_t;

extern FILE *_stdin;
extern FILE *_stdout;
extern FILE *_stderr;

int remove(const char *);

int rename(const char *, const char *);

FILE *tmpfile(void);

char *tmpnam(char *);

int fclose(FILE *);

int fflush(FILE *);

FILE *fopen(const char *, const char *);

FILE *freopen(const char *, const char *, FILE *);

void setbuf(FILE *, char *);

int setvbuf(FILE *, char *, int, size_t);

int fprintf(FILE *, const char *, ...);

int fscanf(FILE *, const char *, ...);

int printf(const char *, ...);

int scanf(const char *, ...);

int sprintf(char *, const char *, ...);

int sscanf(const char *, const char *, ...);

int vfprintf(FILE *, const char *, va_list);

int vprintf(const char *, va_list);

int vsprintf(char *, const char *, va_list);

int fgetc(FILE *);

char *fgets(char *, int, FILE *);

int fputc(int, FILE *);

int fputs(const char *, FILE *);

int (getc)(FILE *);

int (getchar)(void);

char *gets(char *);

int (putc)(int, FILE *);

int (putchar)(int);

int puts(const char *);

int ungetc(int, FILE *);

size_t fread(void *, size_t, size_t, FILE *);

size_t fwrite(const void *, size_t, size_t, FILE *);

int fgetpos(FILE *, fpos_t *);

int fseek(FILE *, long int, int);

int fsetpos(FILE *, const fpos_t *);

long int ftell(FILE *);

void rewind(FILE *);

void clearerr(FILE *);

int feof(FILE *);

int ferror(FILE *);

void perror(const char *);

__END_DECLS

#endif /* _STDIO_H */
