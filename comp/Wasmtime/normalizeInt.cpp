0x7ffff772be40 <+0>:    pushq  %rbp
    0x7ffff772be41 <+1>:    movq   %rsp, %rbp
    0x7ffff772be44 <+4>:    movq   0x8(%rdi), %r10
    0x7ffff772be48 <+8>:    movq   (%r10), %r10
    0x7ffff772be4b <+11>:   addq   $0x10, %r10
    0x7ffff772be4f <+15>:   cmpq   %rsp, %r10
    0x7ffff772be52 <+18>:   ja     0x7ffff772c318            ; <+1240> at vector_algorithms.cpp:70:1
    0x7ffff772be58 <+24>:   subq   $0x40, %rsp
    0x7ffff772be5c <+28>:   movq   %rbx, 0x10(%rsp)
    0x7ffff772be61 <+33>:   movq   %r12, 0x18(%rsp)
    0x7ffff772be66 <+38>:   movq   %r13, 0x20(%rsp)
    0x7ffff772be6b <+43>:   movq   %r14, 0x28(%rsp)
    0x7ffff772be70 <+48>:   movq   %r15, 0x30(%rsp)
    0x7ffff772be75 <+53>:   movl   0x110(%rdi), %r15d
    0x7ffff772be7c <+60>:   movq   %r15, %rbx
    0x7ffff772be7f <+63>:   subl   $0x320, %ebx              ; imm = 0x320
    0x7ffff772be85 <+69>:   movl   %ebx, 0x110(%rdi)
    0x7ffff772be8b <+75>:   movq   0x100(%rdi), %r12
    0x7ffff772be92 <+82>:   leaq   (%r12,%rbx), %r13
    0x7ffff772be96 <+86>:   movl   %edx, 0x9c(%r12,%rbx)
    0x7ffff772be9e <+94>:   movq   %rdx, (%rsp)
    0x7ffff772bea2 <+98>:   movl   %ecx, 0x98(%r12,%rbx)
    0x7ffff772beaa <+106>:  movq   %rcx, %rdx
    0x7ffff772bead <+109>:  movq   %rdi, %r14
    0x7ffff772beb0 <+112>:  movq   %r14, %rsi
    0x7ffff772beb3 <+115>:  movq   %r14, %rdi

-> 41       size_t size = vec.size();

->  0x7ffff772beb6 <+118>:  callq  0x7ffff7727af0            ; std::__2::vector<int, std::__2::allocator<int> >::size[abi:ue170004]() const at vector:604
    0x7ffff772bebb <+123>:  movl   %eax, 0x94(%r12,%rbx)

** 42       __m128i sum_int = _mm_setzero_si128();
   43
   44       // sum of elements

    0x7ffff772bec3 <+131>:  movq   $0x0, 0x2b8(%r12,%rbx)
    0x7ffff772becf <+143>:  movq   $0x0, 0x2b0(%r12,%rbx)
    0x7ffff772bedb <+155>:  movq   0x2b8(%r12,%rbx), %rsi
    0x7ffff772bee3 <+163>:  vmovq  %rsi, %xmm0
    0x7ffff772bee8 <+168>:  vpshufd $0x44, %xmm0, %xmm2       ; xmm2 = xmm0[0,1,0,1]
    0x7ffff772beed <+173>:  vpinsrq $0x1, 0x429(%rip), %xmm2, %xmm1 ; <+1247> at vector_algorithms.cpp:70:1
    0x7ffff772bef7 <+183>:  vmovdqu %xmm1, 0x2a0(%r12,%rbx)
    0x7ffff772bf01 <+193>:  vmovdqu %xmm1, 0x80(%r12,%rbx)

** 45       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bf0b <+203>:  movl   $0x0, 0x7c(%r12,%rbx)
    0x7ffff772bf14 <+212>:  movl   0x7c(%r12,%rbx), %edx
    0x7ffff772bf19 <+217>:  movl   0x94(%r12,%rbx), %r8d
    0x7ffff772bf21 <+225>:  cmpl   %r8d, %edx
    0x7ffff772bf24 <+228>:  jae    0x7ffff772bfbd            ; <+381> at vector_algorithms.cpp:51:34

