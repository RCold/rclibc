#include "_stdlib.h"

int rand(void) {
    _rseed = _rseed * 1103515245UL + 12345UL;
    return (int) (_rseed >> 16) & 32767;
}
