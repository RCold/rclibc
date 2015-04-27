#include "ctype.h"
#include "internal.h"

int (iscntrl)(int c) {
	return _ptype[c] & _CNTRL;
}
