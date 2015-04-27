#include "ctype.h"
#include "internal.h"

int (toupper)(int c) {
	return _pumap[c];
}
