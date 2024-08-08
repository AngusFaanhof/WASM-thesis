0x7ffff7729270 <+0>:    pushq  %rbp
    0x7ffff7729271 <+1>:    movq   %rsp, %rbp
    0x7ffff7729274 <+4>:    movq   0x8(%rdi), %r10
    0x7ffff7729278 <+8>:    movq   (%r10), %r10
    0x7ffff772927b <+11>:   addq   $0x10, %r10
    0x7ffff772927f <+15>:   cmpq   %rsp, %r10
    0x7ffff7729282 <+18>:   ja     0x7ffff7729e5c            ; <+3052> at mandelbrot.cpp:58:1
    0x7ffff7729288 <+24>:   subq   $0x40, %rsp
    0x7ffff772928c <+28>:   movq   %rbx, 0x10(%rsp)
    0x7ffff7729291 <+33>:   movq   %r12, 0x18(%rsp)
    0x7ffff7729296 <+38>:   movq   %r13, 0x20(%rsp)
    0x7ffff772929b <+43>:   movq   %r14, 0x28(%rsp)
    0x7ffff77292a0 <+48>:   movq   %r15, 0x30(%rsp)
    0x7ffff77292a5 <+53>:   movl   0x110(%rdi), %r15d
    0x7ffff77292ac <+60>:   movq   %r15, %r12
    0x7ffff77292af <+63>:   subl   $0x790, %r12d             ; imm = 0x790
    0x7ffff77292b6 <+70>:   movl   %r12d, 0x110(%rdi)
    0x7ffff77292bd <+77>:   movq   0x100(%rdi), %r13
    0x7ffff77292c4 <+84>:   leaq   (%r13,%r12), %r14
    0x7ffff77292c9 <+89>:   movl   %edx, 0x17c(%r13,%r12)
    0x7ffff77292d1 <+97>:   movq   %rdx, (%rsp)
    0x7ffff77292d5 <+101>:  movl   %ecx, 0x178(%r13,%r12)
    0x7ffff77292dd <+109>:  movl   %r8d, 0x174(%r13,%r12)
    0x7ffff77292e5 <+117>:  movl   %r9d, 0x170(%r13,%r12)
    0x7ffff77292ed <+125>:  xorl   %edx, %edx

-> 7        std::vector<int> mandelbrot(pixelWidth * pixelHeight);
-> 8

->  0x7ffff77292ef <+127>:  movb   %dl, 0x16f(%r13,%r12)
    0x7ffff77292f7 <+135>:  movl   0x178(%r13,%r12), %ecx
    0x7ffff77292ff <+143>:  imull  0x174(%r14), %ecx
    0x7ffff7729307 <+151>:  movq   %rdi, %rbx
    0x7ffff772930a <+154>:  movq   (%rsp), %rdx
    0x7ffff772930e <+158>:  movq   %rbx, %rsi
    0x7ffff7729311 <+161>:  movq   %rbx, %rdi
    0x7ffff7729314 <+164>:  callq  0x7ffff7729e90            ; std::__2::vector<int, std::__2::allocator<int> >::vector at vector:1191

** 9        float xScale = (REAL_MAX - REAL_MIN) / pixelWidth;

    0x7ffff7729319 <+169>:  movl   0x178(%r13,%r12), %r8d
    0x7ffff7729321 <+177>:  movl   $0x40400000, %edx         ; imm = 0x40400000
    0x7ffff7729326 <+182>:  vmovd  %edx, %xmm5
    0x7ffff772932a <+186>:  vxorps %xmm2, %xmm2, %xmm4
    0x7ffff772932e <+190>:  vcvtsi2ss %r8d, %xmm4, %xmm6
    0x7ffff7729333 <+195>:  vdivss %xmm6, %xmm5, %xmm4
    0x7ffff7729337 <+199>:  vmovss %xmm4, 0x168(%r13,%r12)

** 10       __m128 xScaleVector = _mm_set1_ps(xScale);
   11

    0x7ffff7729341 <+209>:  vmovss %xmm4, 0x194(%r13,%r12)
    0x7ffff772934b <+219>:  vmovss %xmm4, 0x3ec(%r13,%r12)
    0x7ffff7729355 <+229>:  movl   0x3ec(%r13,%r12), %r11d
    0x7ffff772935d <+237>:  vmovd  %r11d, %xmm6
    0x7ffff7729362 <+242>:  vpbroadcastd %xmm6, %xmm0
    0x7ffff7729367 <+247>:  vmovdqu %xmm0, 0x3d0(%r13,%r12)
    0x7ffff7729371 <+257>:  vmovdqu %xmm0, 0x150(%r13,%r12)

** 12       float yScale = (IMAGINARY_MAX - IMAGINARY_MIN) / pixelHeight;
   13

    0x7ffff772937b <+267>:  vxorps %xmm7, %xmm7, %xmm1
    0x7ffff772937f <+271>:  vcvtsi2ssl 0x174(%r14), %xmm1, %xmm3
    0x7ffff7729388 <+280>:  vdivss %xmm3, %xmm5, %xmm1
    0x7ffff772938c <+284>:  vmovss %xmm1, 0x14c(%r13,%r12)
    0x7ffff7729396 <+294>:  movl   $0xc0000000, %eax         ; imm = 0xC0000000

