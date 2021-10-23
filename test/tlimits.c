#include <assert.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
    assert(CHAR_BIT >= 8 && CHAR_MAX >= 127 && CHAR_MIN <= 0);
    assert(SCHAR_MIN <= -127 && SCHAR_MAX >= 127);
    assert(UCHAR_MAX >= 255 && UCHAR_MAX / 2 >= SCHAR_MAX);
    assert(CHAR_MAX == SCHAR_MAX || CHAR_MAX == UCHAR_MAX);
    assert(MB_LEN_MAX >= 1);
    assert(SHRT_MIN <= -32767 && SHRT_MAX >= 32767 && SHRT_MAX >= SCHAR_MAX);
    assert(USHRT_MAX >= 65535 && USHRT_MAX / 2 >= SHRT_MAX
           && USHRT_MAX >= UCHAR_MAX);
    assert(INT_MIN <= -32767 && INT_MAX >= 32767 && INT_MAX >= SHRT_MAX);
    assert(UINT_MAX >= 65535 && UINT_MAX / 2 >= INT_MAX
           && UINT_MAX >= USHRT_MAX);
    assert(LONG_MIN <= -2147483647L && LONG_MAX >= 2147483647L
           && LONG_MAX >= INT_MAX);
    assert(ULONG_MAX >= 4294967295UL && ULONG_MAX / 2 >= LONG_MAX
           && UINT_MAX <= ULONG_MAX);
    puts("SUCCESS testing <limits.h>");
    return 0;
}
