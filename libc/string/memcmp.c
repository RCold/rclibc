#include "string.h"

int memcmp(const void *s1, const void *s2, size_t n) {
    const char *p1, *p2;
    for (p1 = s1, p2 = s2; n > 0; p1++, p2++, n--)
        if (*p1 != *p2)
            return *p1 - *p2;
    return 0;
}
