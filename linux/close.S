	.equ __NR_close, 0x06
	.text
	.globl close
	.type close, @function
close:
	push %ebx
	mov $__NR_close, %eax
	mov 8(%esp), %ebx
	int $0x80
	pop %ebx
	ret
