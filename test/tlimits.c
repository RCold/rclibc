#include <assert.h>
#include <limits.h>
#include <stdio.h>

int main(void) {
	printf("CHAR_BIT =  %-10i    MB_LEN_MAX = %i\n\n", CHAR_BIT, MB_LEN_MAX);
	printf("CHAR_MAX =  %-10i    CHAR_MIN =   %i\n", CHAR_MAX, CHAR_MIN);
	printf("SCHAR_MAX = %-10i    SCHAR_MIN =  %i\n", SCHAR_MAX, SCHAR_MIN);
	printf("UCHAR_MAX = %-10u\n\n", UCHAR_MAX);
	printf("SHRT_MAX =  %-10i    SHRT_MIN =   %i\n", SHRT_MAX, SHRT_MIN);
	printf("USHRT_MAX = %-10u\n\n", USHRT_MAX);
	printf("INT_MAX =   %-10i    INT_MIN =    %i\n", INT_MAX, INT_MIN);
	printf("UINT_MAX =  %-10u\n\n", UINT_MAX);
	printf("LONG_MAX =  %-10li    LONG_MIN =   %li\n", LONG_MAX, LONG_MIN);
	printf("ULONG_MAX = %-10lu\n\n", ULONG_MAX);
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
