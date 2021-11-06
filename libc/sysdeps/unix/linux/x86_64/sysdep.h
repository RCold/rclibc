#ifndef _LINUX_X86_64_SYSDEP_H
#define _LINUX_X86_64_SYSDEP_H

#if !defined(__linux__) || !defined(__x86_64__)
#error This file only supports Linux x86_64.
#endif /* !defined(__linux__) || !defined(__x86_64__) */

#include "syscall.h"

#define DO_ARG0 /* nothing */
#define DO_ARG1 /* nothing */
#define DO_ARG2 /* nothing */
#define DO_ARG3 /* nothing */
#define DO_ARG4 movq %rcx, %r10
#define DO_ARG5 DO_ARG4
#define DO_ARG6 DO_ARG5

#define DO_CALL(name, argc)                 \
    DO_ARG##argc;                           \
    movl    $SYS_##name, %eax;              \
    syscall

#define SYSCALL_ERROR_HANDLER               \
    cmpq    $-4095, %rax;                   \
    jb      0f;                             \
    orq     $-1, %rax;                      \
0:

#define PSEUDO(symbol, name, argc)          \
    .text;                                  \
    ENTRY(symbol);                          \
    DO_CALL(name, argc);                    \
    SYSCALL_ERROR_HANDLER

#define RET retq

#define PSEUDO_END(symbol) END(symbol)

#define PSEUDO_NOERRNO(symbol, name, argc)  \
    .text;                                  \
    ENTRY(symbol);                          \
    DO_CALL(name, argc)

#define RET_NOERRNO retq

#define PSEUDO_END_NOERRNO(symbol) END(symbol)

#endif /* _LINUX_X86_64_SYSDEP_H */
