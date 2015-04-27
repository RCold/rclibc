#include "ctype.h"
#include "internal.h"

int (islower)(int c) {
	return _ptype[c] & _LOWER;
}
