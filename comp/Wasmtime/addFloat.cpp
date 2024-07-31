0x7ffff772d160 <+0>:   pushq  %rbp
    0x7ffff772d161 <+1>:   movq   %rsp, %rbp
    0x7ffff772d164 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772d168 <+8>:   movq   (%r10), %r10
    0x7ffff772d16b <+11>:  addq   $0x10, %r10
    0x7ffff772d16f <+15>:  cmpq   %rsp, %r10
    0x7ffff772d172 <+18>:  ja     0x7ffff772d375            ; <+533> at vector_algorithms.cpp:161:1
    0x7ffff772d178 <+24>:  subq   $0x40, %rsp
    0x7ffff772d17c <+28>:  movq   %rbx, 0x10(%rsp)
    0x7ffff772d181 <+33>:  movq   %r12, 0x18(%rsp)
    0x7ffff772d186 <+38>:  movq   %r13, 0x20(%rsp)
    0x7ffff772d18b <+43>:  movq   %r14, 0x28(%rsp)
    0x7ffff772d190 <+48>:  movq   %r15, 0x30(%rsp)
    0x7ffff772d195 <+53>:  movl   0x110(%rdi), %r9d
    0x7ffff772d19c <+60>:  movq   %r9, %r15
    0x7ffff772d19f <+63>:  subl   $0xb0, %r15d
    0x7ffff772d1a6 <+70>:  movq   %r9, 0x8(%rsp)
    0x7ffff772d1ab <+75>:  movl   %r15d, 0x110(%rdi)
    0x7ffff772d1b2 <+82>:  movq   0x100(%rdi), %rbx
    0x7ffff772d1b9 <+89>:  leaq   (%rbx,%r15), %r13
    0x7ffff772d1bd <+93>:  movl   %edx, 0x44(%rbx,%r15)
    0x7ffff772d1c2 <+98>:  movq   %rdx, (%rsp)
    0x7ffff772d1c6 <+102>: movl   %ecx, 0x40(%rbx,%r15)
    0x7ffff772d1cb <+107>: movl   %r8d, 0x3c(%rbx,%r15)

-> 150      std::vector<float> result(a.size());
-> 151

->  0x7ffff772d1d0 <+112>: xorl   %r10d, %r10d
    0x7ffff772d1d3 <+115>: movb   %r10b, 0x3b(%rbx,%r15)
    0x7ffff772d1d8 <+120>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d1dd <+125>: movq   %rdi, %r12
    0x7ffff772d1e0 <+128>: movq   %r12, %rsi
    0x7ffff772d1e3 <+131>: movq   %r12, %rdi
    0x7ffff772d1e6 <+134>: callq  0x7ffff77290e0            ; std::__2::vector<float, std::__2::allocator<float> >::size[abi:ue170004]() const at vector:604
    0x7ffff772d1eb <+139>: movq   %rax, %rcx
    0x7ffff772d1ee <+142>: movq   (%rsp), %rdx
    0x7ffff772d1f2 <+146>: movq   %r12, %rsi
    0x7ffff772d1f5 <+149>: movq   %r12, %rdi
    0x7ffff772d1f8 <+152>: callq  0x7ffff772a870            ; std::__2::vector<float, std::__2::allocator<float> >::vector at vector:1191

