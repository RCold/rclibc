#include "string.h"

int strcmp(const char *s1, const char *s2) {
	const unsigned char *p1, *p2;
	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	for (; *p1 != '\0' || *p2 != '\0'; p1++, p2++)
		if (*p1 != *p2)
			return *p1 - *p2;
	return 0;
}
