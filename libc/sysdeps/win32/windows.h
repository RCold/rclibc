#ifndef _WINDOWS_H
#define _WINDOWS_H

#ifndef _WIN32
#error This file is for Windows target only.
#endif /* _WIN32 */

#ifdef __GNUC__

#ifndef __declspec
#define __declspec(e)   __attribute__((e))
#endif /* __declspec */

#ifndef __stdcall
#if defined(__i386__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)
#define __stdcall       __attribute__((__stdcall__)) __attribute__((__force_align_arg_pointer__))
#else
#define __stdcall       __attribute__((__stdcall__))
#endif /* __GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2) */
#elif defined(__x86_64__)
#if __GNUC__ > 5 || (__GNUC__ == 5 && __GNUC_MINOR__ >= 3)
#define __stdcall       __attribute__((__ms_abi__)) __attribute__((__force_align_arg_pointer__))
#else
#define __stdcall       __attribute__((__ms_abi__))
#endif /* __GNUC__ > 5 || (__GNUC__ == 5 && __GNUC_MINOR__ >= 3) */
#else
#define __stdcall
#endif /* defined(__i386__) */
#endif /* __stdcall */

#endif /* __GNUC__ */

#define far                                                 /* minwindef.h */
#define CONST                   const                       /* minwindef.h */
#define WINAPI                  __stdcall                   /* minwindef.h */
#define DECLSPEC_IMPORT         __declspec(dllimport)       /* winnt.h */
#define VOID                    void                        /* winnt.h */
#define FILE_BEGIN              0                           /* winbase.h */
#define FILE_CURRENT            1                           /* winbase.h */
#define FILE_END                2                           /* winbase.h */
#define ERROR_ACCESS_DENIED     5L                          /* winerror.h */
#define WINBASEAPI              DECLSPEC_IMPORT             /* apisetcconv.h */
#define INVALID_HANDLE_VALUE    ((HANDLE) (LONG_PTR) -1)    /* handleapi.h */

#include <sys/cdefs.h>

__BEGIN_DECLS

typedef int BOOL;                       /* minwindef.h */
typedef unsigned long int DWORD;        /* minwindef.h */
typedef CONST void far *LPCVOID;        /* minwindef.h */
typedef DWORD far *LPDWORD;             /* minwindef.h */
typedef char CHAR;                      /* winnt.h */
typedef void *PVOID;                    /* winnt.h */
typedef PVOID HANDLE;                   /* winnt.h */
typedef CONST CHAR *LPCSTR;             /* winnt.h */

#ifdef _WIN64
__extension__ typedef __int64 LONG_PTR;             /* basetsd.h */
__extension__ typedef unsigned __int64 ULONG_PTR;   /* basetsd.h */
#else
typedef long int LONG_PTR;                          /* basetsd.h */
typedef unsigned long int ULONG_PTR;                /* basetsd.h */
#endif /* _WIN64 */

typedef struct _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR InternalHigh;
    union {
        struct {
            DWORD Offset;
            DWORD OffsetHigh;
        } DUMMYSTRUCTNAME;
        PVOID Pointer;
    } DUMMYUNIONNAME;
    HANDLE hEvent;
} *LPOVERLAPPED;    /* minwinbase.h */

WINBASEAPI BOOL WINAPI DeleteFileA(LPCSTR);         /* fileapi.h */
WINBASEAPI BOOL WINAPI CloseHandle(HANDLE);         /* handleapi.h */
WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);  /* processthreadsapi.h */
WINBASEAPI BOOL WINAPI MoveFileA(LPCSTR, LPCSTR);   /* winbase.h */
WINBASEAPI BOOL WINAPI WriteFile(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED);    /* fileapi.h */

__END_DECLS

#endif /* _WINDOWS_H */
