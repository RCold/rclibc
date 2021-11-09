#include "stdio.h"

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *fp) {
    int c;
    char *p = ptr;
    char *end = p + size * nmemb;
    while (p < end && (c = getc(fp)) != EOF)
        *p++ = (char) c;
    return size == 0 ? nmemb : (p - (char *) ptr) / size;
}
