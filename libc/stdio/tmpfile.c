#include "_stdio.h"
#include "stdlib.h"

FILE *tmpfile(void) {
    char *s = malloc(L_tmpnam);
    FILE *fp;
    if (s == NULL)
        return NULL;
    if (_tmpnam(s, L_tmpnam) == NULL || (fp = fopen(s, "wb+")) == NULL) {
        free(s);
        return NULL;
    }
    fp->_tmpfname = s;
    return fp;
}
