#include "ctype.h"

int (islower)(int c) {
    return _ptype[c] & _LOWER;
}
