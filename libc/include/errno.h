#ifndef _ERRNO_H
#define _ERRNO_H

#define EDOM    33
#define ERANGE  34

#define errno   _errno

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

extern int _errno;

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* _ERRNO_H */
