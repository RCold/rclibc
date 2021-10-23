#include "stdio.h"
#include "windows.h"

int rename(const char *old, const char *new) {
    if (MoveFileA(old, new))
        return 0;
    else
        return -1;
}
