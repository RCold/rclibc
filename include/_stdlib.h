#ifndef __STDLIB_H
#define __STDLIB_H

#include <stdlib.h>
#include <sys/cdefs.h>

__BEGIN_DECLS

extern unsigned long int _rseed;

int _prand(void);

__END_DECLS

#endif /* __STDLIB_H */
