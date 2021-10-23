#include "string.h"

char *strrchr(const char *s, int c) {
    const char *p;
    for (p = s; *p != '\0'; p++);
    for (; p >= s; p--)
        if (*p == (char) c)
            return (char *) p;
    return NULL;
}
