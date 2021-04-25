# mark_description "Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.4.243 Build 20190416";
# mark_description "-std=gnu99 -w2 -O3 -xHost -c -S -masm=intel -lm -pthread";
	.intel_syntax noprefix
	.file "sum_auto.c"
	.text
..TXTST0:
.L_2__routine_start_sum_auto_0:
# -- Begin  sum_auto
	.text
# mark_begin;
       .align    16,0x90
	.globl sum_auto
# --- sum_auto(double *, size_t)
sum_auto:
# parameter 1: rdi
# parameter 2: rsi
..B1.1:                         # Preds ..B1.0
                                # Execution count [1.00e+00]
	.cfi_startproc
..___tag_value_sum_auto.1:
..L2:
                                                          #4.38
        vxorpd    xmm0, xmm0, xmm0                              #5.13
        test      rsi, rsi                                      #6.25
        jbe       ..B1.22       # Prob 50%                      #6.25
                                # LOE rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.2:                         # Preds ..B1.1
                                # Execution count [9.00e-01]
        cmp       rsi, 16                                       #6.2
        jb        ..B1.25       # Prob 10%                      #6.2
                                # LOE rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.3:                         # Preds ..B1.2
                                # Execution count [9.00e-01]
        mov       rcx, rdi                                      #6.2
        and       rcx, 31                                       #6.2
        je        ..B1.10       # Prob 50%                      #6.2
                                # LOE rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.4:                         # Preds ..B1.3
                                # Execution count [9.00e-01]
        test      rcx, 7                                        #6.2
        jne       ..B1.23       # Prob 10%                      #6.2
                                # LOE rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.5:                         # Preds ..B1.4
                                # Execution count [4.50e-01]
        neg       rcx                                           #6.2
        add       rcx, 32                                       #6.2
        shr       rcx, 3                                        #6.2
        lea       rax, QWORD PTR [16+rcx]                       #6.2
        cmp       rsi, rax                                      #6.2
        jb        ..B1.23       # Prob 10%                      #6.2
                                # LOE rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.6:                         # Preds ..B1.5
                                # Execution count [9.00e-01]
        mov       rax, rsi                                      #6.2
        xor       edx, edx                                      #6.2
        sub       rax, rcx                                      #6.2
        and       rax, 15                                       #6.2
        neg       rax                                           #6.2
        add       rax, rsi                                      #6.2
        test      rcx, rcx                                      #6.2
        je        ..B1.11       # Prob 9%                       #6.2
                                # LOE rax rdx rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.8:                         # Preds ..B1.6 ..B1.8
                                # Execution count [5.00e+00]
        vaddsd    xmm0, xmm0, QWORD PTR [rdi+rdx*8]             #7.3
        inc       rdx                                           #6.2
        cmp       rdx, rcx                                      #6.2
        jb        ..B1.8        # Prob 82%                      #6.2
        jmp       ..B1.11       # Prob 100%                     #6.2
                                # LOE rax rdx rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.10:                        # Preds ..B1.3
                                # Execution count [4.05e-01]
        mov       rax, rsi                                      #6.2
        and       rax, 15                                       #6.2
        neg       rax                                           #6.2
        add       rax, rsi                                      #6.2
                                # LOE rax rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.11:                        # Preds ..B1.8 ..B1.10 ..B1.6
                                # Execution count [9.00e-01]
        vxorpd    ymm2, ymm2, ymm2                              #5.13
        vxorpd    xmm4, xmm4, xmm4                              #5.13
        vmovapd   ymm1, ymm2                                    #5.13
        vmovsd    xmm3, xmm4, xmm0                              #5.13
        vmovapd   ymm0, ymm1                                    #5.13
        vmovaps   xmm3, xmm3                                    #5.13
                                # LOE rax rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm4 ymm0 ymm1 ymm2 ymm3
..B1.12:                        # Preds ..B1.12 ..B1.11
                                # Execution count [5.00e+00]
        vaddpd    ymm3, ymm3, YMMWORD PTR [rdi+rcx*8]           #7.3
        vaddpd    ymm2, ymm2, YMMWORD PTR [32+rdi+rcx*8]        #7.3
        vaddpd    ymm1, ymm1, YMMWORD PTR [64+rdi+rcx*8]        #7.3
        vaddpd    ymm0, ymm0, YMMWORD PTR [96+rdi+rcx*8]        #7.3
        add       rcx, 16                                       #6.2
        cmp       rcx, rax                                      #6.2
        jb        ..B1.12       # Prob 82%                      #6.2
                                # LOE rax rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm4 ymm0 ymm1 ymm2 ymm3
