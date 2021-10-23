#include "_unistd.h"
#include "syscall.h"

int close(int fildes) {
    return (int) syscall(SYS_close, fildes);
}
