#include "stdio.h"

int fputs(const char *s, FILE *fp) {
    for (; *s != '\0'; s++)
        if (putc(*s, fp) == EOF)
            return EOF;
    return 0;
}
