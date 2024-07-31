0x7ffff772a250 <+0>:    pushq  %rbp
    0x7ffff772a251 <+1>:    movq   %rsp, %rbp
    0x7ffff772a254 <+4>:    movq   0x8(%rdi), %r10
    0x7ffff772a258 <+8>:    movq   (%r10), %r10
    0x7ffff772a25b <+11>:   addq   $0x20, %r10
    0x7ffff772a25f <+15>:   cmpq   %rsp, %r10
    0x7ffff772a262 <+18>:   ja     0x7ffff772a86a            ; <+1562> at matrix_algorithms.cpp:29:1
    0x7ffff772a268 <+24>:   subq   $0x50, %rsp
    0x7ffff772a26c <+28>:   movq   %rbx, 0x20(%rsp)
    0x7ffff772a271 <+33>:   movq   %r12, 0x28(%rsp)
    0x7ffff772a276 <+38>:   movq   %r13, 0x30(%rsp)
    0x7ffff772a27b <+43>:   movq   %r14, 0x38(%rsp)
    0x7ffff772a280 <+48>:   movq   %r15, 0x40(%rsp)
    0x7ffff772a285 <+53>:   movl   0x110(%rdi), %r13d
    0x7ffff772a28c <+60>:   movq   %r13, %r14
    0x7ffff772a28f <+63>:   subl   $0x280, %r14d             ; imm = 0x280
    0x7ffff772a296 <+70>:   movl   %r14d, 0x110(%rdi)
    0x7ffff772a29d <+77>:   movq   0x100(%rdi), %r15
    0x7ffff772a2a4 <+84>:   movq   %rdi, %r10
    0x7ffff772a2a7 <+87>:   leaq   (%r15,%r14), %rbx
    0x7ffff772a2ab <+91>:   movl   %edx, 0xdc(%r15,%r14)
    0x7ffff772a2b3 <+99>:   movq   %rdx, (%rsp)
    0x7ffff772a2b7 <+103>:  movl   %ecx, 0xd8(%r15,%r14)
    0x7ffff772a2bf <+111>:  movl   %r8d, 0xd4(%r15,%r14)

-> 10           std::vector<float> result(rowsCols * rowsCols);
-> 11

->  0x7ffff772a2c7 <+119>:  xorl   %edi, %edi
    0x7ffff772a2c9 <+121>:  movb   %dil, 0xd3(%r15,%r14)
    0x7ffff772a2d1 <+129>:  movl   0xd4(%r15,%r14), %ecx
    0x7ffff772a2d9 <+137>:  imull  %ecx, %ecx
    0x7ffff772a2dc <+140>:  movq   %r10, %r12
    0x7ffff772a2df <+143>:  movq   (%rsp), %rdx
    0x7ffff772a2e3 <+147>:  movq   %r12, %rsi
    0x7ffff772a2e6 <+150>:  movq   %r12, %rdi
    0x7ffff772a2e9 <+153>:  callq  0x7ffff772a870            ; std::__2::vector<float, std::__2::allocator<float> >::vector at vector:1191

