0x5555555586ce <+0>:   endbr64
    0x5555555586d2 <+4>:   pushq  %rbp
    0x5555555586d3 <+5>:   movq   %rsp, %rbp
    0x5555555586d6 <+8>:   pushq  %rbx
    0x5555555586d7 <+9>:   subq   $0x198, %rsp              ; imm = 0x198
    0x5555555586de <+16>:  movq   %rdi, -0x198(%rbp)
    0x5555555586e5 <+23>:  movq   %rsi, -0x1a0(%rbp)

   38   }
   39
** 40   std::vector<float> normalizeVector(std::vector<int>& vec) {

    0x5555555586ec <+30>:  movq   %fs:0x28, %rax
    0x5555555586f5 <+39>:  movq   %rax, -0x18(%rbp)
    0x5555555586f9 <+43>:  xorl   %eax, %eax

-> 41       size_t size = vec.size();

->  0x5555555586fb <+45>:  movq   -0x1a0(%rbp), %rax
    0x555555558702 <+52>:  movq   %rax, %rdi
    0x555555558705 <+55>:  callq  0x5555555594ca            ; std::vector<int, std::allocator<int> >::size at stl_vector.h:918:7
    0x55555555870a <+60>:  movq   %rax, -0x170(%rbp)

   794  _mm_setzero_si128 (void)
   795  {
** 796    return __extension__ (__m128i)(__v4si){ 0, 0, 0, 0 };
   797  }
   798

    0x555555558711 <+67>:  vpxor  %xmm0, %xmm0, %xmm0

** 42       __m128i sum_int = _mm_setzero_si128();
   43
   44       // sum of elements

    0x555555558715 <+71>:  vmovdqa %xmm0, -0x150(%rbp)

** 45       for (size_t i = 0; i < size; i += 4) {

    0x55555555871d <+79>:  movq   $0x0, -0x180(%rbp)
    0x555555558728 <+90>:  jmp    0x5555555587a2            ; <+212> at vector_algorithms.cpp:45:26

** 46           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x55555555872a <+92>:  movq   -0x180(%rbp), %rdx
    0x555555558731 <+99>:  movq   -0x1a0(%rbp), %rax
    0x555555558738 <+106>: movq   %rdx, %rsi
    0x55555555873b <+109>: movq   %rax, %rdi
    0x55555555873e <+112>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x555555558743 <+117>: movq   %rax, -0x168(%rbp)

   701  _mm_loadu_si128 (__m128i_u const *__P)
   702  {
** 703    return *__P;
   704  }
   705

    0x55555555874a <+124>: movq   -0x168(%rbp), %rax
    0x555555558751 <+131>: vmovdqu (%rax), %xmm0

** 46           __m128i values = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x555555558755 <+135>: vmovdqa %xmm0, -0xf0(%rbp)
    0x55555555875d <+143>: vmovdqa -0x150(%rbp), %xmm0
    0x555555558765 <+151>: vmovdqa %xmm0, -0xe0(%rbp)
    0x55555555876d <+159>: vmovdqa -0xf0(%rbp), %xmm0
    0x555555558775 <+167>: vmovdqa %xmm0, -0xd0(%rbp)

   1064 _mm_add_epi32 (__m128i __A, __m128i __B)
   1065 {
** 1066   return (__m128i) ((__v4su)__A + (__v4su)__B);
   1067 }
   1068

    0x55555555877d <+175>: vmovdqa -0xe0(%rbp), %xmm1
    0x555555558785 <+183>: vmovdqa -0xd0(%rbp), %xmm0
    0x55555555878d <+191>: vpaddd %xmm0, %xmm1, %xmm0
    0x555555558791 <+195>: nop

** 47           sum_int = _mm_add_epi32(sum_int, values);
   48       }
   49

    0x555555558792 <+196>: vmovdqa %xmm0, -0x150(%rbp)

** 45       for (size_t i = 0; i < size; i += 4) {

    0x55555555879a <+204>: addq   $0x4, -0x180(%rbp)
    0x5555555587a2 <+212>: movq   -0x180(%rbp), %rax
    0x5555555587a9 <+219>: cmpq   -0x170(%rbp), %rax
    0x5555555587b0 <+226>: jb     0x55555555872a            ; <+92> at vector_algorithms.cpp:46:81
    0x5555555587b6 <+232>: vmovdqa -0x150(%rbp), %xmm0
    0x5555555587be <+240>: vmovdqa %xmm0, -0x70(%rbp)

   806  _mm_cvtepi32_ps (__m128i __A)
   807  {
** 808    return (__m128)__builtin_ia32_cvtdq2ps ((__v4si) __A);
   809  }
   810

    0x5555555587c3 <+245>: vmovdqa -0x70(%rbp), %xmm0
    0x5555555587c8 <+250>: vcvtdq2ps %xmm0, %xmm0
    0x5555555587cc <+254>: nop

   50       // convert to float
** 51       __m128 sum = _mm_cvtepi32_ps(sum_int);
   52

    0x5555555587cd <+255>: vmovaps %xmm0, -0x140(%rbp)
    0x5555555587d5 <+263>: vmovaps -0x140(%rbp), %xmm0
    0x5555555587dd <+271>: vmovaps %xmm0, -0x90(%rbp)
    0x5555555587e5 <+279>: vmovaps -0x140(%rbp), %xmm0
    0x5555555587ed <+287>: vmovaps %xmm0, -0x80(%rbp)

   57   _mm_hadd_ps (__m128 __X, __m128 __Y)
   58   {
** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);
   60   }
   61

    0x5555555587f2 <+292>: vmovaps -0x90(%rbp), %xmm0
    0x5555555587fa <+300>: vhaddps -0x80(%rbp), %xmm0, %xmm0
    0x5555555587ff <+305>: nop

** 53       sum = _mm_hadd_ps(sum, sum);

    0x555555558800 <+306>: vmovaps %xmm0, -0x140(%rbp)
    0x555555558808 <+314>: vmovaps -0x140(%rbp), %xmm0
    0x555555558810 <+322>: vmovaps %xmm0, -0xb0(%rbp)
    0x555555558818 <+330>: vmovaps -0x140(%rbp), %xmm0
    0x555555558820 <+338>: vmovaps %xmm0, -0xa0(%rbp)

** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);

    0x555555558828 <+346>: vmovaps -0xb0(%rbp), %xmm0
    0x555555558830 <+354>: vhaddps -0xa0(%rbp), %xmm0, %xmm0
    0x555555558838 <+362>: nop

