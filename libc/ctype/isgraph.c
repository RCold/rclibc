#include "ctype.h"
#include "internal.h"

int (isgraph)(int c) {
	return _ptype[c] & _GRAPH;
}
