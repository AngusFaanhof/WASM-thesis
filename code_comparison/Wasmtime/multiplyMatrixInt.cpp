0x7ffff772b530 <+0>:   pushq  %rbp
    0x7ffff772b531 <+1>:   movq   %rsp, %rbp
    0x7ffff772b534 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772b538 <+8>:   movq   (%r10), %r10
    0x7ffff772b53b <+11>:  addq   $0x10, %r10
    0x7ffff772b53f <+15>:  cmpq   %rsp, %r10
    0x7ffff772b542 <+18>:  ja     0x7ffff772b842            ; <+786> at matrix_algorithms.cpp:102:1
    0x7ffff772b548 <+24>:  subq   $0x40, %rsp
    0x7ffff772b54c <+28>:  movq   %rbx, 0x10(%rsp)
    0x7ffff772b551 <+33>:  movq   %r12, 0x18(%rsp)
    0x7ffff772b556 <+38>:  movq   %r13, 0x20(%rsp)
    0x7ffff772b55b <+43>:  movq   %r14, 0x28(%rsp)
    0x7ffff772b560 <+48>:  movq   %r15, 0x30(%rsp)
    0x7ffff772b565 <+53>:  movl   0x110(%rdi), %esi
    0x7ffff772b56b <+59>:  movq   %rsi, %r14
    0x7ffff772b56e <+62>:  subl   $0x140, %r14d             ; imm = 0x140
    0x7ffff772b575 <+69>:  movq   %rsi, 0x8(%rsp)
    0x7ffff772b57a <+74>:  movl   %r14d, 0x110(%rdi)
    0x7ffff772b581 <+81>:  movq   0x100(%rdi), %r15
    0x7ffff772b588 <+88>:  leaq   (%r15,%r14), %rbx
    0x7ffff772b58c <+92>:  movl   %edx, 0x58(%r15,%r14)
    0x7ffff772b591 <+97>:  movq   %rdx, (%rsp)
    0x7ffff772b595 <+101>: movl   %ecx, 0x54(%r15,%r14)
    0x7ffff772b59a <+106>: movl   %r8d, 0x50(%r15,%r14)
    0x7ffff772b59f <+111>: movl   %r9d, 0x4c(%r15,%r14)

-> 85           std::vector<int> result(rowsCols * rowsCols);
-> 86

->  0x7ffff772b5a4 <+116>: xorl   %r8d, %r8d
    0x7ffff772b5a7 <+119>: movb   %r8b, 0x4b(%r15,%r14)
    0x7ffff772b5ac <+124>: movl   0x4c(%r15,%r14), %ecx
    0x7ffff772b5b1 <+129>: imull  %ecx, %ecx
    0x7ffff772b5b4 <+132>: movq   %rdi, %r13
    0x7ffff772b5b7 <+135>: movq   (%rsp), %rdx
    0x7ffff772b5bb <+139>: movq   %r13, %rsi
    0x7ffff772b5be <+142>: movq   %r13, %rdi
    0x7ffff772b5c1 <+145>: callq  0x7ffff7729e90            ; std::__2::vector<int, std::__2::allocator<int> >::vector at vector:1191

