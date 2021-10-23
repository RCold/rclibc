#include "ctype.h"

int (isdigit)(int c) {
    return _ptype[c] & _DIGIT;
}
