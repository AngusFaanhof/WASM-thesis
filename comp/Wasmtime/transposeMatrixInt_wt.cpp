0x7ffff772abb0 <+0>:    pushq  %rbp
    0x7ffff772abb1 <+1>:    movq   %rsp, %rbp
    0x7ffff772abb4 <+4>:    movq   0x8(%rdi), %r10
    0x7ffff772abb8 <+8>:    movq   (%r10), %r10
    0x7ffff772abbb <+11>:   addq   $0x20, %r10
    0x7ffff772abbf <+15>:   cmpq   %rsp, %r10
    0x7ffff772abc2 <+18>:   ja     0x7ffff772b160            ; <+1456> at matrix_algorithms.cpp:60:1
    0x7ffff772abc8 <+24>:   subq   $0x50, %rsp
    0x7ffff772abcc <+28>:   movq   %rbx, 0x20(%rsp)
    0x7ffff772abd1 <+33>:   movq   %r12, 0x28(%rsp)
    0x7ffff772abd6 <+38>:   movq   %r13, 0x30(%rsp)
    0x7ffff772abdb <+43>:   movq   %r14, 0x38(%rsp)
    0x7ffff772abe0 <+48>:   movq   %r15, 0x40(%rsp)
    0x7ffff772abe5 <+53>:   movl   0x110(%rdi), %ebx
    0x7ffff772abeb <+59>:   movq   %rbx, %r12
    0x7ffff772abee <+62>:   subl   $0x230, %r12d             ; imm = 0x230
    0x7ffff772abf5 <+69>:   movl   %r12d, 0x110(%rdi)
    0x7ffff772abfc <+76>:   movq   0x100(%rdi), %r13
    0x7ffff772ac03 <+83>:   leaq   (%r13,%r12), %r14
    0x7ffff772ac08 <+88>:   movl   %edx, 0x9c(%r13,%r12)
    0x7ffff772ac10 <+96>:   movq   %rdx, (%rsp)
    0x7ffff772ac14 <+100>:  movl   %ecx, 0x98(%r13,%r12)
    0x7ffff772ac1c <+108>:  movl   %r8d, 0x94(%r13,%r12)

-> 32           std::vector<int> result(rowsCols * rowsCols);
-> 33

->  0x7ffff772ac24 <+116>:  xorl   %r11d, %r11d
    0x7ffff772ac27 <+119>:  movb   %r11b, 0x93(%r13,%r12)
    0x7ffff772ac2f <+127>:  movl   0x94(%r13,%r12), %ecx
    0x7ffff772ac37 <+135>:  imull  %ecx, %ecx
    0x7ffff772ac3a <+138>:  movq   %rdi, %r15
    0x7ffff772ac3d <+141>:  movq   (%rsp), %rdx
    0x7ffff772ac41 <+145>:  movq   %r15, %rsi
    0x7ffff772ac44 <+148>:  movq   %r15, %rdi
    0x7ffff772ac47 <+151>:  callq  0x7ffff7729e90            ; std::__2::vector<int, std::__2::allocator<int> >::vector at vector:1191

