#include "ctype.h"

int (isspace)(int c) {
    return _ptype[c] & _SPACE;
}