** 152      for (int i = 0; i < a.size(); i += 4) {

    0x7ffff772d1fd <+157>: movl   $0x0, 0x34(%rbx,%r15)
    0x7ffff772d206 <+166>: movl   0x34(%rbx,%r15), %r14d
    0x7ffff772d20b <+171>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d210 <+176>: movq   %r12, %rsi
    0x7ffff772d213 <+179>: movq   %r12, %rdi
    0x7ffff772d216 <+182>: callq  0x7ffff77290e0            ; std::__2::vector<float, std::__2::allocator<float> >::size[abi:ue170004]() const at vector:604
    0x7ffff772d21b <+187>: cmpl   %eax, %r14d
    0x7ffff772d21e <+190>: jae    0x7ffff772d312            ; <+434> at vector_algorithms.cpp:150:5

** 153          __m128 vecA = _mm_loadu_ps(&a[i]);

    0x7ffff772d224 <+196>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d229 <+201>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d22e <+206>: movq   %r12, %rsi
    0x7ffff772d231 <+209>: movq   %r12, %rdi
    0x7ffff772d234 <+212>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d239 <+217>: movl   %eax, 0x4c(%rbx,%r15)
    0x7ffff772d23e <+222>: movl   %eax, 0x88(%rbx,%r15)
    0x7ffff772d246 <+230>: movl   %eax, %r8d
    0x7ffff772d249 <+233>: vmovdqu (%rbx,%r8), %xmm2
    0x7ffff772d24f <+239>: vmovdqu %xmm2, 0x20(%rbx,%r15)

** 154          __m128 vecB = _mm_loadu_ps(&b[i]);
   155

    0x7ffff772d256 <+246>: movl   0x3c(%rbx,%r15), %edx
    0x7ffff772d25b <+251>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d260 <+256>: movq   %r12, %rsi
    0x7ffff772d263 <+259>: movq   %r12, %rdi
    0x7ffff772d266 <+262>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d26b <+267>: movl   %eax, 0x48(%rbx,%r15)
    0x7ffff772d270 <+272>: movl   %eax, 0x8c(%rbx,%r15)
    0x7ffff772d278 <+280>: movl   %eax, %r11d
    0x7ffff772d27b <+283>: vmovdqu (%rbx,%r11), %xmm5
    0x7ffff772d281 <+289>: vmovdqu %xmm5, 0x10(%rbx,%r15)

** 156          __m128 sum = _mm_add_ps(vecA, vecB);

    0x7ffff772d288 <+296>: vmovdqu 0x20(%rbx,%r15), %xmm6
    0x7ffff772d28f <+303>: vmovdqu %xmm6, 0x60(%rbx,%r15)
    0x7ffff772d296 <+310>: vmovdqu %xmm5, 0x50(%rbx,%r15)
    0x7ffff772d29d <+317>: vmovdqu 0x60(%rbx,%r15), %xmm0
    0x7ffff772d2a4 <+324>: vmovdqu %xmm0, 0xa0(%rbx,%r15)
    0x7ffff772d2ae <+334>: vmovdqu %xmm5, 0x90(%rbx,%r15)
    0x7ffff772d2b8 <+344>: vmovdqu 0xa0(%rbx,%r15), %xmm2
    0x7ffff772d2c2 <+354>: vaddps %xmm5, %xmm2, %xmm2
    0x7ffff772d2c6 <+358>: vmovdqu %xmm2, (%rbx,%r15)

** 157          _mm_storeu_ps(&result[i], sum);
   158      }
   159

    0x7ffff772d2cc <+364>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d2d1 <+369>: movq   (%rsp), %rdx
    0x7ffff772d2d5 <+373>: movq   %r12, %rsi
    0x7ffff772d2d8 <+376>: movq   %r12, %rdi
    0x7ffff772d2db <+379>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d2e0 <+384>: vmovdqu (%rbx,%r15), %xmm3
    0x7ffff772d2e6 <+390>: movl   %eax, 0x84(%rbx,%r15)
    0x7ffff772d2ee <+398>: vmovdqu %xmm3, 0x70(%rbx,%r15)
    0x7ffff772d2f5 <+405>: movl   0x84(%r13), %r10d
    0x7ffff772d2fc <+412>: vmovdqu %xmm3, (%rbx,%r10)
    0x7ffff772d302 <+418>: movl   $0x4, %r11d

** 152      for (int i = 0; i < a.size(); i += 4) {

    0x7ffff772d308 <+424>: addl   %r11d, 0x34(%rbx,%r15)
    0x7ffff772d30d <+429>: jmp    0x7ffff772d206            ; <+166> at vector_algorithms.cpp:152:21

** 150      std::vector<float> result(a.size());

    0x7ffff772d312 <+434>: movl   $0x1, %edi

** 160      return result;

    0x7ffff772d317 <+439>: movb   %dil, 0x3b(%rbx,%r15)

** 161  }
   162
   163  std::vector<int> vectorAddition(std::vector<int>& a, std::vector<int>& b) {

    0x7ffff772d31c <+444>: movzbq 0x3b(%rbx,%r15), %rdi
    0x7ffff772d322 <+450>: andl   $0x1, %edi
    0x7ffff772d325 <+453>: testl  %edi, %edi
    0x7ffff772d327 <+455>: je     0x7ffff772d337            ; <+471> at vector_algorithms.cpp:161:1
    0x7ffff772d32d <+461>: movq   0x8(%rsp), %r9
    0x7ffff772d332 <+466>: jmp    0x7ffff772d34b            ; <+491> at vector_algorithms.cpp:161:1
    0x7ffff772d337 <+471>: movq   (%rsp), %rdx
    0x7ffff772d33b <+475>: movq   %r12, %rsi
    0x7ffff772d33e <+478>: movq   %r12, %rdi
    0x7ffff772d341 <+481>: callq  0x7ffff7725760            ; std::__2::vector<float, std::__2::allocator<float> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772d346 <+486>: movq   0x8(%rsp), %r9
    0x7ffff772d34b <+491>: movl   %r9d, 0x110(%r12)
    0x7ffff772d353 <+499>: movq   0x10(%rsp), %rbx
    0x7ffff772d358 <+504>: movq   0x18(%rsp), %r12
    0x7ffff772d35d <+509>: movq   0x20(%rsp), %r13
    0x7ffff772d362 <+514>: movq   0x28(%rsp), %r14
    0x7ffff772d367 <+519>: movq   0x30(%rsp), %r15
    0x7ffff772d36c <+524>: addq   $0x40, %rsp
    0x7ffff772d370 <+528>: movq   %rbp, %rsp
    0x7ffff772d373 <+531>: popq   %rbp
    0x7ffff772d374 <+532>: retq
    0x7ffff772d375 <+533>: ud2