** 34           for (size_t i = 0; i < rowsCols; i += 4) {

    0x7ffff772ac4c <+156>:  movl   $0x0, 0x8c(%r13,%r12)
    0x7ffff772ac58 <+168>:  movl   0x8c(%r13,%r12), %ecx
    0x7ffff772ac60 <+176>:  movl   0x94(%r13,%r12), %eax
    0x7ffff772ac68 <+184>:  cmpl   %eax, %ecx
    0x7ffff772ac6a <+186>:  jae    0x7ffff772b107            ; <+1367> at matrix_algorithms.cpp:34:2

** 35                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x7ffff772ac70 <+192>:  movl   $0x0, 0x88(%r13,%r12)
    0x7ffff772ac7c <+204>:  movl   0x88(%r13,%r12), %r9d
    0x7ffff772ac84 <+212>:  movl   0x94(%r13,%r12), %r10d
    0x7ffff772ac8c <+220>:  cmpl   %r10d, %r9d
    0x7ffff772ac8f <+223>:  jae    0x7ffff772b0f5            ; <+1349> at matrix_algorithms.cpp:35:3

** 36                           __m128i row0 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[i * rowsCols + j]));

    0x7ffff772ac95 <+229>:  movl   0x98(%r13,%r12), %edx
    0x7ffff772ac9d <+237>:  movl   0x8c(%r13,%r12), %r8d
    0x7ffff772aca5 <+245>:  movl   0x94(%r13,%r12), %r11d
    0x7ffff772acad <+253>:  movl   0x88(%r13,%r12), %esi
    0x7ffff772acb5 <+261>:  imull  %r11d, %r8d
    0x7ffff772acb9 <+265>:  leal   (%r8,%rsi), %ecx
    0x7ffff772acbd <+269>:  movq   %r15, %rsi
    0x7ffff772acc0 <+272>:  movq   %r15, %rdi
    0x7ffff772acc3 <+275>:  callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772acc8 <+280>:  movl   %eax, 0xac(%r13,%r12)
    0x7ffff772acd0 <+288>:  movl   %eax, %esi
    0x7ffff772acd2 <+290>:  vmovdqu (%r13,%rsi), %xmm7
    0x7ffff772acd9 <+297>:  vmovdqu %xmm7, 0x70(%r13,%r12)

** 37                           __m128i row1 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 1) * rowsCols + j]));

    0x7ffff772ace0 <+304>:  movl   0x98(%r13,%r12), %edx
    0x7ffff772ace8 <+312>:  movl   0x8c(%r13,%r12), %ecx
    0x7ffff772acf0 <+320>:  movl   0x94(%r13,%r12), %edi
    0x7ffff772acf8 <+328>:  movl   0x88(%r13,%r12), %r8d
    0x7ffff772ad00 <+336>:  movl   $0x1, %r9d
    0x7ffff772ad06 <+342>:  movq   %r9, 0x18(%rsp)
    0x7ffff772ad0b <+347>:  leal   0x1(%rcx), %esi
    0x7ffff772ad0e <+350>:  imull  %edi, %esi
    0x7ffff772ad11 <+353>:  leal   (%rsi,%r8), %ecx
    0x7ffff772ad15 <+357>:  movq   %r15, %rsi
    0x7ffff772ad18 <+360>:  movq   %r15, %rdi
    0x7ffff772ad1b <+363>:  callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772ad20 <+368>:  movl   %eax, 0xa8(%r13,%r12)
    0x7ffff772ad28 <+376>:  movl   %eax, %eax
    0x7ffff772ad2a <+378>:  vmovdqu (%r13,%rax), %xmm1
    0x7ffff772ad31 <+385>:  vmovdqu %xmm1, 0x60(%r13,%r12)

** 38                           __m128i row2 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 2) * rowsCols + j]));

    0x7ffff772ad38 <+392>:  movl   0x98(%r13,%r12), %edx
    0x7ffff772ad40 <+400>:  movl   0x8c(%r13,%r12), %r8d
    0x7ffff772ad48 <+408>:  movl   0x94(%r13,%r12), %ecx
    0x7ffff772ad50 <+416>:  movl   0x88(%r13,%r12), %r9d
    0x7ffff772ad58 <+424>:  movl   $0x2, %eax
    0x7ffff772ad5d <+429>:  movq   %rax, 0x10(%rsp)
    0x7ffff772ad62 <+434>:  leal   0x2(%r8), %eax
    0x7ffff772ad66 <+438>:  imull  %ecx, %eax
    0x7ffff772ad69 <+441>:  leal   (%rax,%r9), %ecx
    0x7ffff772ad6d <+445>:  movq   %r15, %rsi
    0x7ffff772ad70 <+448>:  movq   %r15, %rdi
    0x7ffff772ad73 <+451>:  callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772ad78 <+456>:  movl   %eax, 0xa4(%r13,%r12)
    0x7ffff772ad80 <+464>:  movl   %eax, %edx
    0x7ffff772ad82 <+466>:  vmovdqu (%r13,%rdx), %xmm3
    0x7ffff772ad89 <+473>:  vmovdqu %xmm3, 0x50(%r13,%r12)