** 12           for (size_t i = 0; i < rowsCols; i += 4) {

    0x7ffff772a2ee <+158>:  movl   $0x0, 0xcc(%r15,%r14)
    0x7ffff772a2fa <+170>:  movl   0xcc(%r15,%r14), %edx
    0x7ffff772a302 <+178>:  movl   0xd4(%r15,%r14), %r8d
    0x7ffff772a30a <+186>:  cmpl   %r8d, %edx
    0x7ffff772a30d <+189>:  jae    0x7ffff772a810            ; <+1472> at matrix_algorithms.cpp:12:2

** 13                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x7ffff772a313 <+195>:  movl   $0x0, 0xc8(%r15,%r14)
    0x7ffff772a31f <+207>:  movl   0xc8(%r15,%r14), %r11d
    0x7ffff772a327 <+215>:  movl   0xd4(%r15,%r14), %esi
    0x7ffff772a32f <+223>:  cmpl   %esi, %r11d
    0x7ffff772a332 <+226>:  jae    0x7ffff772a7fe            ; <+1454> at matrix_algorithms.cpp:13:3

** 14                           __m128 row0 = _mm_loadu_ps(&m[i * rowsCols + j]);

    0x7ffff772a338 <+232>:  movl   0xd8(%r15,%r14), %edx
    0x7ffff772a340 <+240>:  movl   0xcc(%r15,%r14), %r10d
    0x7ffff772a348 <+248>:  movl   0xd4(%r15,%r14), %edi
    0x7ffff772a350 <+256>:  movl   0xc8(%r15,%r14), %eax
    0x7ffff772a358 <+264>:  imull  %edi, %r10d
    0x7ffff772a35c <+268>:  leal   (%r10,%rax), %ecx
    0x7ffff772a360 <+272>:  movq   %r12, %rsi
    0x7ffff772a363 <+275>:  movq   %r12, %rdi
    0x7ffff772a366 <+278>:  callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772a36b <+283>:  movl   %eax, 0xec(%r15,%r14)
    0x7ffff772a373 <+291>:  movl   %eax, 0x270(%r15,%r14)
    0x7ffff772a37b <+299>:  movl   %eax, %ecx
    0x7ffff772a37d <+301>:  vmovdqu (%r15,%rcx), %xmm2
    0x7ffff772a383 <+307>:  vmovdqu %xmm2, 0xb0(%r15,%r14)

** 15                           __m128 row1 = _mm_loadu_ps(&m[(i + 1) * rowsCols + j]);

    0x7ffff772a38d <+317>:  movl   0xd8(%r15,%r14), %edx
    0x7ffff772a395 <+325>:  movl   0xcc(%r15,%r14), %r9d
    0x7ffff772a39d <+333>:  movl   0xd4(%r15,%r14), %r8d
    0x7ffff772a3a5 <+341>:  movl   0xc8(%r15,%r14), %r10d
    0x7ffff772a3ad <+349>:  movl   $0x1, %ecx
    0x7ffff772a3b2 <+354>:  movq   %rcx, 0x18(%rsp)
    0x7ffff772a3b7 <+359>:  leal   0x1(%r9), %ecx
    0x7ffff772a3bb <+363>:  imull  %r8d, %ecx
    0x7ffff772a3bf <+367>:  addl   %r10d, %ecx
    0x7ffff772a3c2 <+370>:  movq   %r12, %rsi
    0x7ffff772a3c5 <+373>:  movq   %r12, %rdi
    0x7ffff772a3c8 <+376>:  callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772a3cd <+381>:  movl   %eax, 0xe8(%r15,%r14)
    0x7ffff772a3d5 <+389>:  movl   %eax, 0x274(%r15,%r14)
    0x7ffff772a3dd <+397>:  movl   %eax, %r9d
    0x7ffff772a3e0 <+400>:  vmovdqu (%r15,%r9), %xmm5
    0x7ffff772a3e6 <+406>:  vmovdqu %xmm5, 0xa0(%r15,%r14)

** 16                           __m128 row2 = _mm_loadu_ps(&m[(i + 2) * rowsCols + j]);

    0x7ffff772a3f0 <+416>:  movl   0xd8(%r15,%r14), %edx
    0x7ffff772a3f8 <+424>:  movl   0xcc(%r15,%r14), %r11d
    0x7ffff772a400 <+432>:  movl   0xd4(%r15,%r14), %r10d
    0x7ffff772a408 <+440>:  movl   0xc8(%r15,%r14), %esi
    0x7ffff772a410 <+448>:  movl   $0x2, %ecx
    0x7ffff772a415 <+453>:  movq   %rcx, 0x10(%rsp)
    0x7ffff772a41a <+458>:  leal   0x2(%r11), %r9d
    0x7ffff772a41e <+462>:  imull  %r10d, %r9d
    0x7ffff772a422 <+466>:  leal   (%r9,%rsi), %ecx
    0x7ffff772a426 <+470>:  movq   %r12, %rsi
    0x7ffff772a429 <+473>:  movq   %r12, %rdi
    0x7ffff772a42c <+476>:  callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772a431 <+481>:  movl   %eax, 0xe4(%r15,%r14)
    0x7ffff772a439 <+489>:  movl   %eax, 0x278(%r15,%r14)
    0x7ffff772a441 <+497>:  movl   %eax, %esi
    0x7ffff772a443 <+499>:  vmovdqu (%r15,%rsi), %xmm0
    0x7ffff772a449 <+505>:  vmovdqu %xmm0, 0x90(%r15,%r14)

** 17                           __m128 row3 = _mm_loadu_ps(&m[(i + 3) * rowsCols + j]);
   18

    0x7ffff772a453 <+515>:  movl   0xd8(%r15,%r14), %edx
    0x7ffff772a45b <+523>:  movl   0xcc(%r15,%r14), %ecx
    0x7ffff772a463 <+531>:  movl   0xd4(%r15,%r14), %edi
    0x7ffff772a46b <+539>:  movl   0xc8(%r15,%r14), %r8d
    0x7ffff772a473 <+547>:  movl   $0x3, %r9d
    0x7ffff772a479 <+553>:  movq   %r9, 0x8(%rsp)
    0x7ffff772a47e <+558>:  leal   0x3(%rcx), %esi
    0x7ffff772a481 <+561>:  imull  %edi, %esi
    0x7ffff772a484 <+564>:  leal   (%rsi,%r8), %ecx
    0x7ffff772a488 <+568>:  movq   %r12, %rsi
    0x7ffff772a48b <+571>:  movq   %r12, %rdi
    0x7ffff772a48e <+574>:  callq  0x7ffff772a9d0            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772a493 <+579>:  movl   %eax, 0xe0(%r15,%r14)
    0x7ffff772a49b <+587>:  movl   %eax, 0x27c(%r15,%r14)
    0x7ffff772a4a3 <+595>:  movl   %eax, %ecx
    0x7ffff772a4a5 <+597>:  vmovdqu (%r15,%rcx), %xmm3
    0x7ffff772a4ab <+603>:  vmovdqu %xmm3, 0x80(%r15,%r14)

** 19                           _MM_TRANSPOSE4_PS(row0, row1, row2, row3);
   20

    0x7ffff772a4b5 <+613>:  vmovdqu 0xb0(%r15,%r14), %xmm4
    0x7ffff772a4bf <+623>:  vmovdqu %xmm4, 0x70(%r15,%r14)
    0x7ffff772a4c6 <+630>:  vmovdqu 0xa0(%r15,%r14), %xmm5
    0x7ffff772a4d0 <+640>:  vmovdqu %xmm5, 0x60(%r15,%r14)
    0x7ffff772a4d7 <+647>:  vmovdqu 0x90(%r15,%r14), %xmm6
    0x7ffff772a4e1 <+657>:  vmovdqu %xmm6, 0x50(%r15,%r14)
    0x7ffff772a4e8 <+664>:  vmovdqu 0x80(%r15,%r14), %xmm7
    0x7ffff772a4f2 <+674>:  vmovdqu %xmm7, 0x40(%r15,%r14)
    0x7ffff772a4f9 <+681>:  vmovdqu 0x70(%r15,%r14), %xmm1
    0x7ffff772a500 <+688>:  vmovdqu 0x60(%r15,%r14), %xmm0
    0x7ffff772a507 <+695>:  vmovdqu %xmm1, 0x120(%r15,%r14)
    0x7ffff772a511 <+705>:  vmovdqu %xmm0, 0x110(%r15,%r14)
    0x7ffff772a51b <+715>:  vmovdqu 0x120(%r15,%r14), %xmm2
    0x7ffff772a525 <+725>:  vpunpckldq %xmm0, %xmm2, %xmm2       ; xmm2 = xmm2[0],xmm0[0],xmm2[1],xmm0[1]
    0x7ffff772a529 <+729>:  vmovdqu %xmm2, 0x30(%r15,%r14)
    0x7ffff772a530 <+736>:  vmovdqu 0x70(%r15,%r14), %xmm4
    0x7ffff772a537 <+743>:  vmovdqu 0x60(%r15,%r14), %xmm3
    0x7ffff772a53e <+750>:  vmovdqu %xmm4, 0x160(%r15,%r14)
    0x7ffff772a548 <+760>:  vmovdqu %xmm3, 0x150(%r15,%r14)
    0x7ffff772a552 <+770>:  vmovdqu 0x160(%r15,%r14), %xmm5
    0x7ffff772a55c <+780>:  vpunpckhdq %xmm3, %xmm5, %xmm5       ; xmm5 = xmm5[2],xmm3[2],xmm5[3],xmm3[3]
    0x7ffff772a560 <+784>:  vmovdqu %xmm5, 0x20(%r15,%r14)
    0x7ffff772a567 <+791>:  vmovdqu 0x50(%r15,%r14), %xmm7
    0x7ffff772a56e <+798>:  vmovdqu 0x40(%r15,%r14), %xmm6
    0x7ffff772a575 <+805>:  vmovdqu %xmm7, 0x100(%r15,%r14)
    0x7ffff772a57f <+815>:  vmovdqu %xmm6, 0xf0(%r15,%r14)
    0x7ffff772a589 <+825>:  vmovdqu 0x100(%r15,%r14), %xmm0
    0x7ffff772a593 <+835>:  vpunpckldq %xmm6, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm6[0],xmm0[1],xmm6[1]
    0x7ffff772a597 <+839>:  vmovdqu %xmm0, 0x10(%r15,%r14)
    0x7ffff772a59e <+846>:  vmovdqu 0x50(%r15,%r14), %xmm2
    0x7ffff772a5a5 <+853>:  vmovdqu 0x40(%r15,%r14), %xmm1
    0x7ffff772a5ac <+860>:  vmovdqu %xmm2, 0x140(%r15,%r14)
    0x7ffff772a5b6 <+870>:  vmovdqu %xmm1, 0x130(%r15,%r14)
    0x7ffff772a5c0 <+880>:  vmovdqu 0x140(%r15,%r14), %xmm3
    0x7ffff772a5ca <+890>:  vpunpckhdq %xmm1, %xmm3, %xmm3       ; xmm3 = xmm3[2],xmm1[2],xmm3[3],xmm1[3]
    0x7ffff772a5ce <+894>:  vmovdqu %xmm3, (%r15,%r14)
    0x7ffff772a5d4 <+900>:  vmovdqu 0x30(%r15,%r14), %xmm5
    0x7ffff772a5db <+907>:  vmovdqu 0x10(%r15,%r14), %xmm4
    0x7ffff772a5e2 <+914>:  vmovdqu %xmm5, 0x1a0(%r15,%r14)
    0x7ffff772a5ec <+924>:  vmovdqu %xmm4, 0x190(%r15,%r14)
    0x7ffff772a5f6 <+934>:  vmovdqu 0x1a0(%r15,%r14), %xmm6
    0x7ffff772a600 <+944>:  vpunpcklqdq %xmm4, %xmm6, %xmm6       ; xmm6 = xmm6[0],xmm4[0]
    0x7ffff772a604 <+948>:  vmovdqu %xmm6, 0xb0(%r15,%r14)
    0x7ffff772a60e <+958>:  vmovdqu 0x10(%r15,%r14), %xmm0
    0x7ffff772a615 <+965>:  vmovdqu 0x30(%r15,%r14), %xmm7
    0x7ffff772a61c <+972>:  vmovdqu %xmm0, 0x1e0(%r15,%r14)
    0x7ffff772a626 <+982>:  vmovdqu %xmm7, 0x1d0(%r15,%r14)
    0x7ffff772a630 <+992>:  vshufps $0xee, 0x1e0(%rbx), %xmm7, %xmm1 ; xmm1 = xmm7[2,3],mem[2,3]
    0x7ffff772a639 <+1001>: vmovdqu %xmm1, 0xa0(%r15,%r14)
    0x7ffff772a643 <+1011>: vmovdqu 0x20(%r15,%r14), %xmm3
    0x7ffff772a64a <+1018>: vmovdqu (%r15,%r14), %xmm2
    0x7ffff772a650 <+1024>: vmovdqu %xmm3, 0x180(%r15,%r14)
    0x7ffff772a65a <+1034>: vmovdqu %xmm2, 0x170(%r15,%r14)
    0x7ffff772a664 <+1044>: vmovdqu 0x180(%r15,%r14), %xmm4
    0x7ffff772a66e <+1054>: vpunpcklqdq %xmm2, %xmm4, %xmm4       ; xmm4 = xmm4[0],xmm2[0]
    0x7ffff772a672 <+1058>: vmovdqu %xmm4, 0x90(%r15,%r14)
    0x7ffff772a67c <+1068>: vmovdqu (%r15,%r14), %xmm6
    0x7ffff772a682 <+1074>: vmovdqu 0x20(%r15,%r14), %xmm5
    0x7ffff772a689 <+1081>: vmovdqu %xmm6, 0x1c0(%r15,%r14)
    0x7ffff772a693 <+1091>: vmovdqu %xmm5, 0x1b0(%r15,%r14)
    0x7ffff772a69d <+1101>: vshufps $0xee, 0x1c0(%rbx), %xmm5, %xmm7 ; xmm7 = xmm5[2,3],mem[2,3]
    0x7ffff772a6a6 <+1110>: vmovdqu %xmm7, 0x80(%r15,%r14)

** 21                           _mm_storeu_ps(&result[j * rowsCols + i], row0);

    0x7ffff772a6b0 <+1120>: movl   0xc8(%r15,%r14), %ecx
    0x7ffff772a6b8 <+1128>: imull  0xd4(%rbx), %ecx
    0x7ffff772a6bf <+1135>: addl   0xcc(%rbx), %ecx
    0x7ffff772a6c5 <+1141>: movq   (%rsp), %rdx
    0x7ffff772a6c9 <+1145>: movq   %r12, %rsi
    0x7ffff772a6cc <+1148>: movq   %r12, %rdi
    0x7ffff772a6cf <+1151>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772a6d4 <+1156>: vmovdqu 0xb0(%r15,%r14), %xmm0
    0x7ffff772a6de <+1166>: movl   %eax, 0x26c(%r15,%r14)
    0x7ffff772a6e6 <+1174>: vmovdqu %xmm0, 0x250(%r15,%r14)
    0x7ffff772a6f0 <+1184>: movl   0x26c(%rbx), %r10d
    0x7ffff772a6f7 <+1191>: vmovdqu %xmm0, (%r15,%r10)
    0x7ffff772a6fd <+1197>: movq   0x18(%rsp), %rcx
    0x7ffff772a702 <+1202>: addl   0xc8(%rbx), %ecx

** 22                           _mm_storeu_ps(&result[(j + 1) * rowsCols + i], row1);

    0x7ffff772a708 <+1208>: imull  0xd4(%rbx), %ecx
    0x7ffff772a70f <+1215>: addl   0xcc(%rbx), %ecx
    0x7ffff772a715 <+1221>: movq   (%rsp), %rdx
    0x7ffff772a719 <+1225>: movq   %r12, %rsi
    0x7ffff772a71c <+1228>: movq   %r12, %rdi
    0x7ffff772a71f <+1231>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772a724 <+1236>: vmovdqu 0xa0(%r15,%r14), %xmm3
    0x7ffff772a72e <+1246>: movl   %eax, 0x24c(%r15,%r14)
    0x7ffff772a736 <+1254>: vmovdqu %xmm3, 0x230(%r15,%r14)
    0x7ffff772a740 <+1264>: movl   0x24c(%rbx), %edi
    0x7ffff772a746 <+1270>: vmovdqu %xmm3, (%r15,%rdi)
    0x7ffff772a74c <+1276>: movq   0x10(%rsp), %rcx
    0x7ffff772a751 <+1281>: addl   0xc8(%rbx), %ecx

** 23                           _mm_storeu_ps(&result[(j + 2) * rowsCols + i], row2);

    0x7ffff772a757 <+1287>: imull  0xd4(%rbx), %ecx
    0x7ffff772a75e <+1294>: addl   0xcc(%rbx), %ecx
    0x7ffff772a764 <+1300>: movq   (%rsp), %rdx
    0x7ffff772a768 <+1304>: movq   %r12, %rsi
    0x7ffff772a76b <+1307>: movq   %r12, %rdi
    0x7ffff772a76e <+1310>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772a773 <+1315>: vmovdqu 0x90(%r15,%r14), %xmm6
    0x7ffff772a77d <+1325>: movl   %eax, 0x22c(%r15,%r14)
    0x7ffff772a785 <+1333>: vmovdqu %xmm6, 0x210(%r15,%r14)
    0x7ffff772a78f <+1343>: movl   0x22c(%rbx), %edx
    0x7ffff772a795 <+1349>: vmovdqu %xmm6, (%r15,%rdx)
    0x7ffff772a79b <+1355>: movq   0x8(%rsp), %rcx
    0x7ffff772a7a0 <+1360>: addl   0xc8(%rbx), %ecx

** 24                           _mm_storeu_ps(&result[(j + 3) * rowsCols + i], row3);
   25                   }
   26           }

    0x7ffff772a7a6 <+1366>: imull  0xd4(%rbx), %ecx
    0x7ffff772a7ad <+1373>: addl   0xcc(%rbx), %ecx
    0x7ffff772a7b3 <+1379>: movq   (%rsp), %rdx
    0x7ffff772a7b7 <+1383>: movq   %r12, %rsi
    0x7ffff772a7ba <+1386>: movq   %r12, %rdi
    0x7ffff772a7bd <+1389>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772a7c2 <+1394>: vmovdqu 0x80(%r15,%r14), %xmm1
    0x7ffff772a7cc <+1404>: movl   %eax, 0x20c(%r15,%r14)
    0x7ffff772a7d4 <+1412>: vmovdqu %xmm1, 0x1f0(%r15,%r14)
    0x7ffff772a7de <+1422>: movl   0x20c(%rbx), %r10d
    0x7ffff772a7e5 <+1429>: vmovdqu %xmm1, (%r15,%r10)
    0x7ffff772a7eb <+1435>: movl   $0x4, %r11d

