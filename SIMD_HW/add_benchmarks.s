	.file	"add_benchmarks.c"
	.text
	.globl	add
	.type	add, @function
add:
.LFB5162:
	.cfi_startproc
	testq	%rdi, %rdi
	jle	.L1
	movl	$0, %eax
.L3:
	movslq	%eax, %rcx
	movzwl	(%rdx,%rcx,2), %r8d
	addw	%r8w, (%rsi,%rcx,2)
	incl	%eax
	movslq	%eax, %rcx
	cmpq	%rdi, %rcx
	jl	.L3
.L1:
	ret
	.cfi_endproc
.LFE5162:
	.size	add, .-add
	.globl	add_AVX1
	.type	add_AVX1, @function
add_AVX1:
.LFB5163:
	.cfi_startproc
	testq	%rdi, %rdi
	jle	.L5
	movl	$0, %eax
.L7:
	movslq	%eax, %r8
	leaq	(%rsi,%r8,2), %rcx
	vmovdqu	(%rdx,%r8,2), %xmm1
	vpaddw	(%rcx), %xmm1, %xmm0
	vmovups	%xmm0, (%rcx)
	addl	$8, %eax
	movslq	%eax, %rcx
	cmpq	%rdi, %rcx
	jl	.L7
.L5:
	ret
	.cfi_endproc
.LFE5163:
	.size	add_AVX1, .-add_AVX1
	.globl	add_AVX2
	.type	add_AVX2, @function
add_AVX2:
.LFB5164:
	.cfi_startproc
	testq	%rdi, %rdi
	jle	.L9
	movl	$0, %eax
.L11:
	movslq	%eax, %r8
	leaq	(%rsi,%r8,2), %rcx
	vmovdqu	(%rdx,%r8,2), %ymm1
	vpaddw	(%rcx), %ymm1, %ymm0
	vmovdqu	%ymm0, (%rcx)
	addl	$16, %eax
	movslq	%eax, %rcx
	cmpq	%rdi, %rcx
	jl	.L11
.L9:
	ret
	.cfi_endproc
.LFE5164:
	.size	add_AVX2, .-add_AVX2
	.globl	add_SSE
	.type	add_SSE, @function
add_SSE:
.LFB5165:
	.cfi_startproc
	testq	%rdi, %rdi
	jle	.L13
	movl	$0, %eax
.L15:
	movslq	%eax, %r8
	leaq	(%rsi,%r8,2), %rcx
	vmovdqu	(%rdx,%r8,2), %xmm1
	vpaddw	(%rcx), %xmm1, %xmm0
	vmovups	%xmm0, (%rcx)
	addl	$8, %eax
	movslq	%eax, %rcx
	cmpq	%rdi, %rcx
	jl	.L15
.L13:
	ret
	.cfi_endproc
.LFE5165:
	.size	add_SSE, .-add_SSE
	.globl	functions
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Scalar"
.LC1:
	.string	"SSE"
.LC2:
	.string	"AVX"
.LC3:
	.string	"AVX2"
	.data
	.align 32
	.type	functions, @object
	.size	functions, 80
functions:
	.quad	add
	.quad	.LC0
	.quad	add_SSE
	.quad	.LC1
	.quad	add_AVX1
	.quad	.LC2
	.quad	add_AVX2
	.quad	.LC3
	.quad	0
	.quad	0
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-20)"
	.section	.note.GNU-stack,"",@progbits
