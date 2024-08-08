0x7ffff772b1c0 <+0>:   pushq  %rbp
    0x7ffff772b1c1 <+1>:   movq   %rsp, %rbp
    0x7ffff772b1c4 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772b1c8 <+8>:   movq   (%r10), %r10
    0x7ffff772b1cb <+11>:  addq   $0x10, %r10
    0x7ffff772b1cf <+15>:  cmpq   %rsp, %r10
    0x7ffff772b1d2 <+18>:  ja     0x7ffff772b529            ; <+873> at matrix_algorithms.cpp:81:1
    0x7ffff772b1d8 <+24>:  subq   $0x40, %rsp
    0x7ffff772b1dc <+28>:  movq   %rbx, 0x10(%rsp)
    0x7ffff772b1e1 <+33>:  movq   %r12, 0x18(%rsp)
    0x7ffff772b1e6 <+38>:  movq   %r13, 0x20(%rsp)
    0x7ffff772b1eb <+43>:  movq   %r14, 0x28(%rsp)
    0x7ffff772b1f0 <+48>:  movq   %r15, 0x30(%rsp)
    0x7ffff772b1f5 <+53>:  movl   0x110(%rdi), %r10d
    0x7ffff772b1fc <+60>:  movq   %r10, %rbx
    0x7ffff772b1ff <+63>:  subl   $0x150, %ebx              ; imm = 0x150
    0x7ffff772b205 <+69>:  movq   %r10, 0x8(%rsp)
    0x7ffff772b20a <+74>:  movl   %ebx, 0x110(%rdi)
    0x7ffff772b210 <+80>:  movq   0x100(%rdi), %r12
    0x7ffff772b217 <+87>:  leaq   (%r12,%rbx), %r13
    0x7ffff772b21b <+91>:  movl   %edx, 0x58(%r12,%rbx)
    0x7ffff772b220 <+96>:  movq   %rdx, (%rsp)
    0x7ffff772b224 <+100>: movl   %ecx, 0x54(%r12,%rbx)
    0x7ffff772b229 <+105>: movl   %r8d, 0x50(%r12,%rbx)
    0x7ffff772b22e <+110>: movl   %r9d, 0x4c(%r12,%rbx)

-> 64           std::vector<float> result(rowsCols * rowsCols);
-> 65

->  0x7ffff772b233 <+115>: xorl   %ecx, %ecx
    0x7ffff772b235 <+117>: movb   %cl, 0x4b(%r12,%rbx)
    0x7ffff772b23a <+122>: movl   0x4c(%r12,%rbx), %ecx
    0x7ffff772b23f <+127>: imull  %ecx, %ecx
    0x7ffff772b242 <+130>: movq   %rdi, %r15
    0x7ffff772b245 <+133>: movq   (%rsp), %rdx
    0x7ffff772b249 <+137>: movq   %r15, %rsi
    0x7ffff772b24c <+140>: movq   %r15, %rdi
    0x7ffff772b24f <+143>: callq  0x7ffff772a870            ; std::__2::vector<float, std::__2::allocator<float> >::vector at vector:1191

