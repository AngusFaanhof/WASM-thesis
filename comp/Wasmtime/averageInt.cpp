0x7ffff772c6c0 <+0>:   pushq  %rbp
    0x7ffff772c6c1 <+1>:   movq   %rsp, %rbp
    0x7ffff772c6c4 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772c6c8 <+8>:   movq   (%r10), %r10
    0x7ffff772c6cb <+11>:  cmpq   %rsp, %r10
    0x7ffff772c6ce <+14>:  ja     0x7ffff772ca28            ; <+872> at vector_algorithms.cpp:108:5
    0x7ffff772c6d4 <+20>:  subq   $0x20, %rsp
    0x7ffff772c6d8 <+24>:  movq   %rbx, (%rsp)
    0x7ffff772c6dc <+28>:  movq   %r12, 0x8(%rsp)
    0x7ffff772c6e1 <+33>:  movq   %r13, 0x10(%rsp)
    0x7ffff772c6e6 <+38>:  movq   %r15, 0x18(%rsp)
    0x7ffff772c6eb <+43>:  movl   0x110(%rdi), %r13d
    0x7ffff772c6f2 <+50>:  movq   %r13, %r15
    0x7ffff772c6f5 <+53>:  subl   $0x280, %r15d             ; imm = 0x280
    0x7ffff772c6fc <+60>:  movl   %r15d, 0x110(%rdi)
    0x7ffff772c703 <+67>:  movq   0x100(%rdi), %rbx
    0x7ffff772c70a <+74>:  movq   %rdi, %rax
    0x7ffff772c70d <+77>:  leaq   (%rbx,%r15), %rdi
    0x7ffff772c711 <+81>:  movl   %edx, 0x5c(%rbx,%r15)
    0x7ffff772c716 <+86>:  movq   %rax, %r12
    0x7ffff772c719 <+89>:  movq   %r12, %rsi
    0x7ffff772c71c <+92>:  movq   %r12, %rdi

-> 91       size_t size = vec.size();

->  0x7ffff772c71f <+95>:  callq  0x7ffff7727af0            ; std::__2::vector<int, std::__2::allocator<int> >::size[abi:ue170004]() const at vector:604
    0x7ffff772c724 <+100>: movl   %eax, 0x58(%rbx,%r15)

** 92       __m128i sum_int = _mm_setzero_si128();
   93
   94       // sum of elements

    0x7ffff772c729 <+105>: movq   $0x0, 0x228(%rbx,%r15)
    0x7ffff772c735 <+117>: movq   $0x0, 0x220(%rbx,%r15)
    0x7ffff772c741 <+129>: movq   0x228(%rbx,%r15), %r8
    0x7ffff772c749 <+137>: vmovq  %r8, %xmm2
    0x7ffff772c74e <+142>: vpshufd $0x44, %xmm2, %xmm4       ; xmm4 = xmm2[0,1,0,1]
    0x7ffff772c753 <+147>: vpinsrq $0x1, 0x2d3(%rip), %xmm4, %xmm3 ; <+879> at vector_algorithms.cpp:108:5
    0x7ffff772c75d <+157>: vmovdqu %xmm3, 0x210(%rbx,%r15)
    0x7ffff772c767 <+167>: vmovdqu %xmm3, 0x40(%rbx,%r15)

** 95       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c76e <+174>: movl   $0x0, 0x3c(%rbx,%r15)
    0x7ffff772c777 <+183>: movl   0x3c(%rbx,%r15), %esi
    0x7ffff772c77c <+188>: movl   0x58(%rbx,%r15), %edi
    0x7ffff772c781 <+193>: cmpl   %edi, %esi
    0x7ffff772c783 <+195>: jae    0x7ffff772c811            ; <+337> at vector_algorithms.cpp:101:34

** 96           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x7ffff772c789 <+201>: movl   0x5c(%rbx,%r15), %edx
    0x7ffff772c78e <+206>: movl   0x3c(%rbx,%r15), %ecx
    0x7ffff772c793 <+211>: movq   %r12, %rsi
    0x7ffff772c796 <+214>: movq   %r12, %rdi
    0x7ffff772c799 <+217>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772c79e <+222>: movl   %eax, 0x12c(%rbx,%r15)
    0x7ffff772c7a6 <+230>: movl   %eax, %ecx
    0x7ffff772c7a8 <+232>: vmovdqu (%rbx,%rcx), %xmm2
    0x7ffff772c7ad <+237>: vmovdqu %xmm2, 0x20(%rbx,%r15)

