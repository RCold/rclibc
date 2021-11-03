#ifndef _STDDEF_H

#if !defined(__need_NULL) && !defined(__need_size_t) && !defined(__need_wchar_t)
#define _STDDEF_H
#endif /* !defined(__need_NULL) && !defined(__need_size_t) && !defined(__need_wchar_t) */

#if defined(_STDDEF_H) || defined(__need_NULL)
#ifndef _NULL_DEFINED
#define _NULL_DEFINED

#if !defined(__cplusplus)
#define NULL ((void *) 0)
#elif defined(__GNUG__)
#define NULL __null
#else
#define NULL 0
#endif /* !defined(__cplusplus) */

#endif /* _NULL_DEFINED */
#undef __need_NULL
#endif /* defined(_STDDEF_H) || defined(__need_NULL) */

#include <sys/cdefs.h>

#if defined(_STDDEF_H) || defined(__need_size_t)
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED

#if defined(__SIZE_TYPE__)
typedef __SIZE_TYPE__ size_t;
#elif defined(_WIN64)
__extension__ typedef unsigned __int64 size_t;
#elif defined(_WIN32)
typedef unsigned int size_t;
#else
typedef unsigned long int size_t;
#endif /* defined(__SIZE_TYPE__) */

#endif /* _SIZE_T_DEFINED */
#undef __need_size_t
#endif /* defined(_STDDEF_H) || defined(__need_size_t) */

#if defined(_STDDEF_H) || defined(__need_wchar_t)
#ifndef __cplusplus
#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED

#if defined(__WCHAR_TYPE__)
typedef __WCHAR_TYPE__ wchar_t;
#elif defined(_WIN32)
typedef unsigned short int wchar_t;
#else
typedef int wchar_t;
#endif /* defined(__WCHAR_TYPE__) */

#endif /* _WCHAR_T_DEFINED */
#endif /* __cplusplus */
#undef __need_wchar_t
#endif /* defined(_STDDEF_H) || defined(__need_wchar_t) */

#ifdef _STDDEF_H

#ifdef _WIN64
#define offsetof(t, m)      ((size_t) (ptrdiff_t) &((t *) 0)->m)
#else
#define offsetof(t, m)      ((size_t) &((t *) 0)->m)
#endif /* _WIN64 */

#if defined(__PTRDIFF_TYPE__)
typedef __PTRDIFF_TYPE__ ptrdiff_t;
#elif defined(_WIN64)
__extension__ typedef __int64 ptrdiff_t;
#elif defined(_WIN32)
typedef int ptrdiff_t;
#else
typedef long int ptrdiff_t;
#endif /* defined(__PTRDIFF_TYPE__) */

#endif /* _STDDEF_H */

#endif /* _STDDEF_H */
