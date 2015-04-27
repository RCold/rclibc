	.equ __NR_unlink, 0x0a
	.text
	.globl unlink
	.type unlink, @function
unlink:
	push %ebx
	mov $__NR_unlink, %eax
	mov 8(%esp), %ebx
	int $0x80
	pop %ebx
	ret
