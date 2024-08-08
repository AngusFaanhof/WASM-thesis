0x555555557185 <+0>:    endbr64
    0x555555557189 <+4>:    pushq  %rbp
    0x55555555718a <+5>:    movq   %rsp, %rbp
    0x55555555718d <+8>:    pushq  %rbx
    0x55555555718e <+9>:    subq   $0x198, %rsp              ; imm = 0x198
    0x555555557195 <+16>:   movq   %rdi, -0x188(%rbp)
    0x55555555719c <+23>:   movq   %rsi, -0x190(%rbp)
    0x5555555571a3 <+30>:   movq   %rdx, -0x198(%rbp)

   7
   8
** 9    std::vector<float> transposeMatrix(const std::vector<float>& m, size_t rowsCols) {

    0x5555555571aa <+37>:   movq   %fs:0x28, %rax
    0x5555555571b3 <+46>:   movq   %rax, -0x18(%rbp)
    0x5555555571b7 <+50>:   xorl   %eax, %eax

-> 10           std::vector<float> result(rowsCols * rowsCols);
-> 11

->  0x5555555571b9 <+52>:   leaq   -0x171(%rbp), %rax
    0x5555555571c0 <+59>:   movq   %rax, %rdi
    0x5555555571c3 <+62>:   callq  0x555555555854            ; std::allocator<float>::allocator at allocator.h:156:7
    0x5555555571c8 <+67>:   movq   -0x198(%rbp), %rax
    0x5555555571cf <+74>:   imulq  %rax, %rax
    0x5555555571d3 <+78>:   movq   %rax, %rcx
    0x5555555571d6 <+81>:   leaq   -0x171(%rbp), %rdx
    0x5555555571dd <+88>:   movq   -0x188(%rbp), %rax
    0x5555555571e4 <+95>:   movq   %rcx, %rsi
    0x5555555571e7 <+98>:   movq   %rax, %rdi
    0x5555555571ea <+101>:  callq  0x555555558134            ; std::vector<float, std::allocator<float> >::vector at stl_vector.h:510:7
    0x5555555571ef <+106>:  leaq   -0x171(%rbp), %rax
    0x5555555571f6 <+113>:  movq   %rax, %rdi
    0x5555555571f9 <+116>:  callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7

** 12           for (size_t i = 0; i < rowsCols; i += 4) {

    0x5555555571fe <+121>:  movq   $0x0, -0x170(%rbp)
    0x555555557209 <+132>:  jmp    0x5555555575bc            ; <+1079> at matrix_algorithms.cpp:12:23

** 13                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x55555555720e <+137>:  movq   $0x0, -0x168(%rbp)
    0x555555557219 <+148>:  jmp    0x5555555575a0            ; <+1051> at matrix_algorithms.cpp:13:24

** 14                           __m128 row0 = _mm_loadu_ps(&m[i * rowsCols + j]);

    0x55555555721e <+153>:  movq   -0x170(%rbp), %rax
    0x555555557225 <+160>:  imulq  -0x198(%rbp), %rax
    0x55555555722d <+168>:  movq   %rax, %rdx
    0x555555557230 <+171>:  movq   -0x168(%rbp), %rax
    0x555555557237 <+178>:  addq   %rax, %rdx
    0x55555555723a <+181>:  movq   -0x190(%rbp), %rax
    0x555555557241 <+188>:  movq   %rdx, %rsi
    0x555555557244 <+191>:  movq   %rax, %rdi
    0x555555557247 <+194>:  callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x55555555724c <+199>:  movq   %rax, -0x148(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x555555557253 <+206>:  movq   -0x148(%rbp), %rax
    0x55555555725a <+213>:  vmovups (%rax), %xmm0

** 14                           __m128 row0 = _mm_loadu_ps(&m[i * rowsCols + j]);

    0x55555555725e <+217>:  vmovaps %xmm0, -0x120(%rbp)

** 15                           __m128 row1 = _mm_loadu_ps(&m[(i + 1) * rowsCols + j]);

    0x555555557266 <+225>:  movq   -0x170(%rbp), %rax
    0x55555555726d <+232>:  addq   $0x1, %rax
    0x555555557271 <+236>:  imulq  -0x198(%rbp), %rax
    0x555555557279 <+244>:  movq   %rax, %rdx
    0x55555555727c <+247>:  movq   -0x168(%rbp), %rax
    0x555555557283 <+254>:  addq   %rax, %rdx
    0x555555557286 <+257>:  movq   -0x190(%rbp), %rax
    0x55555555728d <+264>:  movq   %rdx, %rsi
    0x555555557290 <+267>:  movq   %rax, %rdi
    0x555555557293 <+270>:  callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x555555557298 <+275>:  movq   %rax, -0x150(%rbp)

** 934    return *(__m128_u *)__P;

    0x55555555729f <+282>:  movq   -0x150(%rbp), %rax
    0x5555555572a6 <+289>:  vmovups (%rax), %xmm0

** 15                           __m128 row1 = _mm_loadu_ps(&m[(i + 1) * rowsCols + j]);

    0x5555555572aa <+293>:  vmovaps %xmm0, -0x110(%rbp)

** 16                           __m128 row2 = _mm_loadu_ps(&m[(i + 2) * rowsCols + j]);

    0x5555555572b2 <+301>:  movq   -0x170(%rbp), %rax
    0x5555555572b9 <+308>:  addq   $0x2, %rax
    0x5555555572bd <+312>:  imulq  -0x198(%rbp), %rax
    0x5555555572c5 <+320>:  movq   %rax, %rdx
    0x5555555572c8 <+323>:  movq   -0x168(%rbp), %rax
    0x5555555572cf <+330>:  addq   %rax, %rdx
    0x5555555572d2 <+333>:  movq   -0x190(%rbp), %rax
    0x5555555572d9 <+340>:  movq   %rdx, %rsi
    0x5555555572dc <+343>:  movq   %rax, %rdi
    0x5555555572df <+346>:  callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x5555555572e4 <+351>:  movq   %rax, -0x158(%rbp)

** 934    return *(__m128_u *)__P;

    0x5555555572eb <+358>:  movq   -0x158(%rbp), %rax
    0x5555555572f2 <+365>:  vmovups (%rax), %xmm0

** 16                           __m128 row2 = _mm_loadu_ps(&m[(i + 2) * rowsCols + j]);

    0x5555555572f6 <+369>:  vmovaps %xmm0, -0x100(%rbp)

** 17                           __m128 row3 = _mm_loadu_ps(&m[(i + 3) * rowsCols + j]);
   18

    0x5555555572fe <+377>:  movq   -0x170(%rbp), %rax
    0x555555557305 <+384>:  addq   $0x3, %rax
    0x555555557309 <+388>:  imulq  -0x198(%rbp), %rax
    0x555555557311 <+396>:  movq   %rax, %rdx
    0x555555557314 <+399>:  movq   -0x168(%rbp), %rax
    0x55555555731b <+406>:  addq   %rax, %rdx
    0x55555555731e <+409>:  movq   -0x190(%rbp), %rax
    0x555555557325 <+416>:  movq   %rdx, %rsi
    0x555555557328 <+419>:  movq   %rax, %rdi
    0x55555555732b <+422>:  callq  0x5555555581b2            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1061:7
    0x555555557330 <+427>:  movq   %rax, -0x160(%rbp)

** 934    return *(__m128_u *)__P;

    0x555555557337 <+434>:  movq   -0x160(%rbp), %rax
    0x55555555733e <+441>:  vmovups (%rax), %xmm0

** 17                           __m128 row3 = _mm_loadu_ps(&m[(i + 3) * rowsCols + j]);

    0x555555557342 <+445>:  vmovaps %xmm0, -0xf0(%rbp)

** 19                           _MM_TRANSPOSE4_PS(row0, row1, row2, row3);
   20

    0x55555555734a <+453>:  vmovaps -0x120(%rbp), %xmm0
    0x555555557352 <+461>:  vmovaps %xmm0, -0xe0(%rbp)
    0x55555555735a <+469>:  vmovaps -0x110(%rbp), %xmm0
    0x555555557362 <+477>:  vmovaps %xmm0, -0xd0(%rbp)
    0x55555555736a <+485>:  vmovaps -0x100(%rbp), %xmm0
    0x555555557372 <+493>:  vmovaps %xmm0, -0xc0(%rbp)
    0x55555555737a <+501>:  vmovaps -0xf0(%rbp), %xmm0
    0x555555557382 <+509>:  vmovaps %xmm0, -0xb0(%rbp)
    0x55555555738a <+517>:  vmovaps -0xe0(%rbp), %xmm0
    0x555555557392 <+525>:  vunpcklps -0xd0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
    0x55555555739a <+533>:  vmovaps %xmm0, -0xa0(%rbp)
    0x5555555573a2 <+541>:  vmovaps -0xc0(%rbp), %xmm0
    0x5555555573aa <+549>:  vunpcklps -0xb0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[0],mem[0],xmm0[1],mem[1]
    0x5555555573b2 <+557>:  vmovaps %xmm0, -0x90(%rbp)
    0x5555555573ba <+565>:  vmovaps -0xe0(%rbp), %xmm0
    0x5555555573c2 <+573>:  vunpckhps -0xd0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[2],mem[2],xmm0[3],mem[3]
    0x5555555573ca <+581>:  vmovaps %xmm0, -0x80(%rbp)
    0x5555555573cf <+586>:  vmovaps -0xc0(%rbp), %xmm0
    0x5555555573d7 <+594>:  vunpckhps -0xb0(%rbp), %xmm0, %xmm0 ; xmm0 = xmm0[2],mem[2],xmm0[3],mem[3]
    0x5555555573df <+602>:  vmovaps %xmm0, -0x70(%rbp)
    0x5555555573e4 <+607>:  vmovaps -0xa0(%rbp), %xmm0
    0x5555555573ec <+615>:  vmovaps -0x90(%rbp), %xmm1
    0x5555555573f4 <+623>:  vmovlhps %xmm1, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm1[0]
    0x5555555573f8 <+627>:  vmovaps %xmm0, -0x120(%rbp)
    0x555555557400 <+635>:  vmovaps -0x90(%rbp), %xmm0
    0x555555557408 <+643>:  vmovlps -0x98(%rbp), %xmm0, %xmm0 ; xmm0 = mem[0,1],xmm0[2,3]
    0x555555557410 <+651>:  vmovaps %xmm0, -0x110(%rbp)
    0x555555557418 <+659>:  vmovaps -0x80(%rbp), %xmm0
    0x55555555741d <+664>:  vmovaps -0x70(%rbp), %xmm2
    0x555555557422 <+669>:  vmovlhps %xmm2, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm2[0]
    0x555555557426 <+673>:  vmovaps %xmm0, -0x100(%rbp)
    0x55555555742e <+681>:  vmovaps -0x70(%rbp), %xmm0
    0x555555557433 <+686>:  vmovlps -0x78(%rbp), %xmm0, %xmm0 ; xmm0 = mem[0,1],xmm0[2,3]
    0x555555557438 <+691>:  vmovaps %xmm0, -0xf0(%rbp)

** 21                           _mm_storeu_ps(&result[j * rowsCols + i], row0);

    0x555555557440 <+699>:  movq   -0x168(%rbp), %rax
    0x555555557447 <+706>:  imulq  -0x198(%rbp), %rax
    0x55555555744f <+714>:  movq   %rax, %rdx
    0x555555557452 <+717>:  movq   -0x170(%rbp), %rax
    0x555555557459 <+724>:  addq   %rax, %rdx
    0x55555555745c <+727>:  movq   -0x188(%rbp), %rax
    0x555555557463 <+734>:  movq   %rdx, %rsi
    0x555555557466 <+737>:  movq   %rax, %rdi
    0x555555557469 <+740>:  callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x55555555746e <+745>:  movq   %rax, -0x128(%rbp)
    0x555555557475 <+752>:  vmovaps -0x120(%rbp), %xmm0
    0x55555555747d <+760>:  vmovaps %xmm0, -0x30(%rbp)

   981  _mm_storeu_ps (float *__P, __m128 __A)
   982  {
** 983    *(__m128_u *)__P = __A;

    0x555555557482 <+765>:  vmovaps -0x30(%rbp), %xmm0
    0x555555557487 <+770>:  movq   -0x128(%rbp), %rax
    0x55555555748e <+777>:  vmovups %xmm0, (%rax)

** 984  }
   985
   986  /* Store the lower SPFP value across four words.  */

    0x555555557492 <+781>:  nop

** 22                           _mm_storeu_ps(&result[(j + 1) * rowsCols + i], row1);

    0x555555557493 <+782>:  movq   -0x168(%rbp), %rax
    0x55555555749a <+789>:  addq   $0x1, %rax
    0x55555555749e <+793>:  imulq  -0x198(%rbp), %rax
    0x5555555574a6 <+801>:  movq   %rax, %rdx
    0x5555555574a9 <+804>:  movq   -0x170(%rbp), %rax
    0x5555555574b0 <+811>:  addq   %rax, %rdx
    0x5555555574b3 <+814>:  movq   -0x188(%rbp), %rax
    0x5555555574ba <+821>:  movq   %rdx, %rsi
    0x5555555574bd <+824>:  movq   %rax, %rdi
    0x5555555574c0 <+827>:  callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x5555555574c5 <+832>:  movq   %rax, -0x130(%rbp)
    0x5555555574cc <+839>:  vmovaps -0x110(%rbp), %xmm0
    0x5555555574d4 <+847>:  vmovaps %xmm0, -0x40(%rbp)

** 983    *(__m128_u *)__P = __A;

    0x5555555574d9 <+852>:  vmovaps -0x40(%rbp), %xmm0
    0x5555555574de <+857>:  movq   -0x130(%rbp), %rax
    0x5555555574e5 <+864>:  vmovups %xmm0, (%rax)

** 984  }

    0x5555555574e9 <+868>:  nop

** 23                           _mm_storeu_ps(&result[(j + 2) * rowsCols + i], row2);

    0x5555555574ea <+869>:  movq   -0x168(%rbp), %rax
    0x5555555574f1 <+876>:  addq   $0x2, %rax
    0x5555555574f5 <+880>:  imulq  -0x198(%rbp), %rax
    0x5555555574fd <+888>:  movq   %rax, %rdx
    0x555555557500 <+891>:  movq   -0x170(%rbp), %rax
    0x555555557507 <+898>:  addq   %rax, %rdx
    0x55555555750a <+901>:  movq   -0x188(%rbp), %rax
    0x555555557511 <+908>:  movq   %rdx, %rsi
    0x555555557514 <+911>:  movq   %rax, %rdi
    0x555555557517 <+914>:  callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x55555555751c <+919>:  movq   %rax, -0x138(%rbp)
    0x555555557523 <+926>:  vmovaps -0x100(%rbp), %xmm0
    0x55555555752b <+934>:  vmovaps %xmm0, -0x50(%rbp)

** 983    *(__m128_u *)__P = __A;

    0x555555557530 <+939>:  vmovaps -0x50(%rbp), %xmm0
    0x555555557535 <+944>:  movq   -0x138(%rbp), %rax
    0x55555555753c <+951>:  vmovups %xmm0, (%rax)

** 984  }

    0x555555557540 <+955>:  nop

** 24                           _mm_storeu_ps(&result[(j + 3) * rowsCols + i], row3);
   25                   }
   26           }

    0x555555557541 <+956>:  movq   -0x168(%rbp), %rax
    0x555555557548 <+963>:  addq   $0x3, %rax
    0x55555555754c <+967>:  imulq  -0x198(%rbp), %rax
    0x555555557554 <+975>:  movq   %rax, %rdx
    0x555555557557 <+978>:  movq   -0x170(%rbp), %rax
    0x55555555755e <+985>:  addq   %rax, %rdx
    0x555555557561 <+988>:  movq   -0x188(%rbp), %rax
    0x555555557568 <+995>:  movq   %rdx, %rsi
    0x55555555756b <+998>:  movq   %rax, %rdi
    0x55555555756e <+1001>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555557573 <+1006>: movq   %rax, -0x140(%rbp)
    0x55555555757a <+1013>: vmovaps -0xf0(%rbp), %xmm0
    0x555555557582 <+1021>: vmovaps %xmm0, -0x60(%rbp)

