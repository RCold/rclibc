#include "internal.h"
#include "stdlib.h"

void srand(unsigned int seed) {
	_rseed = seed;
	return;
}
