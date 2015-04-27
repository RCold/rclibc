#include "internal.h"
#include "limits.h"
#include "stdio.h"

int vsprintf(char *s, const char *format, va_list arg) {
	int ret;
	FILE file;
	file._flag = _IOSTRG;
	file._ptr = s;
	file._wend = (char *) -1;
	ret = vfprintf(&file, format, arg);
	return ret;
}
