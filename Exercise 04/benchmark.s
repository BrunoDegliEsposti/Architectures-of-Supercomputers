# mark_description "Intel(R) C Intel(R) 64 Compiler for applications running on Intel(R) 64, Version 19.0.4.243 Build 20190416";
# mark_description "-I/apps/likwid/4.3.4/include -std=gnu99 -w2 -O3 -DLIKWID_PERFMON -c -S -masm=intel -L/apps/likwid/4.3.4/lib ";
# mark_description "-lm -pthread -llikwid";
	.intel_syntax noprefix
	.file "benchmark.c"
	.text
..TXTST0:
.L_2__routine_start_benchmark_0:
# -- Begin  benchmark
	.text
# mark_begin;
       .align    16,0x90
	.globl benchmark
# --- benchmark(int *, size_t)
benchmark:
# parameter 1: rdi
# parameter 2: rsi
..B1.1:                         # Preds ..B1.0
                                # Execution count [1.00e+00]
	.cfi_startproc
..___tag_value_benchmark.1:
..L2:
                                                          #4.38
        pxor      xmm0, xmm0                                    #5.16
        test      rsi, rsi                                      #6.25
        jbe       ..B1.8        # Prob 50%                      #6.25
                                # LOE rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.2:                         # Preds ..B1.1
                                # Execution count [1.00e+00]
        mov       rax, rsi                                      #4.8
        mov       ecx, 1                                        #6.2
        xor       edx, edx                                      #6.2
        shr       rax, 1                                        #4.8
        je        ..B1.6        # Prob 9%                       #6.2
                                # LOE rax rdx rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.3:                         # Preds ..B1.2
                                # Execution count [9.00e-01]
        movsd     xmm1, QWORD PTR .L_2il0floatpacket.0[rip]     #8.14
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0 xmm1
..B1.4:                         # Preds ..B1.4 ..B1.3
                                # Execution count [2.50e+00]
        movaps    xmm2, xmm1                                    #8.4
        cmp       DWORD PTR [rdi+rdx*8], 0                      #10.4
        addsd     xmm2, xmm0                                    #8.4
        subsd     xmm0, xmm1                                    #10.4
        je        ..L3          # Prob 50%                      #10.4
        movaps    xmm2, xmm0                                    #10.4
..L3:                                                           #
        movaps    xmm0, xmm1                                    #8.4
        cmp       DWORD PTR [4+rdi+rdx*8], 0                    #10.4
        addsd     xmm0, xmm2                                    #8.4
        subsd     xmm2, xmm1                                    #10.4
        je        ..L4          # Prob 50%                      #10.4
        movaps    xmm0, xmm2                                    #10.4
..L4:                                                           #
        inc       rdx                                           #6.2
        cmp       rdx, rax                                      #6.2
        jb        ..B1.4        # Prob 63%                      #6.2
                                # LOE rax rdx rbx rbp rsi rdi r12 r13 r14 r15 xmm0 xmm1
..B1.5:                         # Preds ..B1.4
                                # Execution count [9.00e-01]
        lea       rcx, QWORD PTR [1+rdx+rdx]                    #7.3
                                # LOE rcx rbx rbp rsi rdi r12 r13 r14 r15 xmm0
..B1.6:                         # Preds ..B1.5 ..B1.2
                                # Execution count [1.00e+00]
        lea       rax, QWORD PTR [-1+rcx]                       #6.2
        cmp       rax, rsi                                      #6.2
        jae       ..B1.8        # Prob 9%                       #6.2
                                # LOE rcx rbx rbp rdi r12 r13 r14 r15 xmm0
..B1.7:                         # Preds ..B1.6
                                # Execution count [9.00e-01]
        movsd     xmm1, QWORD PTR .L_2il0floatpacket.0[rip]     #8.4
        cmp       DWORD PTR [-4+rdi+rcx*4], 0                   #10.4
        addsd     xmm1, xmm0                                    #8.4
        subsd     xmm0, QWORD PTR .L_2il0floatpacket.0[rip]     #10.4
        jne       ..L5          # Prob 50%                      #10.4
        movaps    xmm0, xmm1                                    #10.4
..L5:                                                           #
                                # LOE rbx rbp r12 r13 r14 r15 xmm0
..B1.8:                         # Preds ..B1.7 ..B1.6 ..B1.1
                                # Execution count [1.00e+00]
        ret                                                     #13.9
        .align    16,0x90
                                # LOE
	.cfi_endproc
# mark_end;
	.type	benchmark,@function
	.size	benchmark,.-benchmark
..LNbenchmark.0:
	.data
# -- End  benchmark
	.section .rodata, "a"
	.align 8
	.align 8
.L_2il0floatpacket.0:
	.long	0x00000000,0x3ff00000
	.type	.L_2il0floatpacket.0,@object
	.size	.L_2il0floatpacket.0,8
	.data
	.section .note.GNU-stack, ""
# End