** 46           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x7ffff772bf2a <+234>:  movl   0x98(%r12,%rbx), %edx
    0x7ffff772bf32 <+242>:  movl   0x7c(%r12,%rbx), %ecx
    0x7ffff772bf37 <+247>:  movq   %r14, %rsi
    0x7ffff772bf3a <+250>:  movq   %r14, %rdi
    0x7ffff772bf3d <+253>:  callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772bf42 <+258>:  movl   %eax, 0x1bc(%r12,%rbx)
    0x7ffff772bf4a <+266>:  movl   %eax, %r10d
    0x7ffff772bf4d <+269>:  vmovdqu (%r12,%r10), %xmm0
    0x7ffff772bf53 <+275>:  vmovdqu %xmm0, 0x60(%r12,%rbx)

** 47           sum_int = _mm_add_epi32(sum_int, values);
   48       }
   49

    0x7ffff772bf5a <+282>:  vmovdqu 0x80(%r12,%rbx), %xmm1
    0x7ffff772bf64 <+292>:  vmovdqu %xmm1, 0x1d0(%r12,%rbx)
    0x7ffff772bf6e <+302>:  vmovdqu %xmm0, 0x1c0(%r12,%rbx)
    0x7ffff772bf78 <+312>:  vmovdqu 0x1d0(%r12,%rbx), %xmm3
    0x7ffff772bf82 <+322>:  vmovdqu %xmm3, 0x2d0(%r12,%rbx)
    0x7ffff772bf8c <+332>:  vmovdqu %xmm0, 0x2c0(%r12,%rbx)
    0x7ffff772bf96 <+342>:  vmovdqu 0x2d0(%r12,%rbx), %xmm5
    0x7ffff772bfa0 <+352>:  vpaddd %xmm0, %xmm5, %xmm5
    0x7ffff772bfa4 <+356>:  vmovdqu %xmm5, 0x80(%r12,%rbx)
    0x7ffff772bfae <+366>:  movl   $0x4, %edx

** 45       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772bfb3 <+371>:  addl   %edx, 0x7c(%r12,%rbx)
    0x7ffff772bfb8 <+376>:  jmp    0x7ffff772bf14            ; <+212> at vector_algorithms.cpp:45:24

   50       // convert to float
** 51       __m128 sum = _mm_cvtepi32_ps(sum_int);
   52

    0x7ffff772bfbd <+381>:  vmovdqu 0x80(%r12,%rbx), %xmm0
    0x7ffff772bfc7 <+391>:  vmovdqu %xmm0, 0x1f0(%r12,%rbx)
    0x7ffff772bfd1 <+401>:  vmovdqu %xmm0, 0x2e0(%r12,%rbx)
    0x7ffff772bfdb <+411>:  vcvtdq2ps %xmm0, %xmm2
    0x7ffff772bfdf <+415>:  vmovdqu %xmm2, 0x50(%r12,%rbx)

** 53       sum = _mm_hadd_ps(sum, sum);

    0x7ffff772bfe6 <+422>:  vmovdqu %xmm2, 0x150(%r12,%rbx)
    0x7ffff772bff0 <+432>:  vmovdqu %xmm2, 0x140(%r12,%rbx)
    0x7ffff772bffa <+442>:  vmovdqu 0x150(%r12,%rbx), %xmm5
    0x7ffff772c004 <+452>:  vshufps $0x88, %xmm2, %xmm5, %xmm5 ; xmm5 = xmm5[0,2],xmm2[0,2]
    0x7ffff772c009 <+457>:  vmovdqu %xmm5, 0x130(%r12,%rbx)
    0x7ffff772c013 <+467>:  vmovdqu 0x150(%r12,%rbx), %xmm6
    0x7ffff772c01d <+477>:  vmovdqu 0x140(%r12,%rbx), %xmm7
    0x7ffff772c027 <+487>:  vshufps $0xdd, %xmm7, %xmm6, %xmm6 ; xmm6 = xmm6[1,3],xmm7[1,3]
    0x7ffff772c02c <+492>:  vmovdqu %xmm6, 0x120(%r12,%rbx)
    0x7ffff772c036 <+502>:  vmovdqu %xmm5, 0x170(%r12,%rbx)
    0x7ffff772c040 <+512>:  vmovdqu %xmm6, 0x160(%r12,%rbx)
    0x7ffff772c04a <+522>:  vmovdqu 0x170(%r12,%rbx), %xmm1
    0x7ffff772c054 <+532>:  vmovdqu %xmm1, 0x220(%r12,%rbx)
    0x7ffff772c05e <+542>:  vmovdqu %xmm6, 0x210(%r12,%rbx)
    0x7ffff772c068 <+552>:  vmovdqu 0x220(%r12,%rbx), %xmm3
    0x7ffff772c072 <+562>:  vaddps %xmm6, %xmm3, %xmm3
    0x7ffff772c076 <+566>:  vmovdqu %xmm3, 0x50(%r12,%rbx)

