#ifndef _WINDOWS_H
#define _WINDOWS_H

#ifndef _WIN32
#error This file is for Win32 target only.
#endif /* _WIN32 */

#ifdef __GNUC__
#ifndef __declspec
#define __declspec(e)   __attribute__((e))
#endif /* __declspec */
#ifndef __stdcall
#define __stdcall       __attribute__((stdcall))
#endif /* __stdcall */
#endif /* __GNUC__ */

#define far                                                 /* windef.h */
#define CONST                  const                        /* windef.h */
#define WINAPI                 __stdcall                    /* windef.h */
#define DECLSPEC_IMPORT        __declspec(dllimport)        /* winnt.h */
#define VOID                   void                         /* winnt.h */
#define FILE_BEGIN             0                            /* winbase.h */
#define FILE_CURRENT           1                            /* winbase.h */
#define FILE_END               2                            /* winbase.h */
#define ERROR_ACCESS_DENIED    5L                           /* winerror.h */
#define WINBASEAPI             DECLSPEC_IMPORT              /* apisetconv.h */
#define INVALID_HANDLE_VALUE   ((HANDLE) (LONG_PTR) - 1)    /* handleapi.h */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef int BOOL;                       /* windef.h */
typedef char CHAR;                      /* winnt.h */
typedef unsigned long int DWORD;        /* windef.h */
typedef void *PVOID;                    /* winnt.h */
typedef PVOID HANDLE;                   /* winnt.h */
typedef CONST CHAR *LPCSTR;             /* winnt.h */
typedef CONST void far *LPCVOID;        /* windef.h */
typedef DWORD far *LPDWORD;             /* windef.h */
typedef long LONG_PTR;                  /* basetsd.h */
typedef unsigned long int ULONG_PTR;    /* basetsd.h */

typedef struct _OVERLAPPED
{
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
} *LPOVERLAPPED;    /* winbase.h */

WINBASEAPI BOOL WINAPI DeleteFileA(LPCSTR);         /* fileapi.h */
WINBASEAPI BOOL WINAPI CloseHandle(HANDLE);         /* handleapi.h */
WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);  /* processthreadsapi.h */
WINBASEAPI BOOL WINAPI MoveFileA(LPCSTR, LPCSTR);   /* winbase.h */
WINBASEAPI BOOL WINAPI WriteFile(HANDLE, LPCVOID, DWORD, LPDWORD,
		LPOVERLAPPED);                              /* fileapi.h */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _WINDOWS_H */
