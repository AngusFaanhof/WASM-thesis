0x7ffff772b920 <+0>:    pushq  %rbp
    0x7ffff772b921 <+1>:    movq   %rsp, %rbp
    0x7ffff772b924 <+4>:    movq   0x8(%rdi), %r10
    0x7ffff772b928 <+8>:    movq   (%r10), %r10
    0x7ffff772b92b <+11>:   addq   $0x10, %r10
    0x7ffff772b92f <+15>:   cmpq   %rsp, %r10
    0x7ffff772b932 <+18>:   ja     0x7ffff772be39            ; <+1305> at vector_algorithms.cpp:38:1
    0x7ffff772b938 <+24>:   subq   $0x40, %rsp
    0x7ffff772b93c <+28>:   movq   %rbx, 0x10(%rsp)
    0x7ffff772b941 <+33>:   movq   %r12, 0x18(%rsp)
    0x7ffff772b946 <+38>:   movq   %r13, 0x20(%rsp)
    0x7ffff772b94b <+43>:   movq   %r14, 0x28(%rsp)
    0x7ffff772b950 <+48>:   movq   %r15, 0x30(%rsp)
    0x7ffff772b955 <+53>:   movl   0x110(%rdi), %ebx
    0x7ffff772b95b <+59>:   movq   %rbx, %r12
    0x7ffff772b95e <+62>:   subl   $0x310, %r12d             ; imm = 0x310
    0x7ffff772b965 <+69>:   movl   %r12d, 0x110(%rdi)
    0x7ffff772b96c <+76>:   movq   0x100(%rdi), %r13
    0x7ffff772b973 <+83>:   leaq   (%r13,%r12), %r14
    0x7ffff772b978 <+88>:   movl   %edx, 0x84(%r13,%r12)
    0x7ffff772b980 <+96>:   movq   %rdx, (%rsp)
    0x7ffff772b984 <+100>:  movl   %ecx, 0x80(%r13,%r12)
    0x7ffff772b98c <+108>:  movq   %rcx, %rdx
    0x7ffff772b98f <+111>:  movq   %rdi, %r15
    0x7ffff772b992 <+114>:  movq   %r15, %rsi
    0x7ffff772b995 <+117>:  movq   %r15, %rdi

-> 13       size_t size = vec.size();

->  0x7ffff772b998 <+120>:  callq  0x7ffff77290e0            ; std::__2::vector<float, std::__2::allocator<float> >::size[abi:ue170004]() const at vector:604
    0x7ffff772b99d <+125>:  movl   %eax, 0x7c(%r13,%r12)

** 14       __m128 sum = _mm_setzero_ps();
   15
   16       // sum of squares

    0x7ffff772b9a2 <+130>:  movl   $0x0, 0x214(%r13,%r12)
    0x7ffff772b9ae <+142>:  movl   $0x0, 0x210(%r13,%r12)
    0x7ffff772b9ba <+154>:  movl   $0x0, 0x20c(%r13,%r12)
    0x7ffff772b9c6 <+166>:  movl   $0x0, 0x208(%r13,%r12)
    0x7ffff772b9d2 <+178>:  vmovss 0x210(%r13,%r12), %xmm1   ; xmm1 = mem[0],zero,zero,zero
    0x7ffff772b9dc <+188>:  vmovss 0x20c(%r13,%r12), %xmm2   ; xmm2 = mem[0],zero,zero,zero
    0x7ffff772b9e6 <+198>:  vmovss 0x208(%r13,%r12), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff772b9f0 <+208>:  movl   0x214(%r13,%r12), %r11d
    0x7ffff772b9f8 <+216>:  vmovd  %r11d, %xmm0
    0x7ffff772b9fd <+221>:  vpbroadcastd %xmm0, %xmm4
    0x7ffff772ba02 <+226>:  vinsertps $0x10, %xmm1, %xmm4, %xmm1 ; xmm1 = xmm4[0],xmm1[0],xmm4[2,3]
    0x7ffff772ba08 <+232>:  vinsertps $0x20, %xmm2, %xmm1, %xmm1 ; xmm1 = xmm1[0,1],xmm2[0],xmm1[3]
    0x7ffff772ba0e <+238>:  vinsertps $0x30, %xmm3, %xmm1, %xmm1 ; xmm1 = xmm1[0,1,2],xmm3[0]
    0x7ffff772ba14 <+244>:  vmovdqu %xmm1, 0x1f0(%r13,%r12)
    0x7ffff772ba1e <+254>:  vmovdqu %xmm1, 0x60(%r13,%r12)

