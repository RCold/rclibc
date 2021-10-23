#include "_stdio.h"

static unsigned int seed = 0;
static char buf[L_tmpnam];

char *tmpnam(char *s) {
    if (s == NULL)
        s = buf;
    return _tmpnam(s, &seed);
}
