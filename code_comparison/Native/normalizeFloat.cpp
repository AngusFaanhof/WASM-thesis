0x5555555583f4 <+0>:   endbr64
    0x5555555583f8 <+4>:   pushq  %rbp
    0x5555555583f9 <+5>:   movq   %rsp, %rbp
    0x5555555583fc <+8>:   pushq  %rbx
    0x5555555583fd <+9>:   subq   $0x178, %rsp              ; imm = 0x178
    0x555555558404 <+16>:  movq   %rdi, -0x178(%rbp)
    0x55555555840b <+23>:  movq   %rsi, -0x180(%rbp)

   10   }
   11
** 12   std::vector<float> normalizeVector(std::vector<float>& vec) {

    0x555555558412 <+30>:  movq   %fs:0x28, %rax
    0x55555555841b <+39>:  movq   %rax, -0x18(%rbp)
    0x55555555841f <+43>:  xorl   %eax, %eax

-> 13       size_t size = vec.size();

->  0x555555558421 <+45>:  movq   -0x180(%rbp), %rax
    0x555555558428 <+52>:  movq   %rax, %rdi
    0x55555555842b <+55>:  callq  0x555555559466            ; std::vector<float, std::allocator<float> >::size at stl_vector.h:918:7
    0x555555558430 <+60>:  movq   %rax, -0x150(%rbp)

   118  _mm_setzero_ps (void)
   119  {
** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
   121  }
   122

    0x555555558437 <+67>:  vxorps %xmm0, %xmm0, %xmm0

** 14       __m128 sum = _mm_setzero_ps();
   15
   16       // sum of squares

    0x55555555843b <+71>:  vmovaps %xmm0, -0x130(%rbp)

** 17       for (size_t i = 0; i < size; i += 4) {

    0x555555558443 <+79>:  movq   $0x0, -0x160(%rbp)
    0x55555555844e <+90>:  jmp    0x5555555584ee            ; <+250> at vector_algorithms.cpp:17:26

** 18           __m128 values = _mm_loadu_ps(&vec[i]);

    0x555555558453 <+95>:  movq   -0x160(%rbp), %rdx
    0x55555555845a <+102>: movq   -0x180(%rbp), %rax
    0x555555558461 <+109>: movq   %rdx, %rsi
    0x555555558464 <+112>: movq   %rax, %rdi
    0x555555558467 <+115>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x55555555846c <+120>: movq   %rax, -0x148(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x555555558473 <+127>: movq   -0x148(%rbp), %rax
    0x55555555847a <+134>: vmovups (%rax), %xmm0

** 18           __m128 values = _mm_loadu_ps(&vec[i]);

    0x55555555847e <+138>: vmovaps %xmm0, -0xf0(%rbp)
    0x555555558486 <+146>: vmovaps -0xf0(%rbp), %xmm0
    0x55555555848e <+154>: vmovaps %xmm0, -0xc0(%rbp)
    0x555555558496 <+162>: vmovaps -0xf0(%rbp), %xmm0
    0x55555555849e <+170>: vmovaps %xmm0, -0xb0(%rbp)

   196  _mm_mul_ps (__m128 __A, __m128 __B)
   197  {
** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);
   199  }
   200

    0x5555555584a6 <+178>: vmovaps -0xc0(%rbp), %xmm0
    0x5555555584ae <+186>: vmulps -0xb0(%rbp), %xmm0, %xmm0
    0x5555555584b6 <+194>: vmovaps -0x130(%rbp), %xmm1
    0x5555555584be <+202>: vmovaps %xmm1, -0xe0(%rbp)
    0x5555555584c6 <+210>: vmovaps %xmm0, -0xd0(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x5555555584ce <+218>: vmovaps -0xe0(%rbp), %xmm0
    0x5555555584d6 <+226>: vaddps -0xd0(%rbp), %xmm0, %xmm0

** 19           sum = _mm_add_ps(sum, _mm_mul_ps(values, values));
   20       }
   21

    0x5555555584de <+234>: vmovaps %xmm0, -0x130(%rbp)

** 17       for (size_t i = 0; i < size; i += 4) {

    0x5555555584e6 <+242>: addq   $0x4, -0x160(%rbp)
    0x5555555584ee <+250>: movq   -0x160(%rbp), %rax
    0x5555555584f5 <+257>: cmpq   -0x150(%rbp), %rax
    0x5555555584fc <+264>: jb     0x555555558453            ; <+95> at vector_algorithms.cpp:18:44
    0x555555558502 <+270>: vmovaps -0x130(%rbp), %xmm0
    0x55555555850a <+278>: vmovaps %xmm0, -0x70(%rbp)
    0x55555555850f <+283>: vmovaps -0x130(%rbp), %xmm0
    0x555555558517 <+291>: vmovaps %xmm0, -0x60(%rbp)

   57   _mm_hadd_ps (__m128 __X, __m128 __Y)
   58   {
** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);
   60   }
   61

    0x55555555851c <+296>: vmovaps -0x70(%rbp), %xmm0
    0x555555558521 <+301>: vhaddps -0x60(%rbp), %xmm0, %xmm0
    0x555555558526 <+306>: nop

** 22       sum = _mm_hadd_ps(sum, sum);

    0x555555558527 <+307>: vmovaps %xmm0, -0x130(%rbp)
    0x55555555852f <+315>: vmovaps -0x130(%rbp), %xmm0
    0x555555558537 <+323>: vmovaps %xmm0, -0x90(%rbp)
    0x55555555853f <+331>: vmovaps -0x130(%rbp), %xmm0
    0x555555558547 <+339>: vmovaps %xmm0, -0x80(%rbp)

** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);

    0x55555555854c <+344>: vmovaps -0x90(%rbp), %xmm0
    0x555555558554 <+352>: vhaddps -0x80(%rbp), %xmm0, %xmm0
    0x555555558559 <+357>: nop

** 23       sum = _mm_hadd_ps(sum, sum);
   24
   25       // inverse square root

    0x55555555855a <+358>: vmovaps %xmm0, -0x130(%rbp)
    0x555555558562 <+366>: vmovaps -0x130(%rbp), %xmm0
    0x55555555856a <+374>: vmovaps %xmm0, -0xa0(%rbp)

   220  _mm_rsqrt_ps (__m128 __A)
   221  {
** 222    return (__m128) __builtin_ia32_rsqrtps ((__v4sf)__A);
   223  }
   224

    0x555555558572 <+382>: vrsqrtps -0xa0(%rbp), %xmm0
    0x55555555857a <+390>: nop

** 26       __m128 invSqrt = _mm_rsqrt_ps(sum);
   27

    0x55555555857b <+391>: vmovaps %xmm0, -0x120(%rbp)

** 28       std::vector<float> result(size);
   29
   30       // normalize vector

    0x555555558583 <+399>: leaq   -0x161(%rbp), %rax
    0x55555555858a <+406>: movq   %rax, %rdi
    0x55555555858d <+409>: callq  0x555555555854            ; std::allocator<float>::allocator at allocator.h:156:7
    0x555555558592 <+414>: leaq   -0x161(%rbp), %rdx
    0x555555558599 <+421>: movq   -0x150(%rbp), %rcx
    0x5555555585a0 <+428>: movq   -0x178(%rbp), %rax
    0x5555555585a7 <+435>: movq   %rcx, %rsi
    0x5555555585aa <+438>: movq   %rax, %rdi
    0x5555555585ad <+441>: callq  0x555555558134            ; std::vector<float, std::allocator<float> >::vector at stl_vector.h:510:7
    0x5555555585b2 <+446>: leaq   -0x161(%rbp), %rax
    0x5555555585b9 <+453>: movq   %rax, %rdi
    0x5555555585bc <+456>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7

** 31       for (size_t i = 0; i < size; i += 4) {

    0x5555555585c1 <+461>: movq   $0x0, -0x158(%rbp)
    0x5555555585cc <+472>: jmp    0x555555558676            ; <+642> at vector_algorithms.cpp:31:26

** 32           __m128 values = _mm_loadu_ps(&vec[i]);

    0x5555555585d1 <+477>: movq   -0x158(%rbp), %rdx
    0x5555555585d8 <+484>: movq   -0x180(%rbp), %rax
    0x5555555585df <+491>: movq   %rdx, %rsi
    0x5555555585e2 <+494>: movq   %rax, %rdi
    0x5555555585e5 <+497>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x5555555585ea <+502>: movq   %rax, -0x138(%rbp)

** 934    return *(__m128_u *)__P;

    0x5555555585f1 <+509>: movq   -0x138(%rbp), %rax
    0x5555555585f8 <+516>: vmovups (%rax), %xmm0

** 32           __m128 values = _mm_loadu_ps(&vec[i]);

    0x5555555585fc <+520>: vmovaps %xmm0, -0x110(%rbp)
    0x555555558604 <+528>: vmovaps -0x110(%rbp), %xmm0
    0x55555555860c <+536>: vmovaps %xmm0, -0x40(%rbp)
    0x555555558611 <+541>: vmovaps -0x120(%rbp), %xmm0
    0x555555558619 <+549>: vmovaps %xmm0, -0x30(%rbp)

** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);

    0x55555555861e <+554>: vmovaps -0x40(%rbp), %xmm0
    0x555555558623 <+559>: vmulps -0x30(%rbp), %xmm0, %xmm0

** 33           __m128 normalized = _mm_mul_ps(values, invSqrt);

    0x555555558628 <+564>: vmovaps %xmm0, -0x100(%rbp)

** 34           _mm_storeu_ps(&result[i], normalized);
   35       }
   36

    0x555555558630 <+572>: movq   -0x158(%rbp), %rdx
    0x555555558637 <+579>: movq   -0x178(%rbp), %rax
    0x55555555863e <+586>: movq   %rdx, %rsi
    0x555555558641 <+589>: movq   %rax, %rdi
    0x555555558644 <+592>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555558649 <+597>: movq   %rax, -0x140(%rbp)
    0x555555558650 <+604>: vmovaps -0x100(%rbp), %xmm0
    0x555555558658 <+612>: vmovaps %xmm0, -0x50(%rbp)

   981  _mm_storeu_ps (float *__P, __m128 __A)
   982  {
** 983    *(__m128_u *)__P = __A;

    0x55555555865d <+617>: vmovaps -0x50(%rbp), %xmm0
    0x555555558662 <+622>: movq   -0x140(%rbp), %rax
    0x555555558669 <+629>: vmovups %xmm0, (%rax)

** 984  }
   985
   986  /* Store the lower SPFP value across four words.  */

    0x55555555866d <+633>: nop

