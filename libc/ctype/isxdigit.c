#include "ctype.h"
#include "internal.h"

int (isxdigit)(int c) {
	return _ptype[c] & _XDIGIT;
}
