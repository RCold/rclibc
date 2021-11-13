#include "stdlib.h"

long int atol(const char *nptr) {
    return strtol(nptr, NULL, 10);
}
