#include "string.h"

char *strcat(char *s1, const char *s2) {
    char *p1;
    const char *p2;
    for (p1 = s1; *p1 != '\0'; p1++);
    for (p2 = s2; (*p1 = *p2) != '\0'; p1++, p2++);
    return s1;
}