** 31       for (size_t i = 0; i < size; i += 4) {

    0x55555555866e <+634>: addq   $0x4, -0x158(%rbp)
    0x555555558676 <+642>: movq   -0x158(%rbp), %rax
    0x55555555867d <+649>: cmpq   -0x150(%rbp), %rax
    0x555555558684 <+656>: jb     0x5555555585d1            ; <+477> at vector_algorithms.cpp:32:44

** 37       return result;

    0x55555555868a <+662>: jmp    0x5555555586ad            ; <+697> at vector_algorithms.cpp:38:1
    0x55555555868c <+664>: endbr64
    0x555555558690 <+668>: movq   %rax, %rbx
    0x555555558693 <+671>: leaq   -0x161(%rbp), %rax
    0x55555555869a <+678>: movq   %rax, %rdi
    0x55555555869d <+681>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7
    0x5555555586a2 <+686>: movq   %rbx, %rax
    0x5555555586a5 <+689>: movq   %rax, %rdi
    0x5555555586a8 <+692>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 38   }
   39
   40   std::vector<float> normalizeVector(std::vector<int>& vec) {

    0x5555555586ad <+697>: movq   -0x18(%rbp), %rax
    0x5555555586b1 <+701>: subq   %fs:0x28, %rax
    0x5555555586ba <+710>: je     0x5555555586c1            ; <+717> at vector_algorithms.cpp:38:1
    0x5555555586bc <+712>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x5555555586c1 <+717>: movq   -0x178(%rbp), %rax
    0x5555555586c8 <+724>: movq   -0x8(%rbp), %rbx
    0x5555555586cc <+728>: leave
    0x5555555586cd <+729>: retq