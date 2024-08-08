0x555555557614 <+0>:    endbr64
    0x555555557618 <+4>:    pushq  %rbp
    0x555555557619 <+5>:    movq   %rsp, %rbp
    0x55555555761c <+8>:    pushq  %rbx
    0x55555555761d <+9>:    subq   $0x258, %rsp              ; imm = 0x258
    0x555555557624 <+16>:   movq   %rdi, -0x248(%rbp)
    0x55555555762b <+23>:   movq   %rsi, -0x250(%rbp)
    0x555555557632 <+30>:   movq   %rdx, -0x258(%rbp)

   29   }
   30
** 31   std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols) {

    0x555555557639 <+37>:   movq   %fs:0x28, %rax
    0x555555557642 <+46>:   movq   %rax, -0x18(%rbp)
    0x555555557646 <+50>:   xorl   %eax, %eax

-> 32           std::vector<int> result(rowsCols * rowsCols);
-> 33

->  0x555555557648 <+52>:   leaq   -0x231(%rbp), %rax
    0x55555555764f <+59>:   movq   %rax, %rdi
    0x555555557652 <+62>:   callq  0x555555555746            ; std::allocator<int>::allocator at allocator.h:156:7
    0x555555557657 <+67>:   movq   -0x258(%rbp), %rax
    0x55555555765e <+74>:   imulq  %rax, %rax
    0x555555557662 <+78>:   movq   %rax, %rcx
    0x555555557665 <+81>:   leaq   -0x231(%rbp), %rdx
    0x55555555766c <+88>:   movq   -0x248(%rbp), %rax
    0x555555557673 <+95>:   movq   %rcx, %rsi
    0x555555557676 <+98>:   movq   %rax, %rdi
    0x555555557679 <+101>:  callq  0x555555556fa8            ; std::vector<int, std::allocator<int> >::vector at stl_vector.h:510:7
    0x55555555767e <+106>:  leaq   -0x231(%rbp), %rax
    0x555555557685 <+113>:  movq   %rax, %rdi
    0x555555557688 <+116>:  callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7

** 34           for (size_t i = 0; i < rowsCols; i += 4) {

    0x55555555768d <+121>:  movq   $0x0, -0x230(%rbp)
    0x555555557698 <+132>:  jmp    0x555555557b1d            ; <+1289> at matrix_algorithms.cpp:34:23

** 35                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x55555555769d <+137>:  movq   $0x0, -0x228(%rbp)
    0x5555555576a8 <+148>:  jmp    0x555555557b01            ; <+1261> at matrix_algorithms.cpp:35:24

** 36                           __m128i row0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[i * rowsCols + j]));

    0x5555555576ad <+153>:  movq   -0x230(%rbp), %rax
    0x5555555576b4 <+160>:  imulq  -0x258(%rbp), %rax
    0x5555555576bc <+168>:  movq   %rax, %rdx
    0x5555555576bf <+171>:  movq   -0x228(%rbp), %rax
    0x5555555576c6 <+178>:  addq   %rax, %rdx
    0x5555555576c9 <+181>:  movq   -0x250(%rbp), %rax
    0x5555555576d0 <+188>:  movq   %rdx, %rsi
    0x5555555576d3 <+191>:  movq   %rax, %rdi
    0x5555555576d6 <+194>:  callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x5555555576db <+199>:  movq   %rax, -0x208(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x5555555576e2 <+206>:  movq   -0x208(%rbp), %rax
    0x5555555576e9 <+213>:  vmovdqu (%rax), %xmm0

** 36                           __m128i row0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[i * rowsCols + j]));

    0x5555555576ed <+217>:  vmovdqa %xmm0, -0x1e0(%rbp)

