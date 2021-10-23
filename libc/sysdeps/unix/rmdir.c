#include "_unistd.h"
#include "syscall.h"

int rmdir(const char *path) {
    return (int) syscall(SYS_rmdir, path);
}
