#include "syscall.h"
#include "windows.h"

pid_t getpid(void) {
	return GetCurrentProcessId();
}
