#include "_unistd.h"
#include "syscall.h"

void _exit(int status) {
    syscall(SYS_exit, status);
}
