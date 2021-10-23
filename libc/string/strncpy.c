#include "string.h"

char *strncpy(char *s1, const char *s2, size_t n) {
    char *p1;
    const char *p2;
    for (p1 = s1, p2 = s2; n > 0 && (*p1 = *p2) != '\0'; p1++, p2++, n--);
    for (; n > 0; p1++, n--)
        *p1 = '\0';
    return s1;
}
