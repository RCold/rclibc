#include "errno.h"
#include "stdio.h"
#include "string.h"

void perror(const char *s) {
    if (s != NULL && *s != '\0') {
        fputs(s, stderr);
        fputs(": ", stderr);
    }
    fputs(strerror(errno), stderr);
    putc('\n', stderr);
}
