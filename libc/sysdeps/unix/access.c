#include "_unistd.h"
#include "syscall.h"

int access(const char *path, int amode) {
    return (int) syscall(SYS_access, path, amode);
}
