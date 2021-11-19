#include "_stdio.h"

char *_ultoa(uintptr_t val, char *p, unsigned int base, const char *digs) {
    switch (base) {
        case 8:
            while (val != 0) {
                *--p = digs[val & 7];
                val >>= 3;
            }
            break;
        case 16:
            while (val != 0) {
                *--p = digs[val & 15];
                val >>= 4;
            }
            break;
        default:
            while (val != 0) {
                *--p = digs[val % base];
                val /= base;
            }
            break;
    }
    return p;
}
