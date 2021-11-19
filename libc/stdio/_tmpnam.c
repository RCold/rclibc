#include "_stdio.h"
#include "_stdlib.h"
#include "_unistd.h"

#define L_tmpfnam   15

char *_tmpnam(char *s, size_t size) {
    int i;
    int dlen = _tmpdir(s, size - L_tmpfnam);
    int value = _prand();
    if (dlen <= 0)
        return NULL;
    for (i = 0; i < TMP_MAX; i++) {
        sprintf(s + dlen, "tmp%04x%08x", getpid() & 0xffff, value + i);
        if (access(s, F_OK) != 0)
            return s;
    }
    return NULL;
}
