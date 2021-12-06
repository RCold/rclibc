#include "_stdint.h"
#include "_time.h"

static int64_t mkdate(struct tm *timeptr) {
    int mon, era, yoe;
    int64_t year, doy, doe;
    year = (int64_t) timeptr->tm_year + (int64_t) (timeptr->tm_mon / __MONS_PER_YEAR) + (int64_t) __TM_YEAR_BASE;
    mon = timeptr->tm_mon % __MONS_PER_YEAR;
    if (mon < 0) {
        year--;
        mon += __MONS_PER_YEAR;
    }
    era = (int) (year / (int64_t) __YEARS_PER_ERA);
    yoe = (int) (year % (int64_t) __YEARS_PER_ERA);
    if (yoe < 0) {
        era--;
        yoe += __YEARS_PER_ERA;
    }
    doy = (int64_t) _daystomonth(yoe, mon) + (int64_t) timeptr->tm_mday - INT64_C(1);
    doe = (int64_t) (yoe * __DAYS_PER_NYEAR + (yoe + 3) / 4 - (yoe - 1) / 100) + doy;
    return (int64_t) era * (int64_t) __DAYS_PER_ERA + doe - (int64_t) __DAYS_FROM_YEAR_0_TO_EPOCH;
}

time_t mktime(struct tm *timeptr) {
    int64_t ret;
    struct tm tm;
    tzset();
    ret = (int64_t) timeptr->tm_sec + (int64_t) timeptr->tm_min * (int64_t) __SECS_PER_MIN
          + (int64_t) timeptr->tm_hour * (int64_t) __SECS_PER_HOUR + mkdate(timeptr) * (int64_t) __SECS_PER_DAY;
    if (ret > (int64_t) __TIME_MAX || ret < (int64_t) __TIME_MIN || _gmtime((time_t) ret, &tm) != 0)
        return (time_t) -1;
    ret += timezone;
    if (daylight != 0 && (timeptr->tm_isdst > 0 || (timeptr->tm_isdst < 0 && _isindst(&tm)))) {
        ret += _tzrule[1]._offset;
        tm.tm_isdst = 1;
    } else {
        ret += _tzrule[0]._offset;
        tm.tm_isdst = 0;
    }
    if (ret > (int64_t) __TIME_MAX || ret < (int64_t) __TIME_MIN)
        return (time_t) -1;
    *timeptr = tm;
    return (time_t) ret;
}
