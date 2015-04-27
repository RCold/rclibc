#include "ctype.h"
#include "internal.h"

int (isalpha)(int c) {
	return _ptype[c] & _ALPHA;
}
