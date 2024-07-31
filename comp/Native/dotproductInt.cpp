0x555555558ebc <+0>:   endbr64
    0x555555558ec0 <+4>:   pushq  %rbp
    0x555555558ec1 <+5>:   movq   %rsp, %rbp
    0x555555558ec4 <+8>:   subq   $0x100, %rsp              ; imm = 0x100
    0x555555558ecb <+15>:  movq   %rdi, -0xf8(%rbp)
    0x555555558ed2 <+22>:  movq   %rsi, -0x100(%rbp)

-> 131      size_t size = vecA.size();

->  0x555555558ed9 <+29>:  movq   -0xf8(%rbp), %rax
    0x555555558ee0 <+36>:  movq   %rax, %rdi
    0x555555558ee3 <+39>:  callq  0x5555555594ca            ; std::vector<int, std::allocator<int> >::size at stl_vector.h:918:7
    0x555555558ee8 <+44>:  movq   %rax, -0xe8(%rbp)

   794  _mm_setzero_si128 (void)
   795  {
** 796    return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 };
   797  }
   798

    0x555555558eef <+51>:  vpxor  %xmm0, %xmm0, %xmm0

** 132      __m128i sum = _mm_setzero_si128();
   133

    0x555555558ef3 <+55>:  vmovdqa %xmm0, -0xd0(%rbp)

