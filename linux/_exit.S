	.equ __NR_exit, 0x01
	.text
	.globl _exit
	.type _exit, @function
_exit:
	mov $__NR_exit, %eax
	mov 4(%esp), %ebx
	int $0x80