** 14       __m128 realMin = _mm_set1_ps(REAL_MIN);

    0x7ffff772939b <+299>:  movl   %eax, 0x190(%r13,%r12)
    0x7ffff77293a3 <+307>:  vmovss 0x190(%r13,%r12), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff77293ad <+317>:  vmovss %xmm3, 0x40c(%r13,%r12)
    0x7ffff77293b7 <+327>:  movl   0x40c(%r13,%r12), %edx
    0x7ffff77293bf <+335>:  vmovd  %edx, %xmm3
    0x7ffff77293c3 <+339>:  vpbroadcastd %xmm3, %xmm5
    0x7ffff77293c8 <+344>:  vmovdqu %xmm5, 0x3f0(%r13,%r12)
    0x7ffff77293d2 <+354>:  vmovdqu %xmm5, 0x130(%r13,%r12)
    0x7ffff77293dc <+364>:  movl   $0xbfc00000, %r9d         ; imm = 0xBFC00000

** 15       __m128 imaginaryMin = _mm_set1_ps(IMAGINARY_MIN);
   16

    0x7ffff77293e2 <+370>:  movl   %r9d, 0x18c(%r13,%r12)
    0x7ffff77293ea <+378>:  vmovss 0x18c(%r13,%r12), %xmm7   ; xmm7 = mem[0],zero,zero,zero
    0x7ffff77293f4 <+388>:  vmovss %xmm7, 0x42c(%r13,%r12)
    0x7ffff77293fe <+398>:  movl   0x42c(%r13,%r12), %r11d
    0x7ffff7729406 <+406>:  vmovd  %r11d, %xmm7
    0x7ffff772940b <+411>:  vpbroadcastd %xmm7, %xmm1
    0x7ffff7729410 <+416>:  vmovdqu %xmm1, 0x410(%r13,%r12)
    0x7ffff772941a <+426>:  vmovdqu %xmm1, 0x120(%r13,%r12)

** 17       __m128 magnitudeThreshold = _mm_set1_ps(4.0f);

    0x7ffff7729424 <+436>:  movl   $0x40800000, 0x188(%r13,%r12) ; imm = 0x40800000
    0x7ffff7729430 <+448>:  vmovss 0x188(%r13,%r12), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff772943a <+458>:  vmovss %xmm3, 0x44c(%r13,%r12)
    0x7ffff7729444 <+468>:  movl   0x44c(%r13,%r12), %ecx
    0x7ffff772944c <+476>:  vmovd  %ecx, %xmm3
    0x7ffff7729450 <+480>:  vpbroadcastd %xmm3, %xmm5
    0x7ffff7729455 <+485>:  vmovdqu %xmm5, 0x430(%r13,%r12)
    0x7ffff772945f <+495>:  vmovdqu %xmm5, 0x110(%r13,%r12)

** 18       __m128i one = _mm_set1_epi32(1);

    0x7ffff7729469 <+505>:  movl   $0x1, 0x19c(%r13,%r12)
    0x7ffff7729475 <+517>:  movl   $0x1, 0x4ac(%r13,%r12)
    0x7ffff7729481 <+529>:  vmovdqu 0x9d7(%rip), %xmm0        ; <+3056> at mandelbrot.cpp:58:1
    0x7ffff7729489 <+537>:  vmovdqu %xmm0, 0x490(%r13,%r12)
    0x7ffff7729493 <+547>:  vmovdqu %xmm0, 0x100(%r13,%r12)
    0x7ffff772949d <+557>:  movl   $0xffffffff, %esi         ; imm = 0xFFFFFFFF

** 19       __m128i minusOne = _mm_set1_epi32(-1);
   20

    0x7ffff77294a2 <+562>:  movl   %esi, 0x198(%r13,%r12)
    0x7ffff77294aa <+570>:  movl   %esi, 0x4cc(%r13,%r12)
    0x7ffff77294b2 <+578>:  vmovdqu 0x9b6(%rip), %xmm4        ; <+3072> at mandelbrot.cpp:58:1
    0x7ffff77294ba <+586>:  vmovdqu %xmm4, 0x4b0(%r13,%r12)
    0x7ffff77294c4 <+596>:  vmovdqu %xmm4, 0xf0(%r13,%r12)

** 21       __m128 two = _mm_set1_ps(2.0f);
   22

    0x7ffff77294ce <+606>:  movl   $0x40000000, 0x184(%r13,%r12) ; imm = 0x40000000
    0x7ffff77294da <+618>:  vmovss 0x184(%r13,%r12), %xmm7   ; xmm7 = mem[0],zero,zero,zero
    0x7ffff77294e4 <+628>:  vmovss %xmm7, 0x46c(%r13,%r12)
    0x7ffff77294ee <+638>:  movl   0x46c(%r13,%r12), %r9d
    0x7ffff77294f6 <+646>:  vmovd  %r9d, %xmm7
    0x7ffff77294fb <+651>:  vpbroadcastd %xmm7, %xmm1
    0x7ffff7729500 <+656>:  vmovdqu %xmm1, 0x450(%r13,%r12)
    0x7ffff772950a <+666>:  vmovdqu %xmm1, 0xe0(%r13,%r12)

