#include "_stdio.h"

char *_ultoa(uintptr_t val, char *p, int base, const char *digs) {
    switch (base) {
        case 10:
            while (val != 0) {
                *--p = digs[val % 10];
                val /= 10;
            }
            break;
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
            break;
    }
    return p;
}
