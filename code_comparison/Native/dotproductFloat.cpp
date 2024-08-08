0x555555558d1c <+0>:   endbr64
    0x555555558d20 <+4>:   pushq  %rbp
    0x555555558d21 <+5>:   movq   %rsp, %rbp
    0x555555558d24 <+8>:   subq   $0x100, %rsp              ; imm = 0x100
    0x555555558d2b <+15>:  movq   %rdi, -0xf8(%rbp)
    0x555555558d32 <+22>:  movq   %rsi, -0x100(%rbp)

-> 112      size_t size = vecA.size();

->  0x555555558d39 <+29>:  movq   -0xf8(%rbp), %rax
    0x555555558d40 <+36>:  movq   %rax, %rdi
    0x555555558d43 <+39>:  callq  0x555555559466            ; std::vector<float, std::allocator<float> >::size at stl_vector.h:918:7
    0x555555558d48 <+44>:  movq   %rax, -0xe8(%rbp)

   118  _mm_setzero_ps (void)
   119  {
** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
   121  }
   122

    0x555555558d4f <+51>:  vxorps %xmm0, %xmm0, %xmm0

** 113      __m128 sum = _mm_setzero_ps();
   114

    0x555555558d53 <+55>:  vmovaps %xmm0, -0xd0(%rbp)

** 115      for (int i = 0; i < size; i += 4) {

    0x555555558d5b <+63>:  movl   $0x0, -0xec(%rbp)
    0x555555558d65 <+73>:  jmp    0x555555558e39            ; <+285> at vector_algorithms.cpp:115:21

** 116          __m128 a = _mm_loadu_ps(&vecA[i]);

    0x555555558d6a <+78>:  movl   -0xec(%rbp), %eax
    0x555555558d70 <+84>:  movslq %eax, %rdx
    0x555555558d73 <+87>:  movq   -0xf8(%rbp), %rax
    0x555555558d7a <+94>:  movq   %rdx, %rsi
    0x555555558d7d <+97>:  movq   %rax, %rdi
    0x555555558d80 <+100>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555558d85 <+105>: movq   %rax, -0xd8(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x555555558d8c <+112>: movq   -0xd8(%rbp), %rax
    0x555555558d93 <+119>: vmovups (%rax), %xmm0

** 116          __m128 a = _mm_loadu_ps(&vecA[i]);

    0x555555558d97 <+123>: vmovaps %xmm0, -0xc0(%rbp)

** 117          __m128 b = _mm_loadu_ps(&vecB[i]);
   118

    0x555555558d9f <+131>: movl   -0xec(%rbp), %eax
    0x555555558da5 <+137>: movslq %eax, %rdx
    0x555555558da8 <+140>: movq   -0x100(%rbp), %rax
    0x555555558daf <+147>: movq   %rdx, %rsi
    0x555555558db2 <+150>: movq   %rax, %rdi
    0x555555558db5 <+153>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555558dba <+158>: movq   %rax, -0xe0(%rbp)

** 934    return *(__m128_u *)__P;

    0x555555558dc1 <+165>: movq   -0xe0(%rbp), %rax
    0x555555558dc8 <+172>: vmovups (%rax), %xmm0

** 117          __m128 b = _mm_loadu_ps(&vecB[i]);

    0x555555558dcc <+176>: vmovaps %xmm0, -0xb0(%rbp)
    0x555555558dd4 <+184>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558ddc <+192>: vmovaps %xmm0, -0x70(%rbp)
    0x555555558de1 <+197>: vmovaps -0xb0(%rbp), %xmm0
    0x555555558de9 <+205>: vmovaps %xmm0, -0x60(%rbp)

   196  _mm_mul_ps (__m128 __A, __m128 __B)
   197  {
** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);
   199  }
   200

    0x555555558dee <+210>: vmovaps -0x70(%rbp), %xmm0
    0x555555558df3 <+215>: vmulps -0x60(%rbp), %xmm0, %xmm0

** 119          __m128 mul = _mm_mul_ps(a, b);
   120

    0x555555558df8 <+220>: vmovaps %xmm0, -0xa0(%rbp)
    0x555555558e00 <+228>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558e08 <+236>: vmovaps %xmm0, -0x90(%rbp)
    0x555555558e10 <+244>: vmovaps -0xa0(%rbp), %xmm0
    0x555555558e18 <+252>: vmovaps %xmm0, -0x80(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x555555558e1d <+257>: vmovaps -0x90(%rbp), %xmm0
    0x555555558e25 <+265>: vaddps -0x80(%rbp), %xmm0, %xmm0

** 121          sum = _mm_add_ps(sum, mul);
   122      }
   123

    0x555555558e2a <+270>: vmovaps %xmm0, -0xd0(%rbp)

** 115      for (int i = 0; i < size; i += 4) {

    0x555555558e32 <+278>: addl   $0x4, -0xec(%rbp)
    0x555555558e39 <+285>: movl   -0xec(%rbp), %eax
    0x555555558e3f <+291>: cltq
    0x555555558e41 <+293>: cmpq   %rax, -0xe8(%rbp)
    0x555555558e48 <+300>: ja     0x555555558d6a            ; <+78> at vector_algorithms.cpp:116:40
    0x555555558e4e <+306>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558e56 <+314>: vmovaps %xmm0, -0x20(%rbp)
    0x555555558e5b <+319>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558e63 <+327>: vmovaps %xmm0, -0x10(%rbp)

   57   _mm_hadd_ps (__m128 __X, __m128 __Y)
   58   {
** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);
   60   }
   61

    0x555555558e68 <+332>: vmovaps -0x20(%rbp), %xmm0
    0x555555558e6d <+337>: vhaddps -0x10(%rbp), %xmm0, %xmm0
    0x555555558e72 <+342>: nop

** 124      sum = _mm_hadd_ps(sum, sum);

    0x555555558e73 <+343>: vmovaps %xmm0, -0xd0(%rbp)
    0x555555558e7b <+351>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558e83 <+359>: vmovaps %xmm0, -0x40(%rbp)
    0x555555558e88 <+364>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558e90 <+372>: vmovaps %xmm0, -0x30(%rbp)

** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);

    0x555555558e95 <+377>: vmovaps -0x40(%rbp), %xmm0
    0x555555558e9a <+382>: vhaddps -0x30(%rbp), %xmm0, %xmm0
    0x555555558e9f <+387>: nop

** 125      sum = _mm_hadd_ps(sum, sum);
   126
   127      return _mm_cvtss_f32(sum);

    0x555555558ea0 <+388>: vmovaps %xmm0, -0xd0(%rbp)
    0x555555558ea8 <+396>: vmovaps -0xd0(%rbp), %xmm0
    0x555555558eb0 <+404>: vmovaps %xmm0, -0x50(%rbp)

   967  _mm_cvtss_f32 (__m128 __A)
   968  {
** 969    return ((__v4sf)__A)[0];
   970  }
   971

    0x555555558eb5 <+409>: vmovaps -0x50(%rbp), %xmm0

** 128  }
   129
   130  int dotProduct(std::vector<int>& vecA, std::vector<int>& vecB) {

    0x555555558eba <+414>: leave
    0x555555558ebb <+415>: retq