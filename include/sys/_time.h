#ifndef _SYS__TIME_H
#define _SYS__TIME_H

#include <time.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

#ifdef __APPLE__
typedef __int32 suseconds_t;
#else
typedef long int suseconds_t;
#endif /* __APPLE__ */

struct timeval {
    time_t tv_sec;
    suseconds_t tv_usec;
};

int gettimeofday(struct timeval *, void *);

__END_DECLS

#endif /* _SYS__TIME_H */
