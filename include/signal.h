#ifndef _SIGNAL_H
#define _SIGNAL_H

#define SIG_DFL     ((void (*)(int)) 0)
#define SIG_ERR     ((void (*)(int)) -1)
#define SIG_IGN     ((void (*)(int)) 1)

#ifdef _WIN32

#define SIGABRT     22
#define SIGFPE      8
#define SIGILL      4
#define SIGINT      2
#define SIGSEGV     11
#define SIGTERM     15

#else

#define SIGABRT     6
#define SIGFPE      8
#define SIGILL      4
#define SIGINT      2
#define SIGSEGV     11
#define SIGTERM     15

#endif /* _WIN32 */

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef int sig_atomic_t;

void (*signal(int, void (*)(int)))(int);

int raise(int);

__END_DECLS

#endif /* _SIGNAL_H */
