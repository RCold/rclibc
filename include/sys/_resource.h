#ifndef _SYS__RESOURCE_H
#define _SYS__RESOURCE_H

#define RUSAGE_SELF     0

#include <sys/_time.h>

#if defined(__linux__) || defined(__APPLE__)

struct rusage {
    struct timeval ru_utime;
    struct timeval ru_stime;
    long int ru_maxrss;
    long int ru_ixrss;
    long int ru_idrss;
    long int ru_isrss;
    long int ru_minflt;
    long int ru_majflt;
    long int ru_nswap;
    long int ru_inblock;
    long int ru_oublock;
    long int ru_msgsnd;
    long int ru_msgrcv;
    long int ru_nsignals;
    long int ru_nvcsw;
    long int ru_nivcsw;
};

#elif defined(_WIN32)

struct rusage {
    struct timeval ru_utime;
    struct timeval ru_stime;
};

#else
#error Undefined platform for resource
#endif /* defined(__linux__) || defined(__APPLE__) */

int getrusage(int, struct rusage *);

#endif /* _SYS__RESOURCE_H */