** 39                           __m128i row3 = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&m[(i + 3) * rowsCols + j]));
   40
   41                           // _MM_TRANSPOSE4_EPI32(row0, row1, row2, row3);

    0x7ffff772ad90 <+480>:  movl   0x98(%r13,%r12), %edx
    0x7ffff772ad98 <+488>:  movl   0x8c(%r13,%r12), %r9d
    0x7ffff772ada0 <+496>:  movl   0x94(%r13,%r12), %r8d
    0x7ffff772ada8 <+504>:  movl   0x88(%r13,%r12), %r10d
    0x7ffff772adb0 <+512>:  movl   $0x3, %ecx
    0x7ffff772adb5 <+517>:  movq   %rcx, 0x8(%rsp)
    0x7ffff772adba <+522>:  addl   $0x3, %r9d
    0x7ffff772adbe <+526>:  imull  %r8d, %r9d
    0x7ffff772adc2 <+530>:  leal   (%r9,%r10), %ecx
    0x7ffff772adc6 <+534>:  movq   %r15, %rsi
    0x7ffff772adc9 <+537>:  movq   %r15, %rdi
    0x7ffff772adcc <+540>:  callq  0x7ffff772b170            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) const at vector:1546
    0x7ffff772add1 <+545>:  movl   %eax, 0xa0(%r13,%r12)
    0x7ffff772add9 <+553>:  movl   %eax, %r9d
    0x7ffff772addc <+556>:  vmovdqu (%r13,%r9), %xmm5
    0x7ffff772ade3 <+563>:  vmovdqu %xmm5, 0x40(%r13,%r12)

** 42                           __m128i tmp0 = _mm_unpacklo_epi32(row0, row1);

    0x7ffff772adea <+570>:  vmovdqu 0x70(%r13,%r12), %xmm7
    0x7ffff772adf1 <+577>:  vmovdqu 0x60(%r13,%r12), %xmm6
    0x7ffff772adf8 <+584>:  vmovdqu %xmm7, 0xe0(%r13,%r12)
    0x7ffff772ae02 <+594>:  vmovdqu %xmm6, 0xd0(%r13,%r12)
    0x7ffff772ae0c <+604>:  vmovdqu 0xe0(%r13,%r12), %xmm0
    0x7ffff772ae16 <+614>:  vpunpckldq %xmm6, %xmm0, %xmm0       ; xmm0 = xmm0[0],xmm6[0],xmm0[1],xmm6[1]
    0x7ffff772ae1a <+618>:  vmovdqu %xmm0, 0x30(%r13,%r12)

** 43                           __m128i tmp1 = _mm_unpacklo_epi32(row2, row3);

    0x7ffff772ae21 <+625>:  vmovdqu 0x50(%r13,%r12), %xmm2
    0x7ffff772ae28 <+632>:  vmovdqu 0x40(%r13,%r12), %xmm1
    0x7ffff772ae2f <+639>:  vmovdqu %xmm2, 0xc0(%r13,%r12)
    0x7ffff772ae39 <+649>:  vmovdqu %xmm1, 0xb0(%r13,%r12)
    0x7ffff772ae43 <+659>:  vmovdqu 0xc0(%r13,%r12), %xmm3
    0x7ffff772ae4d <+669>:  vpunpckldq %xmm1, %xmm3, %xmm3       ; xmm3 = xmm3[0],xmm1[0],xmm3[1],xmm1[1]
    0x7ffff772ae51 <+673>:  vmovdqu %xmm3, 0x20(%r13,%r12)

** 44                           __m128i tmp2 = _mm_unpackhi_epi32(row0, row1);

    0x7ffff772ae58 <+680>:  vmovdqu 0x70(%r13,%r12), %xmm5
    0x7ffff772ae5f <+687>:  vmovdqu 0x60(%r13,%r12), %xmm4
    0x7ffff772ae66 <+694>:  vmovdqu %xmm5, 0x120(%r13,%r12)
    0x7ffff772ae70 <+704>:  vmovdqu %xmm4, 0x110(%r13,%r12)
    0x7ffff772ae7a <+714>:  vmovdqu 0x120(%r13,%r12), %xmm6
    0x7ffff772ae84 <+724>:  vpunpckhdq %xmm4, %xmm6, %xmm6       ; xmm6 = xmm6[2],xmm4[2],xmm6[3],xmm4[3]
    0x7ffff772ae88 <+728>:  vmovdqu %xmm6, 0x10(%r13,%r12)

