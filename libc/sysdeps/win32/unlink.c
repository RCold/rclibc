#include "_unistd.h"
#include "windows.h"

int unlink(const char *filename) {
    if (DeleteFileA(filename))
        return 0;
    else
        return -1;
}