** 17       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772ba25 <+261>:  movl   $0x0, 0x5c(%r13,%r12)
    0x7ffff772ba2e <+270>:  movl   0x5c(%r13,%r12), %ecx
    0x7ffff772ba33 <+275>:  movl   0x7c(%r13,%r12), %edx
    0x7ffff772ba38 <+280>:  cmpl   %edx, %ecx
    0x7ffff772ba3a <+282>:  jae    0x7ffff772bb17            ; <+503> at vector_algorithms.cpp:22:23

** 18           __m128 values = _mm_loadu_ps(&vec[i]);

    0x7ffff772ba40 <+288>:  movl   0x80(%r13,%r12), %edx
    0x7ffff772ba48 <+296>:  movl   0x5c(%r13,%r12), %ecx
    0x7ffff772ba4d <+301>:  movq   %r15, %rsi
    0x7ffff772ba50 <+304>:  movq   %r15, %rdi
    0x7ffff772ba53 <+307>:  callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772ba58 <+312>:  movl   %eax, 0x8c(%r13,%r12)
    0x7ffff772ba60 <+320>:  movl   %eax, 0x218(%r13,%r12)
    0x7ffff772ba68 <+328>:  movl   %eax, %r10d
    0x7ffff772ba6b <+331>:  vmovdqu (%r13,%r10), %xmm1
    0x7ffff772ba72 <+338>:  vmovdqu %xmm1, 0x40(%r13,%r12)

** 19           sum = _mm_add_ps(sum, _mm_mul_ps(values, values));
   20       }
   21

    0x7ffff772ba79 <+345>:  vmovdqu 0x60(%r13,%r12), %xmm2
    0x7ffff772ba80 <+352>:  vmovdqu %xmm1, 0xe0(%r13,%r12)
    0x7ffff772ba8a <+362>:  vmovdqu %xmm1, 0xd0(%r13,%r12)
    0x7ffff772ba94 <+372>:  vmovdqu 0xe0(%r13,%r12), %xmm4
    0x7ffff772ba9e <+382>:  vmovdqu %xmm4, 0x290(%r13,%r12)
    0x7ffff772baa8 <+392>:  vmovdqu %xmm1, 0x280(%r13,%r12)
    0x7ffff772bab2 <+402>:  vmovdqu 0x290(%r13,%r12), %xmm6
    0x7ffff772babc <+412>:  vmovdqu %xmm2, 0xa0(%r13,%r12)
    0x7ffff772bac6 <+422>:  vmulps %xmm1, %xmm6, %xmm7
    0x7ffff772baca <+426>:  vmovdqu %xmm7, 0x90(%r13,%r12)
    0x7ffff772bad4 <+436>:  vmovdqu 0xa0(%r13,%r12), %xmm0
    0x7ffff772bade <+446>:  vmovdqu %xmm0, 0x270(%r13,%r12)
    0x7ffff772bae8 <+456>:  vmovdqu %xmm7, 0x260(%r13,%r12)
    0x7ffff772baf2 <+466>:  vmovdqu 0x270(%r13,%r12), %xmm2
    0x7ffff772bafc <+476>:  vaddps %xmm7, %xmm2, %xmm2
    0x7ffff772bb00 <+480>:  vmovdqu %xmm2, 0x60(%r13,%r12)
    0x7ffff772bb07 <+487>:  movl   $0x4, %r11d

** 17       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bb0d <+493>:  addl   %r11d, 0x5c(%r13,%r12)
    0x7ffff772bb12 <+498>:  jmp    0x7ffff772ba2e            ; <+270> at vector_algorithms.cpp:17:24

