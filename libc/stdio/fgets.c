#include "stdio.h"

char *fgets(char *s, int n, FILE *fp) {
    int c = 0;
    char *p = s;
    if (n < 1)
        return NULL;
    clearerr(fp);
    while (p - s < n - 1 && c != '\n' && (c = getc(fp)) != EOF)
        *p++ = (char) c;
    if ((c == EOF && p == s) || ferror(fp))
        return NULL;
    *p = '\0';
    return s;
}
