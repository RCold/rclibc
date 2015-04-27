#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
	char f1;
	struct {
		float flt;
	} f2;
	int f3;
} str;

static size_t offs[] = {
	offsetof(str,f1),
	offsetof(str,f2),
	offsetof(str,f3)
};

static char *pc = NULL;

int main(void) {
	ptrdiff_t pd = &pc[INT_MAX] - &pc[0];
	wchar_t wc = L'Z';
	str x = { 1, { 2.0F }, 3 };
	char *ps = (char *) &x;
	printf("sizeof(size_t) = %u\n", sizeof(size_t));
	printf("sizeof(wchar_t) = %u\n", sizeof(wchar_t));
	assert(sizeof(ptrdiff_t) == sizeof(size_t));
	assert(sizeof(size_t) == sizeof(sizeof(char)));
	assert(pd == &pc[INT_MAX] - &pc[0]);
	assert(wc == L'Z');
	assert(offs[0] < offs[1]);
	assert(offs[1] < offs[2]);
	assert(*(char * )(ps + offs[0]) == 1);
	assert(*(float * )(ps + offs[1]) == 2.0F);
	assert(*(int * )(ps + offs[2]) == 3);
	puts("SUCCESS testing <stddef.h>");
	return 0;
}
