#include "assert.h"
#include "stdio.h"
#include "stdlib.h"

void _wassert(const char *expr, const char *file, unsigned int line) {
    fprintf(stderr, "Assertion failed: %s, file %s, line %u\n", expr, file, line);
    abort();
}