** 54       sum = _mm_hadd_ps(sum, sum);
   55
   56       // inverse square root

    0x7ffff772c07d <+573>:  vmovdqu %xmm3, 0xf0(%r12,%rbx)
    0x7ffff772c087 <+583>:  vmovdqu %xmm3, 0xe0(%r12,%rbx)
    0x7ffff772c091 <+593>:  vmovdqu 0xf0(%r12,%rbx), %xmm6
    0x7ffff772c09b <+603>:  vshufps $0x88, %xmm3, %xmm6, %xmm6 ; xmm6 = xmm6[0,2],xmm3[0,2]
    0x7ffff772c0a0 <+608>:  vmovdqu %xmm6, 0xd0(%r12,%rbx)
    0x7ffff772c0aa <+618>:  vmovdqu 0xf0(%r12,%rbx), %xmm7
    0x7ffff772c0b4 <+628>:  vmovdqu 0xe0(%r12,%rbx), %xmm0
    0x7ffff772c0be <+638>:  vshufps $0xdd, %xmm0, %xmm7, %xmm7 ; xmm7 = xmm7[1,3],xmm0[1,3]
    0x7ffff772c0c3 <+643>:  vmovdqu %xmm7, 0xc0(%r12,%rbx)
    0x7ffff772c0cd <+653>:  vmovdqu %xmm6, 0x110(%r12,%rbx)
    0x7ffff772c0d7 <+663>:  vmovdqu %xmm7, 0x100(%r12,%rbx)
    0x7ffff772c0e1 <+673>:  vmovdqu 0x110(%r12,%rbx), %xmm2
    0x7ffff772c0eb <+683>:  vmovdqu %xmm2, 0x240(%r12,%rbx)
    0x7ffff772c0f5 <+693>:  vmovdqu %xmm7, 0x230(%r12,%rbx)
    0x7ffff772c0ff <+703>:  vmovdqu 0x240(%r12,%rbx), %xmm4
    0x7ffff772c109 <+713>:  vaddps %xmm7, %xmm4, %xmm4
    0x7ffff772c10d <+717>:  vmovdqu %xmm4, 0x50(%r12,%rbx)

** 57       __m128 invSqrt = _mm_rsqrt_ps(sum);
   58

    0x7ffff772c114 <+724>:  vmovdqu %xmm4, 0x190(%r12,%rbx)
    0x7ffff772c11e <+734>:  vmovdqu %xmm4, 0x290(%r12,%rbx)
    0x7ffff772c128 <+744>:  vsqrtps %xmm4, %xmm7
    0x7ffff772c12c <+748>:  vmovdqu %xmm7, 0x180(%r12,%rbx)
    0x7ffff772c136 <+758>:  movl   $0x3f800000, 0x20c(%r12,%rbx) ; imm = 0x3F800000
    0x7ffff772c142 <+770>:  vmovss 0x20c(%r12,%rbx), %xmm1   ; xmm1 = mem[0],zero,zero,zero
    0x7ffff772c14c <+780>:  vmovss %xmm1, 0x31c(%r12,%rbx)
    0x7ffff772c156 <+790>:  movl   0x31c(%r12,%rbx), %r8d
    0x7ffff772c15e <+798>:  vmovd  %r8d, %xmm1
    0x7ffff772c163 <+803>:  vpbroadcastd %xmm1, %xmm4
    0x7ffff772c168 <+808>:  vmovdqu %xmm4, 0x300(%r12,%rbx)
    0x7ffff772c172 <+818>:  vmovdqu 0x180(%r12,%rbx), %xmm3
    0x7ffff772c17c <+828>:  vmovdqu %xmm4, 0x280(%r12,%rbx)
    0x7ffff772c186 <+838>:  vmovdqu %xmm3, 0x270(%r12,%rbx)
    0x7ffff772c190 <+848>:  vmovdqu 0x280(%r12,%rbx), %xmm5
    0x7ffff772c19a <+858>:  vdivps %xmm3, %xmm5, %xmm5
    0x7ffff772c19e <+862>:  vmovdqu %xmm5, 0x40(%r12,%rbx)
    0x7ffff772c1a5 <+869>:  xorl   %esi, %esi

