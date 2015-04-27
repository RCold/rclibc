#include "ctype.h"
#include "internal.h"

int (isdigit)(int c) {
	return _ptype[c] & _DIGIT;
}
