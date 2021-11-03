#ifndef __FCNTL_H
#define __FCNTL_H

#if defined(__linux__)

#define O_RDONLY        0x0000
#define O_WRONLY        0x0001
#define O_RDWR          0x0002
#define O_CREAT         0x0040
#define O_TRUNC         0x0200
#define O_APPEND        0x0400
#define O_BINARY        0x0000

#elif defined(__APPLE__)

#define O_RDONLY        0x0000
#define O_WRONLY        0x0001
#define O_RDWR          0x0002
#define O_CREAT         0x0200
#define O_TRUNC         0x0400
#define O_APPEND        0x0008
#define O_BINARY        0x0000

#else

#define O_RDONLY        0x0000
#define O_WRONLY        0x0001
#define O_RDWR          0x0002
#define O_CREAT         0x0004
#define O_TRUNC         0x0008
#define O_APPEND        0x0010
#define O_BINARY        0x0020

#endif /* defined(__linux__) */

#include <sys/cdefs.h>

__BEGIN_DECLS

int open(const char *, int, ...);

__END_DECLS

#endif /* __FCNTL_H */
