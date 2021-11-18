#ifndef _TIME_H
#define _TIME_H

#define __need_size_t
#define __need_NULL

#include <stddef.h>

#ifdef _WIN32
#define CLOCKS_PER_SEC ((clock_t) 1000)
#else
#define CLOCKS_PER_SEC ((clock_t) 1000000)
#endif /* _WIN32 */

#include <sys/cdefs.h>

__BEGIN_DECLS

#ifdef __APPLE__
typedef unsigned long int clock_t;
#else
typedef long int clock_t;
#endif /* __APPLE__ */

#ifdef _WIN64
__extension__ typedef __int64 time_t;
#else
typedef long int time_t;
#endif /* _WIN64 */

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

clock_t clock(void);

double difftime(time_t, time_t);

time_t mktime(struct tm *);

time_t time(time_t *);

char *asctime(const struct tm *);

char *ctime(const time_t *);

struct tm *gmtime(const time_t *);

struct tm *localtime(const time_t *);

size_t strftime(char *, size_t, const char *, const struct tm *);

__END_DECLS

#endif /* _TIME_H */
