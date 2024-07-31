0x5555555567f5 <+0>:    endbr64
    0x5555555567f9 <+4>:    pushq  %rbp
    0x5555555567fa <+5>:    movq   %rsp, %rbp
    0x5555555567fd <+8>:    pushq  %rbx
    0x5555555567fe <+9>:    subq   $0x3c8, %rsp              ; imm = 0x3C8
    0x555555556805 <+16>:   movq   %rdi, -0x3b8(%rbp)
    0x55555555680c <+23>:   movl   %esi, -0x3bc(%rbp)
    0x555555556812 <+29>:   movl   %edx, -0x3c0(%rbp)
    0x555555556818 <+35>:   movl   %ecx, -0x3c4(%rbp)

   4    #include <iostream>
   5
** 6    std::vector<int> mandelbrot(int pixelWidth, int pixelHeight, int maxIterations) {

    0x55555555681e <+41>:   movq   %fs:0x28, %rax
    0x555555556827 <+50>:   movq   %rax, -0x18(%rbp)
    0x55555555682b <+54>:   xorl   %eax, %eax

-> 7        std::vector<int> mandelbrot(pixelWidth * pixelHeight);
-> 8

->  0x55555555682d <+56>:   leaq   -0x3ad(%rbp), %rax
    0x555555556834 <+63>:   movq   %rax, %rdi
    0x555555556837 <+66>:   callq  0x555555555746            ; std::allocator<int>::allocator at allocator.h:156:7
    0x55555555683c <+71>:   movl   -0x3bc(%rbp), %eax
    0x555555556842 <+77>:   imull  -0x3c0(%rbp), %eax
    0x555555556849 <+84>:   movslq %eax, %rcx
    0x55555555684c <+87>:   leaq   -0x3ad(%rbp), %rdx
    0x555555556853 <+94>:   movq   -0x3b8(%rbp), %rax
    0x55555555685a <+101>:  movq   %rcx, %rsi
    0x55555555685d <+104>:  movq   %rax, %rdi
    0x555555556860 <+107>:  callq  0x555555556fa8            ; std::vector<int, std::allocator<int> >::vector at stl_vector.h:510:7
    0x555555556865 <+112>:  leaq   -0x3ad(%rbp), %rax
    0x55555555686c <+119>:  movq   %rax, %rdi
    0x55555555686f <+122>:  callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7

** 9        float xScale = (REAL_MAX - REAL_MIN) / pixelWidth;

    0x555555556874 <+127>:  vcvtsi2ssl -0x3bc(%rbp), %xmm1, %xmm1
    0x55555555687c <+135>:  vmovss 0x3810(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556884 <+143>:  vdivss %xmm1, %xmm0, %xmm0
    0x555555556888 <+147>:  vmovss %xmm0, -0x3a0(%rbp)
    0x555555556890 <+155>:  vmovss -0x3a0(%rbp), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556898 <+163>:  vmovss %xmm0, -0x360(%rbp)

   892  _mm_set1_ps (float __F)
   893  {
** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };
   895  }
   896

    0x5555555568a0 <+171>:  vbroadcastss -0x360(%rbp), %xmm0

** 10       __m128 xScaleVector = _mm_set1_ps(xScale);
   11

    0x5555555568a9 <+180>:  vmovaps %xmm0, -0x310(%rbp)

** 12       float yScale = (IMAGINARY_MAX - IMAGINARY_MIN) / pixelHeight;
   13

    0x5555555568b1 <+188>:  vcvtsi2ssl -0x3c0(%rbp), %xmm1, %xmm1
    0x5555555568b9 <+196>:  vmovss 0x37d3(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x5555555568c1 <+204>:  vdivss %xmm1, %xmm0, %xmm0
    0x5555555568c5 <+208>:  vmovss %xmm0, -0x39c(%rbp)
    0x5555555568cd <+216>:  vmovss 0x37c3(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x5555555568d5 <+224>:  vmovss %xmm0, -0x364(%rbp)

** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };

    0x5555555568dd <+232>:  vbroadcastss -0x364(%rbp), %xmm0

** 14       __m128 realMin = _mm_set1_ps(REAL_MIN);

    0x5555555568e6 <+241>:  vmovaps %xmm0, -0x300(%rbp)
    0x5555555568ee <+249>:  vmovss 0x37a6(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x5555555568f6 <+257>:  vmovss %xmm0, -0x368(%rbp)

** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };

    0x5555555568fe <+265>:  vbroadcastss -0x368(%rbp), %xmm0

** 15       __m128 imaginaryMin = _mm_set1_ps(IMAGINARY_MIN);
   16

    0x555555556907 <+274>:  vmovaps %xmm0, -0x2f0(%rbp)
    0x55555555690f <+282>:  vmovss 0x3789(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556917 <+290>:  vmovss %xmm0, -0x36c(%rbp)

** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };

    0x55555555691f <+298>:  vbroadcastss -0x36c(%rbp), %xmm0

** 17       __m128 magnitudeThreshold = _mm_set1_ps(4.0f);

    0x555555556928 <+307>:  vmovaps %xmm0, -0x2e0(%rbp)
    0x555555556930 <+315>:  movl   $0x1, -0x380(%rbp)
    0x55555555693a <+325>:  movl   -0x380(%rbp), %eax
    0x555555556940 <+331>:  movl   %eax, -0x37c(%rbp)
    0x555555556946 <+337>:  movl   -0x380(%rbp), %eax
    0x55555555694c <+343>:  movl   %eax, -0x378(%rbp)
    0x555555556952 <+349>:  movl   -0x380(%rbp), %eax
    0x555555556958 <+355>:  movl   %eax, -0x374(%rbp)
    0x55555555695e <+361>:  movl   -0x380(%rbp), %eax
    0x555555556964 <+367>:  movl   %eax, -0x370(%rbp)

   602  _mm_set_epi32 (int __q3, int __q2, int __q1, int __q0)
   603  {
** 604    return __extension__ (__m128i)(__v4si){ __q0, __q1, __q2, __q3 };
   605  }
   606

    0x55555555696a <+373>:  movl   -0x37c(%rbp), %eax
    0x555555556970 <+379>:  movl   -0x378(%rbp), %edx
    0x555555556976 <+385>:  vmovd  %edx, %xmm4
    0x55555555697a <+389>:  vpinsrd $0x1, %eax, %xmm4, %xmm1
    0x555555556980 <+395>:  movl   -0x374(%rbp), %eax
    0x555555556986 <+401>:  movl   -0x370(%rbp), %edx
    0x55555555698c <+407>:  vmovd  %edx, %xmm5
    0x555555556990 <+411>:  vpinsrd $0x1, %eax, %xmm5, %xmm0
    0x555555556996 <+417>:  vpunpcklqdq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0]

   642  _mm_set1_epi32 (int __A)
   643  {
** 644    return _mm_set_epi32 (__A, __A, __A, __A);
   645  }
   646

    0x55555555699a <+421>:  nop

** 18       __m128i one = _mm_set1_epi32(1);

    0x55555555699b <+422>:  vmovdqa %xmm0, -0x2d0(%rbp)
    0x5555555569a3 <+430>:  movl   $0xffffffff, -0x394(%rbp) ; imm = 0xFFFFFFFF
    0x5555555569ad <+440>:  movl   -0x394(%rbp), %eax
    0x5555555569b3 <+446>:  movl   %eax, -0x390(%rbp)
    0x5555555569b9 <+452>:  movl   -0x394(%rbp), %eax
    0x5555555569bf <+458>:  movl   %eax, -0x38c(%rbp)
    0x5555555569c5 <+464>:  movl   -0x394(%rbp), %eax
    0x5555555569cb <+470>:  movl   %eax, -0x388(%rbp)
    0x5555555569d1 <+476>:  movl   -0x394(%rbp), %eax
    0x5555555569d7 <+482>:  movl   %eax, -0x384(%rbp)

** 604    return __extension__ (__m128i)(__v4si){ __q0, __q1, __q2, __q3 };

    0x5555555569dd <+488>:  movl   -0x390(%rbp), %eax
    0x5555555569e3 <+494>:  movl   -0x38c(%rbp), %edx
    0x5555555569e9 <+500>:  vmovd  %edx, %xmm6
    0x5555555569ed <+504>:  vpinsrd $0x1, %eax, %xmm6, %xmm1
    0x5555555569f3 <+510>:  movl   -0x388(%rbp), %eax
    0x5555555569f9 <+516>:  movl   -0x384(%rbp), %edx
    0x5555555569ff <+522>:  vmovd  %edx, %xmm7
    0x555555556a03 <+526>:  vpinsrd $0x1, %eax, %xmm7, %xmm0
    0x555555556a09 <+532>:  vpunpcklqdq %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0]

