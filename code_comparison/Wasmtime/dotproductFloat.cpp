0x7ffff772ca40 <+0>:   pushq  %rbp
    0x7ffff772ca41 <+1>:   movq   %rsp, %rbp
    0x7ffff772ca44 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772ca48 <+8>:   movq   (%r10), %r10
    0x7ffff772ca4b <+11>:  cmpq   %rsp, %r10
    0x7ffff772ca4e <+14>:  ja     0x7ffff772cdce            ; <+910> at vector_algorithms.cpp:127:5
    0x7ffff772ca54 <+20>:  subq   $0x20, %rsp
    0x7ffff772ca58 <+24>:  movq   %rbx, (%rsp)
    0x7ffff772ca5c <+28>:  movq   %r13, 0x8(%rsp)
    0x7ffff772ca61 <+33>:  movq   %r14, 0x10(%rsp)
    0x7ffff772ca66 <+38>:  movq   %r15, 0x18(%rsp)
    0x7ffff772ca6b <+43>:  movl   0x110(%rdi), %ebx
    0x7ffff772ca71 <+49>:  movq   %rbx, %r14
    0x7ffff772ca74 <+52>:  subl   $0x240, %r14d             ; imm = 0x240
    0x7ffff772ca7b <+59>:  movl   %r14d, 0x110(%rdi)
    0x7ffff772ca82 <+66>:  movq   0x100(%rdi), %r15
    0x7ffff772ca89 <+73>:  leaq   (%r15,%r14), %r8
    0x7ffff772ca8d <+77>:  movl   %edx, 0x64(%r15,%r14)
    0x7ffff772ca92 <+82>:  movl   %ecx, 0x60(%r15,%r14)

-> 112      size_t size = vecA.size();

->  0x7ffff772ca97 <+87>:  movl   0x64(%r15,%r14), %edx
    0x7ffff772ca9c <+92>:  movq   %rdi, %r13
    0x7ffff772ca9f <+95>:  movq   %r13, %rsi
    0x7ffff772caa2 <+98>:  movq   %r13, %rdi
    0x7ffff772caa5 <+101>: callq  0x7ffff77290e0            ; std::__2::vector<float, std::__2::allocator<float> >::size[abi:ue170004]() const at vector:604
    0x7ffff772caaa <+106>: movl   %eax, 0x5c(%r15,%r14)

** 113      __m128 sum = _mm_setzero_ps();
   114

    0x7ffff772caaf <+111>: movl   $0x0, 0x1b4(%r15,%r14)
    0x7ffff772cabb <+123>: movl   $0x0, 0x1b0(%r15,%r14)
    0x7ffff772cac7 <+135>: movl   $0x0, 0x1ac(%r15,%r14)
    0x7ffff772cad3 <+147>: movl   $0x0, 0x1a8(%r15,%r14)
    0x7ffff772cadf <+159>: vmovss 0x1b0(%r15,%r14), %xmm2   ; xmm2 = mem[0],zero,zero,zero
    0x7ffff772cae9 <+169>: vmovss 0x1ac(%r15,%r14), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff772caf3 <+179>: vmovss 0x1a8(%r15,%r14), %xmm4   ; xmm4 = mem[0],zero,zero,zero
    0x7ffff772cafd <+189>: movl   0x1b4(%r15,%r14), %ecx
    0x7ffff772cb05 <+197>: vmovd  %ecx, %xmm1
    0x7ffff772cb09 <+201>: vpbroadcastd %xmm1, %xmm5
    0x7ffff772cb0e <+206>: vinsertps $0x10, %xmm2, %xmm5, %xmm2 ; xmm2 = xmm5[0],xmm2[0],xmm5[2,3]
    0x7ffff772cb14 <+212>: vinsertps $0x20, %xmm3, %xmm2, %xmm2 ; xmm2 = xmm2[0,1],xmm3[0],xmm2[3]
    0x7ffff772cb1a <+218>: vinsertps $0x30, %xmm4, %xmm2, %xmm2 ; xmm2 = xmm2[0,1,2],xmm4[0]
    0x7ffff772cb20 <+224>: vmovdqu %xmm2, 0x190(%r15,%r14)
    0x7ffff772cb2a <+234>: vmovdqu %xmm2, 0x40(%r15,%r14)

