0x7ffff772d380 <+0>:   pushq  %rbp
    0x7ffff772d381 <+1>:   movq   %rsp, %rbp
    0x7ffff772d384 <+4>:   movq   0x8(%rdi), %r10
    0x7ffff772d388 <+8>:   movq   (%r10), %r10
    0x7ffff772d38b <+11>:  addq   $0x10, %r10
    0x7ffff772d38f <+15>:  cmpq   %rsp, %r10
    0x7ffff772d392 <+18>:  ja     0x7ffff772d586            ; <+518> at vector_algorithms.cpp:175:1
    0x7ffff772d398 <+24>:  subq   $0x40, %rsp
    0x7ffff772d39c <+28>:  movq   %rbx, 0x10(%rsp)
    0x7ffff772d3a1 <+33>:  movq   %r12, 0x18(%rsp)
    0x7ffff772d3a6 <+38>:  movq   %r13, 0x20(%rsp)
    0x7ffff772d3ab <+43>:  movq   %r14, 0x28(%rsp)
    0x7ffff772d3b0 <+48>:  movq   %r15, 0x30(%rsp)
    0x7ffff772d3b5 <+53>:  movl   0x110(%rdi), %r9d
    0x7ffff772d3bc <+60>:  movq   %r9, %r15
    0x7ffff772d3bf <+63>:  subl   $0xb0, %r15d
    0x7ffff772d3c6 <+70>:  movq   %r9, 0x8(%rsp)
    0x7ffff772d3cb <+75>:  movl   %r15d, 0x110(%rdi)
    0x7ffff772d3d2 <+82>:  movq   0x100(%rdi), %rbx
    0x7ffff772d3d9 <+89>:  leaq   (%rbx,%r15), %r13
    0x7ffff772d3dd <+93>:  movl   %edx, 0x44(%rbx,%r15)
    0x7ffff772d3e2 <+98>:  movq   %rdx, (%rsp)
    0x7ffff772d3e6 <+102>: movl   %ecx, 0x40(%rbx,%r15)
    0x7ffff772d3eb <+107>: movl   %r8d, 0x3c(%rbx,%r15)

-> 164      std::vector<int> result(a.size());
-> 165

->  0x7ffff772d3f0 <+112>: xorl   %r10d, %r10d
    0x7ffff772d3f3 <+115>: movb   %r10b, 0x3b(%rbx,%r15)
    0x7ffff772d3f8 <+120>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d3fd <+125>: movq   %rdi, %r12
    0x7ffff772d400 <+128>: movq   %r12, %rsi
    0x7ffff772d403 <+131>: movq   %r12, %rdi
    0x7ffff772d406 <+134>: callq  0x7ffff7727af0            ; std::__2::vector<int, std::__2::allocator<int> >::size[abi:ue170004]() const at vector:604
    0x7ffff772d40b <+139>: movq   %rax, %rcx
    0x7ffff772d40e <+142>: movq   (%rsp), %rdx
    0x7ffff772d412 <+146>: movq   %r12, %rsi
    0x7ffff772d415 <+149>: movq   %r12, %rdi
    0x7ffff772d418 <+152>: callq  0x7ffff7729e90            ; std::__2::vector<int, std::__2::allocator<int> >::vector at vector:1191

