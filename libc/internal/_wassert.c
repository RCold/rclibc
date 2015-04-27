#include "internal.h"
#include "stdio.h"
#include "stdlib.h"

static char *assertstring = "Assertion failed: %s, file %s, line %u\n";

void _wassert(const char *expr, const char *file, unsigned int line) {
	fprintf(stderr, assertstring, expr, file, line);
	abort();
}
