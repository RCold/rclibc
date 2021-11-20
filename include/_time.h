#ifndef __TIME_H
#define __TIME_H

#include <time.h>

struct timespec {
    time_t tv_sec;
    long int tv_nsec;
};

#endif /* __TIME_H */
