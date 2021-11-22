#include "sys/_resource.h"
#include "time.h"

#define CONVTCK(r)  ((r).tv_sec * CLOCKS_PER_SEC + (r).tv_usec / (1000000 / CLOCKS_PER_SEC))

clock_t clock(void) {
    struct rusage ru;
    if (getrusage(RUSAGE_SELF, &ru) != 0)
        return ((clock_t) -1);
    return (clock_t) (CONVTCK(ru.ru_utime) + CONVTCK(ru.ru_stime));
}