** 644    return _mm_set_epi32 (__A, __A, __A, __A);

    0x555555556a0d <+536>:  nop

** 19       __m128i minusOne = _mm_set1_epi32(-1);
   20

    0x555555556a0e <+537>:  vmovdqa %xmm0, -0x2c0(%rbp)
    0x555555556a16 <+545>:  vmovss 0x3686(%rip), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556a1e <+553>:  vmovss %xmm0, -0x398(%rbp)

** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };

    0x555555556a26 <+561>:  vbroadcastss -0x398(%rbp), %xmm0

** 21       __m128 two = _mm_set1_ps(2.0f);
   22

    0x555555556a2f <+570>:  vmovaps %xmm0, -0x2b0(%rbp)

** 23       for (int y = 0; y < pixelHeight; y++) {

    0x555555556a37 <+578>:  movl   $0x0, -0x3ac(%rbp)
    0x555555556a41 <+588>:  jmp    0x555555556ecc            ; <+1751> at mandelbrot.cpp:23:23

** 24           __m128 cImaginary = _mm_add_ps(imaginaryMin, _mm_set1_ps(y * yScale));
   25

    0x555555556a46 <+593>:  vcvtsi2ssl -0x3ac(%rbp), %xmm0, %xmm0
    0x555555556a4e <+601>:  vmulss -0x39c(%rbp), %xmm0, %xmm0
    0x555555556a56 <+609>:  vmovss %xmm0, -0x35c(%rbp)

** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };

    0x555555556a5e <+617>:  vbroadcastss -0x35c(%rbp), %xmm0
    0x555555556a67 <+626>:  vmovaps %xmm0, %xmm1
    0x555555556a6b <+630>:  vmovaps -0x2f0(%rbp), %xmm0
    0x555555556a73 <+638>:  vmovaps %xmm0, -0x220(%rbp)
    0x555555556a7b <+646>:  vmovaps %xmm1, -0x210(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x555555556a83 <+654>:  vmovaps -0x220(%rbp), %xmm0
    0x555555556a8b <+662>:  vaddps -0x210(%rbp), %xmm0, %xmm0

** 24           __m128 cImaginary = _mm_add_ps(imaginaryMin, _mm_set1_ps(y * yScale));

    0x555555556a93 <+670>:  vmovaps %xmm0, -0x2a0(%rbp)

** 26           for (int x = 0; x < pixelWidth; x += 4) {

    0x555555556a9b <+678>:  movl   $0x0, -0x3a8(%rbp)
    0x555555556aa5 <+688>:  jmp    0x555555556eb3            ; <+1726> at mandelbrot.cpp:26:27

** 27               __m128 cReal = _mm_add_ps(realMin, _mm_mul_ps(_mm_set_ps(x + 3, x + 2, x + 1, x), xScaleVector));
   28

    0x555555556aaa <+693>:  vcvtsi2ssl -0x3a8(%rbp), %xmm0, %xmm0
    0x555555556ab2 <+701>:  movl   -0x3a8(%rbp), %eax
    0x555555556ab8 <+707>:  addl   $0x1, %eax
    0x555555556abb <+710>:  vcvtsi2ss %eax, %xmm1, %xmm1
    0x555555556abf <+714>:  movl   -0x3a8(%rbp), %eax
    0x555555556ac5 <+720>:  addl   $0x2, %eax
    0x555555556ac8 <+723>:  vcvtsi2ss %eax, %xmm2, %xmm2
    0x555555556acc <+727>:  movl   -0x3a8(%rbp), %eax
    0x555555556ad2 <+733>:  addl   $0x3, %eax
    0x555555556ad5 <+736>:  vcvtsi2ss %eax, %xmm3, %xmm3
    0x555555556ad9 <+740>:  vmovss %xmm3, -0x358(%rbp)
    0x555555556ae1 <+748>:  vmovss %xmm2, -0x354(%rbp)
    0x555555556ae9 <+756>:  vmovss %xmm1, -0x350(%rbp)
    0x555555556af1 <+764>:  vmovss %xmm0, -0x34c(%rbp)

   947  _mm_set_ps (const float __Z, const float __Y, const float __X, const float __W)
   948  {
** 949    return __extension__ (__m128)(__v4sf){ __W, __X, __Y, __Z };
   950  }
   951

    0x555555556af9 <+772>:  vmovss -0x358(%rbp), %xmm1       ; xmm1 = mem[0],zero,zero,zero
    0x555555556b01 <+780>:  vmovss -0x354(%rbp), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556b09 <+788>:  vunpcklps %xmm1, %xmm0, %xmm1       ; xmm1 = xmm0[0],xmm1[0],xmm0[1],xmm1[1]
    0x555555556b0d <+792>:  vmovss -0x350(%rbp), %xmm2       ; xmm2 = mem[0],zero,zero,zero
    0x555555556b15 <+800>:  vmovss -0x34c(%rbp), %xmm0       ; xmm0 = mem[0],zero,zero,zero
    0x555555556b1d <+808>:  vunpcklps %xmm2, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm2[0],xmm0[1],xmm2[1]
    0x555555556b21 <+812>:  vmovlhps %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0]
    0x555555556b25 <+816>:  vmovaps %xmm0, -0x1e0(%rbp)
    0x555555556b2d <+824>:  vmovaps -0x310(%rbp), %xmm0
    0x555555556b35 <+832>:  vmovaps %xmm0, -0x1d0(%rbp)

   196  _mm_mul_ps (__m128 __A, __m128 __B)
   197  {
** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);
   199  }
   200

    0x555555556b3d <+840>:  vmovaps -0x1e0(%rbp), %xmm0
    0x555555556b45 <+848>:  vmulps -0x1d0(%rbp), %xmm0, %xmm0
    0x555555556b4d <+856>:  vmovaps -0x300(%rbp), %xmm1
    0x555555556b55 <+864>:  vmovaps %xmm1, -0x200(%rbp)
    0x555555556b5d <+872>:  vmovaps %xmm0, -0x1f0(%rbp)

** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);

    0x555555556b65 <+880>:  vmovaps -0x200(%rbp), %xmm0
    0x555555556b6d <+888>:  vaddps -0x1f0(%rbp), %xmm0, %xmm0

** 27               __m128 cReal = _mm_add_ps(realMin, _mm_mul_ps(_mm_set_ps(x + 3, x + 2, x + 1, x), xScaleVector));

    0x555555556b75 <+896>:  vmovaps %xmm0, -0x290(%rbp)

   118  _mm_setzero_ps (void)
   119  {
** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
   121  }
   122

    0x555555556b7d <+904>:  vxorps %xmm0, %xmm0, %xmm0

** 29               __m128 zReal = _mm_setzero_ps();

    0x555555556b81 <+908>:  vmovaps %xmm0, -0x340(%rbp)

** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };

    0x555555556b89 <+916>:  vxorps %xmm0, %xmm0, %xmm0

** 30               __m128 zImaginary = _mm_setzero_ps();
   31

    0x555555556b8d <+920>:  vmovaps %xmm0, -0x330(%rbp)

   794  _mm_setzero_si128 (void)
   795  {
** 796    return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 };
   797  }
   798

    0x555555556b95 <+928>:  vpxor  %xmm0, %xmm0, %xmm0

** 32               __m128i numIterations = _mm_setzero_si128();
   33

    0x555555556b99 <+932>:  vmovdqa %xmm0, -0x320(%rbp)

