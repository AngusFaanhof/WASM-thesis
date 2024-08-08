0x7ffff772cdd0 <+0>:   pushq  %rbp
    0x7ffff772cdd1 <+1>:   movq   %rsp, %rbp
    0x7ffff772cdd4 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772cdd8 <+8>:   movq   (%r10), %r10
    0x7ffff772cddb <+11>:  cmpq   %rsp, %r10
    0x7ffff772cdde <+14>:  ja     0x7ffff772d14f            ; <+895> at vector_algorithms.cpp:146:5
    0x7ffff772cde4 <+20>:  subq   $0x30, %rsp
    0x7ffff772cde8 <+24>:  movq   %rbx, (%rsp)
    0x7ffff772cdec <+28>:  movq   %r12, 0x8(%rsp)
    0x7ffff772cdf1 <+33>:  movq   %r13, 0x10(%rsp)
    0x7ffff772cdf6 <+38>:  movq   %r14, 0x18(%rsp)
    0x7ffff772cdfb <+43>:  movq   %r15, 0x20(%rsp)
    0x7ffff772ce00 <+48>:  movl   0x110(%rdi), %r14d
    0x7ffff772ce07 <+55>:  movq   %r14, %rbx
    0x7ffff772ce0a <+58>:  subl   $0x250, %ebx              ; imm = 0x250
    0x7ffff772ce10 <+64>:  movl   %ebx, 0x110(%rdi)
    0x7ffff772ce16 <+70>:  movq   0x100(%rdi), %r12
    0x7ffff772ce1d <+77>:  leaq   (%r12,%rbx), %r13
    0x7ffff772ce21 <+81>:  movl   %edx, 0x64(%r12,%rbx)
    0x7ffff772ce26 <+86>:  movl   %ecx, 0x60(%r12,%rbx)

-> 131      size_t size = vecA.size();

->  0x7ffff772ce2b <+91>:  movl   0x64(%r12,%rbx), %edx
    0x7ffff772ce30 <+96>:  movq   %rdi, %r15
    0x7ffff772ce33 <+99>:  movq   %r15, %rsi
    0x7ffff772ce36 <+102>: movq   %r15, %rdi
    0x7ffff772ce39 <+105>: callq  0x7ffff7727af0            ; std::__2::vector<int, std::__2::allocator<int> >::size[abi:ue170004]() const at vector:604
    0x7ffff772ce3e <+110>: movl   %eax, 0x5c(%r12,%rbx)

** 132      __m128i sum = _mm_setzero_si128();
   133

    0x7ffff772ce43 <+115>: movq   $0x0, 0x198(%r12,%rbx)
    0x7ffff772ce4f <+127>: movq   $0x0, 0x190(%r12,%rbx)
    0x7ffff772ce5b <+139>: movq   0x198(%r12,%rbx), %rcx
    0x7ffff772ce63 <+147>: vmovq  %rcx, %xmm1
    0x7ffff772ce68 <+152>: vpshufd $0x44, %xmm1, %xmm3       ; xmm3 = xmm1[0,1,0,1]
    0x7ffff772ce6d <+157>: vpinsrq $0x1, 0x2e1(%rip), %xmm3, %xmm2 ; <+903> at vector_algorithms.cpp:146:5
    0x7ffff772ce77 <+167>: vmovdqu %xmm2, 0x180(%r12,%rbx)
    0x7ffff772ce81 <+177>: vmovdqu %xmm2, 0x40(%r12,%rbx)

