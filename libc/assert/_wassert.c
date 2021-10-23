#include "assert.h"
#include "stdio.h"
#include "stdlib.h"

static char *assert_str = "Assertion failed: %s, file %s, line %u\n";

void _wassert(const char *expr, const char *file, unsigned int line) {
    fprintf(stderr, assert_str, expr, file, line);
    abort();
}
