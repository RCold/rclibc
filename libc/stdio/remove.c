#include "_unistd.h"
#include "stdio.h"

int remove(const char *filename) {
    return unlink(filename) == 0 ? 0 : rmdir(filename);
}