** 97           sum_int = _mm_add_epi32(sum_int, values);
   98       }
   99

    0x7ffff772c7b4 <+244>: vmovdqu 0x40(%rbx,%r15), %xmm3
    0x7ffff772c7bb <+251>: vmovdqu %xmm3, 0x140(%rbx,%r15)
    0x7ffff772c7c5 <+261>: vmovdqu %xmm2, 0x130(%rbx,%r15)
    0x7ffff772c7cf <+271>: vmovdqu 0x140(%rbx,%r15), %xmm5
    0x7ffff772c7d9 <+281>: vmovdqu %xmm5, 0x240(%rbx,%r15)
    0x7ffff772c7e3 <+291>: vmovdqu %xmm2, 0x230(%rbx,%r15)
    0x7ffff772c7ed <+301>: vmovdqu 0x240(%rbx,%r15), %xmm7
    0x7ffff772c7f7 <+311>: vpaddd %xmm2, %xmm7, %xmm7
    0x7ffff772c7fb <+315>: vmovdqu %xmm7, 0x40(%rbx,%r15)
    0x7ffff772c802 <+322>: movl   $0x4, %esi

** 95       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c807 <+327>: addl   %esi, 0x3c(%rbx,%r15)
    0x7ffff772c80c <+332>: jmp    0x7ffff772c777            ; <+183> at vector_algorithms.cpp:95:24

   100      // convert to float
** 101      __m128 sum = _mm_cvtepi32_ps(sum_int);
   102

    0x7ffff772c811 <+337>: vmovdqu 0x40(%rbx,%r15), %xmm2
    0x7ffff772c818 <+344>: vmovdqu %xmm2, 0x150(%rbx,%r15)
    0x7ffff772c822 <+354>: vmovdqu %xmm2, 0x250(%rbx,%r15)
    0x7ffff772c82c <+364>: vcvtdq2ps %xmm2, %xmm4
    0x7ffff772c830 <+368>: vmovdqu %xmm4, 0x10(%rbx,%r15)

** 103      __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));
   104

    0x7ffff772c837 <+375>: movl   0x58(%rbx,%r15), %r8d
    0x7ffff772c83c <+380>: vxorps %xmm2, %xmm2, %xmm5
    0x7ffff772c840 <+384>: movl   %r8d, %r9d
    0x7ffff772c843 <+387>: vcvtsi2ss %r9, %xmm5, %xmm0
    0x7ffff772c848 <+392>: vmovss %xmm0, 0x18c(%rbx,%r15)
    0x7ffff772c852 <+402>: vmovss %xmm0, 0x27c(%rbx,%r15)
    0x7ffff772c85c <+412>: movl   0x27c(%rbx,%r15), %r10d
    0x7ffff772c864 <+420>: vmovd  %r10d, %xmm6
    0x7ffff772c869 <+425>: vpbroadcastd %xmm6, %xmm0
    0x7ffff772c86e <+430>: vmovdqu %xmm0, 0x260(%rbx,%r15)
    0x7ffff772c878 <+440>: vmovdqu %xmm4, 0x170(%rbx,%r15)
    0x7ffff772c882 <+450>: vmovdqu %xmm0, 0x160(%rbx,%r15)
    0x7ffff772c88c <+460>: vmovdqu 0x170(%rbx,%r15), %xmm2
    0x7ffff772c896 <+470>: vmovdqu %xmm2, 0x200(%rbx,%r15)
    0x7ffff772c8a0 <+480>: vmovdqu %xmm0, 0x1f0(%rbx,%r15)
    0x7ffff772c8aa <+490>: vmovdqu 0x200(%rbx,%r15), %xmm4
    0x7ffff772c8b4 <+500>: vdivps %xmm0, %xmm4, %xmm4
    0x7ffff772c8b8 <+504>: vmovdqu %xmm4, (%rbx,%r15)

** 105      sum = _mm_hadd_ps(divided, divided);

    0x7ffff772c8be <+510>: vmovdqu %xmm4, 0xf0(%rbx,%r15)
    0x7ffff772c8c8 <+520>: vmovdqu %xmm4, 0xe0(%rbx,%r15)
    0x7ffff772c8d2 <+530>: vmovdqu 0xf0(%rbx,%r15), %xmm7
    0x7ffff772c8dc <+540>: vshufps $0x88, %xmm4, %xmm7, %xmm7 ; xmm7 = xmm7[0,2],xmm4[0,2]
    0x7ffff772c8e1 <+545>: vmovdqu %xmm7, 0xd0(%rbx,%r15)
    0x7ffff772c8eb <+555>: vmovdqu 0xf0(%rbx,%r15), %xmm0
    0x7ffff772c8f5 <+565>: vmovdqu 0xe0(%rbx,%r15), %xmm1
    0x7ffff772c8ff <+575>: vshufps $0xdd, %xmm1, %xmm0, %xmm0 ; xmm0 = xmm0[1,3],xmm1[1,3]
    0x7ffff772c904 <+580>: vmovdqu %xmm0, 0xc0(%rbx,%r15)
    0x7ffff772c90e <+590>: vmovdqu %xmm7, 0x110(%rbx,%r15)
    0x7ffff772c918 <+600>: vmovdqu %xmm0, 0x100(%rbx,%r15)
    0x7ffff772c922 <+610>: vmovdqu 0x110(%rbx,%r15), %xmm3
    0x7ffff772c92c <+620>: vmovdqu %xmm3, 0x1c0(%rbx,%r15)
    0x7ffff772c936 <+630>: vmovdqu %xmm0, 0x1b0(%rbx,%r15)
    0x7ffff772c940 <+640>: vmovdqu 0x1c0(%rbx,%r15), %xmm5
    0x7ffff772c94a <+650>: vaddps %xmm0, %xmm5, %xmm5
    0x7ffff772c94e <+654>: vmovdqu %xmm5, 0x10(%rbx,%r15)

