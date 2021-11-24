#include "_time.h"

typedef struct {
    time_t quot;
    int rem;
} tdiv_t;

static tdiv_t tdiv(time_t numer, int denom) {
    tdiv_t ret;
    ret.quot = numer / (time_t) denom;
    ret.rem = (int) (numer % (time_t) denom);
    if (ret.rem < 0) {
        if (denom < 0) {
            ret.quot++;
            ret.rem -= denom;
        } else if (denom > 0) {
            ret.quot--;
            ret.rem += denom;
        }
    }
    return ret;
}

static int gmdate(time_t days, struct tm *timeptr) {
    int era, doe, yoe, doy, year, mon, day, wday;
    wday = (int) ((days + (time_t) __EPOCH_WDAY) % (time_t) __DAYS_PER_WEEK);
    if (wday < 0)
        wday += __DAYS_PER_WEEK;
    days += (time_t) __DAYS_FROM_YEAR_0_TO_EPOCH;
    if (days >= (time_t) (__DAYS_PER_ERA * 10000) || days < (time_t) (__DAYS_PER_ERA * -10000))
        return -1;
    era = (int) (days / (time_t) __DAYS_PER_ERA);
    doe = (int) (days % (time_t) __DAYS_PER_ERA);
    if (doe < 0) {
        era--;
        doe += __DAYS_PER_ERA;
    }
    yoe = (doe - (doe + 1402) / 1461 + (doe - 59) / 36525) / __DAYS_PER_NYEAR;
    doy = doe - (yoe * __DAYS_PER_NYEAR + (yoe + 3) / 4 - (yoe - 1) / 100);
    year = era * __YEARS_PER_ERA + yoe;
    for (mon = __TM_DECEMBER; mon > __TM_JANUARY; mon--)
        if (doy >= _daystomonth(year, mon))
            break;
    day = doy - _daystomonth(year, mon);
    timeptr->tm_year = year - __TM_YEAR_BASE;
    timeptr->tm_mon = mon;
    timeptr->tm_mday = day + 1;
    timeptr->tm_wday = wday;
    timeptr->tm_yday = doy;
    return 0;
}

int _gmtime(time_t timer, struct tm *timeptr) {
    tdiv_t d;
    struct tm tm;
    d = tdiv(timer, __SECS_PER_MIN);
    tm.tm_sec = d.rem;
    d = tdiv(d.quot, __MINS_PER_HOUR);
    tm.tm_min = d.rem;
    d = tdiv(d.quot, __HOURS_PER_DAY);
    tm.tm_hour = d.rem;
    if (gmdate(d.quot, &tm) != 0)
        return -1;
    tm.tm_isdst = 0;
    *timeptr = tm;
    return 0;
}
