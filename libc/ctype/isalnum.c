#include "ctype.h"

int (isalnum)(int c) {
    return _ptype[c] & _ALNUM;
}
