#include "string.h"

char *strpbrk(const char *s1, const char *s2) {
    const char *p1, *p2;
    for (p1 = s1; *p1 != '\0'; p1++)
        for (p2 = s2; *p2 != '\0'; p2++)
            if (*p1 == *p2)
                return (char *) p1;
    return NULL;
}
