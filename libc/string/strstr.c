#include "string.h"

char *strstr(const char *s1, const char *s2) {
    const char *p, *p1, *p2;
    if (*s2 == '\0')
        return (char *) s1;
    for (p = s1; *p != '\0'; p++) {
        for (p1 = p, p2 = s2; *p1 != '\0' && *p1 == *p2; p1++, p2++);
        if (*p2 == '\0')
            return (char *) p;
    }
    return NULL;
}
