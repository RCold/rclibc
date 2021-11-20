#include "_stdio.h"
#include "_stdlib.h"
#include "_unistd.h"
#include "sys/_time.h"

#define L_tmpfnam   15

static int seed_initialized = 0;
static unsigned long int seed;

static int random_int(void) {
    int size = sizeof(int);
    int ret;
    char *p = (char *) &ret;
    struct timeval tv;
    if (!seed_initialized) {
        gettimeofday(&tv, NULL);
        seed = (unsigned long int) (tv.tv_usec ^ tv.tv_sec);
        seed ^= seed << 24 | seed >> 8;
        seed_initialized = 1;
    }
    while (size-- > 0)
        *p++ = (char) _rand(&seed);
    return ret;
}

char *_tmpnam(char *s, size_t size) {
    int i;
    int dlen = _tmpdir(s, size - L_tmpfnam);
    int value = random_int();
    if (dlen <= 0)
        return NULL;
    for (i = 0; i < TMP_MAX; i++) {
        sprintf(s + dlen, "tmp%04x%08x", getpid() & 0xffff, value + i);
        if (access(s, F_OK) != 0)
            return s;
    }
    return NULL;
}
