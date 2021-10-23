#include "errno.h"
#include "string.h"

static char buf[16];

char *strerror(int errnum) {
    switch (errnum) {
        case 0:
            strcpy(buf, "No error");
            break;
        case EDOM:
            strcpy(buf, "Domain error");
            break;
        case ERANGE:
            strcpy(buf, "Range error");
            break;
        default:
            strcpy(buf, "Unknown error");
            break;
    }
    return buf;
}
