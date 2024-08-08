0x7ffff772c330 <+0>:   pushq  %rbp
    0x7ffff772c331 <+1>:   movq   %rsp, %rbp
    0x7ffff772c334 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772c338 <+8>:   movq   (%r10), %r10
    0x7ffff772c33b <+11>:  cmpq   %rsp, %r10
    0x7ffff772c33e <+14>:  ja     0x7ffff772c6b2            ; <+898> at vector_algorithms.cpp:87:5
    0x7ffff772c344 <+20>:  subq   $0x20, %rsp
    0x7ffff772c348 <+24>:  movq   %rbx, (%rsp)
    0x7ffff772c34c <+28>:  movq   %r12, 0x8(%rsp)
    0x7ffff772c351 <+33>:  movq   %r14, 0x10(%rsp)
    0x7ffff772c356 <+38>:  movq   %r15, 0x18(%rsp)
    0x7ffff772c35b <+43>:  movl   0x110(%rdi), %r12d
    0x7ffff772c362 <+50>:  movq   %r12, %r14
    0x7ffff772c365 <+53>:  subl   $0x250, %r14d             ; imm = 0x250
    0x7ffff772c36c <+60>:  movl   %r14d, 0x110(%rdi)
    0x7ffff772c373 <+67>:  movq   0x100(%rdi), %r15
    0x7ffff772c37a <+74>:  leaq   (%r15,%r14), %r8
    0x7ffff772c37e <+78>:  movl   %edx, 0x48(%r15,%r14)
    0x7ffff772c383 <+83>:  movq   %rdi, %rbx
    0x7ffff772c386 <+86>:  movq   %rbx, %rsi
    0x7ffff772c389 <+89>:  movq   %rbx, %rdi

-> 73       size_t size = vec.size();

->  0x7ffff772c38c <+92>:  callq  0x7ffff77290e0            ; std::__2::vector<float, std::__2::allocator<float> >::size[abi:ue170004]() const at vector:604
    0x7ffff772c391 <+97>:  movl   %eax, 0x44(%r15,%r14)

** 74       __m128 sum = _mm_setzero_ps();
   75
   76       // sum of elements

    0x7ffff772c396 <+102>: movl   $0x0, 0x1a8(%r15,%r14)
    0x7ffff772c3a2 <+114>: movl   $0x0, 0x1a4(%r15,%r14)
    0x7ffff772c3ae <+126>: movl   $0x0, 0x1a0(%r15,%r14)
    0x7ffff772c3ba <+138>: movl   $0x0, 0x19c(%r15,%r14)
    0x7ffff772c3c6 <+150>: vmovss 0x1a4(%r15,%r14), %xmm1   ; xmm1 = mem[0],zero,zero,zero
    0x7ffff772c3d0 <+160>: vmovss 0x1a0(%r15,%r14), %xmm2   ; xmm2 = mem[0],zero,zero,zero
    0x7ffff772c3da <+170>: vmovss 0x19c(%r15,%r14), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff772c3e4 <+180>: movl   0x1a8(%r15,%r14), %eax
    0x7ffff772c3ec <+188>: vmovd  %eax, %xmm0
    0x7ffff772c3f0 <+192>: vpbroadcastd %xmm0, %xmm4
    0x7ffff772c3f5 <+197>: vinsertps $0x10, %xmm1, %xmm4, %xmm1 ; xmm1 = xmm4[0],xmm1[0],xmm4[2,3]
    0x7ffff772c3fb <+203>: vinsertps $0x20, %xmm2, %xmm1, %xmm1 ; xmm1 = xmm1[0,1],xmm2[0],xmm1[3]
    0x7ffff772c401 <+209>: vinsertps $0x30, %xmm3, %xmm1, %xmm1 ; xmm1 = xmm1[0,1,2],xmm3[0]
    0x7ffff772c407 <+215>: vmovdqu %xmm1, 0x180(%r15,%r14)
    0x7ffff772c411 <+225>: vmovdqu %xmm1, 0x30(%r15,%r14)

** 77       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c418 <+232>: movl   $0x0, 0x2c(%r15,%r14)
    0x7ffff772c421 <+241>: movl   0x2c(%r15,%r14), %r9d
    0x7ffff772c426 <+246>: movl   0x44(%r15,%r14), %r10d
    0x7ffff772c42b <+251>: cmpl   %r10d, %r9d
    0x7ffff772c42e <+254>: jae    0x7ffff772c4ba            ; <+394> at vector_algorithms.cpp:82:33

