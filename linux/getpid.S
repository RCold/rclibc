	.equ __NR_getpid, 0x14
	.text
	.globl getpid
	.type getpid, @function
getpid:
	mov $__NR_getpid, %eax
	int $0x80
	ret
