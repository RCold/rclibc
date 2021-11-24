#include "_time.h"

#define isleap(y)   (((y) % 4 == 0 && (y) % 100 != 0) || (y) % 400 == 0)

int _daystomonth(int year, int mon) {
    static const int days[12] = {
            0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };
    if (mon > __TM_FEBRUARY && isleap(year))
        return days[mon] + 1;
    return days[mon];
}
