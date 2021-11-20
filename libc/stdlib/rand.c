#include "_stdlib.h"

int rand(void) {
    return _rand(&_rseed);
}
