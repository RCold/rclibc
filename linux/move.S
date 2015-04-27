	.equ __NR_rename, 0x26
	.text
	.globl move
	.type move, @function
move:
	push %ebx
	push %ecx
	mov $__NR_rename, %eax
	mov 12(%esp), %ebx
	mov 16(%esp), %ecx
	int $0x80
	pop %ecx
	pop %ebx
	ret
