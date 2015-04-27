#include "internal.h"
#include "stdlib.h"

int rand(void) {
	_rseed = _rseed * 1103515245 + 12345;
	return (unsigned int) (_rseed >> 16) & RAND_MAX;
}