** 983    *(__m128_u *)__P = __A;

    0x555555557587 <+1026>: vmovaps -0x60(%rbp), %xmm0
    0x55555555758c <+1031>: movq   -0x140(%rbp), %rax
    0x555555557593 <+1038>: vmovups %xmm0, (%rax)

** 984  }

    0x555555557597 <+1042>: nop

** 13                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x555555557598 <+1043>: addq   $0x4, -0x168(%rbp)
    0x5555555575a0 <+1051>: movq   -0x168(%rbp), %rax
    0x5555555575a7 <+1058>: cmpq   -0x198(%rbp), %rax
    0x5555555575ae <+1065>: jb     0x55555555721e            ; <+153> at matrix_algorithms.cpp:14:36

** 12           for (size_t i = 0; i < rowsCols; i += 4) {

    0x5555555575b4 <+1071>: addq   $0x4, -0x170(%rbp)
    0x5555555575bc <+1079>: movq   -0x170(%rbp), %rax
    0x5555555575c3 <+1086>: cmpq   -0x198(%rbp), %rax
    0x5555555575ca <+1093>: jb     0x55555555720e            ; <+137> at matrix_algorithms.cpp:13:15

   27
** 28           return result;

    0x5555555575d0 <+1099>: jmp    0x5555555575f3            ; <+1134> at matrix_algorithms.cpp:29:1
    0x5555555575d2 <+1101>: endbr64
    0x5555555575d6 <+1105>: movq   %rax, %rbx
    0x5555555575d9 <+1108>: leaq   -0x171(%rbp), %rax
    0x5555555575e0 <+1115>: movq   %rax, %rdi
    0x5555555575e3 <+1118>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7
    0x5555555575e8 <+1123>: movq   %rbx, %rax
    0x5555555575eb <+1126>: movq   %rax, %rdi
    0x5555555575ee <+1129>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 29   }
   30
   31   std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols) {

    0x5555555575f3 <+1134>: movq   -0x18(%rbp), %rax
    0x5555555575f7 <+1138>: subq   %fs:0x28, %rax
    0x555555557600 <+1147>: je     0x555555557607            ; <+1154> at matrix_algorithms.cpp:29:1
    0x555555557602 <+1149>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x555555557607 <+1154>: movq   -0x188(%rbp), %rax
    0x55555555760e <+1161>: movq   -0x8(%rbp), %rbx
    0x555555557612 <+1165>: leave
    0x555555557613 <+1166>: retq