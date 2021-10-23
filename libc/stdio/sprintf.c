#include "stdarg.h"
#include "stdio.h"

int sprintf(char *s, const char *format, ...) {
    int ret;
    va_list arg;
    va_start(arg, format);
    ret = vsprintf(s, format, arg);
    va_end(arg);
    return ret;
}
