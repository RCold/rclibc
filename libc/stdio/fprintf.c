#include "stdarg.h"
#include "stdio.h"

int fprintf(FILE *stream, const char *format, ...) {
	int ret;
	va_list arg;
	va_start(arg, format);
	ret = vfprintf(stream, format, arg);
	va_end(arg);
	return ret;
}
