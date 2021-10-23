#ifndef _SYSCALL_H
#define _SYSCALL_H

#ifndef __x86_64__
#error This file only supports x86_64.
#endif /* __x86_64__ */

#include <sys/cdefs.h>

#if defined(__linux__)

#define SYS_read        0
#define SYS_write       1
#define SYS_open        2
#define SYS_close       3
#define SYS_access      21
#define SYS_getpid      39
#define SYS_exit        60
#define SYS_rename      82
#define SYS_rmdir       84
#define SYS_unlink      87

__BEGIN_DECLS

long int syscall(long int, ...);

__END_DECLS

#elif defined(__APPLE__)

#define SYS_read        3
#define SYS_write       4
#define SYS_open        5
#define SYS_close       6
#define SYS_access      33
#define SYS_getpid      20
#define SYS_exit        1
#define SYS_rename      128
#define SYS_rmdir       137
#define SYS_unlink      10

__BEGIN_DECLS

int syscall(int, ...);

__END_DECLS

#else
#error This file only supports Linux and Darwin.
#endif /* defined(__linux__) */

#endif /* _SYSCALL_H */