** 78           __m128 values = _mm_loadu_ps(&vec[i]);

    0x7ffff772c434 <+260>: movl   0x48(%r15,%r14), %edx
    0x7ffff772c439 <+265>: movl   0x2c(%r15,%r14), %ecx
    0x7ffff772c43e <+270>: movq   %rbx, %rsi
    0x7ffff772c441 <+273>: movq   %rbx, %rdi
    0x7ffff772c444 <+276>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772c449 <+281>: movl   %eax, 0x4c(%r15,%r14)
    0x7ffff772c44e <+286>: movl   %eax, 0x1ac(%r15,%r14)
    0x7ffff772c456 <+294>: movl   %eax, %edi
    0x7ffff772c458 <+296>: vmovdqu (%r15,%rdi), %xmm1
    0x7ffff772c45e <+302>: vmovdqu %xmm1, 0x10(%r15,%r14)

** 79           sum = _mm_add_ps(sum, values);
   80       }
   81

    0x7ffff772c465 <+309>: vmovdqu 0x30(%r15,%r14), %xmm2
    0x7ffff772c46c <+316>: vmovdqu %xmm2, 0x60(%r15,%r14)
    0x7ffff772c473 <+323>: vmovdqu %xmm1, 0x50(%r15,%r14)
    0x7ffff772c47a <+330>: vmovdqu 0x60(%r15,%r14), %xmm4
    0x7ffff772c481 <+337>: vmovdqu %xmm4, 0x200(%r15,%r14)
    0x7ffff772c48b <+347>: vmovdqu %xmm1, 0x1f0(%r15,%r14)
    0x7ffff772c495 <+357>: vmovdqu 0x200(%r15,%r14), %xmm6
    0x7ffff772c49f <+367>: vaddps %xmm1, %xmm6, %xmm6
    0x7ffff772c4a3 <+371>: vmovdqu %xmm6, 0x30(%r15,%r14)
    0x7ffff772c4aa <+378>: movl   $0x4, %r10d

** 77       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c4b0 <+384>: addl   %r10d, 0x2c(%r15,%r14)
    0x7ffff772c4b5 <+389>: jmp    0x7ffff772c421            ; <+241> at vector_algorithms.cpp:77:24

** 82       __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));
   83

    0x7ffff772c4ba <+394>: vmovdqu 0x30(%r15,%r14), %xmm1
    0x7ffff772c4c1 <+401>: movl   0x44(%r15,%r14), %esi
    0x7ffff772c4c6 <+406>: vxorps %xmm6, %xmm6, %xmm0
    0x7ffff772c4ca <+410>: movl   %esi, %edi
    0x7ffff772c4cc <+412>: vcvtsi2ss %rdi, %xmm0, %xmm4
    0x7ffff772c4d1 <+417>: vmovss %xmm4, 0x15c(%r15,%r14)
    0x7ffff772c4db <+427>: vmovss %xmm4, 0x24c(%r15,%r14)
    0x7ffff772c4e5 <+437>: movl   0x24c(%r15,%r14), %eax
    0x7ffff772c4ed <+445>: vmovd  %eax, %xmm2
    0x7ffff772c4f1 <+449>: vpbroadcastd %xmm2, %xmm4
    0x7ffff772c4f6 <+454>: vmovdqu %xmm4, 0x230(%r15,%r14)
    0x7ffff772c500 <+464>: vmovdqu %xmm1, 0x140(%r15,%r14)
    0x7ffff772c50a <+474>: vmovdqu %xmm4, 0x130(%r15,%r14)
    0x7ffff772c514 <+484>: vmovdqu 0x140(%r15,%r14), %xmm6
    0x7ffff772c51e <+494>: vmovdqu %xmm6, 0x220(%r15,%r14)
    0x7ffff772c528 <+504>: vmovdqu %xmm4, 0x210(%r15,%r14)
    0x7ffff772c532 <+514>: vmovdqu 0x220(%r15,%r14), %xmm0
    0x7ffff772c53c <+524>: vdivps %xmm4, %xmm0, %xmm0
    0x7ffff772c540 <+528>: vmovdqu %xmm0, (%r15,%r14)

