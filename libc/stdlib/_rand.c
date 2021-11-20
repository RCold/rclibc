#include "_stdlib.h"

int _rand(unsigned long int *seed) {
    *seed = *seed * 1103515245UL + 12345UL;
    return (int) (*seed >> 16) & 32767;
}
