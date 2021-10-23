#ifndef _SETJMP_H
#define _SETJMP_H

#if defined(__linux__)
#if defined(__i386__)
#define _JBLEN      39
#elif defined(__x86_64__)
#define _JBLEN      50
#endif /* defined(__i386__) */
#elif defined(__APPLE__)
#if defined(__i386__)
#define _JBLEN      18
#elif defined(__x86_64__)
#define _JBLEN      37
#endif /* defined(__i386__) */
#elif defined(_WIN64)
#define _JBLEN      64
#elif defined(_WIN32)
#define _JBLEN      16
#else
#error Undefined platform for setjmp
#endif /* defined(__linux__) */

#ifndef __APPLE__
#define setjmp(e)   _setjmp(e)
#endif /* __APPLE__ */

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef int jmp_buf[_JBLEN];

#ifndef __APPLE__

int _setjmp(jmp_buf);

#else

int setjmp(jmp_buf);

#endif /* __APPLE__ */

void longjmp(jmp_buf, int);

__END_DECLS

#endif /* _SETJMP_H */