** 45                           __m128i tmp3 = _mm_unpackhi_epi32(row2, row3);
   46

    0x7ffff772ae8f <+735>:  vmovdqu 0x50(%r13,%r12), %xmm0
    0x7ffff772ae96 <+742>:  vmovdqu 0x40(%r13,%r12), %xmm7
    0x7ffff772ae9d <+749>:  vmovdqu %xmm0, 0x100(%r13,%r12)
    0x7ffff772aea7 <+759>:  vmovdqu %xmm7, 0xf0(%r13,%r12)
    0x7ffff772aeb1 <+769>:  vmovdqu 0x100(%r13,%r12), %xmm1
    0x7ffff772aebb <+779>:  vpunpckhdq %xmm7, %xmm1, %xmm1       ; xmm1 = xmm1[2],xmm7[2],xmm1[3],xmm7[3]
    0x7ffff772aebf <+783>:  vmovdqu %xmm1, (%r13,%r12)

** 47                           row0 = _mm_unpacklo_epi64(tmp0, tmp1);

    0x7ffff772aec6 <+790>:  vmovdqu 0x30(%r13,%r12), %xmm3
    0x7ffff772aecd <+797>:  vmovdqu 0x20(%r13,%r12), %xmm2
    0x7ffff772aed4 <+804>:  vmovdqu %xmm3, 0x160(%r13,%r12)
    0x7ffff772aede <+814>:  vmovdqu %xmm2, 0x150(%r13,%r12)
    0x7ffff772aee8 <+824>:  vmovdqu 0x160(%r13,%r12), %xmm4
    0x7ffff772aef2 <+834>:  vpunpcklqdq %xmm2, %xmm4, %xmm4       ; xmm4 = xmm4[0],xmm2[0]
    0x7ffff772aef6 <+838>:  vmovdqu %xmm4, 0x70(%r13,%r12)

** 48                           row1 = _mm_unpackhi_epi64(tmp0, tmp1);

    0x7ffff772aefd <+845>:  vmovdqu 0x30(%r13,%r12), %xmm6
    0x7ffff772af04 <+852>:  vmovdqu 0x20(%r13,%r12), %xmm5
    0x7ffff772af0b <+859>:  vmovdqu %xmm6, 0x1a0(%r13,%r12)
    0x7ffff772af15 <+869>:  vmovdqu %xmm5, 0x190(%r13,%r12)
    0x7ffff772af1f <+879>:  vmovdqu 0x1a0(%r13,%r12), %xmm7
    0x7ffff772af29 <+889>:  vpunpckhqdq %xmm5, %xmm7, %xmm7       ; xmm7 = xmm7[1],xmm5[1]
    0x7ffff772af2d <+893>:  vmovdqu %xmm7, 0x60(%r13,%r12)

** 49                           row2 = _mm_unpacklo_epi64(tmp2, tmp3);

    0x7ffff772af34 <+900>:  vmovdqu 0x10(%r13,%r12), %xmm1
    0x7ffff772af3b <+907>:  vmovdqu (%r13,%r12), %xmm0
    0x7ffff772af42 <+914>:  vmovdqu %xmm1, 0x140(%r13,%r12)
    0x7ffff772af4c <+924>:  vmovdqu %xmm0, 0x130(%r13,%r12)
    0x7ffff772af56 <+934>:  vmovdqu 0x140(%r13,%r12), %xmm2
    0x7ffff772af60 <+944>:  vpunpcklqdq %xmm0, %xmm2, %xmm2       ; xmm2 = xmm2[0],xmm0[0]
    0x7ffff772af64 <+948>:  vmovdqu %xmm2, 0x50(%r13,%r12)

