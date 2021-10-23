#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct {
    char c;
} cstruct;

static int test(const char *fmt, ...) {
    int cnt = 0;
    va_list ap;
    va_start(ap, fmt);
    for (; *fmt != '\0'; fmt++)
        switch (*fmt) {
            case 'i':
                assert(va_arg(ap, int) == ++cnt);
                break;
            case 'd':
                assert(va_arg(ap, double) == ++cnt);
                break;
            case 'p':
                assert(va_arg(ap, char *)[0] == ++cnt);
                break;
            case 's':
                assert(va_arg(ap, cstruct).c == ++cnt);
                break;
        }
    va_end(ap);
    return cnt;
}

int main(void) {
    cstruct x = {3};
    assert(test("iisdi", '\1', 2, x, 4.0, 5) == 5);
    assert(test("") == 0);
    assert(test("pdp", "\1", 2.0, "\3") == 3);
    puts("SUCCESS testing <stdarg.h>");
    return 0;
}
