#include "stdio.h"

void setbuf(FILE *fp, char *buf) {
    setvbuf(fp, buf, buf != NULL ? _IOFBF : _IONBF, BUFSIZ);
}
