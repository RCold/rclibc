#include "ctype.h"
#include "internal.h"

int (isupper)(int c) {
	return _ptype[c] & _UPPER;
}
