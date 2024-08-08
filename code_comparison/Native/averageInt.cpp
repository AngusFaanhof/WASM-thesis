0x555555558b5d <+0>:   endbr64
    0x555555558b61 <+4>:   pushq  %rbp
    0x555555558b62 <+5>:   movq   %rsp, %rbp
    0x555555558b65 <+8>:   subq   $0x110, %rsp              ; imm = 0x110
    0x555555558b6c <+15>:  movq   %rdi, -0x108(%rbp)

-> 91       size_t size = vec.size();

->  0x555555558b73 <+22>:  movq   -0x108(%rbp), %rax
    0x555555558b7a <+29>:  movq   %rax, %rdi
    0x555555558b7d <+32>:  callq  0x5555555594ca            ; std::vector<int, std::allocator<int> >::size at stl_vector.h:918:7
    0x555555558b82 <+37>:  movq   %rax, -0xf0(%rbp)

   794  _mm_setzero_si128 (void)
   795  {
** 796    return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 };
   797  }
   798

    0x555555558b89 <+44>:  vpxor  %xmm0, %xmm0, %xmm0

** 92       __m128i sum_int = _mm_setzero_si128();
   93
   94       // sum of elements

    0x555555558b8d <+48>:  vmovdqa %xmm0, -0xe0(%rbp)

** 95       for (size_t i = 0; i < size; i += 4) {

    0x555555558b95 <+56>:  movq   $0x0, -0xf8(%rbp)
    0x555555558ba0 <+67>:  jmp    0x555555558c1a            ; <+189> at vector_algorithms.cpp:95:26

** 96           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x555555558ba2 <+69>:  movq   -0xf8(%rbp), %rdx
    0x555555558ba9 <+76>:  movq   -0x108(%rbp), %rax
    0x555555558bb0 <+83>:  movq   %rdx, %rsi
    0x555555558bb3 <+86>:  movq   %rax, %rdi
    0x555555558bb6 <+89>:  callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555558bbb <+94>:  movq   %rax, -0xe8(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x555555558bc2 <+101>: movq   -0xe8(%rbp), %rax
    0x555555558bc9 <+108>: vmovdqu (%rax), %xmm0

** 96           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x555555558bcd <+112>: vmovdqa %xmm0, -0xb0(%rbp)
    0x555555558bd5 <+120>: vmovdqa -0xe0(%rbp), %xmm0
    0x555555558bdd <+128>: vmovdqa %xmm0, -0xa0(%rbp)
    0x555555558be5 <+136>: vmovdqa -0xb0(%rbp), %xmm0
    0x555555558bed <+144>: vmovdqa %xmm0, -0x90(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x555555558bf5 <+152>: vmovdqa -0xa0(%rbp), %xmm1
    0x555555558bfd <+160>: vmovdqa -0x90(%rbp), %xmm0
    0x555555558c05 <+168>: vpaddd %xmm0, %xmm1, %xmm0
    0x555555558c09 <+172>: nop

** 97           sum_int = _mm_add_epi32(sum_int, values);
   98       }
   99

    0x555555558c0a <+173>: vmovdqa %xmm0, -0xe0(%rbp)

** 95       for (size_t i = 0; i < size; i += 4) {

    0x555555558c12 <+181>: addq   $0x4, -0xf8(%rbp)
    0x555555558c1a <+189>: movq   -0xf8(%rbp), %rax
    0x555555558c21 <+196>: cmpq   -0xf0(%rbp), %rax
    0x555555558c28 <+203>: jb     0x555555558ba2            ; <+69> at vector_algorithms.cpp:96:81
    0x555555558c2e <+209>: vmovdqa -0xe0(%rbp), %xmm0
    0x555555558c36 <+217>: vmovdqa %xmm0, -0x10(%rbp)

   806  _mm_cvtepi32_ps (__m128i __A)
   807  {
** 808    return (__m128)__builtin_ia32_cvtdq2ps ((__v4si) __A);
   809  }
   810

    0x555555558c3b <+222>: vmovdqa -0x10(%rbp), %xmm0
    0x555555558c40 <+227>: vcvtdq2ps %xmm0, %xmm0
    0x555555558c44 <+231>: nop

   100      // convert to float
** 101      __m128 sum = _mm_cvtepi32_ps(sum_int);
   102

    0x555555558c45 <+232>: vmovaps %xmm0, -0xd0(%rbp)

** 103      __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));
   104

    0x555555558c4d <+240>: movq   -0xf0(%rbp), %rax
    0x555555558c54 <+247>: testq  %rax, %rax
    0x555555558c57 <+250>: js     0x555555558c60            ; <+259> at vector_algorithms.cpp:103:32
    0x555555558c59 <+252>: vcvtsi2ss %rax, %xmm0, %xmm0
    0x555555558c5e <+257>: jmp    0x555555558c75            ; <+280> at vector_algorithms.cpp:103:32
    0x555555558c60 <+259>: movq   %rax, %rdx
    0x555555558c63 <+262>: shrq   %rdx
    0x555555558c66 <+265>: andl   $0x1, %eax
    0x555555558c69 <+268>: orq    %rax, %rdx
    0x555555558c6c <+271>: vcvtsi2ss %rdx, %xmm0, %xmm0
    0x555555558c71 <+276>: vaddss %xmm0, %xmm0, %xmm0
    0x555555558c75 <+280>: vmovss %xmm0, -0xfc(%rbp)

   892  _mm_set1_ps (float __F)
   893  {
** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };
   895  }
   896

    0x555555558c7d <+288>: vbroadcastss -0xfc(%rbp), %xmm0
    0x555555558c86 <+297>: vmovaps %xmm0, %xmm1
    0x555555558c8a <+301>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558c92 <+309>: vmovaps %xmm0, -0x30(%rbp)
    0x555555558c97 <+314>: vmovaps %xmm1, -0x20(%rbp)

   202  _mm_div_ps (__m128 __A, __m128 __B)
   203  {
** 204    return (__m128) ((__v4sf)__A / (__v4sf)__B);
   205  }
   206

    0x555555558c9c <+319>: vmovaps -0x30(%rbp), %xmm0
    0x555555558ca1 <+324>: vdivps -0x20(%rbp), %xmm0, %xmm0

