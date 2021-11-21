#include "_stdlib.h"

size_t _ultoa(uintptr_t num, char *s, unsigned int base, const char *digs) {
    size_t ret;
    char c, *p = s;
    switch (base) {
        case 8:
            while (num != 0) {
                *p++ = digs[num & 7];
                num >>= 3;
            }
            break;
        case 16:
            while (num != 0) {
                *p++ = digs[num & 15];
                num >>= 4;
            }
            break;
        default:
            while (num != 0) {
                *p++ = digs[num % base];
                num /= base;
            }
            break;
    }
    ret = p - s;
    *p-- = '\0';
    while (s < p) {
        c = *p;
        *p-- = *s;
        *s++ = c;
    }
    return ret;
}
