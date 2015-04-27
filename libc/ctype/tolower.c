#include "ctype.h"
#include "internal.h"

int (tolower)(int c) {
	return _plmap[c];
}
