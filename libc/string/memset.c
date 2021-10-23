#include "string.h"

void *memset(void *s, int c, size_t n) {
    char *p;
    for (p = s; n > 0; p++, n--)
        *p = (char) c;
    return s;
}