** 115      for (int i = 0; i < size; i += 4) {

    0x7ffff772cb31 <+241>: movl   $0x0, 0x3c(%r15,%r14)
    0x7ffff772cb3a <+250>: movl   0x3c(%r15,%r14), %r10d
    0x7ffff772cb3f <+255>: movl   0x5c(%r15,%r14), %r11d
    0x7ffff772cb44 <+260>: cmpl   %r11d, %r10d
    0x7ffff772cb47 <+263>: jae    0x7ffff772cc58            ; <+536> at vector_algorithms.cpp:124:23

** 116          __m128 a = _mm_loadu_ps(&vecA[i]);

    0x7ffff772cb4d <+269>: movl   0x64(%r15,%r14), %edx
    0x7ffff772cb52 <+274>: movl   0x3c(%r15,%r14), %ecx
    0x7ffff772cb57 <+279>: movq   %r13, %rsi
    0x7ffff772cb5a <+282>: movq   %r13, %rdi
    0x7ffff772cb5d <+285>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772cb62 <+290>: movl   %eax, 0x6c(%r15,%r14)
    0x7ffff772cb67 <+295>: movl   %eax, 0x1b8(%r15,%r14)
    0x7ffff772cb6f <+303>: movl   %eax, %eax
    0x7ffff772cb71 <+305>: vmovdqu (%r15,%rax), %xmm2
    0x7ffff772cb77 <+311>: vmovdqu %xmm2, 0x20(%r15,%r14)

** 117          __m128 b = _mm_loadu_ps(&vecB[i]);
   118

    0x7ffff772cb7e <+318>: movl   0x60(%r15,%r14), %edx
    0x7ffff772cb83 <+323>: movl   0x3c(%r15,%r14), %ecx
    0x7ffff772cb88 <+328>: movq   %r13, %rsi
    0x7ffff772cb8b <+331>: movq   %r13, %rdi
    0x7ffff772cb8e <+334>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772cb93 <+339>: movl   %eax, 0x68(%r15,%r14)
    0x7ffff772cb98 <+344>: movl   %eax, 0x1bc(%r15,%r14)
    0x7ffff772cba0 <+352>: movl   %eax, %r8d
    0x7ffff772cba3 <+355>: vmovdqu (%r15,%r8), %xmm5
    0x7ffff772cba9 <+361>: vmovdqu %xmm5, 0x10(%r15,%r14)

** 119          __m128 mul = _mm_mul_ps(a, b);
   120

    0x7ffff772cbb0 <+368>: vmovdqu 0x20(%r15,%r14), %xmm6
    0x7ffff772cbb7 <+375>: vmovdqu %xmm6, 0xa0(%r15,%r14)
    0x7ffff772cbc1 <+385>: vmovdqu %xmm5, 0x90(%r15,%r14)
    0x7ffff772cbcb <+395>: vmovdqu 0xa0(%r15,%r14), %xmm0
    0x7ffff772cbd5 <+405>: vmovdqu %xmm0, 0x230(%r15,%r14)
    0x7ffff772cbdf <+415>: vmovdqu %xmm5, 0x220(%r15,%r14)
    0x7ffff772cbe9 <+425>: vmovdqu 0x230(%r15,%r14), %xmm2
    0x7ffff772cbf3 <+435>: vmulps %xmm5, %xmm2, %xmm2
    0x7ffff772cbf7 <+439>: vmovdqu %xmm2, (%r15,%r14)

** 121          sum = _mm_add_ps(sum, mul);
   122      }
   123

    0x7ffff772cbfd <+445>: vmovdqu 0x40(%r15,%r14), %xmm3
    0x7ffff772cc04 <+452>: vmovdqu %xmm3, 0x80(%r15,%r14)
    0x7ffff772cc0e <+462>: vmovdqu %xmm2, 0x70(%r15,%r14)
    0x7ffff772cc15 <+469>: vmovdqu 0x80(%r15,%r14), %xmm5
    0x7ffff772cc1f <+479>: vmovdqu %xmm5, 0x210(%r15,%r14)
    0x7ffff772cc29 <+489>: vmovdqu %xmm2, 0x200(%r15,%r14)
    0x7ffff772cc33 <+499>: vmovdqu 0x210(%r15,%r14), %xmm7
    0x7ffff772cc3d <+509>: vaddps %xmm2, %xmm7, %xmm7
    0x7ffff772cc41 <+513>: vmovdqu %xmm7, 0x40(%r15,%r14)
    0x7ffff772cc48 <+520>: movl   $0x4, %r10d