** 134      for (size_t i = 0; i < size; i += 4) {

    0x555555558efb <+63>:  movq   $0x0, -0xf0(%rbp)
    0x555555558f06 <+74>:  jmp    0x555555558fe1            ; <+293> at vector_algorithms.cpp:134:26

** 135          __m128i a = _mm_loadu_si128((__m128i*)&vecA[i]);

    0x555555558f0b <+79>:  movq   -0xf0(%rbp), %rdx
    0x555555558f12 <+86>:  movq   -0xf8(%rbp), %rax
    0x555555558f19 <+93>:  movq   %rdx, %rsi
    0x555555558f1c <+96>:  movq   %rax, %rdi
    0x555555558f1f <+99>:  callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555558f24 <+104>: movq   %rax, -0xd8(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x555555558f2b <+111>: movq   -0xd8(%rbp), %rax
    0x555555558f32 <+118>: vmovdqu (%rax), %xmm0

** 135          __m128i a = _mm_loadu_si128((__m128i*)&vecA[i]);

    0x555555558f36 <+122>: vmovdqa %xmm0, -0xc0(%rbp)

** 136          __m128i b = _mm_loadu_si128((__m128i*)&vecB[i]);
   137

    0x555555558f3e <+130>: movq   -0xf0(%rbp), %rdx
    0x555555558f45 <+137>: movq   -0x100(%rbp), %rax
    0x555555558f4c <+144>: movq   %rdx, %rsi
    0x555555558f4f <+147>: movq   %rax, %rdi
    0x555555558f52 <+150>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555558f57 <+155>: movq   %rax, -0xe0(%rbp)

** 703    return *__P;

    0x555555558f5e <+162>: movq   -0xe0(%rbp), %rax
    0x555555558f65 <+169>: vmovdqu (%rax), %xmm0

** 136          __m128i b = _mm_loadu_si128((__m128i*)&vecB[i]);

    0x555555558f69 <+173>: vmovdqa %xmm0, -0xb0(%rbp)
    0x555555558f71 <+181>: vmovdqa -0xc0(%rbp), %xmm0
    0x555555558f79 <+189>: vmovdqa %xmm0, -0x70(%rbp)
    0x555555558f7e <+194>: vmovdqa -0xb0(%rbp), %xmm0
    0x555555558f86 <+202>: vmovdqa %xmm0, -0x60(%rbp)

   326  _mm_mullo_epi32 (__m128i __X, __m128i __Y)
   327  {
** 328    return (__m128i) ((__v4su)__X * (__v4su)__Y);
   329  }
   330

    0x555555558f8b <+207>: vmovdqa -0x70(%rbp), %xmm1
    0x555555558f90 <+212>: vmovdqa -0x60(%rbp), %xmm0
    0x555555558f95 <+217>: vpmulld %xmm0, %xmm1, %xmm0

** 138          __m128i mul = _mm_mullo_epi32(a, b);
   139

    0x555555558f9a <+222>: vmovdqa %xmm0, -0xa0(%rbp)
    0x555555558fa2 <+230>: vmovdqa -0xd0(%rbp), %xmm0
    0x555555558faa <+238>: vmovdqa %xmm0, -0x90(%rbp)
    0x555555558fb2 <+246>: vmovdqa -0xa0(%rbp), %xmm0
    0x555555558fba <+254>: vmovdqa %xmm0, -0x80(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x555555558fbf <+259>: vmovdqa -0x90(%rbp), %xmm1
    0x555555558fc7 <+267>: vmovdqa -0x80(%rbp), %xmm0
    0x555555558fcc <+272>: vpaddd %xmm0, %xmm1, %xmm0
    0x555555558fd0 <+276>: nop

** 140          sum = _mm_add_epi32(sum, mul);
   141      }
   142

    0x555555558fd1 <+277>: vmovdqa %xmm0, -0xd0(%rbp)

** 134      for (size_t i = 0; i < size; i += 4) {

    0x555555558fd9 <+285>: addq   $0x4, -0xf0(%rbp)
    0x555555558fe1 <+293>: movq   -0xf0(%rbp), %rax
    0x555555558fe8 <+300>: cmpq   -0xe8(%rbp), %rax
    0x555555558fef <+307>: jb     0x555555558f0b            ; <+79> at vector_algorithms.cpp:135:54
    0x555555558ff5 <+313>: vmovdqa -0xd0(%rbp), %xmm0
    0x555555558ffd <+321>: vmovdqa %xmm0, -0x20(%rbp)
    0x555555559002 <+326>: vmovdqa -0xd0(%rbp), %xmm0
    0x55555555900a <+334>: vmovdqa %xmm0, -0x10(%rbp)

   46   _mm_hadd_epi32 (__m128i __X, __m128i __Y)
   47   {
** 48     return (__m128i) __builtin_ia32_phaddd128 ((__v4si)__X, (__v4si)__Y);
   49   }
   50

    0x55555555900f <+339>: vmovdqa -0x10(%rbp), %xmm1
    0x555555559014 <+344>: vmovdqa -0x20(%rbp), %xmm0
    0x555555559019 <+349>: vphaddd %xmm1, %xmm0, %xmm0

** 143      sum = _mm_hadd_epi32(sum, sum);

    0x55555555901e <+354>: vmovdqa %xmm0, -0xd0(%rbp)
    0x555555559026 <+362>: vmovdqa -0xd0(%rbp), %xmm0
    0x55555555902e <+370>: vmovdqa %xmm0, -0x40(%rbp)
    0x555555559033 <+375>: vmovdqa -0xd0(%rbp), %xmm0
    0x55555555903b <+383>: vmovdqa %xmm0, -0x30(%rbp)

** 48     return (__m128i) __builtin_ia32_phaddd128 ((__v4si)__X, (__v4si)__Y);

    0x555555559040 <+388>: vmovdqa -0x30(%rbp), %xmm1
    0x555555559045 <+393>: vmovdqa -0x40(%rbp), %xmm0
    0x55555555904a <+398>: vphaddd %xmm1, %xmm0, %xmm0

** 144      sum = _mm_hadd_epi32(sum, sum);
   145
   146      return _mm_cvtsi128_si32(sum);

    0x55555555904f <+403>: vmovdqa %xmm0, -0xd0(%rbp)
    0x555555559057 <+411>: vmovdqa -0xd0(%rbp), %xmm0
    0x55555555905f <+419>: vmovdqa %xmm0, -0x50(%rbp)

   224  _mm_cvtsi128_si32 (__m128i __A)
   225  {
** 226    return __builtin_ia32_vec_ext_v4si ((__v4si)__A, 0);
   227  }
   228

    0x555555559064 <+424>: vmovdqa -0x50(%rbp), %xmm0
    0x555555559069 <+429>: vmovd  %xmm0, %eax
    0x55555555906d <+433>: nop

** 147  }
   148
   149  std::vector<float> vectorAddition(std::vector<float>& a, std::vector<float>& b) {

    0x55555555906e <+434>: leave
    0x55555555906f <+435>: retq