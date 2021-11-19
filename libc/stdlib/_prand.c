#include "_stdlib.h"
#include "_time.h"

/*
 * Provides fast pseudo-random bits through clock_gettime.
 */

int _prand(void) {
    int ret;
    struct timespec tv;
    clock_gettime(CLOCK_MONOTONIC, &tv);
    ret = (int) (tv.tv_nsec ^ tv.tv_sec);
    ret ^= ret << 24 | ret >> 8;
    return ret;
}
