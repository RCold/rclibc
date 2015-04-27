#ifndef _SETJMP_H
#define _SETJMP_H

#define setjmp(e) _setjmp(e)

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef _JMP_BUF_DEFINED
#define _JMP_BUF_DEFINED
typedef int jmp_buf[16];
#endif /* _JMP_BUF_DEFINED */

int _setjmp(jmp_buf);
void longjmp(jmp_buf, int);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _SETJMP_H */
