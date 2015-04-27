#include "ctype.h"
#include "internal.h"

int (isprint)(int c) {
	return _ptype[c] & _PRINT;
}
