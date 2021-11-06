#ifndef _DARWIN_X86_64_SYSDEP_H
#define _DARWIN_X86_64_SYSDEP_H

#if !defined(__APPLE__) || !defined(__x86_64__)
#error This file only supports Darwin x86_64.
#endif /* !defined(__APPLE__) || !defined(__x86_64__) */

#define SYSCALL_CLASS_UNIX      2
#define SYSCALL_CLASS_SHIFT     24
#define SYSCALL_CLASS_MASK      (0xFF << SYSCALL_CLASS_SHIFT)
#define SYSCALL_NUMBER_MASK     (~SYSCALL_CLASS_MASK)

#define SYSCALL_CONSTRUCT_UNIX(syscall_number)          \
    (SYSCALL_CLASS_UNIX << SYSCALL_CLASS_SHIFT |        \
    (SYSCALL_NUMBER_MASK & (syscall_number)))

#define DO_ARG0 /* nothing */
#define DO_ARG1 /* nothing */
#define DO_ARG2 /* nothing */
#define DO_ARG3 /* nothing */
#define DO_ARG4 movq %rcx, %r10
#define DO_ARG5 DO_ARG4
#define DO_ARG6 DO_ARG5

#define DO_CALL(name, argc)                             \
    DO_ARG##argc;                                       \
    movl    $SYSCALL_CONSTRUCT_UNIX(SYS_##name), %eax;  \
    syscall

#define SYSCALL_ERROR_HANDLER               \
    jnb     0f;                             \
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

#endif /* _DARWIN_X86_64_SYSDEP_H */