** 50                           row3 = _mm_unpackhi_epi64(tmp2, tmp3);
   51

    0x7ffff772af6b <+955>:  vmovdqu 0x10(%r13,%r12), %xmm4
    0x7ffff772af72 <+962>:  vmovdqu (%r13,%r12), %xmm3
    0x7ffff772af79 <+969>:  vmovdqu %xmm4, 0x180(%r13,%r12)
    0x7ffff772af83 <+979>:  vmovdqu %xmm3, 0x170(%r13,%r12)
    0x7ffff772af8d <+989>:  vmovdqu 0x180(%r13,%r12), %xmm5
    0x7ffff772af97 <+999>:  vpunpckhqdq %xmm3, %xmm5, %xmm5       ; xmm5 = xmm5[1],xmm3[1]
    0x7ffff772af9b <+1003>: vmovdqu %xmm5, 0x40(%r13,%r12)

** 52                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[j * rowsCols + i]), row0);

    0x7ffff772afa2 <+1010>: movl   0x88(%r13,%r12), %ecx
    0x7ffff772afaa <+1018>: imull  0x94(%r14), %ecx
    0x7ffff772afb2 <+1026>: addl   0x8c(%r14), %ecx
    0x7ffff772afb9 <+1033>: movq   (%rsp), %rdx
    0x7ffff772afbd <+1037>: movq   %r15, %rsi
    0x7ffff772afc0 <+1040>: movq   %r15, %rdi
    0x7ffff772afc3 <+1043>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772afc8 <+1048>: vmovdqu 0x70(%r13,%r12), %xmm6
    0x7ffff772afcf <+1055>: movl   %eax, 0x22c(%r13,%r12)
    0x7ffff772afd7 <+1063>: vmovdqu %xmm6, 0x210(%r13,%r12)
    0x7ffff772afe1 <+1073>: movl   0x22c(%r14), %r9d
    0x7ffff772afe8 <+1080>: vmovdqu %xmm6, (%r13,%r9)
    0x7ffff772afef <+1087>: movq   0x18(%rsp), %rcx
    0x7ffff772aff4 <+1092>: addl   0x88(%r14), %ecx

** 53                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 1) * rowsCols + i]), row1);

    0x7ffff772affb <+1099>: imull  0x94(%r14), %ecx
    0x7ffff772b003 <+1107>: addl   0x8c(%r14), %ecx
    0x7ffff772b00a <+1114>: movq   (%rsp), %rdx
    0x7ffff772b00e <+1118>: movq   %r15, %rsi
    0x7ffff772b011 <+1121>: movq   %r15, %rdi
    0x7ffff772b014 <+1124>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772b019 <+1129>: vmovdqu 0x60(%r13,%r12), %xmm1
    0x7ffff772b020 <+1136>: movl   %eax, 0x20c(%r13,%r12)
    0x7ffff772b028 <+1144>: vmovdqu %xmm1, 0x1f0(%r13,%r12)
    0x7ffff772b032 <+1154>: movl   0x20c(%r14), %esi
    0x7ffff772b039 <+1161>: vmovdqu %xmm1, (%r13,%rsi)
    0x7ffff772b040 <+1168>: movq   0x10(%rsp), %rcx
    0x7ffff772b045 <+1173>: addl   0x88(%r14), %ecx

** 54                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 2) * rowsCols + i]), row2);

    0x7ffff772b04c <+1180>: imull  0x94(%r14), %ecx
    0x7ffff772b054 <+1188>: addl   0x8c(%r14), %ecx
    0x7ffff772b05b <+1195>: movq   (%rsp), %rdx
    0x7ffff772b05f <+1199>: movq   %r15, %rsi
    0x7ffff772b062 <+1202>: movq   %r15, %rdi
    0x7ffff772b065 <+1205>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772b06a <+1210>: vmovdqu 0x50(%r13,%r12), %xmm4
    0x7ffff772b071 <+1217>: movl   %eax, 0x1ec(%r13,%r12)
    0x7ffff772b079 <+1225>: vmovdqu %xmm4, 0x1d0(%r13,%r12)
    0x7ffff772b083 <+1235>: movl   0x1ec(%r14), %ecx
    0x7ffff772b08a <+1242>: vmovdqu %xmm4, (%r13,%rcx)
    0x7ffff772b091 <+1249>: movq   0x8(%rsp), %rcx
    0x7ffff772b096 <+1254>: addl   0x88(%r14), %ecx

