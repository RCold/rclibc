	.equ __NR_access, 0x21
	.text
	.globl access
	.type access, @function
access:
	push %ebx
	push %ecx
	mov $__NR_access, %eax
	mov 12(%esp), %ebx
	mov 16(%esp), %ecx
	int $0x80
	pop %ecx
	pop %ebx
	ret