** 54       sum = _mm_hadd_ps(sum, sum);
   55
   56       // inverse square root

    0x555555558839 <+363>: vmovaps %xmm0, -0x140(%rbp)
    0x555555558841 <+371>: vmovaps -0x140(%rbp), %xmm0
    0x555555558849 <+379>: vmovaps %xmm0, -0xc0(%rbp)

   220  _mm_rsqrt_ps (__m128 __A)
   221  {
** 222    return (__m128) __builtin_ia32_rsqrtps ((__v4sf)__A);
   223  }
   224

    0x555555558851 <+387>: vrsqrtps -0xc0(%rbp), %xmm0
    0x555555558859 <+395>: nop

** 57       __m128 invSqrt = _mm_rsqrt_ps(sum);
   58

    0x55555555885a <+396>: vmovaps %xmm0, -0x130(%rbp)

** 59       std::vector<float> result(size);
   60
   61       // normalize vector

    0x555555558862 <+404>: leaq   -0x181(%rbp), %rax
    0x555555558869 <+411>: movq   %rax, %rdi
    0x55555555886c <+414>: callq  0x555555555854            ; std::allocator<float>::allocator at allocator.h:156:7
    0x555555558871 <+419>: leaq   -0x181(%rbp), %rdx
    0x555555558878 <+426>: movq   -0x170(%rbp), %rcx
    0x55555555887f <+433>: movq   -0x198(%rbp), %rax
    0x555555558886 <+440>: movq   %rcx, %rsi
    0x555555558889 <+443>: movq   %rax, %rdi
    0x55555555888c <+446>: callq  0x555555558134            ; std::vector<float, std::allocator<float> >::vector at stl_vector.h:510:7
    0x555555558891 <+451>: leaq   -0x181(%rbp), %rax
    0x555555558898 <+458>: movq   %rax, %rdi
    0x55555555889b <+461>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7