** 37                           __m128i row1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 1) * rowsCols + j]));

    0x5555555576f5 <+225>:  movq   -0x230(%rbp), %rax
    0x5555555576fc <+232>:  addq   $0x1, %rax
    0x555555557700 <+236>:  imulq  -0x258(%rbp), %rax
    0x555555557708 <+244>:  movq   %rax, %rdx
    0x55555555770b <+247>:  movq   -0x228(%rbp), %rax
    0x555555557712 <+254>:  addq   %rax, %rdx
    0x555555557715 <+257>:  movq   -0x250(%rbp), %rax
    0x55555555771c <+264>:  movq   %rdx, %rsi
    0x55555555771f <+267>:  movq   %rax, %rdi
    0x555555557722 <+270>:  callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x555555557727 <+275>:  movq   %rax, -0x210(%rbp)

** 703    return *__P;

    0x55555555772e <+282>:  movq   -0x210(%rbp), %rax
    0x555555557735 <+289>:  vmovdqu (%rax), %xmm0

** 37                           __m128i row1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 1) * rowsCols + j]));

    0x555555557739 <+293>:  vmovdqa %xmm0, -0x1d0(%rbp)

** 38                           __m128i row2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 2) * rowsCols + j]));

    0x555555557741 <+301>:  movq   -0x230(%rbp), %rax
    0x555555557748 <+308>:  addq   $0x2, %rax
    0x55555555774c <+312>:  imulq  -0x258(%rbp), %rax
    0x555555557754 <+320>:  movq   %rax, %rdx
    0x555555557757 <+323>:  movq   -0x228(%rbp), %rax
    0x55555555775e <+330>:  addq   %rax, %rdx
    0x555555557761 <+333>:  movq   -0x250(%rbp), %rax
    0x555555557768 <+340>:  movq   %rdx, %rsi
    0x55555555776b <+343>:  movq   %rax, %rdi
    0x55555555776e <+346>:  callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x555555557773 <+351>:  movq   %rax, -0x218(%rbp)

** 703    return *__P;

    0x55555555777a <+358>:  movq   -0x218(%rbp), %rax
    0x555555557781 <+365>:  vmovdqu (%rax), %xmm0

** 38                           __m128i row2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 2) * rowsCols + j]));

    0x555555557785 <+369>:  vmovdqa %xmm0, -0x1c0(%rbp)

** 39                           __m128i row3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 3) * rowsCols + j]));
   40
   41                           // _MM_TRANSPOSE4_EPI32(row0, row1, row2, row3);

    0x55555555778d <+377>:  movq   -0x230(%rbp), %rax
    0x555555557794 <+384>:  addq   $0x3, %rax
    0x555555557798 <+388>:  imulq  -0x258(%rbp), %rax
    0x5555555577a0 <+396>:  movq   %rax, %rdx
    0x5555555577a3 <+399>:  movq   -0x228(%rbp), %rax
    0x5555555577aa <+406>:  addq   %rax, %rdx
    0x5555555577ad <+409>:  movq   -0x250(%rbp), %rax
    0x5555555577b4 <+416>:  movq   %rdx, %rsi
    0x5555555577b7 <+419>:  movq   %rax, %rdi
    0x5555555577ba <+422>:  callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x5555555577bf <+427>:  movq   %rax, -0x220(%rbp)

** 703    return *__P;

    0x5555555577c6 <+434>:  movq   -0x220(%rbp), %rax
    0x5555555577cd <+441>:  vmovdqu (%rax), %xmm0

** 39                           __m128i row3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 3) * rowsCols + j]));

    0x5555555577d1 <+445>:  vmovdqa %xmm0, -0x1b0(%rbp)
    0x5555555577d9 <+453>:  vmovdqa -0x1e0(%rbp), %xmm0
    0x5555555577e1 <+461>:  vmovdqa %xmm0, -0x160(%rbp)
    0x5555555577e9 <+469>:  vmovdqa -0x1d0(%rbp), %xmm0
    0x5555555577f1 <+477>:  vmovdqa %xmm0, -0x150(%rbp)

   1040 _mm_unpacklo_epi32 (__m128i __A, __m128i __B)
   1041 {
** 1042   return (__m128i)__builtin_ia32_punpckldq128 ((__v4si)__A, (__v4si)__B);
   1043 }
   1044

    0x5555555577f9 <+485>:  vmovdqa -0x150(%rbp), %xmm1
    0x555555557801 <+493>:  vmovdqa -0x160(%rbp), %xmm0
    0x555555557809 <+501>:  vpunpckldq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]

