#include "ctype.h"

int (isprint)(int c) {
    return _ptype[c] & _PRINT;
}
