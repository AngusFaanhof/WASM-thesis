0x555555557df1 <+0>:   endbr64
    0x555555557df5 <+4>:   pushq  %rbp
    0x555555557df6 <+5>:   movq   %rsp, %rbp
    0x555555557df9 <+8>:   pushq  %rbx
    0x555555557dfa <+9>:   subq   $0xf8, %rsp
    0x555555557e01 <+16>:  movq   %rdi, -0xe8(%rbp)
    0x555555557e08 <+23>:  movq   %rsi, -0xf0(%rbp)
    0x555555557e0f <+30>:  movq   %rdx, -0xf8(%rbp)
    0x555555557e16 <+37>:  movq   %rcx, -0x100(%rbp)

   82
   83   // code lines: 85, 87, 88, 89, 91, 92, 93, 94, 95, 97, 101
** 84   std::vector<int> multiplyMatrices(const std::vector<int>& A, const std::vector<int>& B, size_t rowsCols) {

    0x555555557e1d <+44>:  movq   %fs:0x28, %rax
    0x555555557e26 <+53>:  movq   %rax, -0x18(%rbp)
    0x555555557e2a <+57>:  xorl   %eax, %eax

-> 85           std::vector<int> result(rowsCols * rowsCols);
-> 86

->  0x555555557e2c <+59>:  leaq   -0xdd(%rbp), %rax
    0x555555557e33 <+66>:  movq   %rax, %rdi
    0x555555557e36 <+69>:  callq  0x555555555746            ; std::allocator<int>::allocator at allocator.h:156:7
    0x555555557e3b <+74>:  movq   -0x100(%rbp), %rax
    0x555555557e42 <+81>:  imulq  %rax, %rax
    0x555555557e46 <+85>:  movq   %rax, %rcx
    0x555555557e49 <+88>:  leaq   -0xdd(%rbp), %rdx
    0x555555557e50 <+95>:  movq   -0xe8(%rbp), %rax
    0x555555557e57 <+102>: movq   %rcx, %rsi
    0x555555557e5a <+105>: movq   %rax, %rdi
    0x555555557e5d <+108>: callq  0x555555556fa8            ; std::vector<int, std::allocator<int> >::vector at stl_vector.h:510:7
    0x555555557e62 <+113>: leaq   -0xdd(%rbp), %rax
    0x555555557e69 <+120>: movq   %rax, %rdi
    0x555555557e6c <+123>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7

** 87           for (size_t i = 0; i < rowsCols; i++) {

    0x555555557e71 <+128>: movq   $0x0, -0xc8(%rbp)
    0x555555557e7c <+139>: jmp    0x55555555806d            ; <+636> at matrix_algorithms.cpp:87:23

** 88                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x555555557e81 <+144>: movq   $0x0, -0xc0(%rbp)
    0x555555557e8c <+155>: jmp    0x555555558051            ; <+608> at matrix_algorithms.cpp:88:24

   794  _mm_setzero_si128 (void)
   795  {
** 796    return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 };
   797  }
   798

    0x555555557e91 <+160>: vpxor  %xmm0, %xmm0, %xmm0

** 89                           __m128i sum = _mm_setzero_si128();
   90

    0x555555557e95 <+164>: vmovdqa %xmm0, -0xa0(%rbp)

** 91                           for (size_t k = 0; k < rowsCols; k++) {

    0x555555557e9d <+172>: movq   $0x0, -0xb8(%rbp)
    0x555555557ea8 <+183>: jmp    0x555555557fec            ; <+507> at matrix_algorithms.cpp:91:25

** 92                                   __m128i a = _mm_set1_epi32(A[i * rowsCols + k]);

    0x555555557ead <+188>: movq   -0xc8(%rbp), %rax
    0x555555557eb4 <+195>: imulq  -0x100(%rbp), %rax
    0x555555557ebc <+203>: movq   %rax, %rdx
    0x555555557ebf <+206>: movq   -0xb8(%rbp), %rax
    0x555555557ec6 <+213>: addq   %rax, %rdx
    0x555555557ec9 <+216>: movq   -0xf0(%rbp), %rax
    0x555555557ed0 <+223>: movq   %rdx, %rsi
    0x555555557ed3 <+226>: movq   %rax, %rdi
    0x555555557ed6 <+229>: callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x555555557edb <+234>: movl   (%rax), %eax
    0x555555557edd <+236>: movl   %eax, -0xdc(%rbp)
    0x555555557ee3 <+242>: movl   -0xdc(%rbp), %eax
    0x555555557ee9 <+248>: movl   %eax, -0xd8(%rbp)
    0x555555557eef <+254>: movl   -0xdc(%rbp), %eax
    0x555555557ef5 <+260>: movl   %eax, -0xd4(%rbp)
    0x555555557efb <+266>: movl   -0xdc(%rbp), %eax
    0x555555557f01 <+272>: movl   %eax, -0xd0(%rbp)
    0x555555557f07 <+278>: movl   -0xdc(%rbp), %eax
    0x555555557f0d <+284>: movl   %eax, -0xcc(%rbp)

   602  _mm_set_epi32 (int __q3, int __q2, int __q1, int __q0)
   603  {
** 604    return __extension__ (__m128i)(__v4si){ __q0, __q1, __q2, __q3 };
   605  }
   606

    0x555555557f13 <+290>: movl   -0xd8(%rbp), %eax
    0x555555557f19 <+296>: movl   -0xd4(%rbp), %edx
    0x555555557f1f <+302>: vmovd  %edx, %xmm2
    0x555555557f23 <+306>: vpinsrd $0x1, %eax, %xmm2, %xmm1
    0x555555557f29 <+312>: movl   -0xd0(%rbp), %eax
    0x555555557f2f <+318>: movl   -0xcc(%rbp), %edx
    0x555555557f35 <+324>: vmovd  %edx, %xmm3
    0x555555557f39 <+328>: vpinsrd $0x1, %eax, %xmm3, %xmm0
    0x555555557f3f <+334>: vpunpcklqdq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0]

   642  _mm_set1_epi32 (int __A)
   643  {
** 644    return _mm_set_epi32 (__A, __A, __A, __A);
   645  }
   646

    0x555555557f43 <+338>: nop

** 92                                   __m128i a = _mm_set1_epi32(A[i * rowsCols + k]);

    0x555555557f44 <+339>: vmovdqa %xmm0, -0x90(%rbp)

** 93                                   __m128i b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[k * rowsCols + j]));

    0x555555557f4c <+347>: movq   -0xb8(%rbp), %rax
    0x555555557f53 <+354>: imulq  -0x100(%rbp), %rax
    0x555555557f5b <+362>: movq   %rax, %rdx
    0x555555557f5e <+365>: movq   -0xc0(%rbp), %rax
    0x555555557f65 <+372>: addq   %rax, %rdx
    0x555555557f68 <+375>: movq   -0xf8(%rbp), %rax
    0x555555557f6f <+382>: movq   %rdx, %rsi
    0x555555557f72 <+385>: movq   %rax, %rdi
    0x555555557f75 <+388>: callq  0x5555555581fa            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1061:7
    0x555555557f7a <+393>: movq   %rax, -0xb0(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x555555557f81 <+400>: movq   -0xb0(%rbp), %rax
    0x555555557f88 <+407>: vmovdqu (%rax), %xmm0

** 93                                   __m128i b = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&B[k * rowsCols + j]));

    0x555555557f8c <+411>: vmovdqa %xmm0, -0x80(%rbp)
    0x555555557f91 <+416>: vmovdqa -0x90(%rbp), %xmm0
    0x555555557f99 <+424>: vmovdqa %xmm0, -0x50(%rbp)
    0x555555557f9e <+429>: vmovdqa -0x80(%rbp), %xmm0
    0x555555557fa3 <+434>: vmovdqa %xmm0, -0x40(%rbp)

   326  _mm_mullo_epi32 (__m128i __X, __m128i __Y)
   327  {
** 328    return (__m128i) ((__v4su)__X * (__v4su)__Y);
   329  }
   330

    0x555555557fa8 <+439>: vmovdqa -0x50(%rbp), %xmm1
    0x555555557fad <+444>: vmovdqa -0x40(%rbp), %xmm0
    0x555555557fb2 <+449>: vpmulld %xmm0, %xmm1, %xmm0
    0x555555557fb7 <+454>: vmovdqa %xmm0, %xmm1
    0x555555557fbb <+458>: vmovdqa -0xa0(%rbp), %xmm0
    0x555555557fc3 <+466>: vmovdqa %xmm0, -0x70(%rbp)
    0x555555557fc8 <+471>: vmovdqa %xmm1, -0x60(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x555555557fcd <+476>: vmovdqa -0x70(%rbp), %xmm1
    0x555555557fd2 <+481>: vmovdqa -0x60(%rbp), %xmm0
    0x555555557fd7 <+486>: vpaddd %xmm0, %xmm1, %xmm0
    0x555555557fdb <+490>: nop

** 94                                   sum = _mm_add_epi32(sum, _mm_mullo_epi32(a, b));
   95                           }
   96

    0x555555557fdc <+491>: vmovdqa %xmm0, -0xa0(%rbp)