** 42                           __m128i tmp0 = _mm_unpacklo_epi32(row0, row1);

    0x55555555780d <+505>:  vmovdqa %xmm0, -0x1a0(%rbp)
    0x555555557815 <+513>:  vmovdqa -0x1c0(%rbp), %xmm0
    0x55555555781d <+521>:  vmovdqa %xmm0, -0x140(%rbp)
    0x555555557825 <+529>:  vmovdqa -0x1b0(%rbp), %xmm0
    0x55555555782d <+537>:  vmovdqa %xmm0, -0x130(%rbp)

** 1042   return (__m128i)__builtin_ia32_punpckldq128 ((__v4si)__A, (__v4si)__B);

    0x555555557835 <+545>:  vmovdqa -0x130(%rbp), %xmm1
    0x55555555783d <+553>:  vmovdqa -0x140(%rbp), %xmm0
    0x555555557845 <+561>:  vpunpckldq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]

** 43                           __m128i tmp1 = _mm_unpacklo_epi32(row2, row3);

    0x555555557849 <+565>:  vmovdqa %xmm0, -0x190(%rbp)
    0x555555557851 <+573>:  vmovdqa -0x1e0(%rbp), %xmm0
    0x555555557859 <+581>:  vmovdqa %xmm0, -0x120(%rbp)
    0x555555557861 <+589>:  vmovdqa -0x1d0(%rbp), %xmm0
    0x555555557869 <+597>:  vmovdqa %xmm0, -0x110(%rbp)

   1016 _mm_unpackhi_epi32 (__m128i __A, __m128i __B)
   1017 {
** 1018   return (__m128i)__builtin_ia32_punpckhdq128 ((__v4si)__A, (__v4si)__B);
   1019 }
   1020

    0x555555557871 <+605>:  vmovdqa -0x110(%rbp), %xmm1
    0x555555557879 <+613>:  vmovdqa -0x120(%rbp), %xmm0
    0x555555557881 <+621>:  vpunpckhdq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[2],xmm1[2],xmm0[3],xmm1[3]

** 44                           __m128i tmp2 = _mm_unpackhi_epi32(row0, row1);

    0x555555557885 <+625>:  vmovdqa %xmm0, -0x180(%rbp)
    0x55555555788d <+633>:  vmovdqa -0x1c0(%rbp), %xmm0
    0x555555557895 <+641>:  vmovdqa %xmm0, -0x100(%rbp)
    0x55555555789d <+649>:  vmovdqa -0x1b0(%rbp), %xmm0
    0x5555555578a5 <+657>:  vmovdqa %xmm0, -0xf0(%rbp)

** 1018   return (__m128i)__builtin_ia32_punpckhdq128 ((__v4si)__A, (__v4si)__B);

    0x5555555578ad <+665>:  vmovdqa -0xf0(%rbp), %xmm1
    0x5555555578b5 <+673>:  vmovdqa -0x100(%rbp), %xmm0
    0x5555555578bd <+681>:  vpunpckhdq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[2],xmm1[2],xmm0[3],xmm1[3]