** 34               for (int i = 0; i < maxIterations; i++) {

    0x555555556ba1 <+940>:  movl   $0x0, -0x3a4(%rbp)
    0x555555556bab <+950>:  jmp    0x555555556e46            ; <+1617> at mandelbrot.cpp:34:31
    0x555555556bb0 <+955>:  vmovaps -0x340(%rbp), %xmm0
    0x555555556bb8 <+963>:  vmovaps %xmm0, -0x160(%rbp)
    0x555555556bc0 <+971>:  vmovaps -0x340(%rbp), %xmm0
    0x555555556bc8 <+979>:  vmovaps %xmm0, -0x150(%rbp)

** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);

    0x555555556bd0 <+987>:  vmovaps -0x160(%rbp), %xmm0
    0x555555556bd8 <+995>:  vmulps -0x150(%rbp), %xmm0, %xmm0

** 35                   __m128 zRealSquared = _mm_mul_ps(zReal, zReal);

    0x555555556be0 <+1003>: vmovaps %xmm0, -0x280(%rbp)
    0x555555556be8 <+1011>: vmovaps -0x330(%rbp), %xmm0
    0x555555556bf0 <+1019>: vmovaps %xmm0, -0x180(%rbp)
    0x555555556bf8 <+1027>: vmovaps -0x330(%rbp), %xmm0
    0x555555556c00 <+1035>: vmovaps %xmm0, -0x170(%rbp)

** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);

    0x555555556c08 <+1043>: vmovaps -0x180(%rbp), %xmm0
    0x555555556c10 <+1051>: vmulps -0x170(%rbp), %xmm0, %xmm0

** 36                   __m128 zImaginarySquared = _mm_mul_ps(zImaginary, zImaginary);
   37

    0x555555556c18 <+1059>: vmovaps %xmm0, -0x270(%rbp)
    0x555555556c20 <+1067>: vmovaps -0x280(%rbp), %xmm0
    0x555555556c28 <+1075>: vmovaps %xmm0, -0x1a0(%rbp)
    0x555555556c30 <+1083>: vmovaps -0x270(%rbp), %xmm0
    0x555555556c38 <+1091>: vmovaps %xmm0, -0x190(%rbp)

** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);

    0x555555556c40 <+1099>: vmovaps -0x1a0(%rbp), %xmm0
    0x555555556c48 <+1107>: vaddps -0x190(%rbp), %xmm0, %xmm0

** 38                   __m128 magnitude = _mm_add_ps(zRealSquared, zImaginarySquared);

    0x555555556c50 <+1115>: vmovaps %xmm0, -0x260(%rbp)
    0x555555556c58 <+1123>: vmovaps -0x260(%rbp), %xmm0
    0x555555556c60 <+1131>: vmovaps %xmm0, -0x1c0(%rbp)
    0x555555556c68 <+1139>: vmovaps -0x2e0(%rbp), %xmm0
    0x555555556c70 <+1147>: vmovaps %xmm0, -0x1b0(%rbp)

   366  _mm_cmplt_ps (__m128 __A, __m128 __B)
   367  {
** 368    return (__m128) __builtin_ia32_cmpltps ((__v4sf)__A, (__v4sf)__B);
   369  }
   370

    0x555555556c78 <+1155>: vmovaps -0x1c0(%rbp), %xmm0
    0x555555556c80 <+1163>: vcmpltps -0x1b0(%rbp), %xmm0, %xmm0
    0x555555556c89 <+1172>: nop
    0x555555556c8a <+1173>: vmovaps %xmm0, -0x120(%rbp)

   1580 _mm_castps_si128(__m128 __A)
   1581 {
** 1582   return (__m128i) __A;
   1583 }
   1584

    0x555555556c92 <+1181>: vmovdqa -0x120(%rbp), %xmm0