** 22       sum = _mm_hadd_ps(sum, sum);

    0x7ffff772bb17 <+503>:  vmovdqu 0x60(%r13,%r12), %xmm5
    0x7ffff772bb1e <+510>:  vmovdqu %xmm5, 0x180(%r13,%r12)
    0x7ffff772bb28 <+520>:  vmovdqu %xmm5, 0x170(%r13,%r12)
    0x7ffff772bb32 <+530>:  vmovdqu 0x180(%r13,%r12), %xmm7
    0x7ffff772bb3c <+540>:  vshufps $0x88, %xmm5, %xmm7, %xmm7 ; xmm7 = xmm7[0,2],xmm5[0,2]
    0x7ffff772bb41 <+545>:  vmovdqu %xmm7, 0x160(%r13,%r12)
    0x7ffff772bb4b <+555>:  vmovdqu 0x180(%r13,%r12), %xmm0
    0x7ffff772bb55 <+565>:  vmovdqu 0x170(%r13,%r12), %xmm1
    0x7ffff772bb5f <+575>:  vshufps $0xdd, %xmm1, %xmm0, %xmm0 ; xmm0 = xmm0[1,3],xmm1[1,3]
    0x7ffff772bb64 <+580>:  vmovdqu %xmm0, 0x150(%r13,%r12)
    0x7ffff772bb6e <+590>:  vmovdqu %xmm7, 0x1a0(%r13,%r12)
    0x7ffff772bb78 <+600>:  vmovdqu %xmm0, 0x190(%r13,%r12)
    0x7ffff772bb82 <+610>:  vmovdqu 0x1a0(%r13,%r12), %xmm3
    0x7ffff772bb8c <+620>:  vmovdqu %xmm3, 0x230(%r13,%r12)
    0x7ffff772bb96 <+630>:  vmovdqu %xmm0, 0x220(%r13,%r12)
    0x7ffff772bba0 <+640>:  vmovdqu 0x230(%r13,%r12), %xmm5
    0x7ffff772bbaa <+650>:  vaddps %xmm0, %xmm5, %xmm5
    0x7ffff772bbae <+654>:  vmovdqu %xmm5, 0x60(%r13,%r12)

** 23       sum = _mm_hadd_ps(sum, sum);
   24
   25       // inverse square root

    0x7ffff772bbb5 <+661>:  vmovdqu %xmm5, 0x120(%r13,%r12)
    0x7ffff772bbbf <+671>:  vmovdqu %xmm5, 0x110(%r13,%r12)
    0x7ffff772bbc9 <+681>:  vmovdqu 0x120(%r13,%r12), %xmm0
    0x7ffff772bbd3 <+691>:  vshufps $0x88, %xmm5, %xmm0, %xmm0 ; xmm0 = xmm0[0,2],xmm5[0,2]
    0x7ffff772bbd8 <+696>:  vmovdqu %xmm0, 0x100(%r13,%r12)
    0x7ffff772bbe2 <+706>:  vmovdqu 0x120(%r13,%r12), %xmm1
    0x7ffff772bbec <+716>:  vmovdqu 0x110(%r13,%r12), %xmm2
    0x7ffff772bbf6 <+726>:  vshufps $0xdd, %xmm2, %xmm1, %xmm1 ; xmm1 = xmm1[1,3],xmm2[1,3]
    0x7ffff772bbfb <+731>:  vmovdqu %xmm1, 0xf0(%r13,%r12)
    0x7ffff772bc05 <+741>:  vmovdqu %xmm0, 0x140(%r13,%r12)
    0x7ffff772bc0f <+751>:  vmovdqu %xmm1, 0x130(%r13,%r12)
    0x7ffff772bc19 <+761>:  vmovdqu 0x140(%r13,%r12), %xmm4
    0x7ffff772bc23 <+771>:  vmovdqu %xmm4, 0x250(%r13,%r12)
    0x7ffff772bc2d <+781>:  vmovdqu %xmm1, 0x240(%r13,%r12)
    0x7ffff772bc37 <+791>:  vmovdqu 0x250(%r13,%r12), %xmm6
    0x7ffff772bc41 <+801>:  vaddps %xmm1, %xmm6, %xmm6
    0x7ffff772bc45 <+805>:  vmovdqu %xmm6, 0x60(%r13,%r12)