** 45                           __m128i tmp3 = _mm_unpackhi_epi32(row2, row3);
   46

    0x5555555578c1 <+685>:  vmovdqa %xmm0, -0x170(%rbp)
    0x5555555578c9 <+693>:  vmovdqa -0x1a0(%rbp), %xmm0
    0x5555555578d1 <+701>:  vmovdqa %xmm0, -0xe0(%rbp)
    0x5555555578d9 <+709>:  vmovdqa -0x190(%rbp), %xmm0
    0x5555555578e1 <+717>:  vmovdqa %xmm0, -0xd0(%rbp)

   1046 _mm_unpacklo_epi64 (__m128i __A, __m128i __B)
   1047 {
** 1048   return (__m128i)__builtin_ia32_punpcklqdq128 ((__v2di)__A, (__v2di)__B);
   1049 }
   1050

    0x5555555578e9 <+725>:  vmovdqa -0xe0(%rbp), %xmm0
    0x5555555578f1 <+733>:  vpunpcklqdq -0xd0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[0],mem[0]
    0x5555555578f9 <+741>:  nop

** 47                           row0 = _mm_unpacklo_epi64(tmp0, tmp1);

    0x5555555578fa <+742>:  vmovdqa %xmm0, -0x1e0(%rbp)
    0x555555557902 <+750>:  vmovdqa -0x1a0(%rbp), %xmm0
    0x55555555790a <+758>:  vmovdqa %xmm0, -0xc0(%rbp)
    0x555555557912 <+766>:  vmovdqa -0x190(%rbp), %xmm0
    0x55555555791a <+774>:  vmovdqa %xmm0, -0xb0(%rbp)

   1022 _mm_unpackhi_epi64 (__m128i __A, __m128i __B)
   1023 {
** 1024   return (__m128i)__builtin_ia32_punpckhqdq128 ((__v2di)__A, (__v2di)__B);
   1025 }
   1026

    0x555555557922 <+782>:  vmovdqa -0xc0(%rbp), %xmm0
    0x55555555792a <+790>:  vpunpckhqdq -0xb0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[1],mem[1]
    0x555555557932 <+798>:  nop

** 48                           row1 = _mm_unpackhi_epi64(tmp0, tmp1);

    0x555555557933 <+799>:  vmovdqa %xmm0, -0x1d0(%rbp)
    0x55555555793b <+807>:  vmovdqa -0x180(%rbp), %xmm0
    0x555555557943 <+815>:  vmovdqa %xmm0, -0xa0(%rbp)
    0x55555555794b <+823>:  vmovdqa -0x170(%rbp), %xmm0
    0x555555557953 <+831>:  vmovdqa %xmm0, -0x90(%rbp)

** 1048   return (__m128i)__builtin_ia32_punpcklqdq128 ((__v2di)__A, (__v2di)__B);

    0x55555555795b <+839>:  vmovdqa -0xa0(%rbp), %xmm0
    0x555555557963 <+847>:  vpunpcklqdq -0x90(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[0],mem[0]
    0x55555555796b <+855>:  nop

** 49                           row2 = _mm_unpacklo_epi64(tmp2, tmp3);

    0x55555555796c <+856>:  vmovdqa %xmm0, -0x1c0(%rbp)
    0x555555557974 <+864>:  vmovdqa -0x180(%rbp), %xmm0
    0x55555555797c <+872>:  vmovdqa %xmm0, -0x80(%rbp)
    0x555555557981 <+877>:  vmovdqa -0x170(%rbp), %xmm0
    0x555555557989 <+885>:  vmovdqa %xmm0, -0x70(%rbp)

** 1024   return (__m128i)__builtin_ia32_punpckhqdq128 ((__v2di)__A, (__v2di)__B);

    0x55555555798e <+890>:  vmovdqa -0x80(%rbp), %xmm0
    0x555555557993 <+895>:  vpunpckhqdq -0x70(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[1],mem[1]
    0x555555557998 <+900>:  nop

** 50                           row3 = _mm_unpackhi_epi64(tmp2, tmp3);
   51

    0x555555557999 <+901>:  vmovdqa %xmm0, -0x1b0(%rbp)

** 52                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[j * rowsCols + i]), row0);

    0x5555555579a1 <+909>:  movq   -0x228(%rbp), %rax
    0x5555555579a8 <+916>:  imulq  -0x258(%rbp), %rax
    0x5555555579b0 <+924>:  movq   %rax, %rdx
    0x5555555579b3 <+927>:  movq   -0x230(%rbp), %rax
    0x5555555579ba <+934>:  addq   %rax, %rdx
    0x5555555579bd <+937>:  movq   -0x248(%rbp), %rax
    0x5555555579c4 <+944>:  movq   %rdx, %rsi
    0x5555555579c7 <+947>:  movq   %rax, %rdi
    0x5555555579ca <+950>:  callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x5555555579cf <+955>:  movq   %rax, -0x1e8(%rbp)
    0x5555555579d6 <+962>:  vmovdqa -0x1e0(%rbp), %xmm0
    0x5555555579de <+970>:  vmovdqa %xmm0, -0x30(%rbp)

   737  _mm_storeu_si128 (__m128i_u *__P, __m128i __B)
   738  {
** 739    *__P = __B;

    0x5555555579e3 <+975>:  vmovdqa -0x30(%rbp), %xmm0
    0x5555555579e8 <+980>:  movq   -0x1e8(%rbp), %rax
    0x5555555579ef <+987>:  vmovdqu %xmm0, (%rax)

** 740  }
   741
   742  extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))

    0x5555555579f3 <+991>:  nop