** 87           for (size_t i = 0; i < rowsCols; i++) {

    0x7ffff772b5c6 <+150>: movl   $0x0, 0x44(%r15,%r14)
    0x7ffff772b5cf <+159>: movl   $0x1, %r12d
    0x7ffff772b5d5 <+165>: movl   0x44(%r15,%r14), %r11d
    0x7ffff772b5da <+170>: movl   0x4c(%r15,%r14), %esi
    0x7ffff772b5df <+175>: cmpl   %esi, %r11d
    0x7ffff772b5e2 <+178>: jae    0x7ffff772b7e5            ; <+693> at matrix_algorithms.cpp:101:2

** 88                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x7ffff772b5e8 <+184>: movl   $0x0, 0x40(%r15,%r14)
    0x7ffff772b5f1 <+193>: movl   0x40(%r15,%r14), %ecx
    0x7ffff772b5f6 <+198>: movl   0x4c(%r15,%r14), %edx
    0x7ffff772b5fb <+203>: cmpl   %edx, %ecx
    0x7ffff772b5fd <+205>: jae    0x7ffff772b7db            ; <+683> at matrix_algorithms.cpp:87:36

** 89                           __m128i sum = _mm_setzero_si128();
   90

    0x7ffff772b603 <+211>: movq   $0x0, 0xd8(%r15,%r14)
    0x7ffff772b60f <+223>: movq   $0x0, 0xd0(%r15,%r14)
    0x7ffff772b61b <+235>: movq   0xd8(%r15,%r14), %r10
    0x7ffff772b623 <+243>: vmovq  %r10, %xmm6
    0x7ffff772b628 <+248>: vpshufd $0x44, %xmm6, %xmm0       ; xmm0 = xmm6[0,1,0,1]
    0x7ffff772b62d <+253>: vpinsrq $0x1, 0x211(%rip), %xmm0, %xmm7 ; <+791> at matrix_algorithms.cpp:102:1
    0x7ffff772b637 <+263>: vmovdqu %xmm7, 0xc0(%r15,%r14)
    0x7ffff772b641 <+273>: vmovdqu %xmm7, 0x30(%r15,%r14)

** 91                           for (size_t k = 0; k < rowsCols; k++) {

    0x7ffff772b648 <+280>: movl   $0x0, 0x2c(%r15,%r14)
    0x7ffff772b651 <+289>: movl   0x2c(%r15,%r14), %ecx
    0x7ffff772b656 <+294>: movl   0x4c(%r15,%r14), %eax
    0x7ffff772b65b <+299>: cmpl   %eax, %ecx
    0x7ffff772b65d <+301>: jae    0x7ffff772b796            ; <+614> at matrix_algorithms.cpp:97:56

** 92                                   __m128i a = _mm_set1_epi32(A[i * rowsCols + k]);

    0x7ffff772b663 <+307>: movl   0x54(%r15,%r14), %edx
    0x7ffff772b668 <+312>: movl   0x44(%r15,%r14), %edi
    0x7ffff772b66d <+317>: movl   0x4c(%r15,%r14), %r8d
    0x7ffff772b672 <+322>: movl   0x2c(%r15,%r14), %r9d
    0x7ffff772b677 <+327>: imull  %r8d, %edi
    0x7ffff772b67b <+331>: leal   (%rdi,%r9), %ecx
    0x7ffff772b67f <+335>: movq   %r13, %rsi
    0x7ffff772b682 <+338>: movq   %r13, %rdi
    0x7ffff772b685 <+341>: callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772b68a <+346>: movl   %eax, %edx
    0x7ffff772b68c <+348>: movl   (%r15,%rdx), %edx
    0x7ffff772b690 <+352>: movl   %edx, 0x7c(%r15,%r14)
    0x7ffff772b695 <+357>: movl   %edx, 0xfc(%r15,%r14)
    0x7ffff772b69d <+365>: vmovd  %edx, %xmm6
    0x7ffff772b6a1 <+369>: vpbroadcastd %xmm6, %xmm0
    0x7ffff772b6a6 <+374>: vmovdqu %xmm0, 0xe0(%r15,%r14)
    0x7ffff772b6b0 <+384>: vmovdqu %xmm0, 0x10(%r15,%r14)

** 93                                   __m128i b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[k * rowsCols + j]));

    0x7ffff772b6b7 <+391>: movl   0x50(%r15,%r14), %edx
    0x7ffff772b6bc <+396>: movl   0x2c(%r15,%r14), %r8d
    0x7ffff772b6c1 <+401>: movl   0x4c(%r15,%r14), %r11d
    0x7ffff772b6c6 <+406>: movl   0x40(%r15,%r14), %esi
    0x7ffff772b6cb <+411>: imull  %r11d, %r8d
    0x7ffff772b6cf <+415>: leal   (%r8,%rsi), %ecx
    0x7ffff772b6d3 <+419>: movq   %r13, %rsi
    0x7ffff772b6d6 <+422>: movq   %r13, %rdi
    0x7ffff772b6d9 <+425>: callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772b6de <+430>: movl   %eax, 0x5c(%r15,%r14)
    0x7ffff772b6e3 <+435>: movl   %eax, %esi
    0x7ffff772b6e5 <+437>: vmovdqu (%r15,%rsi), %xmm2
    0x7ffff772b6eb <+443>: vmovdqu %xmm2, (%r15,%r14)

** 94                                   sum = _mm_add_epi32(sum, _mm_mullo_epi32(a, b));
   95                           }
   96

    0x7ffff772b6f1 <+449>: vmovdqu 0x30(%r15,%r14), %xmm3
    0x7ffff772b6f8 <+456>: vmovdqu 0x10(%r15,%r14), %xmm4
    0x7ffff772b6ff <+463>: vmovdqu %xmm4, 0xb0(%r15,%r14)
    0x7ffff772b709 <+473>: vmovdqu %xmm2, 0xa0(%r15,%r14)
    0x7ffff772b713 <+483>: vmovdqu 0xb0(%r15,%r14), %xmm5
    0x7ffff772b71d <+493>: vmovdqu %xmm5, 0x130(%r15,%r14)
    0x7ffff772b727 <+503>: vmovdqu %xmm2, 0x120(%r15,%r14)
    0x7ffff772b731 <+513>: vmovdqu 0x130(%r15,%r14), %xmm7
    0x7ffff772b73b <+523>: vmovdqu %xmm3, 0x90(%r15,%r14)
    0x7ffff772b745 <+533>: vpmulld %xmm2, %xmm7, %xmm0
    0x7ffff772b74a <+538>: vmovdqu %xmm0, 0x80(%r15,%r14)
    0x7ffff772b754 <+548>: vmovdqu 0x90(%r15,%r14), %xmm1
    0x7ffff772b75e <+558>: vmovdqu %xmm1, 0x110(%r15,%r14)
    0x7ffff772b768 <+568>: vmovdqu %xmm0, 0x100(%r15,%r14)
    0x7ffff772b772 <+578>: vmovdqu 0x110(%r15,%r14), %xmm3
    0x7ffff772b77c <+588>: vpaddd %xmm0, %xmm3, %xmm3
    0x7ffff772b780 <+592>: vmovdqu %xmm3, 0x30(%r15,%r14)
    0x7ffff772b787 <+599>: movl   $0x1, %edi

