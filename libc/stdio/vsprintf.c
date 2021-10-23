#include "_stdio.h"

int vsprintf(char *s, const char *format, va_list arg) {
    int ret;
    FILE f;
    _finit(&f, s, (char *) -1);
    f._flag = __IOSTR | __IOFBF;
    f._wend = f._end;
    ret = vfprintf(&f, format, arg);
    putc('\0', &f);
    return ret;
}