** 53                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 1) * rowsCols + i]), row1);

    0x5555555579f4 <+992>:  movq   -0x228(%rbp), %rax
    0x5555555579fb <+999>:  addq   $0x1, %rax
    0x5555555579ff <+1003>: imulq  -0x258(%rbp), %rax
    0x555555557a07 <+1011>: movq   %rax, %rdx
    0x555555557a0a <+1014>: movq   -0x230(%rbp), %rax
    0x555555557a11 <+1021>: addq   %rax, %rdx
    0x555555557a14 <+1024>: movq   -0x248(%rbp), %rax
    0x555555557a1b <+1031>: movq   %rdx, %rsi
    0x555555557a1e <+1034>: movq   %rax, %rdi
    0x555555557a21 <+1037>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555557a26 <+1042>: movq   %rax, -0x1f0(%rbp)
    0x555555557a2d <+1049>: vmovdqa -0x1d0(%rbp), %xmm0
    0x555555557a35 <+1057>: vmovdqa %xmm0, -0x40(%rbp)

** 739    *__P = __B;

    0x555555557a3a <+1062>: vmovdqa -0x40(%rbp), %xmm0
    0x555555557a3f <+1067>: movq   -0x1f0(%rbp), %rax
    0x555555557a46 <+1074>: vmovdqu %xmm0, (%rax)

** 740  }

    0x555555557a4a <+1078>: nop

** 54                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 2) * rowsCols + i]), row2);

    0x555555557a4b <+1079>: movq   -0x228(%rbp), %rax
    0x555555557a52 <+1086>: addq   $0x2, %rax
    0x555555557a56 <+1090>: imulq  -0x258(%rbp), %rax
    0x555555557a5e <+1098>: movq   %rax, %rdx
    0x555555557a61 <+1101>: movq   -0x230(%rbp), %rax
    0x555555557a68 <+1108>: addq   %rax, %rdx
    0x555555557a6b <+1111>: movq   -0x248(%rbp), %rax
    0x555555557a72 <+1118>: movq   %rdx, %rsi
    0x555555557a75 <+1121>: movq   %rax, %rdi
    0x555555557a78 <+1124>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555557a7d <+1129>: movq   %rax, -0x1f8(%rbp)
    0x555555557a84 <+1136>: vmovdqa -0x1c0(%rbp), %xmm0
    0x555555557a8c <+1144>: vmovdqa %xmm0, -0x50(%rbp)

