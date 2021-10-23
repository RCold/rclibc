#include "_stdio.h"

char *_ultoa(uint64_t val, char *p, int base, const char *digs) {
    switch (base) {
        case 10:
            while (val != UINT64_C(0)) {
                *--p = digs[val % UINT64_C(10)];
                val /= UINT64_C(10);
            }
            break;
        case 8:
            while (val != UINT64_C(0)) {
                *--p = digs[val & UINT64_C(7)];
                val >>= 3;
            }
            break;
        case 16:
            while (val != UINT64_C(0)) {
                *--p = digs[val & UINT64_C(15)];
                val >>= 4;
            }
            break;
        default:
            break;
    }
    return p;
}
