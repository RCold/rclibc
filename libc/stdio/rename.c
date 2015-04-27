#include "stdio.h"
#include "syscall.h"

int rename(const char *old, const char *new) {
	return move(old, new);
}
