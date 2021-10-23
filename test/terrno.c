#include <assert.h>
#include <errno.h>
#include <stdio.h>

int main(void) {
    assert(errno == 0);
    errno = ERANGE;
    assert(errno == ERANGE);
    errno = 0;
    assert(errno == 0);
    errno = EDOM;
    assert(errno == EDOM);
    puts("SUCCESS testing <errno.h>");
    return 0;
}
