#ifndef _DARWIN_SYSDEP_H
#define _DARWIN_SYSDEP_H

#ifndef __APPLE__
#error This file is for Darwin target only.
#endif /* __APPLE__ */

#define C_SYMBOL_NAME(name)     _##name
#define C_LABEL(name)           C_SYMBOL_NAME(name)##:

#define ENTRY_P2ALIGN(name, alignment)      \
    .globl      C_SYMBOL_NAME(name);        \
    .p2align    alignment, 0x90;            \
    C_LABEL(name)

#define ENTRY(name)     ENTRY_P2ALIGN(name, 4)
#define END(name)

#include "syscall.h"

#ifdef __x86_64__

#include "x86_64/sysdep.h"

#else
#error This file only supports Darwin x86_64.
#endif /* __x86_64__ */

#endif /* _DARWIN_SYSDEP_H */
