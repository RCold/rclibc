#include "stdarg.h"
#include "stdio.h"

int printf(const char *format, ...) {
    int ret;
    va_list arg;
    va_start(arg, format);
    ret = vfprintf(stdout, format, arg);
    va_end(arg);
    return ret;
}
