#ifndef __STDINT_H
#define __STDINT_H

#ifdef __GNUC__

#define __int_c_join(a, b)  (a##b)
#define __int_c(v, s)       __int_c_join(v, s)

#if defined(__INT32_C)
#define INT32_C(v)      __INT32_C(v)
#elif defined(__INT32_C_SUFFIX__)
#define INT32_C(v)      __int_c(v, __INT32_C_SUFFIX__)
#else
#define INT32_C(v)      (v)
#endif /* defined(__INT32_C) */

#if defined(__UINT32_C)
#define UINT32_C(v)     __UINT32_C(v)
#elif defined(__UINT32_C_SUFFIX__)
#define UINT32_C(v)     __int_c(v, __UINT32_C_SUFFIX__)
#else
#define UINT32_C(v)     (v##U)
#endif /* defined(__UINT32_C) */

#if defined(__INT64_C)
#define INT64_C(v)      (__extension__ __INT64_C(v))
#elif defined(__INT64_C_SUFFIX__)
#define INT64_C(v)      (__extension__ __int_c(v, __INT64_C_SUFFIX__))
#else
#define INT64_C(v)      (__extension__ (v##LL))
#endif /* defined(__INT64_C) */

#if defined(__UINT64_C)
#define UINT64_C(v)     (__extension__ __UINT64_C(v))
#elif defined(__UINT64_C_SUFFIX__)
#define UINT64_C(v)     (__extension__ __int_c(v, __UINT64_C_SUFFIX__))
#else
#define UINT64_C(v)     (__extension__ (v##ULL))
#endif /* defined(__UINT64_C) */

#else

#define INT32_C(v)      (v##i32)
#define UINT32_C(v)     (v##ui32)
#define INT64_C(v)      (v##i64)
#define UINT64_C(v)     (v##ui64)

#endif /* __GNUC__ */

#define INT32_MAX       INT32_C(2147483647)
#define INT32_MIN       (-INT32_MAX - INT32_C(1))
#define UINT32_MAX      UINT32_C(4294967295)

#define INT64_MAX       INT64_C(9223372036854775807)
#define INT64_MIN       (-INT64_MAX - INT64_C(1))
#define UINT64_MAX      UINT64_C(18446744073709551615)

#include <limits.h>

#if defined(_WIN64)
#define INTPTR_MAX      INT64_MAX
#elif defined(_WIN32)
#define INTPTR_MAX      INT_MAX
#else
#define INTPTR_MAX      LONG_MAX
#endif /* __INTPTR_MAX__ */
#define INTPTR_MIN      (-INTPTR_MAX - 1)

#if defined(_WIN64)
#define UINTPTR_MAX     UINT64_MAX
#elif defined(_WIN32)
#define UINTPTR_MAX     UINT_MAX
#else
#define UINTPTR_MAX     ULONG_MAX
#endif /* __UINTPTR_MAX__ */

#include <sys/cdefs.h>

#ifdef __INT32_TYPE__
typedef __INT32_TYPE__ int32_t;
#else
typedef __int32 int32_t;
#endif /* __INT32_TYPE__ */

#ifdef __UINT32_TYPE__
typedef __UINT32_TYPE__ uint32_t;
#else
typedef unsigned __int32 uint32_t;
#endif /* __UINT32_TYPE__ */

#ifdef __INT64_TYPE__
__extension__ typedef __INT64_TYPE__ int64_t;
#else
__extension__ typedef __int64 int64_t;
#endif /* __INT64_TYPE__ */

#ifdef __UINT64_TYPE__
__extension__ typedef __UINT64_TYPE__ uint64_t;
#else
__extension__ typedef unsigned __int64 uint64_t;
#endif /* __UINT64_TYPE__ */

#if defined(__INTPTR_TYPE__)
__extension__ typedef __INTPTR_TYPE__ intptr_t;
#elif defined(_WIN64)
__extension__ typedef __int64 intptr_t;
#elif defined(_WIN32)
typedef int intptr_t;
#else
typedef long int intptr_t;
#endif /* defined(__INTPTR_TYPE__) */

#if defined(__UINTPTR_TYPE__)
__extension__ typedef __UINTPTR_TYPE__ uintptr_t;
#elif defined(_WIN64)
__extension__ typedef unsigned __int64 uintptr_t;
#elif defined(_WIN32)
typedef unsigned int uintptr_t;
#else
typedef unsigned long int uintptr_t;
#endif /* defined(__UINTPTR_TYPE__) */

#endif /* __STDINT_H */
