#include "_stdio.h"
#include "_unistd.h"

char *_tmpnam(char *s, unsigned int *u) {
    int n;
    do {
        if (*u >= TMP_MAX)
            return NULL;
        n = _tmpdir(s, L_tmpnam - 12);
        if (n <= 0)
            return NULL;
        sprintf(s + n, "t%4x.%u", getpid(), (*u)++);
    } while (access(s, 0) == 0);
    return s;
}