** 39                   __m128i mask = _mm_castps_si128(_mm_cmplt_ps(magnitude, magnitudeThreshold));
   40
   41                   // all iterations >= maxIterations

    0x555555556c9a <+1189>: vmovdqa %xmm0, -0x250(%rbp)
    0x555555556ca2 <+1197>: vmovdqa -0x250(%rbp), %xmm0
    0x555555556caa <+1205>: vmovdqa %xmm0, -0x140(%rbp)
    0x555555556cb2 <+1213>: vmovdqa -0x250(%rbp), %xmm0
    0x555555556cba <+1221>: vmovdqa %xmm0, -0x130(%rbp)

   67   _mm_testz_si128 (__m128i __M, __m128i __V)
   68   {
** 69     return __builtin_ia32_ptestz128 ((__v2di)__M, (__v2di)__V);
   70   }
   71

    0x555555556cc2 <+1229>: movl   $0x0, %eax
    0x555555556cc7 <+1234>: vmovdqa -0x140(%rbp), %xmm0
    0x555555556ccf <+1242>: vptest -0x130(%rbp), %xmm0
    0x555555556cd8 <+1251>: sete   %al
    0x555555556cdb <+1254>: nop

** 42                   if (_mm_testz_si128(mask, mask)) break;
   43

    0x555555556cdc <+1255>: testl  %eax, %eax
    0x555555556cde <+1257>: setne  %al
    0x555555556ce1 <+1260>: testb  %al, %al
    0x555555556ce3 <+1262>: jne    0x555555556e5a            ; <+1637> at mandelbrot.cpp:42:50
    0x555555556ce9 <+1268>: vmovdqa -0x250(%rbp), %xmm0
    0x555555556cf1 <+1276>: vmovdqa %xmm0, -0x50(%rbp)
    0x555555556cf6 <+1281>: vmovdqa -0x2d0(%rbp), %xmm0
    0x555555556cfe <+1289>: vmovdqa %xmm0, -0x40(%rbp)

   1309 _mm_and_si128 (__m128i __A, __m128i __B)
   1310 {
** 1311   return (__m128i) ((__v2du)__A & (__v2du)__B);
   1312 }
   1313

    0x555555556d03 <+1294>: vmovdqa -0x50(%rbp), %xmm1
    0x555555556d08 <+1299>: vmovdqa -0x40(%rbp), %xmm0
    0x555555556d0d <+1304>: vpand  %xmm0, %xmm1, %xmm0
    0x555555556d11 <+1308>: vmovdqa %xmm0, %xmm1
    0x555555556d15 <+1312>: vmovdqa -0x320(%rbp), %xmm0
    0x555555556d1d <+1320>: vmovdqa %xmm0, -0x70(%rbp)
    0x555555556d22 <+1325>: vmovdqa %xmm1, -0x60(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x555555556d27 <+1330>: vmovdqa -0x70(%rbp), %xmm1
    0x555555556d2c <+1335>: vmovdqa -0x60(%rbp), %xmm0
    0x555555556d31 <+1340>: vpaddd %xmm0, %xmm1, %xmm0

** 44                   numIterations = _mm_add_epi32(numIterations, _mm_and_si128(mask, one));
   45

    0x555555556d35 <+1344>: vmovdqa %xmm0, -0x320(%rbp)
    0x555555556d3d <+1352>: vmovaps -0x280(%rbp), %xmm0
    0x555555556d45 <+1360>: vmovaps %xmm0, -0x90(%rbp)
    0x555555556d4d <+1368>: vmovaps -0x270(%rbp), %xmm0
    0x555555556d55 <+1376>: vmovaps %xmm0, -0x80(%rbp)

   190  _mm_sub_ps (__m128 __A, __m128 __B)
   191  {
** 192    return (__m128) ((__v4sf)__A - (__v4sf)__B);
   193  }
   194

    0x555555556d5a <+1381>: vmovaps -0x90(%rbp), %xmm0
    0x555555556d62 <+1389>: vsubps -0x80(%rbp), %xmm0, %xmm0
    0x555555556d67 <+1394>: vmovaps %xmm0, -0xb0(%rbp)
    0x555555556d6f <+1402>: vmovaps -0x290(%rbp), %xmm0
    0x555555556d77 <+1410>: vmovaps %xmm0, -0xa0(%rbp)

** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);

    0x555555556d7f <+1418>: vmovaps -0xb0(%rbp), %xmm0
    0x555555556d87 <+1426>: vaddps -0xa0(%rbp), %xmm0, %xmm0

