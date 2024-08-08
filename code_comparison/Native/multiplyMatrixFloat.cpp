0x555555557b75 <+0>:   endbr64
    0x555555557b79 <+4>:   pushq  %rbp
    0x555555557b7a <+5>:   movq   %rsp, %rbp
    0x555555557b7d <+8>:   pushq  %rbx
    0x555555557b7e <+9>:   subq   $0xe8, %rsp
    0x555555557b85 <+16>:  movq   %rdi, -0xd8(%rbp)
    0x555555557b8c <+23>:  movq   %rsi, -0xe0(%rbp)
    0x555555557b93 <+30>:  movq   %rdx, -0xe8(%rbp)
    0x555555557b9a <+37>:  movq   %rcx, -0xf0(%rbp)

   61
   62   // code lines: 64, 66, 67, 68, 70, 71, 72, 73, 74, 76, 80
** 63   std::vector<float> multiplyMatrices(const std::vector<float>& A, const std::vector<float>& B, size_t rowsCols) {

    0x555555557ba1 <+44>:  movq   %fs:0x28, %rax
    0x555555557baa <+53>:  movq   %rax, -0x18(%rbp)
    0x555555557bae <+57>:  xorl   %eax, %eax

-> 64           std::vector<float> result(rowsCols * rowsCols);
-> 65

->  0x555555557bb0 <+59>:  leaq   -0xcd(%rbp), %rax
    0x555555557bb7 <+66>:  movq   %rax, %rdi
    0x555555557bba <+69>:  callq  0x555555555854            ; std::allocator<float>::allocator at allocator.h:156:7
    0x555555557bbf <+74>:  movq   -0xf0(%rbp), %rax
    0x555555557bc6 <+81>:  imulq  %rax, %rax
    0x555555557bca <+85>:  movq   %rax, %rcx
    0x555555557bcd <+88>:  leaq   -0xcd(%rbp), %rdx
    0x555555557bd4 <+95>:  movq   -0xd8(%rbp), %rax
    0x555555557bdb <+102>: movq   %rcx, %rsi
    0x555555557bde <+105>: movq   %rax, %rdi
    0x555555557be1 <+108>: callq  0x555555558134            ; std::vector<float, std::allocator<float> >::vector at stl_vector.h:510:7
    0x555555557be6 <+113>: leaq   -0xcd(%rbp), %rax
    0x555555557bed <+120>: movq   %rax, %rdi
    0x555555557bf0 <+123>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7

** 66           for (size_t i = 0; i < rowsCols; i++) {

    0x555555557bf5 <+128>: movq   $0x0, -0xc8(%rbp)
    0x555555557c00 <+139>: jmp    0x555555557d99            ; <+548> at matrix_algorithms.cpp:66:23

** 67                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x555555557c05 <+144>: movq   $0x0, -0xc0(%rbp)
    0x555555557c10 <+155>: jmp    0x555555557d7d            ; <+520> at matrix_algorithms.cpp:67:24

   118  _mm_setzero_ps (void)
   119  {
** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
   121  }
   122

    0x555555557c15 <+160>: vxorps %xmm0, %xmm0, %xmm0

** 68                           __m128 sum = _mm_setzero_ps();
   69

    0x555555557c19 <+164>: vmovaps %xmm0, -0xa0(%rbp)

** 70                           for (size_t k = 0; k < rowsCols; k++) {

    0x555555557c21 <+172>: movq   $0x0, -0xb8(%rbp)
    0x555555557c2c <+183>: jmp    0x555555557d0e            ; <+409> at matrix_algorithms.cpp:70:25

** 71                                   __m128 a = _mm_set1_ps(A[i * rowsCols + k]);

    0x555555557c31 <+188>: movq   -0xc8(%rbp), %rax
    0x555555557c38 <+195>: imulq  -0xf0(%rbp), %rax
    0x555555557c40 <+203>: movq   %rax, %rdx
    0x555555557c43 <+206>: movq   -0xb8(%rbp), %rax
    0x555555557c4a <+213>: addq   %rax, %rdx
    0x555555557c4d <+216>: movq   -0xe0(%rbp), %rax
    0x555555557c54 <+223>: movq   %rdx, %rsi
    0x555555557c57 <+226>: movq   %rax, %rdi
    0x555555557c5a <+229>: callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x555555557c5f <+234>: vmovss (%rax), %xmm0             ; xmm0 = mem[0],zero,zero,zero
    0x555555557c63 <+238>: vmovss %xmm0, -0xcc(%rbp)

   892  _mm_set1_ps (float __F)
   893  {
** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };
   895  }
   896

    0x555555557c6b <+246>: vbroadcastss -0xcc(%rbp), %xmm0

** 71                                   __m128 a = _mm_set1_ps(A[i * rowsCols + k]);

    0x555555557c74 <+255>: vmovaps %xmm0, -0x90(%rbp)

** 72                                   __m128 b = _mm_loadu_ps(&B[k * rowsCols + j]);

    0x555555557c7c <+263>: movq   -0xb8(%rbp), %rax
    0x555555557c83 <+270>: imulq  -0xf0(%rbp), %rax
    0x555555557c8b <+278>: movq   %rax, %rdx
    0x555555557c8e <+281>: movq   -0xc0(%rbp), %rax
    0x555555557c95 <+288>: addq   %rax, %rdx
    0x555555557c98 <+291>: movq   -0xe8(%rbp), %rax
    0x555555557c9f <+298>: movq   %rdx, %rsi
    0x555555557ca2 <+301>: movq   %rax, %rdi
    0x555555557ca5 <+304>: callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x555555557caa <+309>: movq   %rax, -0xb0(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x555555557cb1 <+316>: movq   -0xb0(%rbp), %rax
    0x555555557cb8 <+323>: vmovups (%rax), %xmm0

** 72                                   __m128 b = _mm_loadu_ps(&B[k * rowsCols + j]);

    0x555555557cbc <+327>: vmovaps %xmm0, -0x80(%rbp)
    0x555555557cc1 <+332>: vmovaps -0x90(%rbp), %xmm0
    0x555555557cc9 <+340>: vmovaps %xmm0, -0x50(%rbp)
    0x555555557cce <+345>: vmovaps -0x80(%rbp), %xmm0
    0x555555557cd3 <+350>: vmovaps %xmm0, -0x40(%rbp)

   196  _mm_mul_ps (__m128 __A, __m128 __B)
   197  {
** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);
   199  }
   200

    0x555555557cd8 <+355>: vmovaps -0x50(%rbp), %xmm0
    0x555555557cdd <+360>: vmulps -0x40(%rbp), %xmm0, %xmm0
    0x555555557ce2 <+365>: vmovaps -0xa0(%rbp), %xmm1
    0x555555557cea <+373>: vmovaps %xmm1, -0x70(%rbp)
    0x555555557cef <+378>: vmovaps %xmm0, -0x60(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x555555557cf4 <+383>: vmovaps -0x70(%rbp), %xmm0
    0x555555557cf9 <+388>: vaddps -0x60(%rbp), %xmm0, %xmm0

** 73                                   sum = _mm_add_ps(sum, _mm_mul_ps(a, b));
   74                           }
   75

    0x555555557cfe <+393>: vmovaps %xmm0, -0xa0(%rbp)

** 70                           for (size_t k = 0; k < rowsCols; k++) {

    0x555555557d06 <+401>: addq   $0x1, -0xb8(%rbp)
    0x555555557d0e <+409>: movq   -0xb8(%rbp), %rax
    0x555555557d15 <+416>: cmpq   -0xf0(%rbp), %rax
    0x555555557d1c <+423>: jb     0x555555557c31            ; <+188> at matrix_algorithms.cpp:71:32

** 76                           _mm_storeu_ps(&result[i * rowsCols + j], sum);
   77                   }
   78           }

    0x555555557d22 <+429>: movq   -0xc8(%rbp), %rax
    0x555555557d29 <+436>: imulq  -0xf0(%rbp), %rax
    0x555555557d31 <+444>: movq   %rax, %rdx
    0x555555557d34 <+447>: movq   -0xc0(%rbp), %rax
    0x555555557d3b <+454>: addq   %rax, %rdx
    0x555555557d3e <+457>: movq   -0xd8(%rbp), %rax
    0x555555557d45 <+464>: movq   %rdx, %rsi
    0x555555557d48 <+467>: movq   %rax, %rdi
    0x555555557d4b <+470>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555557d50 <+475>: movq   %rax, -0xa8(%rbp)
    0x555555557d57 <+482>: vmovaps -0xa0(%rbp), %xmm0
    0x555555557d5f <+490>: vmovaps %xmm0, -0x30(%rbp)

   981  _mm_storeu_ps (float *__P, __m128 __A)
   982  {
** 983    *(__m128_u *)__P = __A;

    0x555555557d64 <+495>: vmovaps -0x30(%rbp), %xmm0
    0x555555557d69 <+500>: movq   -0xa8(%rbp), %rax
    0x555555557d70 <+507>: vmovups %xmm0, (%rax)

** 984  }
   985
   986  /* Store the lower SPFP value across four words.  */

    0x555555557d74 <+511>: nop

** 67                   for (size_t j = 0; j < rowsCols; j+=4) {

    0x555555557d75 <+512>: addq   $0x4, -0xc0(%rbp)
    0x555555557d7d <+520>: movq   -0xc0(%rbp), %rax
    0x555555557d84 <+527>: cmpq   -0xf0(%rbp), %rax
    0x555555557d8b <+534>: jb     0x555555557c15            ; <+160> [inlined] _mm_setzero_ps() at xmmintrin.h:120:57

** 66           for (size_t i = 0; i < rowsCols; i++) {

    0x555555557d91 <+540>: addq   $0x1, -0xc8(%rbp)
    0x555555557d99 <+548>: movq   -0xc8(%rbp), %rax
    0x555555557da0 <+555>: cmpq   -0xf0(%rbp), %rax
    0x555555557da7 <+562>: jb     0x555555557c05            ; <+144> at matrix_algorithms.cpp:67:15

   79
** 80           return result;

    0x555555557dad <+568>: jmp    0x555555557dd0            ; <+603> at matrix_algorithms.cpp:81:1
    0x555555557daf <+570>: endbr64
    0x555555557db3 <+574>: movq   %rax, %rbx
    0x555555557db6 <+577>: leaq   -0xcd(%rbp), %rax
    0x555555557dbd <+584>: movq   %rax, %rdi
    0x555555557dc0 <+587>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7
    0x555555557dc5 <+592>: movq   %rbx, %rax
    0x555555557dc8 <+595>: movq   %rax, %rdi
    0x555555557dcb <+598>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 81   }
   82
   83   // code lines: 85, 87, 88, 89, 91, 92, 93, 94, 95, 97, 101

    0x555555557dd0 <+603>: movq   -0x18(%rbp), %rax
    0x555555557dd4 <+607>: subq   %fs:0x28, %rax
    0x555555557ddd <+616>: je     0x555555557de4            ; <+623> at matrix_algorithms.cpp:81:1
    0x555555557ddf <+618>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x555555557de4 <+623>: movq   -0xd8(%rbp), %rax
    0x555555557deb <+630>: movq   -0x8(%rbp), %rbx
    0x555555557def <+634>: leave
    0x555555557df0 <+635>: retq