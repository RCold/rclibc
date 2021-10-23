#include "ctype.h"

int (isgraph)(int c) {
    return _ptype[c] & _GRAPH;
}
