#include "string.h"

int strcmp(const char *s1, const char *s2) {
    const char *p1, *p2;
    for (p1 = s1, p2 = s2; *p1 != '\0' || *p2 != '\0'; p1++, p2++)
        if (*p1 != *p2)
            return *p1 - *p2;
    return 0;
}
