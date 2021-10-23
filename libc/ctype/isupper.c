#include "ctype.h"

int (isupper)(int c) {
    return _ptype[c] & _UPPER;
}
