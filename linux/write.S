	.equ __NR_write, 0x04
	.text
	.globl write
	.type write, @function
write:
	push %ebx
	push %ecx
	push %edx
	mov $__NR_write, %eax
	mov 16(%esp), %ebx
	mov 20(%esp), %ecx
	mov 24(%esp), %edx
	int $0x80
	pop %edx
	pop %ecx
	pop %ebx
	ret