** 62       for (size_t i = 0; i < size; i += 4) {

    0x5555555588a0 <+466>: movq   $0x0, -0x178(%rbp)
    0x5555555588ab <+477>: jmp    0x555555558974            ; <+678> at vector_algorithms.cpp:62:26

** 63           __m128i valuesI = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x5555555588b0 <+482>: movq   -0x178(%rbp), %rdx
    0x5555555588b7 <+489>: movq   -0x1a0(%rbp), %rax
    0x5555555588be <+496>: movq   %rdx, %rsi
    0x5555555588c1 <+499>: movq   %rax, %rdi
    0x5555555588c4 <+502>: callq  0x555555557026            ; std::vector<int, std::allocator<int> >::operator[] at stl_vector.h:1043:7
    0x5555555588c9 <+507>: movq   %rax, -0x160(%rbp)

** 703    return *__P;

    0x5555555588d0 <+514>: movq   -0x160(%rbp), %rax
    0x5555555588d7 <+521>: vmovdqu (%rax), %xmm0

** 63           __m128i valuesI = _mm_loadu_si128(reinterpret_cast<const __m128i*>(&vec[i]));

    0x5555555588db <+525>: vmovdqa %xmm0, -0x120(%rbp)
    0x5555555588e3 <+533>: vmovdqa -0x120(%rbp), %xmm0
    0x5555555588eb <+541>: vmovdqa %xmm0, -0x60(%rbp)

** 808    return (__m128)__builtin_ia32_cvtdq2ps ((__v4si) __A);

    0x5555555588f0 <+546>: vmovdqa -0x60(%rbp), %xmm0
    0x5555555588f5 <+551>: vcvtdq2ps %xmm0, %xmm0
    0x5555555588f9 <+555>: nop

** 64           __m128 values = _mm_cvtepi32_ps(valuesI);

    0x5555555588fa <+556>: vmovaps %xmm0, -0x110(%rbp)
    0x555555558902 <+564>: vmovaps -0x110(%rbp), %xmm0
    0x55555555890a <+572>: vmovaps %xmm0, -0x40(%rbp)
    0x55555555890f <+577>: vmovaps -0x130(%rbp), %xmm0
    0x555555558917 <+585>: vmovaps %xmm0, -0x30(%rbp)

   196  _mm_mul_ps (__m128 __A, __m128 __B)
   197  {
** 198    return (__m128) ((__v4sf)__A * (__v4sf)__B);
   199  }
   200

    0x55555555891c <+590>: vmovaps -0x40(%rbp), %xmm0
    0x555555558921 <+595>: vmulps -0x30(%rbp), %xmm0, %xmm0

** 65           __m128 normalized = _mm_mul_ps(values, invSqrt);

    0x555555558926 <+600>: vmovaps %xmm0, -0x100(%rbp)

** 66           _mm_storeu_ps(&result[i], normalized);
   67       }
   68

    0x55555555892e <+608>: movq   -0x178(%rbp), %rdx
    0x555555558935 <+615>: movq   -0x198(%rbp), %rax
    0x55555555893c <+622>: movq   %rdx, %rsi
    0x55555555893f <+625>: movq   %rax, %rdi
    0x555555558942 <+628>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555558947 <+633>: movq   %rax, -0x158(%rbp)
    0x55555555894e <+640>: vmovaps -0x100(%rbp), %xmm0
    0x555555558956 <+648>: vmovaps %xmm0, -0x50(%rbp)

   981  _mm_storeu_ps (float *__P, __m128 __A)
   982  {
** 983    *(__m128_u *)__P = __A;

    0x55555555895b <+653>: vmovaps -0x50(%rbp), %xmm0
    0x555555558960 <+658>: movq   -0x158(%rbp), %rax
    0x555555558967 <+665>: vmovups %xmm0, (%rax)

** 984  }
   985
   986  /* Store the lower SPFP value across four words.  */

    0x55555555896b <+669>: nop

** 62       for (size_t i = 0; i < size; i += 4) {

    0x55555555896c <+670>: addq   $0x4, -0x178(%rbp)
    0x555555558974 <+678>: movq   -0x178(%rbp), %rax
    0x55555555897b <+685>: cmpq   -0x170(%rbp), %rax
    0x555555558982 <+692>: jb     0x5555555588b0            ; <+482> at vector_algorithms.cpp:63:82

** 69       return result;

    0x555555558988 <+698>: jmp    0x5555555589ab            ; <+733> at vector_algorithms.cpp:70:1
    0x55555555898a <+700>: endbr64
    0x55555555898e <+704>: movq   %rax, %rbx
    0x555555558991 <+707>: leaq   -0x181(%rbp), %rax
    0x555555558998 <+714>: movq   %rax, %rdi
    0x55555555899b <+717>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7
    0x5555555589a0 <+722>: movq   %rbx, %rax
    0x5555555589a3 <+725>: movq   %rax, %rdi
    0x5555555589a6 <+728>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 70   }
   71
   72   float averageVector(std::vector<float>& vec) {

    0x5555555589ab <+733>: movq   -0x18(%rbp), %rax
    0x5555555589af <+737>: subq   %fs:0x28, %rax
    0x5555555589b8 <+746>: je     0x5555555589bf            ; <+753> at vector_algorithms.cpp:70:1
    0x5555555589ba <+748>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x5555555589bf <+753>: movq   -0x198(%rbp), %rax
    0x5555555589c6 <+760>: movq   -0x8(%rbp), %rbx
    0x5555555589ca <+764>: leave
    0x5555555589cb <+765>: retq