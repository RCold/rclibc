#ifndef _SYSDEP_H
#define _SYSDEP_H

#if defined(__linux__)

#include "linux/sysdep.h"

#elif defined(__APPLE__)

#include "darwin/sysdep.h"

#else
#error This file only supports Linux and Darwin.
#endif /* defined(__linux__) */

#define SYSCALL(name, argc)                     \
    PSEUDO(name, name, argc);                   \
    RET;                                        \
    PSEUDO_END(name)

#define SYSCALL_NOERRNO(name, argc)             \
    PSEUDO_NOERRNO(name, name, argc);           \
    RET_NOERRNO;                                \
    PSEUDO_END_NOERRNO(name)

#define _SYSCALL_NORETURN(name, argc)           \
    PSEUDO_NOERRNO(_##name, name, argc);        \
    PSEUDO_END_NOERRNO(_##name)

#endif /* _SYSDEP_H */