** 46                   __m128 newZReal = _mm_add_ps(_mm_sub_ps(zRealSquared, zImaginarySquared), cReal);

    0x555555556d8f <+1434>: vmovaps %xmm0, -0x240(%rbp)
    0x555555556d97 <+1442>: vmovaps -0x340(%rbp), %xmm0
    0x555555556d9f <+1450>: vmovaps %xmm0, -0xd0(%rbp)
    0x555555556da7 <+1458>: vmovaps -0x330(%rbp), %xmm0
    0x555555556daf <+1466>: vmovaps %xmm0, -0xc0(%rbp)

** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);

    0x555555556db7 <+1474>: vmovaps -0xd0(%rbp), %xmm0
    0x555555556dbf <+1482>: vmulps -0xc0(%rbp), %xmm0, %xmm0
    0x555555556dc7 <+1490>: vmovaps -0x2b0(%rbp), %xmm1
    0x555555556dcf <+1498>: vmovaps %xmm1, -0xf0(%rbp)
    0x555555556dd7 <+1506>: vmovaps %xmm0, -0xe0(%rbp)
    0x555555556ddf <+1514>: vmovaps -0xf0(%rbp), %xmm0
    0x555555556de7 <+1522>: vmulps -0xe0(%rbp), %xmm0, %xmm0
    0x555555556def <+1530>: vmovaps %xmm0, -0x110(%rbp)
    0x555555556df7 <+1538>: vmovaps -0x2a0(%rbp), %xmm0
    0x555555556dff <+1546>: vmovaps %xmm0, -0x100(%rbp)

** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);

    0x555555556e07 <+1554>: vmovaps -0x110(%rbp), %xmm0
    0x555555556e0f <+1562>: vaddps -0x100(%rbp), %xmm0, %xmm0

** 47                   __m128 newZImaginary = _mm_add_ps(_mm_mul_ps(two, _mm_mul_ps(zReal, zImaginary)), cImaginary);
   48

    0x555555556e17 <+1570>: vmovaps %xmm0, -0x230(%rbp)

** 49                   zReal = newZReal;

    0x555555556e1f <+1578>: vmovaps -0x240(%rbp), %xmm0
    0x555555556e27 <+1586>: vmovaps %xmm0, -0x340(%rbp)

** 50                   zImaginary = newZImaginary;
   51               }
   52

    0x555555556e2f <+1594>: vmovaps -0x230(%rbp), %xmm0
    0x555555556e37 <+1602>: vmovaps %xmm0, -0x330(%rbp)

