	.file	"sum_intrinsics4.c"
	.intel_syntax noprefix
	.text
	.p2align 4,,15
	.globl	sum_intrinsics4
	.type	sum_intrinsics4, @function
sum_intrinsics4:
.LFB5454:
	.cfi_startproc
	mov	rdx, rsi
	and	rdx, -16
	je	.L10
	vxorpd	xmm2, xmm2, xmm2
	mov	rax, rdi
	vmovapd	ymm1, ymm2
	vmovapd	ymm3, ymm2
	lea	r8, [rdx-1]
	vmovapd	ymm0, ymm2
	lea	rcx, [rdi+rdx*8]
	.p2align 4,,10
	.p2align 3
.L3:
	vaddpd	ymm0, ymm0, YMMWORD PTR [rax]
	sub	rax, -128
	vaddpd	ymm3, ymm3, YMMWORD PTR [rax-96]
	vaddpd	ymm1, ymm1, YMMWORD PTR [rax-64]
	vaddpd	ymm2, ymm2, YMMWORD PTR [rax-32]
	cmp	rcx, rax
	jne	.L3
	vaddpd	ymm0, ymm0, ymm3
	mov	rdx, r8
	vaddpd	ymm1, ymm1, ymm2
	and	rdx, -16
	add	rdx, 16
	vaddpd	ymm0, ymm0, ymm1
.L2:
	vhaddpd	ymm0, ymm0, ymm0
	vextractf128	xmm1, ymm0, 0x1
	vaddpd	ymm0, ymm0, ymm1
	cmp	rsi, rdx
	jbe	.L15
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	lea	rax, [rsi-1]
	mov	r8, rsi
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rax, rdx
	and	rsp, -32
	vmovapd	YMMWORD PTR [rsp-32], ymm0
	sub	r8, rdx
	vmovsd	xmm0, QWORD PTR [rsp-32]
	cmp	rax, 2
	jbe	.L5
	lea	rax, [rdi+rdx*8]
	mov	rcx, r8
	shr	rcx, 2
	sal	rcx, 5
	add	rcx, rax
	.p2align 4,,10
	.p2align 3
.L6:
	vmovupd	xmm4, XMMWORD PTR [rax]
	vinsertf128	ymm1, ymm4, XMMWORD PTR [rax+16], 0x1
	vaddsd	xmm0, xmm0, xmm1
	vunpckhpd	xmm2, xmm1, xmm1
	vextractf128	xmm1, ymm1, 0x1
	add	rax, 32
	vaddsd	xmm2, xmm2, xmm0
	vaddsd	xmm0, xmm1, xmm2
	vunpckhpd	xmm1, xmm1, xmm1
	vaddsd	xmm0, xmm0, xmm1
	cmp	rax, rcx
	jne	.L6
	mov	rax, r8
	and	rax, -4
	add	rdx, rax
	cmp	rax, r8
	je	.L13
.L5:
	lea	rax, [rdx+1]
	vaddsd	xmm0, xmm0, QWORD PTR [rdi+rdx*8]
	cmp	rsi, rax
	jbe	.L13
	add	rdx, 2
	vaddsd	xmm0, xmm0, QWORD PTR [rdi+rax*8]
	cmp	rsi, rdx
	jbe	.L13
	vaddsd	xmm0, xmm0, QWORD PTR [rdi+rdx*8]
.L13:
	vzeroupper
	leave
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L15:
	.cfi_restore 6
	vzeroupper
	ret
	.p2align 4,,10
	.p2align 3
.L10:
	vxorpd	xmm0, xmm0, xmm0
	jmp	.L2
	.cfi_endproc
.LFE5454:
	.size	sum_intrinsics4, .-sum_intrinsics4
	.ident	"GCC: (GNU) 8.1.0"
	.section	.note.GNU-stack,"",@progbits
