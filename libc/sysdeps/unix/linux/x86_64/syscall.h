#ifndef _LINUX_X86_64_SYSCALL_H
#define _LINUX_X86_64_SYSCALL_H

#if !defined(__linux__) || !defined(__x86_64__)
#error This file only supports Linux x86_64.
#endif /* !defined(__linux__) || !defined(__x86_64__) */

#define SYS_read            0
#define SYS_write           1
#define SYS_open            2
#define SYS_close           3
#define SYS_stat            4
#define SYS_access          21
#define SYS_getpid          39
#define SYS_exit            60
#define SYS_rename          82
#define SYS_rmdir           84
#define SYS_unlink          87
#define SYS_gettimeofday    96
#define SYS_getrusage       98

#endif /* _LINUX_X86_64_SYSCALL_H */
