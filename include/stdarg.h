#ifndef _STDARG_H

#ifndef __need_va_list
#define _STDARG_H
#endif /* __need_va_list */

#if defined(_STDARG_H) || defined(__need_va_list)
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED

#if __GNUC__ > 2
typedef __builtin_va_list va_list;
#else
typedef char *va_list;
#endif /* __GNUC__ > 2 */

#endif /* _VA_LIST_DEFINED */
#undef __need_va_list
#endif /* defined(_STDARG_H) || defined(__need_va_list) */

#ifdef _STDARG_H
#if __GNUC__ > 2

#if __GNUC__ == 3 && __GNUC_MINOR__ < 3
#define va_start(a, p)  __builtin_stdarg_start(a, p)
#else
#define va_start(a, p)  __builtin_va_start(a, p)
#endif /* __GNUC__ == 3 && __GNUC_MINOR__ < 3 */
#define va_arg(a, t)    __builtin_va_arg(a, t)
#define va_end(a)       __builtin_va_end(a)
#define __va_copy(d, s) __builtin_va_copy((d), (s))

#else

#define __va_size(t)    ((sizeof(t) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(a, p)  ((void) ((a) = (char *) &(p) + __va_size(p)))
#define va_arg(a, t)    (*(t *) (((a) += __va_size(t)) - __va_size(t)))
#define va_end(a)       ((void) 0)
#define __va_copy(d, s) ((void) ((d) = (s)))

#endif /* __GNUC__ > 2 */
#endif /* _STDARG_H */

#endif /* _STDARG_H */
