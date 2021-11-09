#include "errno.h"
#include "stdio.h"
#include "string.h"

static char buf[64];

char *strerror(int errnum) {
    switch (errnum) {
        case 0:
            strcpy(buf, "Undefined error: 0");
            break;
        case EDOM:
            strcpy(buf, "Numerical argument out of domain");
            break;
        case ERANGE:
            strcpy(buf, "Result too large");
            break;
        default:
            sprintf(buf, "Unknown error: %d", errnum);
            break;
    }
    return buf;
}
