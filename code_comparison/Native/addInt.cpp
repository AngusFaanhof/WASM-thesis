0x555555559231 <+0>:   endbr64
    0x555555559235 <+4>:   pushq  %rbp
    0x555555559236 <+5>:   movq   %rsp, %rbp
    0x555555559239 <+8>:   pushq  %rbx
    0x55555555923a <+9>:   subq   $0xb8, %rsp
    0x555555559241 <+16>:  movq   %rdi, -0xa8(%rbp)
    0x555555559248 <+23>:  movq   %rsi, -0xb0(%rbp)
    0x55555555924f <+30>:  movq   %rdx, -0xb8(%rbp)

   161  }
   162
** 163  std::vector<int> vectorAddition(std::vector<int>& a, std::vector<int>& b) {

    0x555555559256 <+37>:  movq   %fs:0x28, %rax
    0x55555555925f <+46>:  movq   %rax, -0x18(%rbp)
    0x555555559263 <+50>:  xorl   %eax, %eax

-> 164      std::vector<int> result(a.size());
-> 165

->  0x555555559265 <+52>:  leaq   -0x9d(%rbp), %rax
    0x55555555926c <+59>:  movq   %rax, %rdi
    0x55555555926f <+62>:  callq  0x555555555746            ; std::allocator<int>::allocator at allocator.h:156:7
    0x555555559274 <+67>:  movq   -0xb0(%rbp), %rax
    0x55555555927b <+74>:  movq   %rax, %rdi
    0x55555555927e <+77>:  callq  0x5555555594ca            ; std::vector<int, std::allocator<int> >::size at stl_vector.h:918:7
    0x555555559283 <+82>:  movq   %rax, %rcx
    0x555555559286 <+85>:  leaq   -0x9d(%rbp), %rdx
    0x55555555928d <+92>:  movq   -0xa8(%rbp), %rax
    0x555555559294 <+99>:  movq   %rcx, %rsi
    0x555555559297 <+102>: movq   %rax, %rdi
    0x55555555929a <+105>: callq  0x555555556fa8            ; std::vector<int, std::allocator<int> >::vector at stl_vector.h:510:7
    0x55555555929f <+110>: leaq   -0x9d(%rbp), %rax
    0x5555555592a6 <+117>: movq   %rax, %rdi
    0x5555555592a9 <+120>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7

** 166      for (int i = 0; i < a.size(); i += 4) {

    0x5555555592ae <+125>: movl   $0x0, -0x9c(%rbp)
    0x5555555592b8 <+135>: jmp    0x55555555938c            ; <+347> at vector_algorithms.cpp:166:21

** 167          __m128i vecA = _mm_loadu_si128((__m128i*)&a[i]);

    0x5555555592bd <+140>: movl   -0x9c(%rbp), %eax
    0x5555555592c3 <+146>: movslq %eax, %rdx
    0x5555555592c6 <+149>: movq   -0xb0(%rbp), %rax
    0x5555555592cd <+156>: movq   %rdx, %rsi
    0x5555555592d0 <+159>: movq   %rax, %rdi
    0x5555555592d3 <+162>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x5555555592d8 <+167>: movq   %rax, -0x88(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x5555555592df <+174>: movq   -0x88(%rbp), %rax
    0x5555555592e6 <+181>: vmovdqu (%rax), %xmm0

** 167          __m128i vecA = _mm_loadu_si128((__m128i*)&a[i]);

    0x5555555592ea <+185>: vmovdqa %xmm0, -0x80(%rbp)

** 168          __m128i vecB = _mm_loadu_si128((__m128i*)&b[i]);
   169

    0x5555555592ef <+190>: movl   -0x9c(%rbp), %eax
    0x5555555592f5 <+196>: movslq %eax, %rdx
    0x5555555592f8 <+199>: movq   -0xb8(%rbp), %rax
    0x5555555592ff <+206>: movq   %rdx, %rsi
    0x555555559302 <+209>: movq   %rax, %rdi
    0x555555559305 <+212>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x55555555930a <+217>: movq   %rax, -0x90(%rbp)

** 703    return *__P;

    0x555555559311 <+224>: movq   -0x90(%rbp), %rax
    0x555555559318 <+231>: vmovdqu (%rax), %xmm0

** 168          __m128i vecB = _mm_loadu_si128((__m128i*)&b[i]);

    0x55555555931c <+235>: vmovdqa %xmm0, -0x70(%rbp)
    0x555555559321 <+240>: vmovdqa -0x80(%rbp), %xmm0
    0x555555559326 <+245>: vmovdqa %xmm0, -0x40(%rbp)
    0x55555555932b <+250>: vmovdqa -0x70(%rbp), %xmm0
    0x555555559330 <+255>: vmovdqa %xmm0, -0x30(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x555555559335 <+260>: vmovdqa -0x40(%rbp), %xmm1
    0x55555555933a <+265>: vmovdqa -0x30(%rbp), %xmm0
    0x55555555933f <+270>: vpaddd %xmm0, %xmm1, %xmm0

** 170          __m128i sum = _mm_add_epi32(vecA, vecB);

    0x555555559343 <+274>: vmovdqa %xmm0, -0x60(%rbp)

** 171          _mm_storeu_si128((__m128i*)&result[i], sum);
   172      }
   173

    0x555555559348 <+279>: movl   -0x9c(%rbp), %eax
    0x55555555934e <+285>: movslq %eax, %rdx
    0x555555559351 <+288>: movq   -0xa8(%rbp), %rax
    0x555555559358 <+295>: movq   %rdx, %rsi
    0x55555555935b <+298>: movq   %rax, %rdi
    0x55555555935e <+301>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555559363 <+306>: movq   %rax, -0x98(%rbp)
    0x55555555936a <+313>: vmovdqa -0x60(%rbp), %xmm0
    0x55555555936f <+318>: vmovdqa %xmm0, -0x50(%rbp)

   737  _mm_storeu_si128 (__m128i_u *__P, __m128i __B)
   738  {
** 739    *__P = __B;

    0x555555559374 <+323>: vmovdqa -0x50(%rbp), %xmm0
    0x555555559379 <+328>: movq   -0x98(%rbp), %rax
    0x555555559380 <+335>: vmovdqu %xmm0, (%rax)

** 740  }
   741
   742  extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))

    0x555555559384 <+339>: nop

** 166      for (int i = 0; i < a.size(); i += 4) {

    0x555555559385 <+340>: addl   $0x4, -0x9c(%rbp)
    0x55555555938c <+347>: movl   -0x9c(%rbp), %eax
    0x555555559392 <+353>: movslq %eax, %rbx
    0x555555559395 <+356>: movq   -0xb0(%rbp), %rax
    0x55555555939c <+363>: movq   %rax, %rdi
    0x55555555939f <+366>: callq  0x5555555594ca            ; std::vector<int, std::allocator<int> >::size at stl_vector.h:918:7
    0x5555555593a4 <+371>: cmpq   %rax, %rbx
    0x5555555593a7 <+374>: setb   %al
    0x5555555593aa <+377>: testb  %al, %al
    0x5555555593ac <+379>: jne    0x5555555592bd            ; <+140> at vector_algorithms.cpp:167:54

** 174      return result;

    0x5555555593b2 <+385>: jmp    0x5555555593d5            ; <+420> at vector_algorithms.cpp:175:1
    0x5555555593b4 <+387>: endbr64
    0x5555555593b8 <+391>: movq   %rax, %rbx
    0x5555555593bb <+394>: leaq   -0x9d(%rbp), %rax
    0x5555555593c2 <+401>: movq   %rax, %rdi
    0x5555555593c5 <+404>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7
    0x5555555593ca <+409>: movq   %rbx, %rax
    0x5555555593cd <+412>: movq   %rax, %rdi
    0x5555555593d0 <+415>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 175  }

    0x5555555593d5 <+420>: movq   -0x18(%rbp), %rax
    0x5555555593d9 <+424>: subq   %fs:0x28, %rax
    0x5555555593e2 <+433>: je     0x5555555593e9            ; <+440> at vector_algorithms.cpp:175:1
    0x5555555593e4 <+435>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x5555555593e9 <+440>: movq   -0xa8(%rbp), %rax
    0x5555555593f0 <+447>: movq   -0x8(%rbp), %rbx
    0x5555555593f4 <+451>: leave
    0x5555555593f5 <+452>: retq