** 26       __m128 invSqrt = _mm_rsqrt_ps(sum);
   27

    0x7ffff772bc4c <+812>:  vmovdqu %xmm6, 0x1c0(%r13,%r12)
    0x7ffff772bc56 <+822>:  vmovdqu %xmm6, 0x2e0(%r13,%r12)
    0x7ffff772bc60 <+832>:  vsqrtps %xmm6, %xmm1
    0x7ffff772bc64 <+836>:  vmovdqu %xmm1, 0x1b0(%r13,%r12)
    0x7ffff772bc6e <+846>:  movl   $0x3f800000, 0x1ec(%r13,%r12) ; imm = 0x3F800000
    0x7ffff772bc7a <+858>:  vmovss 0x1ec(%r13,%r12), %xmm3   ; xmm3 = mem[0],zero,zero,zero
    0x7ffff772bc84 <+868>:  vmovss %xmm3, 0x30c(%r13,%r12)
    0x7ffff772bc8e <+878>:  movl   0x30c(%r13,%r12), %r9d
    0x7ffff772bc96 <+886>:  vmovd  %r9d, %xmm3
    0x7ffff772bc9b <+891>:  vpbroadcastd %xmm3, %xmm6
    0x7ffff772bca0 <+896>:  vmovdqu %xmm6, 0x2f0(%r13,%r12)
    0x7ffff772bcaa <+906>:  vmovdqu 0x1b0(%r13,%r12), %xmm5
    0x7ffff772bcb4 <+916>:  vmovdqu %xmm6, 0x2d0(%r13,%r12)
    0x7ffff772bcbe <+926>:  vmovdqu %xmm5, 0x2c0(%r13,%r12)
    0x7ffff772bcc8 <+936>:  vmovdqu 0x2d0(%r13,%r12), %xmm7
    0x7ffff772bcd2 <+946>:  vdivps %xmm5, %xmm7, %xmm7
    0x7ffff772bcd6 <+950>:  vmovdqu %xmm7, 0x30(%r13,%r12)
    0x7ffff772bcdd <+957>:  xorl   %edi, %edi

** 28       std::vector<float> result(size);
   29
   30       // normalize vector

    0x7ffff772bcdf <+959>:  movb   %dil, 0x2f(%r13,%r12)
    0x7ffff772bce4 <+964>:  movl   0x7c(%r13,%r12), %ecx
    0x7ffff772bce9 <+969>:  movq   (%rsp), %rdx
    0x7ffff772bced <+973>:  movq   %r15, %rsi
    0x7ffff772bcf0 <+976>:  movq   %r15, %rdi
    0x7ffff772bcf3 <+979>:  callq  0x7ffff772a870            ; std::__2::vector<float, std::__2::allocator<float> >::vector at vector:1191

** 31       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bcf8 <+984>:  movl   $0x0, 0x28(%r13,%r12)
    0x7ffff772bd01 <+993>:  movl   0x28(%r13,%r12), %edx
    0x7ffff772bd06 <+998>:  movl   0x7c(%r13,%r12), %r8d
    0x7ffff772bd0b <+1003>: cmpl   %r8d, %edx
    0x7ffff772bd0e <+1006>: jae    0x7ffff772bde6            ; <+1222> at vector_algorithms.cpp:17:5

** 32           __m128 values = _mm_loadu_ps(&vec[i]);

    0x7ffff772bd14 <+1012>: movl   0x80(%r13,%r12), %edx
    0x7ffff772bd1c <+1020>: movl   0x28(%r13,%r12), %ecx
    0x7ffff772bd21 <+1025>: movq   %r15, %rsi
    0x7ffff772bd24 <+1028>: movq   %r15, %rdi
    0x7ffff772bd27 <+1031>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772bd2c <+1036>: movl   %eax, 0x88(%r13,%r12)
    0x7ffff772bd34 <+1044>: movl   %eax, 0x21c(%r13,%r12)
    0x7ffff772bd3c <+1052>: movl   %eax, %r11d
    0x7ffff772bd3f <+1055>: vmovdqu (%r13,%r11), %xmm7
    0x7ffff772bd46 <+1062>: vmovdqu %xmm7, 0x10(%r13,%r12)

