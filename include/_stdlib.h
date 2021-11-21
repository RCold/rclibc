#ifndef __STDLIB_H
#define __STDLIB_H

#include <_stdint.h>
#include <stdlib.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

extern unsigned long int _rseed;

int _rand(unsigned long int *);

size_t _ultoa(uintptr_t, char *, unsigned int, const char *);

__END_DECLS

#endif /* __STDLIB_H */