..B1.13:                        # Preds ..B1.12
                                # Execution count [9.00e-01]
        vaddpd    ymm2, ymm3, ymm2                              #5.13
        lea       rdx, QWORD PTR [1+rax]                        #6.2
        vaddpd    ymm0, ymm1, ymm0                              #5.13
        vaddpd    ymm1, ymm2, ymm0                              #5.13
        vextractf128 xmm3, ymm1, 1                              #5.13
        vaddpd    xmm5, xmm1, xmm3                              #5.13
        vunpckhpd xmm6, xmm5, xmm5                              #5.13
        vaddsd    xmm0, xmm5, xmm6                              #5.13
        cmp       rdx, rsi                                      #6.2
        ja        ..B1.22       # Prob 50%                      #6.2
                                # LOE rax rbx rbp rsi rdi r12 r13 r14 r15 xmm0 xmm4
..B1.14:                        # Preds ..B1.13
                                # Execution count [9.00e-01]
        sub       rsi, rax                                      #6.2
        cmp       rsi, 4                                        #6.2
        jb        ..B1.24       # Prob 10%                      #6.2
                                # LOE rax rbx rbp rsi rdi r12 r13 r14 r15 xmm0 xmm4
..B1.15:                        # Preds ..B1.14
                                # Execution count [9.00e-01]
        mov       rdx, rsi                                      #6.2
        vmovsd    xmm0, xmm4, xmm0                              #5.13
        and       rdx, -4                                       #6.2
        xor       r8d, r8d                                      #6.2
        lea       rcx, QWORD PTR [rdi+rax*8]                    #7.10
        vmovaps   xmm0, xmm0                                    #5.13
                                # LOE rax rdx rcx rbx rbp rsi rdi r8 r12 r13 r14 r15 ymm0
..B1.16:                        # Preds ..B1.16 ..B1.15
                                # Execution count [5.00e+00]
        vaddpd    ymm0, ymm0, YMMWORD PTR [rcx+r8*8]            #7.3
        add       r8, 4                                         #6.2
        cmp       r8, rdx                                       #6.2
        jb        ..B1.16       # Prob 82%                      #6.2
                                # LOE rax rdx rcx rbx rbp rsi rdi r8 r12 r13 r14 r15 ymm0
..B1.17:                        # Preds ..B1.16
                                # Execution count [9.00e-01]
        vextractf128 xmm1, ymm0, 1                              #5.13
        vaddpd    xmm2, xmm0, xmm1                              #5.13
        vunpckhpd xmm3, xmm2, xmm2                              #5.13
        vaddsd    xmm0, xmm2, xmm3                              #5.13
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.18:                        # Preds ..B1.17 ..B1.24 ..B1.23
                                # Execution count [1.00e+00]
        cmp       rdx, rsi                                      #6.2
        jae       ..B1.22       # Prob 9%                       #6.2
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.19:                        # Preds ..B1.18
                                # Execution count [9.00e-01]
        lea       rax, QWORD PTR [rdi+rax*8]                    #7.10
                                # LOE rax rdx rbx rbp rsi r12 r13 r14 r15 xmm0
..B1.20:                        # Preds ..B1.20 ..B1.19
                                # Execution count [5.00e+00]
        vaddsd    xmm0, xmm0, QWORD PTR [rax+rdx*8]             #7.3
        inc       rdx                                           #6.2
        cmp       rdx, rsi                                      #6.2
        jb        ..B1.20       # Prob 82%                      #6.2
                                # LOE rax rdx rbx rbp rsi r12 r13 r14 r15 xmm0
..B1.22:                        # Preds ..B1.20 ..B1.13 ..B1.18 ..B1.25 ..B1.1
                                #      
                                # Execution count [1.00e+00]
        vzeroupper                                              #9.9
        ret                                                     #9.9
                                # LOE
..B1.23:                        # Preds ..B1.25 ..B1.4 ..B1.5
                                # Execution count [5.00e-02]
        xor       eax, eax                                      #6.2
        xor       edx, edx                                      #6.2
        jmp       ..B1.18       # Prob 100%                     #6.2
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.24:                        # Preds ..B1.14
                                # Execution count [9.00e-02]: Infreq
        xor       edx, edx                                      #6.2
        jmp       ..B1.18       # Prob 100%                     #6.2
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.25:                        # Preds ..B1.2
                                # Execution count [0.00e+00]: Infreq
        cmp       rsi, 1                                        #6.2
        jae       ..B1.23       # Prob 50%                      #6.2
        jmp       ..B1.22       # Prob 100%                     #6.2
        .align    16,0x90
                                # LOE rbx rbp rsi rdi r12 r13 r14 r15 xmm0
	.cfi_endproc
# mark_end;
	.type	sum_auto,@function
	.size	sum_auto,.-sum_auto
..LNsum_auto.0:
	.data
# -- End  sum_auto
	.data
	.section .note.GNU-stack, ""
# End