** 23       for (int y = 0; y < pixelHeight; y++) {

    0x7ffff7729514 <+676>:  movl   $0x0, 0xdc(%r13,%r12)
    0x7ffff7729520 <+688>:  movl   0xdc(%r13,%r12), %edi
    0x7ffff7729528 <+696>:  movl   0x174(%r13,%r12), %eax
    0x7ffff7729530 <+704>:  cmpl   %eax, %edi
    0x7ffff7729532 <+706>:  jge    0x7ffff7729e00            ; <+2960> at mandelbrot.cpp:23:5

** 24           __m128 cImaginary = _mm_add_ps(imaginaryMin, _mm_set1_ps(y * yScale));
   25

    0x7ffff7729538 <+712>:  vmovdqu 0x120(%r13,%r12), %xmm6
    0x7ffff7729542 <+722>:  movl   0xdc(%r13,%r12), %ecx
    0x7ffff772954a <+730>:  vmovss 0x14c(%r13,%r12), %xmm7   ; xmm7 = mem[0],zero,zero,zero
    0x7ffff7729554 <+740>:  vxorps %xmm4, %xmm4, %xmm0
    0x7ffff7729558 <+744>:  vcvtsi2ss %ecx, %xmm0, %xmm0
    0x7ffff772955c <+748>:  vmulss %xmm7, %xmm0, %xmm7
    0x7ffff7729560 <+752>:  vmovss %xmm7, 0x180(%r13,%r12)
    0x7ffff772956a <+762>:  vmovss %xmm7, 0x48c(%r13,%r12)
    0x7ffff7729574 <+772>:  movl   0x48c(%r13,%r12), %r8d
    0x7ffff772957c <+780>:  vmovd  %r8d, %xmm7
    0x7ffff7729581 <+785>:  vpbroadcastd %xmm7, %xmm1
    0x7ffff7729586 <+790>:  vmovdqu %xmm1, 0x470(%r13,%r12)
    0x7ffff7729590 <+800>:  vmovdqu %xmm6, 0x230(%r13,%r12)
    0x7ffff772959a <+810>:  vmovdqu %xmm1, 0x220(%r13,%r12)
    0x7ffff77295a4 <+820>:  vmovdqu 0x230(%r13,%r12), %xmm3
    0x7ffff77295ae <+830>:  vmovdqu %xmm3, 0x4e0(%r13,%r12)
    0x7ffff77295b8 <+840>:  vmovdqu %xmm1, 0x4d0(%r13,%r12)
    0x7ffff77295c2 <+850>:  vmovdqu 0x4e0(%r13,%r12), %xmm5
    0x7ffff77295cc <+860>:  vaddps %xmm1, %xmm5, %xmm5
    0x7ffff77295d0 <+864>:  vmovdqu %xmm5, 0xc0(%r13,%r12)

** 26           for (int x = 0; x < pixelWidth; x += 4) {

    0x7ffff77295da <+874>:  movl   $0x0, 0xbc(%r13,%r12)
    0x7ffff77295e6 <+886>:  movl   0xbc(%r13,%r12), %edx
    0x7ffff77295ee <+894>:  movl   0x178(%r13,%r12), %r8d
    0x7ffff77295f6 <+902>:  cmpl   %r8d, %edx
    0x7ffff77295f9 <+905>:  jge    0x7ffff7729dee            ; <+2942> at mandelbrot.cpp:26:9

** 27               __m128 cReal = _mm_add_ps(realMin, _mm_mul_ps(_mm_set_ps(x + 3, x + 2, x + 1, x), xScaleVector));
   28

    0x7ffff77295ff <+911>:  vmovdqu 0x130(%r13,%r12), %xmm2
    0x7ffff7729609 <+921>:  movl   0xbc(%r13,%r12), %r9d
    0x7ffff7729611 <+929>:  leal   0x3(%r9), %r10d
    0x7ffff7729615 <+933>:  vxorps %xmm0, %xmm0, %xmm3
    0x7ffff7729619 <+937>:  vcvtsi2ss %r10d, %xmm3, %xmm4
    0x7ffff772961e <+942>:  vmovss %xmm4, 0x2ec(%r13,%r12)
    0x7ffff7729628 <+952>:  leal   0x2(%r9), %r10d
    0x7ffff772962c <+956>:  vxorps %xmm1, %xmm1, %xmm3
    0x7ffff7729630 <+960>:  vcvtsi2ss %r10d, %xmm3, %xmm5
    0x7ffff7729635 <+965>:  vmovss %xmm5, 0x2e8(%r13,%r12)
    0x7ffff772963f <+975>:  leal   0x1(%r9), %r11d
    0x7ffff7729643 <+979>:  vxorps %xmm3, %xmm3, %xmm4
    0x7ffff7729647 <+983>:  vcvtsi2ss %r11d, %xmm4, %xmm6
    0x7ffff772964c <+988>:  vmovss %xmm6, 0x2e4(%r13,%r12)
    0x7ffff7729656 <+998>:  vxorps %xmm3, %xmm3, %xmm5
    0x7ffff772965a <+1002>: vcvtsi2ss %r9d, %xmm5, %xmm7
    0x7ffff772965f <+1007>: vmovss %xmm7, 0x2e0(%r13,%r12)
    0x7ffff7729669 <+1017>: vmovss 0x2e4(%r13,%r12), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff7729673 <+1027>: vmovss 0x2e8(%r13,%r12), %xmm1   ; xmm1 = mem[0],zero,zero,zero
    0x7ffff772967d <+1037>: vmovss 0x2ec(%r13,%r12), %xmm6   ; xmm6 = mem[0],zero,zero,zero
    0x7ffff7729687 <+1047>: vmovss %xmm7, 0x62c(%r13,%r12)
    0x7ffff7729691 <+1057>: vmovss %xmm0, 0x628(%r13,%r12)
    0x7ffff772969b <+1067>: vmovss %xmm1, 0x624(%r13,%r12)
    0x7ffff77296a5 <+1077>: vmovss %xmm6, 0x620(%r13,%r12)
    0x7ffff77296af <+1087>: vmovss 0x628(%r13,%r12), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff77296b9 <+1097>: vmovss 0x624(%r13,%r12), %xmm4   ; xmm4 = mem[0],zero,zero,zero
    0x7ffff77296c3 <+1107>: movl   0x62c(%r13,%r12), %r8d
    0x7ffff77296cb <+1115>: vmovd  %r8d, %xmm1
    0x7ffff77296d0 <+1120>: vpbroadcastd %xmm1, %xmm5
    0x7ffff77296d5 <+1125>: vinsertps $0x10, %xmm3, %xmm5, %xmm3 ; xmm3 = xmm5[0],xmm3[0],xmm5[2,3]
    0x7ffff77296db <+1131>: vinsertps $0x20, %xmm4, %xmm3, %xmm3 ; xmm3 = xmm3[0,1],xmm4[0],xmm3[3]
    0x7ffff77296e1 <+1137>: vinsertps $0x30, %xmm6, %xmm3, %xmm4 ; xmm4 = xmm3[0,1,2],xmm6[0]
    0x7ffff77296e7 <+1143>: vmovdqu %xmm4, 0x610(%r13,%r12)
    0x7ffff77296f1 <+1153>: vmovdqu 0x150(%r13,%r12), %xmm3
    0x7ffff77296fb <+1163>: vmovdqu %xmm4, 0x2d0(%r13,%r12)
    0x7ffff7729705 <+1173>: vmovdqu %xmm3, 0x2c0(%r13,%r12)
    0x7ffff772970f <+1183>: vmovdqu 0x2d0(%r13,%r12), %xmm5
    0x7ffff7729719 <+1193>: vmovdqu %xmm5, 0x580(%r13,%r12)
    0x7ffff7729723 <+1203>: vmovdqu %xmm3, 0x570(%r13,%r12)
    0x7ffff772972d <+1213>: vmovdqu 0x580(%r13,%r12), %xmm7
    0x7ffff7729737 <+1223>: vmovdqu %xmm2, 0x210(%r13,%r12)
    0x7ffff7729741 <+1233>: vmulps %xmm3, %xmm7, %xmm0
    0x7ffff7729745 <+1237>: vmovdqu %xmm0, 0x200(%r13,%r12)
    0x7ffff772974f <+1247>: vmovdqu 0x210(%r13,%r12), %xmm1
    0x7ffff7729759 <+1257>: vmovdqu %xmm1, 0x500(%r13,%r12)
    0x7ffff7729763 <+1267>: vmovdqu %xmm0, 0x4f0(%r13,%r12)
    0x7ffff772976d <+1277>: vmovdqu 0x500(%r13,%r12), %xmm3
    0x7ffff7729777 <+1287>: vaddps %xmm0, %xmm3, %xmm3
    0x7ffff772977b <+1291>: vmovdqu %xmm3, 0xa0(%r13,%r12)

** 29               __m128 zReal = _mm_setzero_ps();

    0x7ffff7729785 <+1301>: movl   $0x0, 0x64c(%r13,%r12)
    0x7ffff7729791 <+1313>: movl   $0x0, 0x648(%r13,%r12)
    0x7ffff772979d <+1325>: movl   $0x0, 0x644(%r13,%r12)
    0x7ffff77297a9 <+1337>: movl   $0x0, 0x640(%r13,%r12)
    0x7ffff77297b5 <+1349>: vmovss 0x648(%r13,%r12), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff77297bf <+1359>: vmovss 0x644(%r13,%r12), %xmm1   ; xmm1 = mem[0],zero,zero,zero
    0x7ffff77297c9 <+1369>: vmovss 0x640(%r13,%r12), %xmm2   ; xmm2 = mem[0],zero,zero,zero
    0x7ffff77297d3 <+1379>: movl   0x64c(%r13,%r12), %edi
    0x7ffff77297db <+1387>: vmovd  %edi, %xmm7
    0x7ffff77297df <+1391>: vpbroadcastd %xmm7, %xmm3
    0x7ffff77297e4 <+1396>: vinsertps $0x10, %xmm0, %xmm3, %xmm0 ; xmm0 = xmm3[0],xmm0[0],xmm3[2,3]
    0x7ffff77297ea <+1402>: vinsertps $0x20, %xmm1, %xmm0, %xmm0 ; xmm0 = xmm0[0,1],xmm1[0],xmm0[3]
    0x7ffff77297f0 <+1408>: vinsertps $0x30, %xmm2, %xmm0, %xmm0 ; xmm0 = xmm0[0,1,2],xmm2[0]
    0x7ffff77297f6 <+1414>: vmovdqu %xmm0, 0x630(%r13,%r12)
    0x7ffff7729800 <+1424>: vmovdqu %xmm0, 0x90(%r13,%r12)

** 30               __m128 zImaginary = _mm_setzero_ps();
   31

    0x7ffff772980a <+1434>: movl   $0x0, 0x66c(%r13,%r12)
    0x7ffff7729816 <+1446>: movl   $0x0, 0x668(%r13,%r12)
    0x7ffff7729822 <+1458>: movl   $0x0, 0x664(%r13,%r12)
    0x7ffff772982e <+1470>: movl   $0x0, 0x660(%r13,%r12)
    0x7ffff772983a <+1482>: vmovss 0x668(%r13,%r12), %xmm6   ; xmm6 = mem[0],zero,zero,zero
    0x7ffff7729844 <+1492>: vmovss 0x664(%r13,%r12), %xmm7   ; xmm7 = mem[0],zero,zero,zero
    0x7ffff772984e <+1502>: vmovss 0x660(%r13,%r12), %xmm0   ; xmm0 = mem[0],zero,zero,zero
    0x7ffff7729858 <+1512>: movl   0x66c(%r13,%r12), %r10d
    0x7ffff7729860 <+1520>: vmovd  %r10d, %xmm5
    0x7ffff7729865 <+1525>: vpbroadcastd %xmm5, %xmm1
    0x7ffff772986a <+1530>: vinsertps $0x10, %xmm6, %xmm1, %xmm6 ; xmm6 = xmm1[0],xmm6[0],xmm1[2,3]
    0x7ffff7729870 <+1536>: vinsertps $0x20, %xmm7, %xmm6, %xmm6 ; xmm6 = xmm6[0,1],xmm7[0],xmm6[3]
    0x7ffff7729876 <+1542>: vinsertps $0x30, %xmm0, %xmm6, %xmm6 ; xmm6 = xmm6[0,1,2],xmm0[0]
    0x7ffff772987c <+1548>: vmovdqu %xmm6, 0x650(%r13,%r12)
    0x7ffff7729886 <+1558>: vmovdqu %xmm6, 0x80(%r13,%r12)

** 32               __m128i numIterations = _mm_setzero_si128();
   33

    0x7ffff7729890 <+1568>: movq   $0x0, 0x688(%r13,%r12)
    0x7ffff772989c <+1580>: movq   $0x0, 0x680(%r13,%r12)
    0x7ffff77298a8 <+1592>: movq   0x688(%r13,%r12), %rax
    0x7ffff77298b0 <+1600>: vmovq  %rax, %xmm1
    0x7ffff77298b5 <+1605>: vpshufd $0x44, %xmm1, %xmm3       ; xmm3 = xmm1[0,1,0,1]
    0x7ffff77298ba <+1610>: vpinsrq $0x1, 0x5bc(%rip), %xmm3, %xmm2 ; <+3087> at mandelbrot.cpp:58:1
    0x7ffff77298c4 <+1620>: vmovdqu %xmm2, 0x670(%r13,%r12)
    0x7ffff77298ce <+1630>: vmovdqu %xmm2, 0x70(%r13,%r12)

** 34               for (int i = 0; i < maxIterations; i++) {

    0x7ffff77298d5 <+1637>: movl   $0x0, 0x6c(%r13,%r12)
    0x7ffff77298de <+1646>: movl   $0xffffff90, %r8d         ; imm = 0xFFFFFF90
    0x7ffff77298e4 <+1652>: movl   $0xffffff60, %r9d         ; imm = 0xFFFFFF60
    0x7ffff77298ea <+1658>: movl   0x6c(%r13,%r12), %r10d
    0x7ffff77298ef <+1663>: movl   0x170(%r13,%r12), %r11d
    0x7ffff77298f7 <+1671>: cmpl   %r11d, %r10d
    0x7ffff77298fa <+1674>: jge    0x7ffff7729d8f            ; <+2847> at mandelbrot.cpp:53:52

** 35                   __m128 zRealSquared = _mm_mul_ps(zReal, zReal);

    0x7ffff7729900 <+1680>: vmovdqu 0x90(%r13,%r12), %xmm1
    0x7ffff772990a <+1690>: vmovdqu %xmm1, 0x2b0(%r13,%r12)
    0x7ffff7729914 <+1700>: vmovdqu %xmm1, 0x2a0(%r13,%r12)
    0x7ffff772991e <+1710>: vmovdqu 0x2b0(%r13,%r12), %xmm3
    0x7ffff7729928 <+1720>: vmovdqu %xmm3, 0x5a0(%r13,%r12)
    0x7ffff7729932 <+1730>: vmovdqu %xmm1, 0x590(%r13,%r12)
    0x7ffff772993c <+1740>: vmovdqu 0x5a0(%r13,%r12), %xmm5
    0x7ffff7729946 <+1750>: vmulps %xmm1, %xmm5, %xmm5
    0x7ffff772994a <+1754>: vmovdqu %xmm5, 0x50(%r13,%r12)

** 36                   __m128 zImaginarySquared = _mm_mul_ps(zImaginary, zImaginary);
   37

    0x7ffff7729951 <+1761>: vmovdqu 0x80(%r13,%r12), %xmm6
    0x7ffff772995b <+1771>: vmovdqu %xmm6, 0x290(%r13,%r12)
    0x7ffff7729965 <+1781>: vmovdqu %xmm6, 0x280(%r13,%r12)
    0x7ffff772996f <+1791>: vmovdqu 0x290(%r13,%r12), %xmm0
    0x7ffff7729979 <+1801>: vmovdqu %xmm0, 0x5c0(%r13,%r12)
    0x7ffff7729983 <+1811>: vmovdqu %xmm6, 0x5b0(%r13,%r12)
    0x7ffff772998d <+1821>: vmovdqu 0x5c0(%r13,%r12), %xmm2
    0x7ffff7729997 <+1831>: vmulps %xmm6, %xmm2, %xmm2
    0x7ffff772999b <+1835>: vmovdqu %xmm2, 0x40(%r13,%r12)

** 38                   __m128 magnitude = _mm_add_ps(zRealSquared, zImaginarySquared);

    0x7ffff77299a2 <+1842>: vmovdqu 0x50(%r13,%r12), %xmm3
    0x7ffff77299a9 <+1849>: vmovdqu %xmm3, 0x1f0(%r13,%r12)
    0x7ffff77299b3 <+1859>: vmovdqu %xmm2, 0x1e0(%r13,%r12)
    0x7ffff77299bd <+1869>: vmovdqu 0x1f0(%r13,%r12), %xmm5
    0x7ffff77299c7 <+1879>: vmovdqu %xmm5, 0x520(%r13,%r12)
    0x7ffff77299d1 <+1889>: vmovdqu %xmm2, 0x510(%r13,%r12)
    0x7ffff77299db <+1899>: vmovdqu 0x520(%r13,%r12), %xmm7
    0x7ffff77299e5 <+1909>: vaddps %xmm2, %xmm7, %xmm7
    0x7ffff77299e9 <+1913>: vmovdqu %xmm7, 0x30(%r13,%r12)

** 39                   __m128i mask = _mm_castps_si128(_mm_cmplt_ps(magnitude, magnitudeThreshold));
   40
   41                   // all iterations >= maxIterations

    0x7ffff77299f0 <+1920>: vmovdqu 0x110(%r13,%r12), %xmm0
    0x7ffff77299fa <+1930>: vmovdqu %xmm7, 0x310(%r13,%r12)
    0x7ffff7729a04 <+1940>: vmovdqu %xmm0, 0x300(%r13,%r12)
    0x7ffff7729a0e <+1950>: vmovdqu 0x310(%r13,%r12), %xmm2
    0x7ffff7729a18 <+1960>: vmovdqu %xmm2, 0x6a0(%r13,%r12)
    0x7ffff7729a22 <+1970>: vmovdqu %xmm0, 0x690(%r13,%r12)
    0x7ffff7729a2c <+1980>: vmovdqu 0x6a0(%r13,%r12), %xmm4
    0x7ffff7729a36 <+1990>: vcmpltps %xmm0, %xmm4, %xmm4
    0x7ffff7729a3b <+1995>: vmovdqu %xmm4, 0x2f0(%r13,%r12)
    0x7ffff7729a45 <+2005>: vmovdqu %xmm4, 0x20(%r13,%r12)

** 42                   if (_mm_testz_si128(mask, mask)) break;
   43

    0x7ffff7729a4c <+2012>: vmovdqu %xmm4, 0x340(%r13,%r12)
    0x7ffff7729a56 <+2022>: vmovdqu %xmm4, 0x330(%r13,%r12)
    0x7ffff7729a60 <+2032>: vmovdqu 0x340(%r13,%r12), %xmm0
    0x7ffff7729a6a <+2042>: vmovdqu %xmm0, 0x6e0(%r13,%r12)
    0x7ffff7729a74 <+2052>: vmovdqu %xmm4, 0x6d0(%r13,%r12)
    0x7ffff7729a7e <+2062>: vmovdqu 0x6e0(%r13,%r12), %xmm2
    0x7ffff7729a88 <+2072>: vpand  %xmm4, %xmm2, %xmm2
    0x7ffff7729a8c <+2076>: vmovdqu %xmm2, 0x320(%r13,%r12)
    0x7ffff7729a96 <+2086>: vmovdqu %xmm2, 0x740(%r13,%r12)
    0x7ffff7729aa0 <+2096>: movl   $0x0, 0x73c(%r13,%r12)
    0x7ffff7729aac <+2108>: vmovdqu 0x740(%r13,%r12), %xmm5
    0x7ffff7729ab6 <+2118>: vmovdqu %xmm5, 0x720(%r13,%r12)
    0x7ffff7729ac0 <+2128>: movl   $0x1, %ecx
    0x7ffff7729ac5 <+2133>: movq   %rcx, %rdi
    0x7ffff7729ac8 <+2136>: andl   0x73c(%r14), %edi
    0x7ffff7729acf <+2143>: shll   $0x3, %edi
    0x7ffff7729ad2 <+2146>: leal   (%r15,%r8), %edx
    0x7ffff7729ad6 <+2150>: orl    %edi, %edx
    0x7ffff7729ad8 <+2152>: movq   (%r13,%rdx), %rdx
    0x7ffff7729add <+2157>: vmovdqu 0x320(%r13,%r12), %xmm6
    0x7ffff7729ae7 <+2167>: vmovdqu %xmm6, 0x710(%r13,%r12)
    0x7ffff7729af1 <+2177>: movl   $0x1, 0x70c(%r13,%r12)
    0x7ffff7729afd <+2189>: vmovdqu 0x710(%r13,%r12), %xmm0
    0x7ffff7729b07 <+2199>: vmovdqu %xmm0, 0x6f0(%r13,%r12)
    0x7ffff7729b11 <+2209>: andl   0x70c(%r14), %ecx
    0x7ffff7729b18 <+2216>: shll   $0x3, %ecx
    0x7ffff7729b1b <+2219>: leal   (%r15,%r9), %r10d
    0x7ffff7729b1f <+2223>: orl    %ecx, %r10d
    0x7ffff7729b22 <+2226>: orq    (%r13,%r10), %rdx
    0x7ffff7729b27 <+2231>: testq  %rdx, %rdx
    0x7ffff7729b2a <+2234>: je     0x7ffff7729d8f            ; <+2847> at mandelbrot.cpp:53:52

** 44                   numIterations = _mm_add_epi32(numIterations, _mm_and_si128(mask, one));
   45

    0x7ffff7729b30 <+2240>: vmovdqu 0x70(%r13,%r12), %xmm4
    0x7ffff7729b37 <+2247>: vmovdqu 0x20(%r13,%r12), %xmm6
    0x7ffff7729b3e <+2254>: vmovdqu 0x100(%r13,%r12), %xmm5
    0x7ffff7729b48 <+2264>: vmovdqu %xmm6, 0x380(%r13,%r12)
    0x7ffff7729b52 <+2274>: vmovdqu %xmm5, 0x370(%r13,%r12)
    0x7ffff7729b5c <+2284>: vmovdqu 0x380(%r13,%r12), %xmm6
    0x7ffff7729b66 <+2294>: vmovdqu %xmm6, 0x6c0(%r13,%r12)
    0x7ffff7729b70 <+2304>: vmovdqu %xmm5, 0x6b0(%r13,%r12)
    0x7ffff7729b7a <+2314>: vmovdqu 0x6c0(%r13,%r12), %xmm0
    0x7ffff7729b84 <+2324>: vmovdqu %xmm4, 0x360(%r13,%r12)
    0x7ffff7729b8e <+2334>: vpand  %xmm5, %xmm0, %xmm1
    0x7ffff7729b92 <+2338>: vmovdqu %xmm1, 0x350(%r13,%r12)
    0x7ffff7729b9c <+2348>: vmovdqu 0x360(%r13,%r12), %xmm2
    0x7ffff7729ba6 <+2358>: vmovdqu %xmm2, 0x760(%r13,%r12)
    0x7ffff7729bb0 <+2368>: vmovdqu %xmm1, 0x750(%r13,%r12)
    0x7ffff7729bba <+2378>: vmovdqu 0x760(%r13,%r12), %xmm4
    0x7ffff7729bc4 <+2388>: vpaddd %xmm1, %xmm4, %xmm4
    0x7ffff7729bc8 <+2392>: vmovdqu %xmm4, 0x70(%r13,%r12)

** 46                   __m128 newZReal = _mm_add_ps(_mm_sub_ps(zRealSquared, zImaginarySquared), cReal);

    0x7ffff7729bcf <+2399>: vmovdqu 0x50(%r13,%r12), %xmm6
    0x7ffff7729bd6 <+2406>: vmovdqu 0x40(%r13,%r12), %xmm5
    0x7ffff7729bdd <+2413>: vmovdqu %xmm6, 0x3a0(%r13,%r12)
    0x7ffff7729be7 <+2423>: vmovdqu %xmm5, 0x390(%r13,%r12)
    0x7ffff7729bf1 <+2433>: vmovdqu 0x3a0(%r13,%r12), %xmm7
    0x7ffff7729bfb <+2443>: vmovdqu %xmm7, 0x780(%r13,%r12)
    0x7ffff7729c05 <+2453>: vmovdqu %xmm5, 0x770(%r13,%r12)
    0x7ffff7729c0f <+2463>: vmovdqu 0x780(%r13,%r12), %xmm2
    0x7ffff7729c19 <+2473>: vmovdqu 0xa0(%r13,%r12), %xmm1
    0x7ffff7729c23 <+2483>: vsubps %xmm5, %xmm2, %xmm2
    0x7ffff7729c27 <+2487>: vmovdqu %xmm2, 0x1d0(%r13,%r12)
    0x7ffff7729c31 <+2497>: vmovdqu %xmm1, 0x1c0(%r13,%r12)
    0x7ffff7729c3b <+2507>: vmovdqu 0x1d0(%r13,%r12), %xmm3
    0x7ffff7729c45 <+2517>: vmovdqu %xmm3, 0x540(%r13,%r12)
    0x7ffff7729c4f <+2527>: vmovdqu %xmm1, 0x530(%r13,%r12)
    0x7ffff7729c59 <+2537>: vmovdqu 0x540(%r13,%r12), %xmm5
    0x7ffff7729c63 <+2547>: vaddps %xmm1, %xmm5, %xmm5
    0x7ffff7729c67 <+2551>: vmovdqu %xmm5, 0x10(%r13,%r12)

** 47                   __m128 newZImaginary = _mm_add_ps(_mm_mul_ps(two, _mm_mul_ps(zReal, zImaginary)), cImaginary);
   48

    0x7ffff7729c6e <+2558>: vmovdqu 0xe0(%r13,%r12), %xmm6
    0x7ffff7729c78 <+2568>: vmovdqu 0x90(%r13,%r12), %xmm0
    0x7ffff7729c82 <+2578>: vmovdqu 0x80(%r13,%r12), %xmm7
    0x7ffff7729c8c <+2588>: vmovdqu %xmm0, 0x270(%r13,%r12)
    0x7ffff7729c96 <+2598>: vmovdqu %xmm7, 0x260(%r13,%r12)
    0x7ffff7729ca0 <+2608>: vmovdqu 0x270(%r13,%r12), %xmm0
    0x7ffff7729caa <+2618>: vmovdqu %xmm0, 0x5e0(%r13,%r12)
    0x7ffff7729cb4 <+2628>: vmovdqu %xmm7, 0x5d0(%r13,%r12)
    0x7ffff7729cbe <+2638>: vmovdqu 0x5e0(%r13,%r12), %xmm2
    0x7ffff7729cc8 <+2648>: vmovdqu %xmm6, 0x250(%r13,%r12)
    0x7ffff7729cd2 <+2658>: vmulps %xmm7, %xmm2, %xmm3
    0x7ffff7729cd6 <+2662>: vmovdqu %xmm3, 0x240(%r13,%r12)
    0x7ffff7729ce0 <+2672>: vmovdqu 0x250(%r13,%r12), %xmm4
    0x7ffff7729cea <+2682>: vmovdqu %xmm4, 0x600(%r13,%r12)
    0x7ffff7729cf4 <+2692>: vmovdqu %xmm3, 0x5f0(%r13,%r12)
    0x7ffff7729cfe <+2702>: vmovdqu 0x600(%r13,%r12), %xmm7
    0x7ffff7729d08 <+2712>: vmovdqu 0xc0(%r13,%r12), %xmm6
    0x7ffff7729d12 <+2722>: vmulps %xmm3, %xmm7, %xmm7
    0x7ffff7729d16 <+2726>: vmovdqu %xmm7, 0x1b0(%r13,%r12)
    0x7ffff7729d20 <+2736>: vmovdqu %xmm6, 0x1a0(%r13,%r12)
    0x7ffff7729d2a <+2746>: vmovdqu 0x1b0(%r13,%r12), %xmm0
    0x7ffff7729d34 <+2756>: vmovdqu %xmm0, 0x560(%r13,%r12)
    0x7ffff7729d3e <+2766>: vmovdqu %xmm6, 0x550(%r13,%r12)
    0x7ffff7729d48 <+2776>: vmovdqu 0x560(%r13,%r12), %xmm2
    0x7ffff7729d52 <+2786>: vaddps %xmm6, %xmm2, %xmm2
    0x7ffff7729d56 <+2790>: vmovdqu %xmm2, (%r13,%r12)

** 49                   zReal = newZReal;

    0x7ffff7729d5d <+2797>: vmovdqu 0x10(%r13,%r12), %xmm3
    0x7ffff7729d64 <+2804>: vmovdqu %xmm3, 0x90(%r13,%r12)

** 50                   zImaginary = newZImaginary;
   51               }
   52

    0x7ffff7729d6e <+2814>: vmovdqu (%r13,%r12), %xmm4
    0x7ffff7729d75 <+2821>: vmovdqu %xmm4, 0x80(%r13,%r12)
    0x7ffff7729d7f <+2831>: movl   $0x1, %r10d

** 34               for (int i = 0; i < maxIterations; i++) {

    0x7ffff7729d85 <+2837>: addl   %r10d, 0x6c(%r13,%r12)
    0x7ffff7729d8a <+2842>: jmp    0x7ffff77298ea            ; <+1658> at mandelbrot.cpp:34:29

** 53               _mm_storeu_si128((__m128i*)&mandelbrot[y * pixelWidth + x], numIterations);
   54           }
   55       }

    0x7ffff7729d8f <+2847>: movl   0xdc(%r13,%r12), %ecx
    0x7ffff7729d97 <+2855>: imull  0x178(%r14), %ecx
    0x7ffff7729d9f <+2863>: addl   0xbc(%r14), %ecx
    0x7ffff7729da6 <+2870>: movq   (%rsp), %rdx
    0x7ffff7729daa <+2874>: movq   %rbx, %rsi
    0x7ffff7729dad <+2877>: movq   %rbx, %rdi
    0x7ffff7729db0 <+2880>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff7729db5 <+2885>: vmovdqu 0x70(%r13,%r12), %xmm7
    0x7ffff7729dbc <+2892>: movl   %eax, 0x3cc(%r13,%r12)
    0x7ffff7729dc4 <+2900>: vmovdqu %xmm7, 0x3b0(%r13,%r12)
    0x7ffff7729dce <+2910>: movl   0x3cc(%r14), %esi
    0x7ffff7729dd5 <+2917>: vmovdqu %xmm7, (%r13,%rsi)
    0x7ffff7729ddc <+2924>: movl   $0x4, %edi

** 26           for (int x = 0; x < pixelWidth; x += 4) {

    0x7ffff7729de1 <+2929>: addl   %edi, 0xbc(%r13,%r12)
    0x7ffff7729de9 <+2937>: jmp    0x7ffff77295e6            ; <+886> at mandelbrot.cpp:26:25
    0x7ffff7729dee <+2942>: movl   $0x1, %ecx

** 23       for (int y = 0; y < pixelHeight; y++) {

    0x7ffff7729df3 <+2947>: addl   %ecx, 0xdc(%r13,%r12)
    0x7ffff7729dfb <+2955>: jmp    0x7ffff7729520            ; <+688> at mandelbrot.cpp:23:21
    0x7ffff7729e00 <+2960>: movl   $0x1, %r8d

   56
** 57       return mandelbrot;

    0x7ffff7729e06 <+2966>: movb   %r8b, 0x16f(%r13,%r12)

** 58   }

    0x7ffff7729e0e <+2974>: movzbq 0x16f(%r13,%r12), %r8
    0x7ffff7729e17 <+2983>: andl   $0x1, %r8d
    0x7ffff7729e1b <+2987>: testl  %r8d, %r8d
    0x7ffff7729e1e <+2990>: jne    0x7ffff7729e33            ; <+3011> at mandelbrot.cpp:58:1
    0x7ffff7729e24 <+2996>: movq   (%rsp), %rdx
    0x7ffff7729e28 <+3000>: movq   %rbx, %rsi
    0x7ffff7729e2b <+3003>: movq   %rbx, %rdi
    0x7ffff7729e2e <+3006>: callq  0x7ffff77256b0            ; std::__2::vector<int, std::__2::allocator<int> >::~vector[abi:ue170004]() at vector:500
    0x7ffff7729e33 <+3011>: movl   %r15d, 0x110(%rbx)
    0x7ffff7729e3a <+3018>: movq   0x10(%rsp), %rbx
    0x7ffff7729e3f <+3023>: movq   0x18(%rsp), %r12
    0x7ffff7729e44 <+3028>: movq   0x20(%rsp), %r13
    0x7ffff7729e49 <+3033>: movq   0x28(%rsp), %r14
    0x7ffff7729e4e <+3038>: movq   0x30(%rsp), %r15
    0x7ffff7729e53 <+3043>: addq   $0x40, %rsp
    0x7ffff7729e57 <+3047>: movq   %rbp, %rsp
    0x7ffff7729e5a <+3050>: popq   %rbp
    0x7ffff7729e5b <+3051>: retq
    0x7ffff7729e5c <+3052>: ud2
    0x7ffff7729e5e <+3054>: addb   %al, (%rax)
    0x7ffff7729e60 <+3056>: addl   %eax, (%rax)
    0x7ffff7729e62 <+3058>: addb   %al, (%rax)
    0x7ffff7729e64 <+3060>: addl   %eax, (%rax)
    0x7ffff7729e66 <+3062>: addb   %al, (%rax)
    0x7ffff7729e68 <+3064>: addl   %eax, (%rax)
    0x7ffff7729e6a <+3066>: addb   %al, (%rax)
    0x7ffff7729e6c <+3068>: addl   %eax, (%rax)
    0x7ffff7729e6e <+3070>: addb   %al, (%rax)