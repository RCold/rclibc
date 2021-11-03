#ifndef _SETJMP_H
#define _SETJMP_H

#if defined(__linux__) && defined(__x86_64__)
#define _JBLEN      50
#elif defined(__linux__) && defined(__i386__)
#define _JBLEN      39
#elif defined(__APPLE__) && defined(__x86_64__)
#define _JBLEN      37
#elif defined(__APPLE__) && defined(__i386__)
#define _JBLEN      18
#elif defined(_WIN64) && (defined(__x86_64__) || defined(_M_AMD64))
#define _JBLEN      64
#elif defined(_WIN32) && (defined(__i386__) || defined(_M_IX86))
#define _JBLEN      16
#else
#error Undefined platform for setjmp
#endif /* defined(__linux__) && defined(__x86_64__) */

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef int jmp_buf[_JBLEN];

#ifndef __APPLE__
#define setjmp(e)   _setjmp(e)

int _setjmp(jmp_buf);

#else

int setjmp(jmp_buf);

#endif /* __APPLE__ */

void longjmp(jmp_buf, int);

__END_DECLS

#endif /* _SETJMP_H */
