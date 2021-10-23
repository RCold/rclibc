#include "stdarg.h"
#include "stdio.h"

int fprintf(FILE *fp, const char *format, ...) {
    int ret;
    va_list arg;
    va_start(arg, format);
    ret = vfprintf(fp, format, arg);
    va_end(arg);
    return ret;
}
