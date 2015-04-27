#ifndef _STDLIB_H
#define _STDLIB_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1
#define RAND_MAX        32767

#define MB_CUR_MAX _mb_cur_max

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif /* _SIZE_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short int wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifndef _DIV_T_DEFINED
#define _DIV_T_DEFINED
typedef struct {
	int quot;
	int rem;
} div_t;
typedef struct {
	long quot;
	long rem;
} ldiv_t;
#endif /* _DIV_T_DEFINED */

extern int _mb_cur_max;

void abort(void);
int abs(int);
int atexit(void (*)(void));
double atof(const char *);
int atoi(const char *);
long int atol(const char *);
void *bsearch(const void *, const void *, size_t, size_t,
		int (*)(const void *, const void *));
void *calloc(size_t, size_t);
div_t div(int, int);
void exit(int);
void free(void *);
char *getenv(const char *);
long int labs(long int);
ldiv_t ldiv(long int, long int);
void *malloc(size_t);
int mblen(const char *, size_t);
size_t mbstowcs(wchar_t *, const char *, size_t);
int mbtowc(wchar_t *, const char *, size_t);
void qsort(void *, size_t, size_t, int (*)(const void *, const void *));
int rand(void);
void *realloc(void *, size_t);
void srand(unsigned int);
double strtod(const char *, char **);
long int strtol(const char *, char **, int);
unsigned long int strtoul(const char *, char **, int);
int system(const char *);
size_t wcstombs(char *, const wchar_t *, size_t);
int wctomb(char *, wchar_t);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STDLIB_H */
