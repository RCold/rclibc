#ifndef _LINUX_SYSDEP_H
#define _LINUX_SYSDEP_H

#ifndef __linux__
#error This file is for Linux target only.
#endif /* __linux__ */

#define C_SYMBOL_NAME(name)     name
#define C_LABEL(name)           C_SYMBOL_NAME(name)##:

#define ASM_SIZE_DIRECTIVE(name)                \
    .size       name, .-name;

#define ENTRY_P2ALIGN(name, alignment)          \
    .globl      C_SYMBOL_NAME(name);            \
    .type       C_SYMBOL_NAME(name), @function; \
    .p2align    alignment, 0x90;                \
    C_LABEL(name)

#define ENTRY(name)     ENTRY_P2ALIGN(name, 4)
#define END(name)       ASM_SIZE_DIRECTIVE(name)

#ifdef __x86_64__

#include "x86_64/sysdep.h"

#else
#error This file only supports Linux x86_64.
#endif /* __x86_64__ */

#endif /* _LINUX_SYSDEP_H */