** 13                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x7ffff772a7f1 <+1441>: addl   %r11d, 0xc8(%r15,%r14)
    0x7ffff772a7f9 <+1449>: jmp    0x7ffff772a31f            ; <+207> at matrix_algorithms.cpp:13:22
    0x7ffff772a7fe <+1454>: movl   $0x4, %edi

** 12           for (size_t i = 0; i < rowsCols; i += 4) {

    0x7ffff772a803 <+1459>: addl   %edi, 0xcc(%r15,%r14)
    0x7ffff772a80b <+1467>: jmp    0x7ffff772a2fa            ; <+170> at matrix_algorithms.cpp:12:21
    0x7ffff772a810 <+1472>: movl   $0x1, %ecx

   27
** 28           return result;

    0x7ffff772a815 <+1477>: movb   %cl, 0xd3(%r15,%r14)

** 29   }
   30
   31   std::vector<int> transposeMatrix(const std::vector<int>& m, size_t rowsCols) {

    0x7ffff772a81d <+1485>: movzbq 0xd3(%r15,%r14), %rcx
    0x7ffff772a826 <+1494>: andl   $0x1, %ecx
    0x7ffff772a829 <+1497>: testl  %ecx, %ecx
    0x7ffff772a82b <+1499>: jne    0x7ffff772a840            ; <+1520> at matrix_algorithms.cpp:29:1
    0x7ffff772a831 <+1505>: movq   (%rsp), %rdx
    0x7ffff772a835 <+1509>: movq   %r12, %rsi
    0x7ffff772a838 <+1512>: movq   %r12, %rdi
    0x7ffff772a83b <+1515>: callq  0x7ffff7725760            ; std::__2::vector<float, std::__2::allocator<float> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772a840 <+1520>: movl   %r13d, 0x110(%r12)
    0x7ffff772a848 <+1528>: movq   0x20(%rsp), %rbx
    0x7ffff772a84d <+1533>: movq   0x28(%rsp), %r12
    0x7ffff772a852 <+1538>: movq   0x30(%rsp), %r13
    0x7ffff772a857 <+1543>: movq   0x38(%rsp), %r14
    0x7ffff772a85c <+1548>: movq   0x40(%rsp), %r15
    0x7ffff772a861 <+1553>: addq   $0x50, %rsp
    0x7ffff772a865 <+1557>: movq   %rbp, %rsp
    0x7ffff772a868 <+1560>: popq   %rbp
    0x7ffff772a869 <+1561>: retq
    0x7ffff772a86a <+1562>: ud2