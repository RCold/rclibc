#ifndef _DARWIN_SYSCALL_H
#define _DARWIN_SYSCALL_H

#ifndef __APPLE__
#error This file is for Darwin target only.
#endif /* __APPLE__ */

#define SYS_read            3
#define SYS_write           4
#define SYS_open            5
#define SYS_close           6
#define SYS_stat            188
#define SYS_access          33
#define SYS_getpid          20
#define SYS_exit            1
#define SYS_rename          128
#define SYS_rmdir           137
#define SYS_unlink          10
#define SYS_gettimeofday    116
#define SYS_getrusage       117

#endif /* _DARWIN_SYSCALL_H */
