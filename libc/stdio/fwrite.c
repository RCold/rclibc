#include "stdio.h"

size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp) {
    const char *p = ptr;
    const char *end = p + size * nmemb;
    for (; p < end && putc(*p, fp) != EOF; p++);
    return size == 0 ? nmemb : (p - (const char *) ptr) / size;
}
