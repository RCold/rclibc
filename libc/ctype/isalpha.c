#include "ctype.h"

int (isalpha)(int c) {
    return _ptype[c] & _ALPHA;
}