** 66           for (size_t i = 0; i < rowsCols; i++) {

    0x7ffff772b254 <+148>: movl   $0x0, 0x44(%r12,%rbx)
    0x7ffff772b25d <+157>: movl   $0x1, %r14d
    0x7ffff772b263 <+163>: movl   0x44(%r12,%rbx), %r9d
    0x7ffff772b268 <+168>: movl   0x4c(%r12,%rbx), %r10d
    0x7ffff772b26d <+173>: cmpl   %r10d, %r9d
    0x7ffff772b270 <+176>: jae    0x7ffff772b4cc            ; <+780> at matrix_algorithms.cpp:80:2

** 67                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x7ffff772b276 <+182>: movl   $0x0, 0x40(%r12,%rbx)
    0x7ffff772b27f <+191>: movl   0x40(%r12,%rbx), %edi
    0x7ffff772b284 <+196>: movl   0x4c(%r12,%rbx), %eax
    0x7ffff772b289 <+201>: cmpl   %eax, %edi
    0x7ffff772b28b <+203>: jae    0x7ffff772b4c2            ; <+770> at matrix_algorithms.cpp:66:36

** 68                           __m128 sum = _mm_setzero_ps();
   69

    0x7ffff772b291 <+209>: movl   $0x0, 0xec(%r12,%rbx)
    0x7ffff772b29d <+221>: movl   $0x0, 0xe8(%r12,%rbx)
    0x7ffff772b2a9 <+233>: movl   $0x0, 0xe4(%r12,%rbx)
    0x7ffff772b2b5 <+245>: movl   $0x0, 0xe0(%r12,%rbx)
    0x7ffff772b2c1 <+257>: vmovss 0xe8(%r12,%rbx), %xmm0    ; xmm0 = mem[0],zero,zero,zero
    0x7ffff772b2cb <+267>: vmovss 0xe4(%r12,%rbx), %xmm1    ; xmm1 = mem[0],zero,zero,zero
    0x7ffff772b2d5 <+277>: vmovss 0xe0(%r12,%rbx), %xmm2    ; xmm2 = mem[0],zero,zero,zero
    0x7ffff772b2df <+287>: movl   0xec(%r12,%rbx), %r10d
    0x7ffff772b2e7 <+295>: vmovd  %r10d, %xmm7
    0x7ffff772b2ec <+300>: vpbroadcastd %xmm7, %xmm3
    0x7ffff772b2f1 <+305>: vinsertps $0x10, %xmm0, %xmm3, %xmm0 ; xmm0 = xmm3[0],xmm0[0],xmm3[2,3]
    0x7ffff772b2f7 <+311>: vinsertps $0x20, %xmm1, %xmm0, %xmm0 ; xmm0 = xmm0[0,1],xmm1[0],xmm0[3]
    0x7ffff772b2fd <+317>: vinsertps $0x30, %xmm2, %xmm0, %xmm0 ; xmm0 = xmm0[0,1,2],xmm2[0]
    0x7ffff772b303 <+323>: vmovdqu %xmm0, 0xd0(%r12,%rbx)
    0x7ffff772b30d <+333>: vmovdqu %xmm0, 0x30(%r12,%rbx)

** 70                           for (size_t k = 0; k < rowsCols; k++) {

    0x7ffff772b314 <+340>: movl   $0x0, 0x2c(%r12,%rbx)
    0x7ffff772b31d <+349>: movl   0x2c(%r12,%rbx), %eax
    0x7ffff772b322 <+354>: movl   0x4c(%r12,%rbx), %ecx
    0x7ffff772b327 <+359>: cmpl   %ecx, %eax
    0x7ffff772b329 <+361>: jae    0x7ffff772b478            ; <+696> at matrix_algorithms.cpp:76:26

** 71                                   __m128 a = _mm_set1_ps(A[i * rowsCols + k]);

    0x7ffff772b32f <+367>: movl   0x54(%r12,%rbx), %edx
    0x7ffff772b334 <+372>: movl   0x44(%r12,%rbx), %edi
    0x7ffff772b339 <+377>: movl   0x4c(%r12,%rbx), %r8d
    0x7ffff772b33e <+382>: movl   0x2c(%r12,%rbx), %r9d
    0x7ffff772b343 <+387>: imull  %r8d, %edi
    0x7ffff772b347 <+391>: leal   (%rdi,%r9), %ecx
    0x7ffff772b34b <+395>: movq   %r15, %rsi
    0x7ffff772b34e <+398>: movq   %r15, %rdi
    0x7ffff772b351 <+401>: callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772b356 <+406>: movl   %eax, %edx
    0x7ffff772b358 <+408>: vmovss (%r12,%rdx), %xmm6        ; xmm6 = mem[0],zero,zero,zero
    0x7ffff772b35e <+414>: vmovss %xmm6, 0x7c(%r12,%rbx)
    0x7ffff772b365 <+421>: vmovss %xmm6, 0x10c(%r12,%rbx)
    0x7ffff772b36f <+431>: movl   0x10c(%r12,%rbx), %r9d
    0x7ffff772b377 <+439>: vmovd  %r9d, %xmm7
    0x7ffff772b37c <+444>: vpbroadcastd %xmm7, %xmm1
    0x7ffff772b381 <+449>: vmovdqu %xmm1, 0xf0(%r12,%rbx)
    0x7ffff772b38b <+459>: vmovdqu %xmm1, 0x10(%r12,%rbx)

** 72                                   __m128 b = _mm_loadu_ps(&B[k * rowsCols + j]);

    0x7ffff772b392 <+466>: movl   0x50(%r12,%rbx), %edx
    0x7ffff772b397 <+471>: movl   0x2c(%r12,%rbx), %r8d
    0x7ffff772b39c <+476>: movl   0x4c(%r12,%rbx), %r11d
    0x7ffff772b3a1 <+481>: movl   0x40(%r12,%rbx), %esi
    0x7ffff772b3a6 <+486>: imull  %r11d, %r8d
    0x7ffff772b3aa <+490>: leal   (%r8,%rsi), %ecx
    0x7ffff772b3ae <+494>: movq   %r15, %rsi
    0x7ffff772b3b1 <+497>: movq   %r15, %rdi
    0x7ffff772b3b4 <+500>: callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772b3b9 <+505>: movl   %eax, 0x5c(%r12,%rbx)
    0x7ffff772b3be <+510>: movl   %eax, 0xcc(%r12,%rbx)
    0x7ffff772b3c6 <+518>: movl   %eax, %edi
    0x7ffff772b3c8 <+520>: vmovdqu (%r12,%rdi), %xmm4
    0x7ffff772b3ce <+526>: vmovdqu %xmm4, (%r12,%rbx)

** 73                                   sum = _mm_add_ps(sum, _mm_mul_ps(a, b));
   74                           }
   75

    0x7ffff772b3d4 <+532>: vmovdqu 0x30(%r12,%rbx), %xmm5
    0x7ffff772b3db <+539>: vmovdqu 0x10(%r12,%rbx), %xmm6
    0x7ffff772b3e2 <+546>: vmovdqu %xmm6, 0xb0(%r12,%rbx)
    0x7ffff772b3ec <+556>: vmovdqu %xmm4, 0xa0(%r12,%rbx)
    0x7ffff772b3f6 <+566>: vmovdqu 0xb0(%r12,%rbx), %xmm7
    0x7ffff772b400 <+576>: vmovdqu %xmm7, 0x140(%r12,%rbx)
    0x7ffff772b40a <+586>: vmovdqu %xmm4, 0x130(%r12,%rbx)
    0x7ffff772b414 <+596>: vmovdqu 0x140(%r12,%rbx), %xmm1
    0x7ffff772b41e <+606>: vmovdqu %xmm5, 0x90(%r12,%rbx)
    0x7ffff772b428 <+616>: vmulps %xmm4, %xmm1, %xmm2
    0x7ffff772b42c <+620>: vmovdqu %xmm2, 0x80(%r12,%rbx)
    0x7ffff772b436 <+630>: vmovdqu 0x90(%r12,%rbx), %xmm3
    0x7ffff772b440 <+640>: vmovdqu %xmm3, 0x120(%r12,%rbx)
    0x7ffff772b44a <+650>: vmovdqu %xmm2, 0x110(%r12,%rbx)
    0x7ffff772b454 <+660>: vmovdqu 0x120(%r12,%rbx), %xmm5
    0x7ffff772b45e <+670>: vaddps %xmm2, %xmm5, %xmm5
    0x7ffff772b462 <+674>: vmovdqu %xmm5, 0x30(%r12,%rbx)
    0x7ffff772b469 <+681>: movl   $0x1, %eax

** 70                           for (size_t k = 0; k < rowsCols; k++) {

    0x7ffff772b46e <+686>: addl   %eax, 0x2c(%r12,%rbx)
    0x7ffff772b473 <+691>: jmp    0x7ffff772b31d            ; <+349> at matrix_algorithms.cpp:70:23

** 76                           _mm_storeu_ps(&result[i * rowsCols + j], sum);
   77                   }
   78           }

    0x7ffff772b478 <+696>: movl   0x44(%r12,%rbx), %ecx
    0x7ffff772b47d <+701>: imull  0x4c(%r13), %ecx
    0x7ffff772b482 <+706>: addl   0x40(%r13), %ecx
    0x7ffff772b486 <+710>: movq   (%rsp), %rdx
    0x7ffff772b48a <+714>: movq   %r15, %rsi
    0x7ffff772b48d <+717>: movq   %r15, %rdi
    0x7ffff772b490 <+720>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772b495 <+725>: vmovdqu 0x30(%r12,%rbx), %xmm0
    0x7ffff772b49c <+732>: movl   %eax, 0x78(%r12,%rbx)
    0x7ffff772b4a1 <+737>: vmovdqu %xmm0, 0x60(%r12,%rbx)
    0x7ffff772b4a8 <+744>: movl   0x78(%r13), %r9d
    0x7ffff772b4ac <+748>: vmovdqu %xmm0, (%r12,%r9)
    0x7ffff772b4b2 <+754>: movl   $0x4, %r10d

