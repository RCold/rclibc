#include "ctype.h"

int (iscntrl)(int c) {
    return _ptype[c] & _CNTRL;
}