** 106      sum = _mm_hadd_ps(sum, sum);
   107

    0x7ffff772c955 <+661>: vmovdqu %xmm5, 0x90(%rbx,%r15)
    0x7ffff772c95f <+671>: vmovdqu %xmm5, 0x80(%rbx,%r15)
    0x7ffff772c969 <+681>: vmovdqu 0x90(%rbx,%r15), %xmm0
    0x7ffff772c973 <+691>: vshufps $0x88, %xmm5, %xmm0, %xmm0 ; xmm0 = xmm0[0,2],xmm5[0,2]
    0x7ffff772c978 <+696>: vmovdqu %xmm0, 0x70(%rbx,%r15)
    0x7ffff772c97f <+703>: vmovdqu 0x90(%rbx,%r15), %xmm1
    0x7ffff772c989 <+713>: vmovdqu 0x80(%rbx,%r15), %xmm2
    0x7ffff772c993 <+723>: vshufps $0xdd, %xmm2, %xmm1, %xmm1 ; xmm1 = xmm1[1,3],xmm2[1,3]
    0x7ffff772c998 <+728>: vmovdqu %xmm1, 0x60(%rbx,%r15)
    0x7ffff772c99f <+735>: vmovdqu %xmm0, 0xb0(%rbx,%r15)
    0x7ffff772c9a9 <+745>: vmovdqu %xmm1, 0xa0(%rbx,%r15)
    0x7ffff772c9b3 <+755>: vmovdqu 0xb0(%rbx,%r15), %xmm4
    0x7ffff772c9bd <+765>: vmovdqu %xmm4, 0x1e0(%rbx,%r15)
    0x7ffff772c9c7 <+775>: vmovdqu %xmm1, 0x1d0(%rbx,%r15)
    0x7ffff772c9d1 <+785>: vmovdqu 0x1e0(%rbx,%r15), %xmm6
    0x7ffff772c9db <+795>: vaddps %xmm1, %xmm6, %xmm6
    0x7ffff772c9df <+799>: vmovdqu %xmm6, 0x10(%rbx,%r15)

** 108      return _mm_cvtss_f32(sum);
   109  }
   110

    0x7ffff772c9e6 <+806>: vmovdqu %xmm6, 0x1a0(%rbx,%r15)
    0x7ffff772c9f0 <+816>: vmovdqu %xmm6, 0x190(%rbx,%r15)
    0x7ffff772c9fa <+826>: vmovss 0x190(%rbx,%r15), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff772ca04 <+836>: movl   %r13d, 0x110(%r12)
    0x7ffff772ca0c <+844>: movq   (%rsp), %rbx
    0x7ffff772ca10 <+848>: movq   0x8(%rsp), %r12
    0x7ffff772ca15 <+853>: movq   0x10(%rsp), %r13
    0x7ffff772ca1a <+858>: movq   0x18(%rsp), %r15
    0x7ffff772ca1f <+863>: addq   $0x20, %rsp
    0x7ffff772ca23 <+867>: movq   %rbp, %rsp
    0x7ffff772ca26 <+870>: popq   %rbp
    0x7ffff772ca27 <+871>: retq
    0x7ffff772ca28 <+872>: ud2
    0x7ffff772ca2a <+874>: addb   %al, (%rax)
    0x7ffff772ca2c <+876>: addb   %al, (%rax)
    0x7ffff772ca2e <+878>: addb   %al, (%rax)
    0x7ffff772ca30 <+880>: addb   %al, (%rax)
    0x7ffff772ca32 <+882>: addb   %al, (%rax)
    0x7ffff772ca34 <+884>: addb   %al, (%rax)
    0x7ffff772ca36 <+886>: addb   %al, (%rax)