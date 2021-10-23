#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

typedef struct {
    char f1;
    struct {
        double dbl;
    } f2;
    int f3;
} cstruct;

int main(void) {
    size_t offs[] = {
            offsetof(cstruct, f1),
            offsetof(cstruct, f2),
            offsetof(cstruct, f3)
    };
    char *pc = (char *) 1;
    ptrdiff_t pd = &pc[INT_MAX] - &pc[0];
    wchar_t wc = L'Z';
    cstruct x = {1, {2.0}, 3};
    char *ps = (char *) &x;
    assert(sizeof(size_t) == sizeof(sizeof(char)));
    assert(sizeof(ptrdiff_t) == sizeof(size_t));
    assert(pd == &pc[INT_MAX] - &pc[0]);
    assert(wc == L'Z');
    assert(offs[0] < offs[1]);
    assert(offs[1] < offs[2]);
    assert(*(char *) (ps + offs[0]) == 1);
    assert(*(double *) (ps + offs[1]) == 2.0);
    assert(*(int *) (ps + offs[2]) == 3);
    puts("SUCCESS testing <stddef.h>");
    return 0;
}