** 91                           for (size_t k = 0; k < rowsCols; k++) {

    0x555555557fe4 <+499>: addq   $0x1, -0xb8(%rbp)
    0x555555557fec <+507>: movq   -0xb8(%rbp), %rax
    0x555555557ff3 <+514>: cmpq   -0x100(%rbp), %rax
    0x555555557ffa <+521>: jb     0x555555557ead            ; <+188> at matrix_algorithms.cpp:92:36

** 97                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[i * rowsCols]), sum);
   98                   }
   99           }

    0x555555558000 <+527>: movq   -0xc8(%rbp), %rax
    0x555555558007 <+534>: imulq  -0x100(%rbp), %rax
    0x55555555800f <+542>: movq   %rax, %rdx
    0x555555558012 <+545>: movq   -0xe8(%rbp), %rax
    0x555555558019 <+552>: movq   %rdx, %rsi
    0x55555555801c <+555>: movq   %rax, %rdi
    0x55555555801f <+558>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555558024 <+563>: movq   %rax, -0xa8(%rbp)
    0x55555555802b <+570>: vmovdqa -0xa0(%rbp), %xmm0
    0x555555558033 <+578>: vmovdqa %xmm0, -0x30(%rbp)

   737  _mm_storeu_si128 (__m128i_u *__P, __m128i __B)
   738  {
** 739    *__P = __B;

    0x555555558038 <+583>: vmovdqa -0x30(%rbp), %xmm0
    0x55555555803d <+588>: movq   -0xa8(%rbp), %rax
    0x555555558044 <+595>: vmovdqu %xmm0, (%rax)

** 740  }
   741
   742  extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))

    0x555555558048 <+599>: nop

