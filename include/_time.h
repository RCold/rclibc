#ifndef __TIME_H
#define __TIME_H

#define __SECS_PER_MIN      60
#define __MINS_PER_HOUR     60
#define __SECS_PER_HOUR     (__SECS_PER_MIN * __MINS_PER_HOUR)
#define __HOURS_PER_DAY     24
#define __SECS_PER_DAY      (__SECS_PER_HOUR * __HOURS_PER_DAY)
#define __DAYS_PER_WEEK     7
#define __DAYS_PER_NYEAR    365
#define __MONS_PER_YEAR     12
#define __YEARS_PER_ERA     400
#define __LEAP_DAYS_PER_ERA 97
#define __DAYS_PER_ERA      (__YEARS_PER_ERA * __DAYS_PER_NYEAR + __LEAP_DAYS_PER_ERA)

#define __DAYS_FROM_YEAR_0_TO_EPOCH     719528

#define __TM_SUNDAY         0
#define __TM_MONDAY         1
#define __TM_TUESDAY        2
#define __TM_WEDNESDAY      3
#define __TM_THURSDAY       4
#define __TM_FRIDAY         5
#define __TM_SATURDAY       6

#define __TM_JANUARY        0
#define __TM_FEBRUARY       1
#define __TM_MARCH          2
#define __TM_APRIL          3
#define __TM_MAY            4
#define __TM_JUNE           5
#define __TM_JULY           6
#define __TM_AUGUST         7
#define __TM_SEPTEMBER      8
#define __TM_OCTOBER        9
#define __TM_NOVEMBER       10
#define __TM_DECEMBER       11

#define __TM_YEAR_BASE      1900
#define __EPOCH_YEAR        1970
#define __EPOCH_WDAY        __TM_THURSDAY

#include <time.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

struct timespec {
    time_t tv_sec;
    long int tv_nsec;
};

extern int daylight;
extern long timezone;

extern struct tm *_tmbuf;

void tzset(void);

int _daystomonth(int, int);

int _gmtime(time_t, struct tm *);

__END_DECLS

#endif /* __TIME_H */
