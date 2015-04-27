#include "string.h"

void *memchr(const void *s, int c, size_t n) {
	const unsigned char *p;
	for (p = s; n > 0; p++, n--)
		if (*p == (unsigned char) c)
			return (void *) p;
	return NULL;
}