** 739    *__P = __B;

    0x555555557a91 <+1149>: vmovdqa -0x50(%rbp), %xmm0
    0x555555557a96 <+1154>: movq   -0x1f8(%rbp), %rax
    0x555555557a9d <+1161>: vmovdqu %xmm0, (%rax)

** 740  }

    0x555555557aa1 <+1165>: nop

** 55                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 3) * rowsCols + i]), row3);
   56                   }
   57           }

    0x555555557aa2 <+1166>: movq   -0x228(%rbp), %rax
    0x555555557aa9 <+1173>: addq   $0x3, %rax
    0x555555557aad <+1177>: imulq  -0x258(%rbp), %rax
    0x555555557ab5 <+1185>: movq   %rax, %rdx
    0x555555557ab8 <+1188>: movq   -0x230(%rbp), %rax
    0x555555557abf <+1195>: addq   %rax, %rdx
    0x555555557ac2 <+1198>: movq   -0x248(%rbp), %rax
    0x555555557ac9 <+1205>: movq   %rdx, %rsi
    0x555555557acc <+1208>: movq   %rax, %rdi
    0x555555557acf <+1211>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555557ad4 <+1216>: movq   %rax, -0x200(%rbp)
    0x555555557adb <+1223>: vmovdqa -0x1b0(%rbp), %xmm0
    0x555555557ae3 <+1231>: vmovdqa %xmm0, -0x60(%rbp)

** 739    *__P = __B;

    0x555555557ae8 <+1236>: vmovdqa -0x60(%rbp), %xmm0
    0x555555557aed <+1241>: movq   -0x200(%rbp), %rax
    0x555555557af4 <+1248>: vmovdqu %xmm0, (%rax)

** 740  }

    0x555555557af8 <+1252>: nop

** 35                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x555555557af9 <+1253>: addq   $0x4, -0x228(%rbp)
    0x555555557b01 <+1261>: movq   -0x228(%rbp), %rax
    0x555555557b08 <+1268>: cmpq   -0x258(%rbp), %rax
    0x555555557b0f <+1275>: jb     0x5555555576ad            ; <+153> at matrix_algorithms.cpp:36:73

** 34           for (size_t i = 0; i < rowsCols; i += 4) {

    0x555555557b15 <+1281>: addq   $0x4, -0x230(%rbp)
    0x555555557b1d <+1289>: movq   -0x230(%rbp), %rax
    0x555555557b24 <+1296>: cmpq   -0x258(%rbp), %rax
    0x555555557b2b <+1303>: jb     0x55555555769d            ; <+137> at matrix_algorithms.cpp:35:15

   58
** 59           return result;

    0x555555557b31 <+1309>: jmp    0x555555557b54            ; <+1344> at matrix_algorithms.cpp:60:1
    0x555555557b33 <+1311>: endbr64
    0x555555557b37 <+1315>: movq   %rax, %rbx
    0x555555557b3a <+1318>: leaq   -0x231(%rbp), %rax
    0x555555557b41 <+1325>: movq   %rax, %rdi
    0x555555557b44 <+1328>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7
    0x555555557b49 <+1333>: movq   %rbx, %rax
    0x555555557b4c <+1336>: movq   %rax, %rdi
    0x555555557b4f <+1339>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 60   }
   61
   62   // code lines: 64, 66, 67, 68, 70, 71, 72, 73, 74, 76, 80

    0x555555557b54 <+1344>: movq   -0x18(%rbp), %rax
    0x555555557b58 <+1348>: subq   %fs:0x28, %rax
    0x555555557b61 <+1357>: je     0x555555557b68            ; <+1364> at matrix_algorithms.cpp:60:1
    0x555555557b63 <+1359>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x555555557b68 <+1364>: movq   -0x248(%rbp), %rax
    0x555555557b6f <+1371>: movq   -0x8(%rbp), %rbx
    0x555555557b73 <+1375>: leave
    0x555555557b74 <+1376>: retq