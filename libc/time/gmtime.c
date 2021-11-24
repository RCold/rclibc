#include "_time.h"

struct tm *gmtime(const time_t *timer) {
    if (_gmtime(*timer, _tmbuf) != 0)
        return NULL;
    return _tmbuf;
}
