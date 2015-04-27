#include "ctype.h"
#include "internal.h"

int (ispunct)(int c) {
	return _ptype[c] & _PUNCT;
}