** 134      for (size_t i = 0; i < size; i += 4) {

    0x7ffff772ce88 <+184>: movl   $0x0, 0x3c(%r12,%rbx)
    0x7ffff772ce91 <+193>: movl   0x3c(%r12,%rbx), %r10d
    0x7ffff772ce96 <+198>: movl   0x5c(%r12,%rbx), %r11d
    0x7ffff772ce9b <+203>: cmpl   %r11d, %r10d
    0x7ffff772ce9e <+206>: jae    0x7ffff772cf9f            ; <+463> at vector_algorithms.cpp:143:26

** 135          __m128i a = _mm_loadu_si128((__m128i*)&vecA[i]);

    0x7ffff772cea4 <+212>: movl   0x64(%r12,%rbx), %edx
    0x7ffff772cea9 <+217>: movl   0x3c(%r12,%rbx), %ecx
    0x7ffff772ceae <+222>: movq   %r15, %rsi
    0x7ffff772ceb1 <+225>: movq   %r15, %rdi
    0x7ffff772ceb4 <+228>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772ceb9 <+233>: movl   %eax, 0x6c(%r12,%rbx)
    0x7ffff772cebe <+238>: movl   %eax, %edi
    0x7ffff772cec0 <+240>: vmovdqu (%r12,%rdi), %xmm1
    0x7ffff772cec6 <+246>: vmovdqu %xmm1, 0x20(%r12,%rbx)

** 136          __m128i b = _mm_loadu_si128((__m128i*)&vecB[i]);
   137

    0x7ffff772cecd <+253>: movl   0x60(%r12,%rbx), %edx
    0x7ffff772ced2 <+258>: movl   0x3c(%r12,%rbx), %ecx
    0x7ffff772ced7 <+263>: movq   %r15, %rsi
    0x7ffff772ceda <+266>: movq   %r15, %rdi
    0x7ffff772cedd <+269>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772cee2 <+274>: movl   %eax, 0x68(%r12,%rbx)
    0x7ffff772cee7 <+279>: movl   %eax, %ecx
    0x7ffff772cee9 <+281>: vmovdqu (%r12,%rcx), %xmm3
    0x7ffff772ceef <+287>: vmovdqu %xmm3, 0x10(%r12,%rbx)

** 138          __m128i mul = _mm_mullo_epi32(a, b);
   139

    0x7ffff772cef6 <+294>: vmovdqu 0x20(%r12,%rbx), %xmm4
    0x7ffff772cefd <+301>: vmovdqu %xmm4, 0xa0(%r12,%rbx)
    0x7ffff772cf07 <+311>: vmovdqu %xmm3, 0x90(%r12,%rbx)
    0x7ffff772cf11 <+321>: vmovdqu 0xa0(%r12,%rbx), %xmm6
    0x7ffff772cf1b <+331>: vmovdqu %xmm6, 0x210(%r12,%rbx)
    0x7ffff772cf25 <+341>: vmovdqu %xmm3, 0x200(%r12,%rbx)
    0x7ffff772cf2f <+351>: vmovdqu 0x210(%r12,%rbx), %xmm0
    0x7ffff772cf39 <+361>: vpmulld %xmm3, %xmm0, %xmm0
    0x7ffff772cf3e <+366>: vmovdqu %xmm0, (%r12,%rbx)

** 140          sum = _mm_add_epi32(sum, mul);
   141      }
   142

    0x7ffff772cf44 <+372>: vmovdqu 0x40(%r12,%rbx), %xmm1
    0x7ffff772cf4b <+379>: vmovdqu %xmm1, 0x80(%r12,%rbx)
    0x7ffff772cf55 <+389>: vmovdqu %xmm0, 0x70(%r12,%rbx)
    0x7ffff772cf5c <+396>: vmovdqu 0x80(%r12,%rbx), %xmm3
    0x7ffff772cf66 <+406>: vmovdqu %xmm3, 0x1f0(%r12,%rbx)
    0x7ffff772cf70 <+416>: vmovdqu %xmm0, 0x1e0(%r12,%rbx)
    0x7ffff772cf7a <+426>: vmovdqu 0x1f0(%r12,%rbx), %xmm5
    0x7ffff772cf84 <+436>: vpaddd %xmm0, %xmm5, %xmm5
    0x7ffff772cf88 <+440>: vmovdqu %xmm5, 0x40(%r12,%rbx)
    0x7ffff772cf8f <+447>: movl   $0x4, %r8d