** 88                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x555555558049 <+600>: addq   $0x4, -0xc0(%rbp)
    0x555555558051 <+608>: movq   -0xc0(%rbp), %rax
    0x555555558058 <+615>: cmpq   -0x100(%rbp), %rax
    0x55555555805f <+622>: jb     0x555555557e91            ; <+160> [inlined] _mm_setzero_si128() at emmintrin.h:796:54

** 87           for (size_t i = 0; i < rowsCols; i++) {

    0x555555558065 <+628>: addq   $0x1, -0xc8(%rbp)
    0x55555555806d <+636>: movq   -0xc8(%rbp), %rax
    0x555555558074 <+643>: cmpq   -0x100(%rbp), %rax
    0x55555555807b <+650>: jb     0x555555557e81            ; <+144> at matrix_algorithms.cpp:88:15

   100
** 101          return result;

    0x555555558081 <+656>: jmp    0x5555555580a4            ; <+691> at matrix_algorithms.cpp:102:1
    0x555555558083 <+658>: endbr64
    0x555555558087 <+662>: movq   %rax, %rbx
    0x55555555808a <+665>: leaq   -0xdd(%rbp), %rax
    0x555555558091 <+672>: movq   %rax, %rdi
    0x555555558094 <+675>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7
    0x555555558099 <+680>: movq   %rbx, %rax
    0x55555555809c <+683>: movq   %rax, %rdi
    0x55555555809f <+686>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 102  }

    0x5555555580a4 <+691>: movq   -0x18(%rbp), %rax
    0x5555555580a8 <+695>: subq   %fs:0x28, %rax
    0x5555555580b1 <+704>: je     0x5555555580b8            ; <+711> at matrix_algorithms.cpp:102:1
    0x5555555580b3 <+706>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x5555555580b8 <+711>: movq   -0xe8(%rbp), %rax
    0x5555555580bf <+718>: movq   -0x8(%rbp), %rbx
    0x5555555580c3 <+722>: leave
    0x5555555580c4 <+723>: retq