** 59       std::vector<float> result(size);
   60
   61       // normalize vector

    0x7ffff772c1a7 <+871>:  movb   %sil, 0x3f(%r12,%rbx)
    0x7ffff772c1ac <+876>:  movl   0x94(%r12,%rbx), %ecx
    0x7ffff772c1b4 <+884>:  movq   (%rsp), %rdx
    0x7ffff772c1b8 <+888>:  movq   %r14, %rsi
    0x7ffff772c1bb <+891>:  movq   %r14, %rdi
    0x7ffff772c1be <+894>:  callq  0x7ffff772a870            ; std::__2::vector<float, std::__2::allocator<float> >::vector at vector:1191

** 62       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c1c3 <+899>:  movl   $0x0, 0x38(%r12,%rbx)
    0x7ffff772c1cc <+908>:  movl   0x38(%r12,%rbx), %ecx
    0x7ffff772c1d1 <+913>:  movl   0x94(%r12,%rbx), %edx
    0x7ffff772c1d9 <+921>:  cmpl   %edx, %ecx
    0x7ffff772c1db <+923>:  jae    0x7ffff772c2c5            ; <+1157> at vector_algorithms.cpp:45:5

** 63           __m128i valuesI = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x7ffff772c1e1 <+929>:  movl   0x98(%r12,%rbx), %edx
    0x7ffff772c1e9 <+937>:  movl   0x38(%r12,%rbx), %ecx
    0x7ffff772c1ee <+942>:  movq   %r14, %rsi
    0x7ffff772c1f1 <+945>:  movq   %r14, %rdi
    0x7ffff772c1f4 <+948>:  callq  0x7ffff7729ff0            ; std::__2::vector<int, std::__2::allocator<int> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772c1f9 <+953>:  movl   %eax, 0x1b8(%r12,%rbx)
    0x7ffff772c201 <+961>:  movl   %eax, %r9d
    0x7ffff772c204 <+964>:  vmovdqu (%r12,%r9), %xmm4
    0x7ffff772c20a <+970>:  vmovdqu %xmm4, 0x20(%r12,%rbx)

** 64           __m128 values = _mm_cvtepi32_ps(valuesI);

    0x7ffff772c211 <+977>:  vmovdqu %xmm4, 0x1e0(%r12,%rbx)
    0x7ffff772c21b <+987>:  vmovdqu %xmm4, 0x2f0(%r12,%rbx)
    0x7ffff772c225 <+997>:  vcvtdq2ps %xmm4, %xmm7
    0x7ffff772c229 <+1001>: vmovdqu %xmm7, 0x10(%r12,%rbx)

** 65           __m128 normalized = _mm_mul_ps(values, invSqrt);

    0x7ffff772c230 <+1008>: vmovdqu 0x40(%r12,%rbx), %xmm0
    0x7ffff772c237 <+1015>: vmovdqu %xmm7, 0xb0(%r12,%rbx)
    0x7ffff772c241 <+1025>: vmovdqu %xmm0, 0xa0(%r12,%rbx)
    0x7ffff772c24b <+1035>: vmovdqu 0xb0(%r12,%rbx), %xmm2
    0x7ffff772c255 <+1045>: vmovdqu %xmm2, 0x260(%r12,%rbx)
    0x7ffff772c25f <+1055>: vmovdqu %xmm0, 0x250(%r12,%rbx)
    0x7ffff772c269 <+1065>: vmovdqu 0x260(%r12,%rbx), %xmm4
    0x7ffff772c273 <+1075>: vmulps %xmm0, %xmm4, %xmm4
    0x7ffff772c277 <+1079>: vmovdqu %xmm4, (%r12,%rbx)

