#include "string.h"

size_t strspn(const char *s1, const char *s2) {
    const char *p1, *p2;
    for (p1 = s1; *p1 != '\0'; p1++)
        for (p2 = s2; *p1 != *p2; p2++)
            if (*p2 == '\0')
                return p1 - s1;
    return p1 - s1;
}
