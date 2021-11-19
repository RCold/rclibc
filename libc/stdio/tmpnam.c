#include "_stdio.h"

static char buf[L_tmpnam];

char *tmpnam(char *s) {
    if (s == NULL)
        s = buf;
    return _tmpnam(s, L_tmpnam);
}
