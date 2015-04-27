#include "internal.h"
#include "stdio.h"
#include "syscall.h"

char *_tmpnam(char *s, unsigned long int *u) {
	int n;
	do {
		if (*u >= TMP_MAX)
			return NULL;
		n = tmppath(s);
		if (n == 0 || n > L_tmpnam - 12)
			return NULL;
		s += n;
		sprintf(s, "t%4x.%lu", getpid(), (*u)++);
	} while (access(s, 0) == 0);
	return s;
}
