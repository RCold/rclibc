#ifndef _STDIO_H
#define _STDIO_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define BUFSIZ          512
#define EOF             (-1)
#define FILENAME_MAX    260
#define FOPEN_MAX       20
#define L_tmpnam        255
#define TMP_MAX         32767

#define SEEK_SET        0
#define SEEK_CUR        1
#define SEEK_END        2

#define _IOFBF          0x0040
#define _IOLBF          0x0080
#define _IONBF          0x0100

#define getc(s) ((int) ((s)->_ptr < (s)->_rend ? \
    *(unsigned char *) (s)->_ptr++ : fgetc(s)))
#define getchar() getc(stdin)
#define putc(c,s) ((int) ((s)->_ptr + 1 < (s)->_wend ? \
    (*(unsigned char *) (s)->_ptr++ = (unsigned char) (c)) : fputc(c,s)))
#define putchar(c) putc(c,stdout)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif /* _SIZE_T_DEFINED */

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef char *va_list;
#endif /* _VA_LIST_DEFINED */

#ifndef _FILE_DEFINED
#define _FILE_DEFINED
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
#endif /* _FILE_DEFINED */

/* File position type. */
#ifndef _FPOS_T_DEFINED
#define _FPOS_T_DEFINED
typedef long int fpos_t;
#endif /* _FPOS_T_DEFINED */

extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

void clearerr(FILE *);
int fclose(FILE *);
int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
int fgetc(FILE *);
int fgetpos(FILE *, fpos_t *);
char *fgets(char *, int, FILE *);
FILE *fopen(const char *, const char *);
int fprintf(FILE *, const char *, ...);
int fputc(int, FILE *);
int fputs(const char *, FILE *);
size_t fread(void *, size_t, size_t, FILE *);
FILE *freopen(const char *, const char *, FILE *);
int fscanf(FILE *, const char *, ...);
int fseek(FILE *, long, int);
int fsetpos(FILE *, const fpos_t *);
long ftell(FILE *);
size_t fwrite(const void *, size_t, size_t, FILE *);
int (getc)(FILE *);
int (getchar)(void);
char *gets(char *);
void perror(const char *);
int printf(const char *, ...);
int (putc)(int, FILE *);
int (putchar)(int);
int puts(const char *);
int remove(const char *);
int rename(const char *, const char *);
void rewind(FILE *);
int scanf(const char *, ...);
void setbuf(FILE *, char *);
int setvbuf(FILE *, char *, int, size_t);
int sprintf(char *, const char *, ...);
int sscanf(const char *, const char *, ...);
FILE *tmpfile(void);
char *tmpnam(char *);
int ungetc(int, FILE *);
int vfprintf(FILE *, const char *, va_list);
int vprintf(const char *, va_list);
int vsprintf(char *, const char *, va_list);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STDIO_H */
