#include "_unistd.h"
#include "syscall.h"

ssize_t write(int fildes, const void *buf, size_t nbyte) {
    return (ssize_t) syscall(SYS_write, fildes, buf, nbyte);
}
