#ifndef __TIME_H
#define __TIME_H

#ifdef __APPLE__
#define CLOCK_MONOTONIC     6
#else
#define CLOCK_MONOTONIC     1
#endif /* __APPLE__ */

#include <time.h>

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

typedef int clockid_t;

int clock_gettime(clockid_t, struct timespec *);

#endif /* __TIME_H */
