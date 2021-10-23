#include "_unistd.h"
#include "syscall.h"

int unlink(const char *path) {
    return (int) syscall(SYS_unlink, path);
}
