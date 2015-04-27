	.equ __NR_open, 0x05
	.text
	.globl open
	.type open, @function
open:
	push %ebx
	push %ecx
	push %edx
	mov $__NR_open, %eax
	mov 16(%esp), %ebx
	mov 20(%esp), %ecx
	mov 24(%esp), %edx
	int $0x80
	pop %edx
	pop %ecx
	pop %ebx
	ret
