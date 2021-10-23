#include "ctype.h"

int (ispunct)(int c) {
    return _ptype[c] & _PUNCT;
}
