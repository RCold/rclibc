#include "stdio.h"
#include "syscall.h"

int remove(const char *filename) {
	return unlink(filename);
}
