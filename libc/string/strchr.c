#include "string.h"

char *strchr(const char *s, int c) {
    const char *p;
    for (p = s; *p != (char) c; p++)
        if (*p == '\0')
            return NULL;
    return (char *) p;
}
