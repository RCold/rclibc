#ifndef _CTYPE_H
#define _CTYPE_H

#define _UPPER      0x0001
#define _LOWER      0x0002
#define _DIGIT      0x0004
#define _SPACE      0x0008
#define _PUNCT      0x0010
#define _CNTRL      0x0020
#define _BLANK      0x0040
#define _XDIGIT     0x0080
#define _ALPHA      (_UPPER | _LOWER)
#define _ALNUM      (_ALPHA | _DIGIT)
#define _GRAPH      (_ALNUM | _PUNCT)
#define _PRINT      (_GRAPH | _BLANK)

#define isalnum(c)  ((int) (_ptype[(int) (c)] & _ALNUM))
#define isalpha(c)  ((int) (_ptype[(int) (c)] & _ALPHA))
#define iscntrl(c)  ((int) (_ptype[(int) (c)] & _CNTRL))
#define isdigit(c)  ((int) (_ptype[(int) (c)] & _DIGIT))
#define isgraph(c)  ((int) (_ptype[(int) (c)] & _GRAPH))
#define islower(c)  ((int) (_ptype[(int) (c)] & _LOWER))
#define isprint(c)  ((int) (_ptype[(int) (c)] & _PRINT))
#define ispunct(c)  ((int) (_ptype[(int) (c)] & _PUNCT))
#define isspace(c)  ((int) (_ptype[(int) (c)] & _SPACE))
#define isupper(c)  ((int) (_ptype[(int) (c)] & _UPPER))
#define isxdigit(c) ((int) (_ptype[(int) (c)] & _XDIGIT))
#define tolower(c)  ((int) (_plmap[(int) (c)]))
#define toupper(c)  ((int) (_pumap[(int) (c)]))

#include <sys/cdefs.h>

__BEGIN_DECLS

extern const unsigned short int *_ptype;
extern const short int *_plmap;
extern const short int *_pumap;

int (isalnum)(int);

int (isalpha)(int);

int (iscntrl)(int);

int (isdigit)(int);

int (isgraph)(int);

int (islower)(int);

int (isprint)(int);

int (ispunct)(int);

int (isspace)(int);

int (isupper)(int);

int (isxdigit)(int);

int (tolower)(int);

int (toupper)(int);

__END_DECLS

#endif /* _CTYPE_H */