** 91                           for (size_t k = 0; k < rowsCols; k++) {

    0x7ffff772b78c <+604>: addl   %edi, 0x2c(%r15,%r14)
    0x7ffff772b791 <+609>: jmp    0x7ffff772b651            ; <+289> at matrix_algorithms.cpp:91:23

** 97                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[i * rowsCols]), sum);
   98                   }
   99           }

    0x7ffff772b796 <+614>: movl   0x44(%r15,%r14), %ecx
    0x7ffff772b79b <+619>: imull  0x4c(%rbx), %ecx
    0x7ffff772b79f <+623>: movq   (%rsp), %rdx
    0x7ffff772b7a3 <+627>: movq   %r13, %rsi
    0x7ffff772b7a6 <+630>: movq   %r13, %rdi
    0x7ffff772b7a9 <+633>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772b7ae <+638>: vmovdqu 0x30(%r15,%r14), %xmm6
    0x7ffff772b7b5 <+645>: movl   %eax, 0x78(%r15,%r14)
    0x7ffff772b7ba <+650>: vmovdqu %xmm6, 0x60(%r15,%r14)
    0x7ffff772b7c1 <+657>: movl   0x78(%rbx), %r8d
    0x7ffff772b7c5 <+661>: vmovdqu %xmm6, (%r15,%r8)
    0x7ffff772b7cb <+667>: movl   $0x4, %r9d

** 88                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x7ffff772b7d1 <+673>: addl   %r9d, 0x40(%r15,%r14)
    0x7ffff772b7d6 <+678>: jmp    0x7ffff772b5f1            ; <+193> at matrix_algorithms.cpp:88:22

** 87           for (size_t i = 0; i < rowsCols; i++) {

    0x7ffff772b7db <+683>: addl   %r12d, 0x44(%r15,%r14)
    0x7ffff772b7e0 <+688>: jmp    0x7ffff772b5d5            ; <+165> at matrix_algorithms.cpp:87:21

   100
** 101          return result;

    0x7ffff772b7e5 <+693>: movb   %r12b, 0x4b(%r15,%r14)

** 102  }

    0x7ffff772b7ea <+698>: movzbq 0x4b(%r15,%r14), %rdi
    0x7ffff772b7f0 <+704>: andl   $0x1, %edi
    0x7ffff772b7f3 <+707>: testl  %edi, %edi
    0x7ffff772b7f5 <+709>: je     0x7ffff772b805            ; <+725> at matrix_algorithms.cpp:102:1
    0x7ffff772b7fb <+715>: movq   0x8(%rsp), %rsi
    0x7ffff772b800 <+720>: jmp    0x7ffff772b819            ; <+745> at matrix_algorithms.cpp:102:1
    0x7ffff772b805 <+725>: movq   (%rsp), %rdx
    0x7ffff772b809 <+729>: movq   %r13, %rsi
    0x7ffff772b80c <+732>: movq   %r13, %rdi
    0x7ffff772b80f <+735>: callq  0x7ffff77256b0            ; std::__2::vector<int, std::__2::allocator<int> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772b814 <+740>: movq   0x8(%rsp), %rsi
    0x7ffff772b819 <+745>: movl   %esi, 0x110(%r13)
    0x7ffff772b820 <+752>: movq   0x10(%rsp), %rbx
    0x7ffff772b825 <+757>: movq   0x18(%rsp), %r12
    0x7ffff772b82a <+762>: movq   0x20(%rsp), %r13
    0x7ffff772b82f <+767>: movq   0x28(%rsp), %r14
    0x7ffff772b834 <+772>: movq   0x30(%rsp), %r15
    0x7ffff772b839 <+777>: addq   $0x40, %rsp
    0x7ffff772b83d <+781>: movq   %rbp, %rsp
    0x7ffff772b840 <+784>: popq   %rbp
    0x7ffff772b841 <+785>: retq
    0x7ffff772b842 <+786>: ud2
    0x7ffff772b844 <+788>: addb   %al, (%rax)
    0x7ffff772b846 <+790>: addb   %al, (%rax)
    0x7ffff772b848 <+792>: addb   %al, (%rax)
    0x7ffff772b84a <+794>: addb   %al, (%rax)
    0x7ffff772b84c <+796>: addb   %al, (%rax)
    0x7ffff772b84e <+798>: addb   %al, (%rax)