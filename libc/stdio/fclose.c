#include "_stdio.h"

int fclose(FILE *fp) {
    int ret = _fclose(fp);
    _freefile(fp);
    return ret;
}
