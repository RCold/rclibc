#include "ctype.h"

int (isxdigit)(int c) {
    return _ptype[c] & _XDIGIT;
}
