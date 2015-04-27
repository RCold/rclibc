#ifndef _SIGNAL_H
#define _SIGNAL_H

#define SIGABRT     22
#define SIGFPE      8
#define SIGILL      4
#define SIGINT      2
#define SIGSEGV     11
#define SIGTERM     15

#define SIG_DFL     ((void (*)(int)) 0)
#define SIG_ERR     ((void (*)(int)) -1)
#define SIG_IGN     ((void (*)(int)) 1)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _SIG_ATOMIC_T_DEFINED
#define _SIG_ATOMIC_T_DEFINED
typedef int sig_atomic_t;
#endif /* _SIG_ATOMIC_T_DEFINED */

int raise(int);
void (*signal(int, void (*)(int)))(int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SIGNAL_H */
