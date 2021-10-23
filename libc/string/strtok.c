#include "string.h"

static char *next = NULL;

char *strtok(char *s1, const char *s2) {
    char *begin, *end;
    begin = s1 != NULL ? s1 : next;
    if (begin == NULL)
        return NULL;
    begin += strspn(begin, s2);
    if (*begin == '\0') {
        next = NULL;
        return NULL;
    }
    end = strpbrk(begin, s2);
    if (end != NULL && *end != '\0')
        *end++ = '\0';
    next = end;
    return begin;
}