** 166      for (int i = 0; i < a.size(); i += 4) {

    0x7ffff772d41d <+157>: movl   $0x0, 0x34(%rbx,%r15)
    0x7ffff772d426 <+166>: movl   0x34(%rbx,%r15), %r14d
    0x7ffff772d42b <+171>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d430 <+176>: movq   %r12, %rsi
    0x7ffff772d433 <+179>: movq   %r12, %rdi
    0x7ffff772d436 <+182>: callq  0x7ffff7727af0            ; std::__2::vector<int, std::__2::allocator<int> >::size[abi:ue170004]() const at vector:604
    0x7ffff772d43b <+187>: cmpl   %eax, %r14d
    0x7ffff772d43e <+190>: jae    0x7ffff772d520            ; <+416> at vector_algorithms.cpp:164:5

** 167          __m128i vecA = _mm_loadu_si128((__m128i*)&a[i]);

    0x7ffff772d444 <+196>: movl   0x40(%rbx,%r15), %edx
    0x7ffff772d449 <+201>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d44e <+206>: movq   %r12, %rsi
    0x7ffff772d451 <+209>: movq   %r12, %rdi
    0x7ffff772d454 <+212>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d459 <+217>: movl   %eax, 0x4c(%rbx,%r15)
    0x7ffff772d45e <+222>: movl   %eax, %edx
    0x7ffff772d460 <+224>: vmovdqu (%rbx,%rdx), %xmm1
    0x7ffff772d465 <+229>: vmovdqu %xmm1, 0x20(%rbx,%r15)

** 168          __m128i vecB = _mm_loadu_si128((__m128i*)&b[i]);
   169

    0x7ffff772d46c <+236>: movl   0x3c(%rbx,%r15), %edx
    0x7ffff772d471 <+241>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d476 <+246>: movq   %r12, %rsi
    0x7ffff772d479 <+249>: movq   %r12, %rdi
    0x7ffff772d47c <+252>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d481 <+257>: movl   %eax, 0x48(%rbx,%r15)
    0x7ffff772d486 <+262>: movl   %eax, %r9d
    0x7ffff772d489 <+265>: vmovdqu (%rbx,%r9), %xmm3
    0x7ffff772d48f <+271>: vmovdqu %xmm3, 0x10(%rbx,%r15)

** 170          __m128i sum = _mm_add_epi32(vecA, vecB);

    0x7ffff772d496 <+278>: vmovdqu 0x20(%rbx,%r15), %xmm4
    0x7ffff772d49d <+285>: vmovdqu %xmm4, 0x60(%rbx,%r15)
    0x7ffff772d4a4 <+292>: vmovdqu %xmm3, 0x50(%rbx,%r15)
    0x7ffff772d4ab <+299>: vmovdqu 0x60(%rbx,%r15), %xmm6
    0x7ffff772d4b2 <+306>: vmovdqu %xmm6, 0xa0(%rbx,%r15)
    0x7ffff772d4bc <+316>: vmovdqu %xmm3, 0x90(%rbx,%r15)
    0x7ffff772d4c6 <+326>: vmovdqu 0xa0(%rbx,%r15), %xmm0
    0x7ffff772d4d0 <+336>: vpaddd %xmm3, %xmm0, %xmm0
    0x7ffff772d4d4 <+340>: vmovdqu %xmm0, (%rbx,%r15)

** 171          _mm_storeu_si128((__m128i*)&result[i], sum);
   172      }
   173

    0x7ffff772d4da <+346>: movl   0x34(%rbx,%r15), %ecx
    0x7ffff772d4df <+351>: movq   (%rsp), %rdx
    0x7ffff772d4e3 <+355>: movq   %r12, %rsi
    0x7ffff772d4e6 <+358>: movq   %r12, %rdi
    0x7ffff772d4e9 <+361>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772d4ee <+366>: vmovdqu (%rbx,%r15), %xmm1
    0x7ffff772d4f4 <+372>: movl   %eax, 0x8c(%rbx,%r15)
    0x7ffff772d4fc <+380>: vmovdqu %xmm1, 0x70(%rbx,%r15)
    0x7ffff772d503 <+387>: movl   0x8c(%r13), %r8d
    0x7ffff772d50a <+394>: vmovdqu %xmm1, (%rbx,%r8)
    0x7ffff772d510 <+400>: movl   $0x4, %r9d

** 166      for (int i = 0; i < a.size(); i += 4) {

    0x7ffff772d516 <+406>: addl   %r9d, 0x34(%rbx,%r15)
    0x7ffff772d51b <+411>: jmp    0x7ffff772d426            ; <+166> at vector_algorithms.cpp:166:21

** 164      std::vector<int> result(a.size());

    0x7ffff772d520 <+416>: movl   $0x1, %r11d

** 174      return result;

    0x7ffff772d526 <+422>: movb   %r11b, 0x3b(%rbx,%r15)

** 175  }

    0x7ffff772d52b <+427>: movzbq 0x3b(%rbx,%r15), %r11
    0x7ffff772d531 <+433>: andl   $0x1, %r11d
    0x7ffff772d535 <+437>: testl  %r11d, %r11d
    0x7ffff772d538 <+440>: je     0x7ffff772d548            ; <+456> at vector_algorithms.cpp:175:1
    0x7ffff772d53e <+446>: movq   0x8(%rsp), %r9
    0x7ffff772d543 <+451>: jmp    0x7ffff772d55c            ; <+476> at vector_algorithms.cpp:175:1
    0x7ffff772d548 <+456>: movq   (%rsp), %rdx
    0x7ffff772d54c <+460>: movq   %r12, %rsi
    0x7ffff772d54f <+463>: movq   %r12, %rdi
    0x7ffff772d552 <+466>: callq  0x7ffff77256b0            ; std::__2::vector<int, std::__2::allocator<int> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772d557 <+471>: movq   0x8(%rsp), %r9
    0x7ffff772d55c <+476>: movl   %r9d, 0x110(%r12)
    0x7ffff772d564 <+484>: movq   0x10(%rsp), %rbx
    0x7ffff772d569 <+489>: movq   0x18(%rsp), %r12
    0x7ffff772d56e <+494>: movq   0x20(%rsp), %r13
    0x7ffff772d573 <+499>: movq   0x28(%rsp), %r14
    0x7ffff772d578 <+504>: movq   0x30(%rsp), %r15
    0x7ffff772d57d <+509>: addq   $0x40, %rsp
    0x7ffff772d581 <+513>: movq   %rbp, %rsp
    0x7ffff772d584 <+516>: popq   %rbp
    0x7ffff772d585 <+517>: retq
    0x7ffff772d586 <+518>: ud2