** 34               for (int i = 0; i < maxIterations; i++) {

    0x555555556e3f <+1610>: addl   $0x1, -0x3a4(%rbp)
    0x555555556e46 <+1617>: movl   -0x3a4(%rbp), %eax
    0x555555556e4c <+1623>: cmpl   -0x3c4(%rbp), %eax
    0x555555556e52 <+1629>: jl     0x555555556bb0            ; <+955> at mandelbrot.cpp:34:13
    0x555555556e58 <+1635>: jmp    0x555555556e5b            ; <+1638> at mandelbrot.cpp:53:54

** 42                   if (_mm_testz_si128(mask, mask)) break;

    0x555555556e5a <+1637>: nop

** 53               _mm_storeu_si128((__m128i*)&mandelbrot[y * pixelWidth + x], numIterations);
   54           }
   55       }

    0x555555556e5b <+1638>: movl   -0x3ac(%rbp), %eax
    0x555555556e61 <+1644>: imull  -0x3bc(%rbp), %eax
    0x555555556e68 <+1651>: movl   %eax, %edx
    0x555555556e6a <+1653>: movl   -0x3a8(%rbp), %eax
    0x555555556e70 <+1659>: addl   %edx, %eax
    0x555555556e72 <+1661>: movslq %eax, %rdx
    0x555555556e75 <+1664>: movq   -0x3b8(%rbp), %rax
    0x555555556e7c <+1671>: movq   %rdx, %rsi
    0x555555556e7f <+1674>: movq   %rax, %rdi
    0x555555556e82 <+1677>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555556e87 <+1682>: movq   %rax, -0x348(%rbp)
    0x555555556e8e <+1689>: vmovdqa -0x320(%rbp), %xmm0
    0x555555556e96 <+1697>: vmovdqa %xmm0, -0x30(%rbp)

   737  _mm_storeu_si128 (__m128i_u *__P, __m128i __B)
   738  {
** 739    *__P = __B;

    0x555555556e9b <+1702>: vmovdqa -0x30(%rbp), %xmm0
    0x555555556ea0 <+1707>: movq   -0x348(%rbp), %rax
    0x555555556ea7 <+1714>: vmovdqu %xmm0, (%rax)

** 740  }
   741
   742  extern __inline void __attribute__((__gnu_inline__, __always_inline__, __artificial__))

    0x555555556eab <+1718>: nop

** 26           for (int x = 0; x < pixelWidth; x += 4) {

    0x555555556eac <+1719>: addl   $0x4, -0x3a8(%rbp)
    0x555555556eb3 <+1726>: movl   -0x3a8(%rbp), %eax
    0x555555556eb9 <+1732>: cmpl   -0x3bc(%rbp), %eax
    0x555555556ebf <+1738>: jl     0x555555556aaa            ; <+693> at mandelbrot.cpp:27:38

** 23       for (int y = 0; y < pixelHeight; y++) {

    0x555555556ec5 <+1744>: addl   $0x1, -0x3ac(%rbp)
    0x555555556ecc <+1751>: movl   -0x3ac(%rbp), %eax
    0x555555556ed2 <+1757>: cmpl   -0x3c0(%rbp), %eax
    0x555555556ed8 <+1763>: jl     0x555555556a46            ; <+593> at mandelbrot.cpp:24:39

   56
** 57       return mandelbrot;

    0x555555556ede <+1769>: jmp    0x555555556f01            ; <+1804> at mandelbrot.cpp:58:1
    0x555555556ee0 <+1771>: endbr64
    0x555555556ee4 <+1775>: movq   %rax, %rbx
    0x555555556ee7 <+1778>: leaq   -0x3ad(%rbp), %rax
    0x555555556eee <+1785>: movq   %rax, %rdi
    0x555555556ef1 <+1788>: callq  0x555555555766            ; std::allocator<int>::~allocator at allocator.h:174:7
    0x555555556ef6 <+1793>: movq   %rbx, %rax
    0x555555556ef9 <+1796>: movq   %rax, %rdi
    0x555555556efc <+1799>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 58   }

    0x555555556f01 <+1804>: movq   -0x18(%rbp), %rax
    0x555555556f05 <+1808>: subq   %fs:0x28, %rax
    0x555555556f0e <+1817>: je     0x555555556f15            ; <+1824> at mandelbrot.cpp:58:1
    0x555555556f10 <+1819>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x555555556f15 <+1824>: movq   -0x3b8(%rbp), %rax
    0x555555556f1c <+1831>: movq   -0x8(%rbp), %rbx
    0x555555556f20 <+1835>: leave
    0x555555556f21 <+1836>: retq