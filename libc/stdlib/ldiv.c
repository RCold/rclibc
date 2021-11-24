#include "stdlib.h"

ldiv_t ldiv(long int numer, long int denom) {
    ldiv_t ret;
    ret.quot = numer / denom;
    ret.rem = numer % denom;
    if ((numer < 0) != (ret.rem < 0)) {
        if (ret.quot < 0) {
            ret.quot++;
            ret.rem -= denom;
        } else if (ret.quot > 0) {
            ret.quot--;
            ret.rem += denom;
        }
    }
    return ret;
}
