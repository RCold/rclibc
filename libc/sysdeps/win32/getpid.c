#include "_unistd.h"
#include "windows.h"

pid_t getpid(void) {
    return (pid_t) GetCurrentProcessId();
}
