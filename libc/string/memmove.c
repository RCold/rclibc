#include "string.h"

void *memmove(void *s1, const void *s2, size_t n) {
    char *p1 = s1;
    const char *p2 = s2;
    if (p1 > p2 && p1 < p2 + n)
        for (p1 += n - 1, p2 += n - 1; n > 0; p1--, p2--, n--)
            *p1 = *p2;
    else
        for (; n > 0; p1++, p2++, n--)
            *p1 = *p2;
    return s1;
}