** 134      for (size_t i = 0; i < size; i += 4) {

    0x7ffff772cf95 <+453>: addl   %r8d, 0x3c(%r12,%rbx)
    0x7ffff772cf9a <+458>: jmp    0x7ffff772ce91            ; <+193> at vector_algorithms.cpp:134:24

** 143      sum = _mm_hadd_epi32(sum, sum);

    0x7ffff772cf9f <+463>: vmovdqu 0x40(%r12,%rbx), %xmm0
    0x7ffff772cfa6 <+470>: vmovdqu %xmm0, 0x140(%r12,%rbx)
    0x7ffff772cfb0 <+480>: vmovdqu %xmm0, 0x130(%r12,%rbx)
    0x7ffff772cfba <+490>: vmovdqu 0x140(%r12,%rbx), %xmm2
    0x7ffff772cfc4 <+500>: vshufps $0x88, %xmm0, %xmm2, %xmm2 ; xmm2 = xmm2[0,2],xmm0[0,2]
    0x7ffff772cfc9 <+505>: vmovdqu %xmm2, 0x120(%r12,%rbx)
    0x7ffff772cfd3 <+515>: vmovdqu 0x140(%r12,%rbx), %xmm3
    0x7ffff772cfdd <+525>: vmovdqu 0x130(%r12,%rbx), %xmm4
    0x7ffff772cfe7 <+535>: vshufps $0xdd, %xmm4, %xmm3, %xmm3 ; xmm3 = xmm3[1,3],xmm4[1,3]
    0x7ffff772cfec <+540>: vmovdqu %xmm3, 0x110(%r12,%rbx)
    0x7ffff772cff6 <+550>: vmovdqu %xmm2, 0x160(%r12,%rbx)
    0x7ffff772d000 <+560>: vmovdqu %xmm3, 0x150(%r12,%rbx)
    0x7ffff772d00a <+570>: vmovdqu 0x160(%r12,%rbx), %xmm6
    0x7ffff772d014 <+580>: vmovdqu %xmm6, 0x1b0(%r12,%rbx)
    0x7ffff772d01e <+590>: vmovdqu %xmm3, 0x1a0(%r12,%rbx)
    0x7ffff772d028 <+600>: vmovdqu 0x1b0(%r12,%rbx), %xmm0
    0x7ffff772d032 <+610>: vpaddd %xmm3, %xmm0, %xmm0
    0x7ffff772d036 <+614>: vmovdqu %xmm0, 0x40(%r12,%rbx)

** 144      sum = _mm_hadd_epi32(sum, sum);
   145

    0x7ffff772d03d <+621>: vmovdqu %xmm0, 0xe0(%r12,%rbx)
    0x7ffff772d047 <+631>: vmovdqu %xmm0, 0xd0(%r12,%rbx)
    0x7ffff772d051 <+641>: vmovdqu 0xe0(%r12,%rbx), %xmm3
    0x7ffff772d05b <+651>: vshufps $0x88, %xmm0, %xmm3, %xmm3 ; xmm3 = xmm3[0,2],xmm0[0,2]
    0x7ffff772d060 <+656>: vmovdqu %xmm3, 0xc0(%r12,%rbx)
    0x7ffff772d06a <+666>: vmovdqu 0xe0(%r12,%rbx), %xmm4
    0x7ffff772d074 <+676>: vmovdqu 0xd0(%r12,%rbx), %xmm5
    0x7ffff772d07e <+686>: vshufps $0xdd, %xmm5, %xmm4, %xmm4 ; xmm4 = xmm4[1,3],xmm5[1,3]
    0x7ffff772d083 <+691>: vmovdqu %xmm4, 0xb0(%r12,%rbx)
    0x7ffff772d08d <+701>: vmovdqu %xmm3, 0x100(%r12,%rbx)
    0x7ffff772d097 <+711>: vmovdqu %xmm4, 0xf0(%r12,%rbx)
    0x7ffff772d0a1 <+721>: vmovdqu 0x100(%r12,%rbx), %xmm7
    0x7ffff772d0ab <+731>: vmovdqu %xmm7, 0x1d0(%r12,%rbx)
    0x7ffff772d0b5 <+741>: vmovdqu %xmm4, 0x1c0(%r12,%rbx)
    0x7ffff772d0bf <+751>: vmovdqu 0x1d0(%r12,%rbx), %xmm1
    0x7ffff772d0c9 <+761>: vpaddd %xmm4, %xmm1, %xmm1
    0x7ffff772d0cd <+765>: vmovdqu %xmm1, 0x40(%r12,%rbx)

** 146      return _mm_cvtsi128_si32(sum);
   147  }
   148

    0x7ffff772d0d4 <+772>: vmovdqu %xmm1, 0x170(%r12,%rbx)
    0x7ffff772d0de <+782>: vmovdqu %xmm1, 0x240(%r12,%rbx)
    0x7ffff772d0e8 <+792>: movl   $0x0, 0x23c(%r12,%rbx)
    0x7ffff772d0f4 <+804>: vmovdqu 0x240(%r12,%rbx), %xmm5
    0x7ffff772d0fe <+814>: vmovdqu %xmm5, 0x220(%r12,%rbx)
    0x7ffff772d108 <+824>: movl   $0xffffffd0, %eax         ; imm = 0xFFFFFFD0
    0x7ffff772d10d <+829>: leal   (%r14,%rax), %r10d
    0x7ffff772d111 <+833>: movl   $0x3, %esi
    0x7ffff772d116 <+838>: andl   0x23c(%r13), %esi
    0x7ffff772d11d <+845>: shll   $0x2, %esi
    0x7ffff772d120 <+848>: orl    %esi, %r10d
    0x7ffff772d123 <+851>: movl   (%r12,%r10), %eax
    0x7ffff772d127 <+855>: movl   %r14d, 0x110(%r15)
    0x7ffff772d12e <+862>: movq   (%rsp), %rbx
    0x7ffff772d132 <+866>: movq   0x8(%rsp), %r12
    0x7ffff772d137 <+871>: movq   0x10(%rsp), %r13
    0x7ffff772d13c <+876>: movq   0x18(%rsp), %r14
    0x7ffff772d141 <+881>: movq   0x20(%rsp), %r15
    0x7ffff772d146 <+886>: addq   $0x30, %rsp
    0x7ffff772d14a <+890>: movq   %rbp, %rsp
    0x7ffff772d14d <+893>: popq   %rbp
    0x7ffff772d14e <+894>: retq
    0x7ffff772d14f <+895>: ud2
    0x7ffff772d151 <+897>: addb   %al, (%rax)
    0x7ffff772d153 <+899>: addb   %al, (%rax)
    0x7ffff772d155 <+901>: addb   %al, (%rax)
    0x7ffff772d157 <+903>: addb   %al, (%rax)
    0x7ffff772d159 <+905>: addb   %al, (%rax)
    0x7ffff772d15b <+907>: addb   %al, (%rax)
    0x7ffff772d15d <+909>: addb   %al, (%rax)