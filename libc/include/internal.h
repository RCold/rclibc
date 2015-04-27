#ifndef _INTERNAL_H
#define _INTERNAL_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define _BUFSIZ         4096

#define _IOREAD         0x0001
#define _IOWRT          0x0002
#define _IORW           0x0004
#define _IOEOF          0x0008
#define _IOERR          0x0010
#define _IOSTRG         0x0020
#define _IOFBF          0x0040
#define _IOLBF          0x0080
#define _IONBF          0x0100
#define _IODBF          0x0200

#define _UPPER          0x0001
#define _LOWER          0x0002
#define _DIGIT          0x0004
#define _SPACE          0x0008
#define _PUNCT          0x0010
#define _CNTRL          0x0020
#define _BLANK          0x0040
#define _XDIGIT         0x0080
#define _ALPHA          (0x0100 | _UPPER | _LOWER)
#define _ALNUM          (_ALPHA | _DIGIT)
#define _GRAPH          (_ALNUM | _PUNCT)
#define _PRINT          (_GRAPH | _BLANK)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

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

extern const unsigned short int _ctype[];
extern const unsigned short int *_ptype;
extern const short int _cumap[];
extern const short int *_pumap;
extern const short int _clmap[];
extern const short int *_plmap;
extern unsigned long int _rseed;
extern FILE _iob[];
extern FILE *_piob[];

void _allocbuf(FILE *);
FILE *_allocfile(void);
int _fclose(FILE *);
FILE *_fopen(const char *, const char *, FILE *);
void _freebuf(FILE *);
void _freefile(FILE *);
char *_tmpnam(char *, unsigned long int *);
void _wassert(const char *, const char *, unsigned int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _INTERNAL_H */