** 33           __m128 normalized = _mm_mul_ps(values, invSqrt);

    0x7ffff772bd4d <+1069>: vmovdqu 0x30(%r13,%r12), %xmm0
    0x7ffff772bd54 <+1076>: vmovdqu %xmm7, 0xc0(%r13,%r12)
    0x7ffff772bd5e <+1086>: vmovdqu %xmm0, 0xb0(%r13,%r12)
    0x7ffff772bd68 <+1096>: vmovdqu 0xc0(%r13,%r12), %xmm2
    0x7ffff772bd72 <+1106>: vmovdqu %xmm2, 0x2b0(%r13,%r12)
    0x7ffff772bd7c <+1116>: vmovdqu %xmm0, 0x2a0(%r13,%r12)
    0x7ffff772bd86 <+1126>: vmovdqu 0x2b0(%r13,%r12), %xmm4
    0x7ffff772bd90 <+1136>: vmulps %xmm0, %xmm4, %xmm4
    0x7ffff772bd94 <+1140>: vmovdqu %xmm4, (%r13,%r12)

** 34           _mm_storeu_ps(&result[i], normalized);
   35       }
   36

    0x7ffff772bd9b <+1147>: movl   0x28(%r13,%r12), %ecx
    0x7ffff772bda0 <+1152>: movq   (%rsp), %rdx
    0x7ffff772bda4 <+1156>: movq   %r15, %rsi
    0x7ffff772bda7 <+1159>: movq   %r15, %rdi
    0x7ffff772bdaa <+1162>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772bdaf <+1167>: vmovdqu (%r13,%r12), %xmm5
    0x7ffff772bdb6 <+1174>: movl   %eax, 0x1e8(%r13,%r12)
    0x7ffff772bdbe <+1182>: vmovdqu %xmm5, 0x1d0(%r13,%r12)
    0x7ffff772bdc8 <+1192>: movl   0x1e8(%r14), %r10d
    0x7ffff772bdcf <+1199>: vmovdqu %xmm5, (%r13,%r10)
    0x7ffff772bdd6 <+1206>: movl   $0x4, %r11d

** 31       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bddc <+1212>: addl   %r11d, 0x28(%r13,%r12)
    0x7ffff772bde1 <+1217>: jmp    0x7ffff772bd01            ; <+993> at vector_algorithms.cpp:31:24

** 17       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bde6 <+1222>: movl   $0x1, %edi

** 37       return result;

    0x7ffff772bdeb <+1227>: movb   %dil, 0x2f(%r13,%r12)

** 38   }
   39
   40   std::vector<float> normalizeVector(std::vector<int>& vec) {

    0x7ffff772bdf0 <+1232>: movzbq 0x2f(%r13,%r12), %rdi
    0x7ffff772bdf6 <+1238>: andl   $0x1, %edi
    0x7ffff772bdf9 <+1241>: testl  %edi, %edi
    0x7ffff772bdfb <+1243>: jne    0x7ffff772be10            ; <+1264> at vector_algorithms.cpp:38:1
    0x7ffff772be01 <+1249>: movq   (%rsp), %rdx
    0x7ffff772be05 <+1253>: movq   %r15, %rsi
    0x7ffff772be08 <+1256>: movq   %r15, %rdi
    0x7ffff772be0b <+1259>: callq  0x7ffff7725760            ; std::__2::vector<float, std::__2::allocator<float> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772be10 <+1264>: movl   %ebx, 0x110(%r15)
    0x7ffff772be17 <+1271>: movq   0x10(%rsp), %rbx
    0x7ffff772be1c <+1276>: movq   0x18(%rsp), %r12
    0x7ffff772be21 <+1281>: movq   0x20(%rsp), %r13
    0x7ffff772be26 <+1286>: movq   0x28(%rsp), %r14
    0x7ffff772be2b <+1291>: movq   0x30(%rsp), %r15
    0x7ffff772be30 <+1296>: addq   $0x40, %rsp
    0x7ffff772be34 <+1300>: movq   %rbp, %rsp
    0x7ffff772be37 <+1303>: popq   %rbp
    0x7ffff772be38 <+1304>: retq
    0x7ffff772be39 <+1305>: ud2