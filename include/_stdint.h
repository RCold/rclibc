#ifndef __STDINT_H
#define __STDINT_H

#ifdef __GNUC__

#define __join(a, b)        (a ## b)
#define __int_c(v, suffix)  __join(v, suffix)

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
#define UINT32_C(v)     (v ## U)
#endif /* defined(__UINT32_C) */

#if defined(__INT64_C)
#define INT64_C(v)     (__extension__ __INT64_C(v))
#elif defined(__INT64_C_SUFFIX__)
#define INT64_C(v)     (__extension__ __int_c(v, __INT64_C_SUFFIX__))
#else
#define INT64_C(v)     (__extension__ (v ## LL))
#endif /* defined(__INT64_C) */

#if defined(__UINT64_C)
#define UINT64_C(v)     (__extension__ __UINT64_C(v))
#elif defined(__UINT64_C_SUFFIX__)
#define UINT64_C(v)     (__extension__ __int_c(v, __UINT64_C_SUFFIX__))
#else
#define UINT64_C(v)     (__extension__ (v ## ULL))
#endif /* defined(__UINT64_C) */

#ifdef __INT32_TYPE__
__extension__ typedef __INT32_TYPE__ int32_t;
#else
__extension__ typedef int int32_t;
#endif /* __INT32_TYPE__ */

#ifdef __UINT32_TYPE__
__extension__ typedef __UINT32_TYPE__ uint32_t;
#else
__extension__ typedef unsigned int uint32_t;
#endif /* __UINT32_TYPE__ */

#ifdef __INT64_TYPE__
__extension__ typedef __INT64_TYPE__ int64_t;
#else
__extension__ typedef long long int int64_t;
#endif /* __INT64_TYPE__ */

#ifdef __UINT64_TYPE__
__extension__ typedef __UINT64_TYPE__ uint64_t;
#else
__extension__ typedef unsigned long long int uint64_t;
#endif /* __UINT64_TYPE__ */

#else

#define INT32_C(v)      (v ## i32)
#define UINT32_C(v)     (v ## ui32)
#define INT64_C(v)      (v ## i64)
#define UINT64_C(v)     (v ## ui64)

typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

#endif /* __GNUC__ */

#endif /* __STDINT_H */
