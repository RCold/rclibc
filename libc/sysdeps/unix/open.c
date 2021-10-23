#include "_fcntl.h"
#include "syscall.h"

int open(const char *path, int oflag) {
    return (int) syscall(SYS_open, path, oflag);
}
