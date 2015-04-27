#ifndef _SYSCALL_H
#define _SYSCALL_H

#define O_RDONLY    0x0001
#define O_WRONLY    0x0002
#define O_RDWR      0x0004
#define O_CREAT     0x0008
#define O_TRUNC     0x0010
#define O_APPEND    0x0020
#define O_BINARY	0x0040

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
typedef int ssize_t;
#endif /* _SSIZE_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif /* _SIZE_T_DEFINED */

#ifndef _PID_T_DEFINED
#define _PID_T_DEFINED
typedef long int pid_t;
#endif /* _PID_T_DEFINED */

void _exit(int);
int access(const char *, int);
int close(int);
pid_t getpid(void);
int isatty(int);
int move(const char *, const char *);
int open(const char *, int);
ssize_t read(int, void *, size_t);
int tmppath(char *);
int unlink(const char *);
ssize_t write(int, const void *, size_t);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* _ERRNO_H */