** 84       sum = _mm_hadd_ps(divided, divided);

    0x7ffff772c546 <+534>: vmovdqu %xmm0, 0x100(%r15,%r14)
    0x7ffff772c550 <+544>: vmovdqu %xmm0, 0xf0(%r15,%r14)
    0x7ffff772c55a <+554>: vmovdqu 0x100(%r15,%r14), %xmm3
    0x7ffff772c564 <+564>: vshufps $0x88, %xmm0, %xmm3, %xmm3 ; xmm3 = xmm3[0,2],xmm0[0,2]
    0x7ffff772c569 <+569>: vmovdqu %xmm3, 0xe0(%r15,%r14)
    0x7ffff772c573 <+579>: vmovdqu 0x100(%r15,%r14), %xmm4
    0x7ffff772c57d <+589>: vmovdqu 0xf0(%r15,%r14), %xmm5
    0x7ffff772c587 <+599>: vshufps $0xdd, %xmm5, %xmm4, %xmm4 ; xmm4 = xmm4[1,3],xmm5[1,3]
    0x7ffff772c58c <+604>: vmovdqu %xmm4, 0xd0(%r15,%r14)
    0x7ffff772c596 <+614>: vmovdqu %xmm3, 0x120(%r15,%r14)
    0x7ffff772c5a0 <+624>: vmovdqu %xmm4, 0x110(%r15,%r14)
    0x7ffff772c5aa <+634>: vmovdqu 0x120(%r15,%r14), %xmm7
    0x7ffff772c5b4 <+644>: vmovdqu %xmm7, 0x1c0(%r15,%r14)
    0x7ffff772c5be <+654>: vmovdqu %xmm4, 0x1b0(%r15,%r14)
    0x7ffff772c5c8 <+664>: vmovdqu 0x1c0(%r15,%r14), %xmm1
    0x7ffff772c5d2 <+674>: vaddps %xmm4, %xmm1, %xmm1
    0x7ffff772c5d6 <+678>: vmovdqu %xmm1, 0x30(%r15,%r14)

** 85       sum = _mm_hadd_ps(sum, sum);
   86

    0x7ffff772c5dd <+685>: vmovdqu %xmm1, 0xa0(%r15,%r14)
    0x7ffff772c5e7 <+695>: vmovdqu %xmm1, 0x90(%r15,%r14)
    0x7ffff772c5f1 <+705>: vmovdqu 0xa0(%r15,%r14), %xmm4
    0x7ffff772c5fb <+715>: vshufps $0x88, %xmm1, %xmm4, %xmm4 ; xmm4 = xmm4[0,2],xmm1[0,2]
    0x7ffff772c600 <+720>: vmovdqu %xmm4, 0x80(%r15,%r14)
    0x7ffff772c60a <+730>: vmovdqu 0xa0(%r15,%r14), %xmm5
    0x7ffff772c614 <+740>: vmovdqu 0x90(%r15,%r14), %xmm6
    0x7ffff772c61e <+750>: vshufps $0xdd, %xmm6, %xmm5, %xmm5 ; xmm5 = xmm5[1,3],xmm6[1,3]
    0x7ffff772c623 <+755>: vmovdqu %xmm5, 0x70(%r15,%r14)
    0x7ffff772c62a <+762>: vmovdqu %xmm4, 0xc0(%r15,%r14)
    0x7ffff772c634 <+772>: vmovdqu %xmm5, 0xb0(%r15,%r14)
    0x7ffff772c63e <+782>: vmovdqu 0xc0(%r15,%r14), %xmm0
    0x7ffff772c648 <+792>: vmovdqu %xmm0, 0x1e0(%r15,%r14)
    0x7ffff772c652 <+802>: vmovdqu %xmm5, 0x1d0(%r15,%r14)
    0x7ffff772c65c <+812>: vmovdqu 0x1e0(%r15,%r14), %xmm2
    0x7ffff772c666 <+822>: vaddps %xmm5, %xmm2, %xmm2
    0x7ffff772c66a <+826>: vmovdqu %xmm2, 0x30(%r15,%r14)

** 87       return _mm_cvtss_f32(sum);
   88   }
   89

    0x7ffff772c671 <+833>: vmovdqu %xmm2, 0x170(%r15,%r14)
    0x7ffff772c67b <+843>: vmovdqu %xmm2, 0x160(%r15,%r14)
    0x7ffff772c685 <+853>: vmovss 0x160(%r15,%r14), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff772c68f <+863>: movl   %r12d, 0x110(%rbx)
    0x7ffff772c696 <+870>: movq   (%rsp), %rbx
    0x7ffff772c69a <+874>: movq   0x8(%rsp), %r12
    0x7ffff772c69f <+879>: movq   0x10(%rsp), %r14
    0x7ffff772c6a4 <+884>: movq   0x18(%rsp), %r15
    0x7ffff772c6a9 <+889>: addq   $0x20, %rsp
    0x7ffff772c6ad <+893>: movq   %rbp, %rsp
    0x7ffff772c6b0 <+896>: popq   %rbp
    0x7ffff772c6b1 <+897>: retq
    0x7ffff772c6b2 <+898>: ud2