** 66           _mm_storeu_ps(&result[i], normalized);
   67       }
   68

    0x7ffff772c27d <+1085>: movl   0x38(%r12,%rbx), %ecx
    0x7ffff772c282 <+1090>: movq   (%rsp), %rdx
    0x7ffff772c286 <+1094>: movq   %r14, %rsi
    0x7ffff772c289 <+1097>: movq   %r14, %rdi
    0x7ffff772c28c <+1100>: callq  0x7ffff772aa20            ; std::__2::vector<float, std::__2::allocator<float> >::operator[][abi:ue170004](unsigned long) at vector:1536
    0x7ffff772c291 <+1105>: vmovdqu (%r12,%rbx), %xmm5
    0x7ffff772c297 <+1111>: movl   %eax, 0x1b4(%r12,%rbx)
    0x7ffff772c29f <+1119>: vmovdqu %xmm5, 0x1a0(%r12,%rbx)
    0x7ffff772c2a9 <+1129>: movl   0x1b4(%r13), %r11d
    0x7ffff772c2b0 <+1136>: vmovdqu %xmm5, (%r12,%r11)
    0x7ffff772c2b6 <+1142>: movl   $0x4, %esi

** 62       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c2bb <+1147>: addl   %esi, 0x38(%r12,%rbx)
    0x7ffff772c2c0 <+1152>: jmp    0x7ffff772c1cc            ; <+908> at vector_algorithms.cpp:62:24

** 45       for (size_t i = 0; i < size; i += 4) {

    0x7ffff772c2c5 <+1157>: movl   $0x1, %eax

** 69       return result;

    0x7ffff772c2ca <+1162>: movb   %al, 0x3f(%r12,%rbx)

** 70   }
   71
   72   float averageVector(std::vector<float>& vec) {

    0x7ffff772c2cf <+1167>: movzbq 0x3f(%r12,%rbx), %rax
    0x7ffff772c2d5 <+1173>: andl   $0x1, %eax
    0x7ffff772c2d8 <+1176>: testl  %eax, %eax
    0x7ffff772c2da <+1178>: jne    0x7ffff772c2ef            ; <+1199> at vector_algorithms.cpp:70:1
    0x7ffff772c2e0 <+1184>: movq   (%rsp), %rdx
    0x7ffff772c2e4 <+1188>: movq   %r14, %rsi
    0x7ffff772c2e7 <+1191>: movq   %r14, %rdi
    0x7ffff772c2ea <+1194>: callq  0x7ffff7725760            ; std::__2::vector<float, std::__2::allocator<float> >::~vector[abi:ue170004]() at vector:500
    0x7ffff772c2ef <+1199>: movl   %r15d, 0x110(%r14)
    0x7ffff772c2f6 <+1206>: movq   0x10(%rsp), %rbx
    0x7ffff772c2fb <+1211>: movq   0x18(%rsp), %r12
    0x7ffff772c300 <+1216>: movq   0x20(%rsp), %r13
    0x7ffff772c305 <+1221>: movq   0x28(%rsp), %r14
    0x7ffff772c30a <+1226>: movq   0x30(%rsp), %r15
    0x7ffff772c30f <+1231>: addq   $0x40, %rsp
    0x7ffff772c313 <+1235>: movq   %rbp, %rsp
    0x7ffff772c316 <+1238>: popq   %rbp
    0x7ffff772c317 <+1239>: retq
    0x7ffff772c318 <+1240>: ud2
    0x7ffff772c31a <+1242>: addb   %al, (%rax)
    0x7ffff772c31c <+1244>: addb   %al, (%rax)
    0x7ffff772c31e <+1246>: addb   %al, (%rax)
    0x7ffff772c320 <+1248>: addb   %al, (%rax)
    0x7ffff772c322 <+1250>: addb   %al, (%rax)
    0x7ffff772c324 <+1252>: addb   %al, (%rax)
    0x7ffff772c326 <+1254>: addb   %al, (%rax)