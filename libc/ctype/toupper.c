#include "ctype.h"

int (toupper)(int c) {
    return _pumap[c];
}