** 103      __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));

    0x555555558ca6 <+329>: vmovaps %xmm0, -0xc0(%rbp)
    0x555555558cae <+337>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558cb6 <+345>: vmovaps %xmm0, -0x50(%rbp)
    0x555555558cbb <+350>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558cc3 <+358>: vmovaps %xmm0, -0x40(%rbp)

   57   _mm_hadd_ps (__m128 __X, __m128 __Y)
   58   {
** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);
   60   }
   61

    0x555555558cc8 <+363>: vmovaps -0x50(%rbp), %xmm0
    0x555555558ccd <+368>: vhaddps -0x40(%rbp), %xmm0, %xmm0
    0x555555558cd2 <+373>: nop

** 105      sum = _mm_hadd_ps(divided, divided);

    0x555555558cd3 <+374>: vmovaps %xmm0, -0xd0(%rbp)
    0x555555558cdb <+382>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558ce3 <+390>: vmovaps %xmm0, -0x70(%rbp)
    0x555555558ce8 <+395>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558cf0 <+403>: vmovaps %xmm0, -0x60(%rbp)

** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);

    0x555555558cf5 <+408>: vmovaps -0x70(%rbp), %xmm0
    0x555555558cfa <+413>: vhaddps -0x60(%rbp), %xmm0, %xmm0
    0x555555558cff <+418>: nop

** 106      sum = _mm_hadd_ps(sum, sum);
   107
   108      return _mm_cvtss_f32(sum);

    0x555555558d00 <+419>: vmovaps %xmm0, -0xd0(%rbp)
    0x555555558d08 <+427>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558d10 <+435>: vmovaps %xmm0, -0x80(%rbp)

   967  _mm_cvtss_f32 (__m128 __A)
   968  {
** 969    return ((__v4sf)__A)[0];
   970  }
   971

    0x555555558d15 <+440>: vmovaps -0x80(%rbp), %xmm0

** 109  }
   110
   111  float dotProduct(std::vector<float>& vecA, std::vector<float>& vecB) {

    0x555555558d1a <+445>: leave
    0x555555558d1b <+446>: retq