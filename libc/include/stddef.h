#ifndef _STDDEF_H
#define _STDDEF_H

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else /* __cplusplus */
#define NULL ((void *) 0)
#endif /* __cplusplus */
#endif /* NULL */

#define offsetof(t,m) ((size_t) &((t *)0)->m)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _PTRDIFF_T_DEFINED
#define _PTRDIFF_T_DEFINED
typedef int ptrdiff_t;
#endif /* _PTRDIFF_T_DEFINED */

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif /* _SIZE_T_DEFINED */

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
typedef unsigned short int wchar_t;
#endif /* _WCHAR_T_DEFINED */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _STDDEF_H */
