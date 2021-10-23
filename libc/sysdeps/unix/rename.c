#include "stdio.h"
#include "syscall.h"

int rename(const char *old, const char *new) {
    return (int) syscall(SYS_rename, old, new);
}
