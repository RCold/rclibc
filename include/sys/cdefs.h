#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H

#ifdef __cplusplus
#define __BEGIN_DECLS   extern "C" {
#define __END_DECLS     }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif /* __cplusplus */

#ifdef __GNUC__
#define __int8          char
#define __int16         short int
#define __int32         int
#define __int64         long long int
#else
#define __extension__
#endif /* __GNUC__ */

#endif /* _SYS_CDEFS_H */
