#include "_unistd.h"
#include "syscall.h"

ssize_t read(int fildes, void *buf, size_t nbyte) {
    return (ssize_t) syscall(SYS_read, fildes, buf, nbyte);
}
