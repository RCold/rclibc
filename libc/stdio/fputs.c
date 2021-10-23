#include "stdio.h"

int fputs(const char *s, FILE *fp) {
    while (*s != '\0')
        if (putc(*s++, fp) == EOF)
            return EOF;
    return 0;
}
