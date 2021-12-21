	.file	"test.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.globl	a
	.bss
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.ident	"GCC: (GNU) 11.1.0"
	.section	.note.GNU-stack,"",@progbits
