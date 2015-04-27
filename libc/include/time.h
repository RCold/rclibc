#ifndef _TIME_H
#define _TIME_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define CLOCKS_PER_SEC ((clock_t) 1000)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif /* _SIZE_T_DEFINED */

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
typedef unsigned int clock_t;
#endif /* _CLOCK_T_DEFINED */

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
typedef unsigned long int time_t;
#endif /* _TIME_T_DEFINED */

#ifndef _TIME_DEFINED
#define _TIME_DEFINED
struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};
#endif /* _TIME_DEFINED */

char *asctime(const struct tm *);
clock_t clock(void);
char *ctime(const time_t *);
double difftime(time_t, time_t);
struct tm *gmtime(const time_t *);
struct tm *localtime(const time_t *);
time_t mktime(struct tm *);
size_t strftime(char *, size_t, const char *, const struct tm *);
time_t time(time_t *);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TIME_H */
