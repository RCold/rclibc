#include "time.h"
#include "sys/_time.h"

time_t time(time_t *timer) {
    struct timeval tv;
    if (gettimeofday(&tv, NULL) != 0)
        return (time_t) -1;
    if (timer != NULL)
        *timer = tv.tv_sec;
    return tv.tv_sec;
}