** 67                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x7ffff772b4b8 <+760>: addl   %r10d, 0x40(%r12,%rbx)
    0x7ffff772b4bd <+765>: jmp    0x7ffff772b27f            ; <+191> at matrix_algorithms.cpp:67:22

** 66           for (size_t i = 0; i < rowsCols; i++) {

    0x7ffff772b4c2 <+770>: addl   %r14d, 0x44(%r12,%rbx)
    0x7ffff772b4c7 <+775>: jmp    0x7ffff772b263            ; <+163> at matrix_algorithms.cpp:66:21

   79
** 80           return result;

    0x7ffff772b4cc <+780>: movb   %r14b, 0x4b(%r12,%rbx)

** 81   }
   82
   83   // code lines: 85, 87, 88, 89, 91, 92, 93, 94, 95, 97, 101

    0x7ffff772b4d1 <+785>: movzbq 0x4b(%r12,%rbx), %rax
    0x7ffff772b4d7 <+791>: andl   $0x1, %eax
    0x7ffff772b4da <+794>: testl  %eax, %eax
    0x7ffff772b4dc <+796>: je     0x7ffff772b4ec            ; <+812> at matrix_algorithms.cpp:81:1
    0x7ffff772b4e2 <+802>: movq   0x8(%rsp), %r10
    0x7ffff772b4e7 <+807>: jmp    0x7ffff772b500            ; <+832> at matrix_algorithms.cpp:81:1
    0x7ffff772b4ec <+812>: movq   (%rsp), %rdx
    0x7ffff772b4f0 <+816>: movq   %r15, %rsi
    0x7ffff772b4f3 <+819>: movq   %r15, %rdi
    0x7ffff772b4f6 <+822>: callq  0x7ffff7725760            ; std::__2::vector<float, std::__2::allocator<float> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772b4fb <+827>: movq   0x8(%rsp), %r10
    0x7ffff772b500 <+832>: movl   %r10d, 0x110(%r15)
    0x7ffff772b507 <+839>: movq   0x10(%rsp), %rbx
    0x7ffff772b50c <+844>: movq   0x18(%rsp), %r12
    0x7ffff772b511 <+849>: movq   0x20(%rsp), %r13
    0x7ffff772b516 <+854>: movq   0x28(%rsp), %r14
    0x7ffff772b51b <+859>: movq   0x30(%rsp), %r15
    0x7ffff772b520 <+864>: addq   $0x40, %rsp
    0x7ffff772b524 <+868>: movq   %rbp, %rsp
    0x7ffff772b527 <+871>: popq   %rbp
    0x7ffff772b528 <+872>: retq
    0x7ffff772b529 <+873>: ud2