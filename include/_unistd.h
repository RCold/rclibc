#ifndef __UNISTD_H
#define __UNISTD_H

#define __need_size_t

#include <stddef.h>

#define R_OK            4
#define W_OK            2
#define X_OK            1
#define F_OK            0

#define STDIN_FILENO    0
#define STDOUT_FILENO   1
#define STDERR_FILENO   2

#include <sys/cdefs.h>

__BEGIN_DECLS

#if defined(_WIN64)
__extension__ typedef __int64 ssize_t;
#elif defined(_WIN32)
typedef int ssize_t;
#else
typedef long int ssize_t;
#endif /* defined(_WIN64) */

typedef int pid_t;

int access(const char *, int);

int close(int);

void _exit(int);

pid_t getpid(void);

ssize_t read(int, void *, size_t);

int rmdir(const char *);

int unlink(const char *);

ssize_t write(int, const void *, size_t);

__END_DECLS

#endif /* __UNISTD_H */
