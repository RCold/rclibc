#include "stdio.h"

char *gets(char *s) {
    int c;
    char *p = s;
    clearerr(stdin);
    while ((c = getchar()) != EOF && c != '\n')
        *p++ = (char) c;
    if ((c == EOF && p == s) || ferror(stdin))
        return NULL;
    *p = '\0';
    return s;
}
