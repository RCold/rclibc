	.equ __NR_read, 0x03
	.text
	.globl read
	.type read, @function
read:
	push %ebx
	push %ecx
	push %edx
	mov $__NR_read, %eax
	mov 16(%esp), %ebx
	mov 20(%esp), %ecx
	mov 24(%esp), %edx
	int $0x80
	pop %edx
	pop %ecx
	pop %ebx
	ret
