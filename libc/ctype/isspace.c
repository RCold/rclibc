#include "ctype.h"
#include "internal.h"

int (isspace)(int c) {
	return _ptype[c] & _SPACE;
}