** 55                           _mm_storeu_si128(reinterpret_cast<__m128i*>(&result[(j + 3) * rowsCols + i]), row3);
   56                   }
   57           }

    0x7ffff772b09d <+1261>: imull  0x94(%r14), %ecx
    0x7ffff772b0a5 <+1269>: addl   0x8c(%r14), %ecx
    0x7ffff772b0ac <+1276>: movq   (%rsp), %rdx
    0x7ffff772b0b0 <+1280>: movq   %r15, %rsi
    0x7ffff772b0b3 <+1283>: movq   %r15, %rdi
    0x7ffff772b0b6 <+1286>: callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772b0bb <+1291>: vmovdqu 0x40(%r13,%r12), %xmm7
    0x7ffff772b0c2 <+1298>: movl   %eax, 0x1cc(%r13,%r12)
    0x7ffff772b0ca <+1306>: vmovdqu %xmm7, 0x1b0(%r13,%r12)
    0x7ffff772b0d4 <+1316>: movl   0x1cc(%r14), %r9d
    0x7ffff772b0db <+1323>: vmovdqu %xmm7, (%r13,%r9)
    0x7ffff772b0e2 <+1330>: movl   $0x4, %r10d

** 35                   for (size_t j = 0; j < rowsCols; j += 4) {

    0x7ffff772b0e8 <+1336>: addl   %r10d, 0x88(%r13,%r12)
    0x7ffff772b0f0 <+1344>: jmp    0x7ffff772ac7c            ; <+204> at matrix_algorithms.cpp:35:22
    0x7ffff772b0f5 <+1349>: movl   $0x4, %esi

** 34           for (size_t i = 0; i < rowsCols; i += 4) {

    0x7ffff772b0fa <+1354>: addl   %esi, 0x8c(%r13,%r12)
    0x7ffff772b102 <+1362>: jmp    0x7ffff772ac58            ; <+168> at matrix_algorithms.cpp:34:21
    0x7ffff772b107 <+1367>: movl   $0x1, %eax

   58
** 59           return result;

    0x7ffff772b10c <+1372>: movb   %al, 0x93(%r13,%r12)

** 60   }
   61
   62   // code lines: 64, 66, 67, 68, 70, 71, 72, 73, 74, 76, 80

    0x7ffff772b114 <+1380>: movzbq 0x93(%r13,%r12), %rax
    0x7ffff772b11d <+1389>: andl   $0x1, %eax
    0x7ffff772b120 <+1392>: testl  %eax, %eax
    0x7ffff772b122 <+1394>: jne    0x7ffff772b137            ; <+1415> at matrix_algorithms.cpp:60:1
    0x7ffff772b128 <+1400>: movq   (%rsp), %rdx
    0x7ffff772b12c <+1404>: movq   %r15, %rsi
    0x7ffff772b12f <+1407>: movq   %r15, %rdi
    0x7ffff772b132 <+1410>: callq  0x7ffff77256b0            ; std::__2::vector<int, std::__2::allocator<int> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772b137 <+1415>: movl   %ebx, 0x110(%r15)
    0x7ffff772b13e <+1422>: movq   0x20(%rsp), %rbx
    0x7ffff772b143 <+1427>: movq   0x28(%rsp), %r12
    0x7ffff772b148 <+1432>: movq   0x30(%rsp), %r13
    0x7ffff772b14d <+1437>: movq   0x38(%rsp), %r14
    0x7ffff772b152 <+1442>: movq   0x40(%rsp), %r15
    0x7ffff772b157 <+1447>: addq   $0x50, %rsp
    0x7ffff772b15b <+1451>: movq   %rbp, %rsp
    0x7ffff772b15e <+1454>: popq   %rbp
    0x7ffff772b15f <+1455>: retq
    0x7ffff772b160 <+1456>: ud2