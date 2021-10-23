#include "_unistd.h"
#include "syscall.h"

pid_t getpid(void) {
    return (pid_t) syscall(SYS_getpid);
}
