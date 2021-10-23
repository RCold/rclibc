#include "stdio.h"

int puts(const char *s) {
    if (fputs(s, stdout) == EOF || putchar('\n') == EOF)
        return EOF;
    return 0;
}
