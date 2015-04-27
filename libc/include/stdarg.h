#ifndef _STDARG_H
#define _STDARG_H

#define _size(t)        ((sizeof(t) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(a,p)   ((void) ((a) = (char *) &(p) + _size(p)))
#define va_arg(a,t)     (*(t *) (((a) += _size(t)) - _size(t)))
#define va_end(a)       ((void) 0)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef char *va_list;
#endif /* _VA_LIST_DEFINED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STDARG_H */