** 115      for (int i = 0; i < size; i += 4) {

    0x7ffff772cc4e <+526>: addl   %r10d, 0x3c(%r15,%r14)
    0x7ffff772cc53 <+531>: jmp    0x7ffff772cb3a            ; <+250> at vector_algorithms.cpp:115:21

** 124      sum = _mm_hadd_ps(sum, sum);

    0x7ffff772cc58 <+536>: vmovdqu 0x40(%r15,%r14), %xmm2
    0x7ffff772cc5f <+543>: vmovdqu %xmm2, 0x140(%r15,%r14)
    0x7ffff772cc69 <+553>: vmovdqu %xmm2, 0x130(%r15,%r14)
    0x7ffff772cc73 <+563>: vmovdqu 0x140(%r15,%r14), %xmm4
    0x7ffff772cc7d <+573>: vshufps $0x88, %xmm2, %xmm4, %xmm4 ; xmm4 = xmm4[0,2],xmm2[0,2]
    0x7ffff772cc82 <+578>: vmovdqu %xmm4, 0x120(%r15,%r14)
    0x7ffff772cc8c <+588>: vmovdqu 0x140(%r15,%r14), %xmm5
    0x7ffff772cc96 <+598>: vmovdqu 0x130(%r15,%r14), %xmm6
    0x7ffff772cca0 <+608>: vshufps $0xdd, %xmm6, %xmm5, %xmm5 ; xmm5 = xmm5[1,3],xmm6[1,3]
    0x7ffff772cca5 <+613>: vmovdqu %xmm5, 0x110(%r15,%r14)
    0x7ffff772ccaf <+623>: vmovdqu %xmm4, 0x160(%r15,%r14)
    0x7ffff772ccb9 <+633>: vmovdqu %xmm5, 0x150(%r15,%r14)
    0x7ffff772ccc3 <+643>: vmovdqu 0x160(%r15,%r14), %xmm0
    0x7ffff772cccd <+653>: vmovdqu %xmm0, 0x1d0(%r15,%r14)
    0x7ffff772ccd7 <+663>: vmovdqu %xmm5, 0x1c0(%r15,%r14)
    0x7ffff772cce1 <+673>: vmovdqu 0x1d0(%r15,%r14), %xmm2
    0x7ffff772cceb <+683>: vaddps %xmm5, %xmm2, %xmm2
    0x7ffff772ccef <+687>: vmovdqu %xmm2, 0x40(%r15,%r14)

** 125      sum = _mm_hadd_ps(sum, sum);
   126

    0x7ffff772ccf6 <+694>: vmovdqu %xmm2, 0xe0(%r15,%r14)
    0x7ffff772cd00 <+704>: vmovdqu %xmm2, 0xd0(%r15,%r14)
    0x7ffff772cd0a <+714>: vmovdqu 0xe0(%r15,%r14), %xmm5
    0x7ffff772cd14 <+724>: vshufps $0x88, %xmm2, %xmm5, %xmm5 ; xmm5 = xmm5[0,2],xmm2[0,2]
    0x7ffff772cd19 <+729>: vmovdqu %xmm5, 0xc0(%r15,%r14)
    0x7ffff772cd23 <+739>: vmovdqu 0xe0(%r15,%r14), %xmm6
    0x7ffff772cd2d <+749>: vmovdqu 0xd0(%r15,%r14), %xmm7
    0x7ffff772cd37 <+759>: vshufps $0xdd, %xmm7, %xmm6, %xmm6 ; xmm6 = xmm6[1,3],xmm7[1,3]
    0x7ffff772cd3c <+764>: vmovdqu %xmm6, 0xb0(%r15,%r14)
    0x7ffff772cd46 <+774>: vmovdqu %xmm5, 0x100(%r15,%r14)
    0x7ffff772cd50 <+784>: vmovdqu %xmm6, 0xf0(%r15,%r14)
    0x7ffff772cd5a <+794>: vmovdqu 0x100(%r15,%r14), %xmm1
    0x7ffff772cd64 <+804>: vmovdqu %xmm1, 0x1f0(%r15,%r14)
    0x7ffff772cd6e <+814>: vmovdqu %xmm6, 0x1e0(%r15,%r14)
    0x7ffff772cd78 <+824>: vmovdqu 0x1f0(%r15,%r14), %xmm3
    0x7ffff772cd82 <+834>: vaddps %xmm6, %xmm3, %xmm3
    0x7ffff772cd86 <+838>: vmovdqu %xmm3, 0x40(%r15,%r14)

** 127      return _mm_cvtss_f32(sum);
   128  }
   129

    0x7ffff772cd8d <+845>: vmovdqu %xmm3, 0x180(%r15,%r14)
    0x7ffff772cd97 <+855>: vmovdqu %xmm3, 0x170(%r15,%r14)
    0x7ffff772cda1 <+865>: vmovss 0x170(%r15,%r14), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff772cdab <+875>: movl   %ebx, 0x110(%r13)
    0x7ffff772cdb2 <+882>: movq   (%rsp), %rbx
    0x7ffff772cdb6 <+886>: movq   0x8(%rsp), %r13
    0x7ffff772cdbb <+891>: movq   0x10(%rsp), %r14
    0x7ffff772cdc0 <+896>: movq   0x18(%rsp), %r15
    0x7ffff772cdc5 <+901>: addq   $0x20, %rsp
    0x7ffff772cdc9 <+905>: movq   %rbp, %rsp
    0x7ffff772cdcc <+908>: popq   %rbp
    0x7ffff772cdcd <+909>: retq
    0x7ffff772cdce <+910>: ud2