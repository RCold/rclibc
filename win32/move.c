#include "syscall.h"
#include "windows.h"

int move(const char *old, const char *new) {
	if (MoveFileA(old, new))
		return 0;
	else
		return -1;
}
