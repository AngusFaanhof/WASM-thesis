0x5555555589cc <+0>:   endbr64
    0x5555555589d0 <+4>:   pushq  %rbp
    0x5555555589d1 <+5>:   movq   %rsp, %rbp
    0x5555555589d4 <+8>:   subq   $0xf0, %rsp
    0x5555555589db <+15>:  movq   %rdi, -0xe8(%rbp)

-> 73       size_t size = vec.size();

->  0x5555555589e2 <+22>:  movq   -0xe8(%rbp), %rax
    0x5555555589e9 <+29>:  movq   %rax, %rdi
    0x5555555589ec <+32>:  callq  0x555555559466            ; std::vector<float, std::allocator<float> >::size at stl_vector.h:918:7
    0x5555555589f1 <+37>:  movq   %rax, -0xd0(%rbp)

   118  _mm_setzero_ps (void)
   119  {
** 120    return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
   121  }
   122

    0x5555555589f8 <+44>:  vxorps %xmm0, %xmm0, %xmm0

** 74       __m128 sum = _mm_setzero_ps();
   75
   76       // sum of elements

    0x5555555589fc <+48>:  vmovaps %xmm0, -0xc0(%rbp)

** 77       for (size_t i = 0; i < size; i += 4) {

    0x555555558a04 <+56>:  movq   $0x0, -0xd8(%rbp)
    0x555555558a0f <+67>:  jmp    0x555555558a7e            ; <+178> at vector_algorithms.cpp:77:26

** 78           __m128 values = _mm_loadu_ps(&vec[i]);

    0x555555558a11 <+69>:  movq   -0xd8(%rbp), %rdx
    0x555555558a18 <+76>:  movq   -0xe8(%rbp), %rax
    0x555555558a1f <+83>:  movq   %rdx, %rsi
    0x555555558a22 <+86>:  movq   %rax, %rdi
    0x555555558a25 <+89>:  callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555558a2a <+94>:  movq   %rax, -0xc8(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x555555558a31 <+101>: movq   -0xc8(%rbp), %rax
    0x555555558a38 <+108>: vmovups (%rax), %xmm0

** 78           __m128 values = _mm_loadu_ps(&vec[i]);

    0x555555558a3c <+112>: vmovaps %xmm0, -0xa0(%rbp)
    0x555555558a44 <+120>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558a4c <+128>: vmovaps %xmm0, -0x90(%rbp)
    0x555555558a54 <+136>: vmovaps -0xa0(%rbp), %xmm0
    0x555555558a5c <+144>: vmovaps %xmm0, -0x80(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x555555558a61 <+149>: vmovaps -0x90(%rbp), %xmm0
    0x555555558a69 <+157>: vaddps -0x80(%rbp), %xmm0, %xmm0

** 79           sum = _mm_add_ps(sum, values);
   80       }
   81

    0x555555558a6e <+162>: vmovaps %xmm0, -0xc0(%rbp)

** 77       for (size_t i = 0; i < size; i += 4) {

    0x555555558a76 <+170>: addq   $0x4, -0xd8(%rbp)
    0x555555558a7e <+178>: movq   -0xd8(%rbp), %rax
    0x555555558a85 <+185>: cmpq   -0xd0(%rbp), %rax
    0x555555558a8c <+192>: jb     0x555555558a11            ; <+69> at vector_algorithms.cpp:78:44

** 82       __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));
   83

    0x555555558a8e <+194>: movq   -0xd0(%rbp), %rax
    0x555555558a95 <+201>: testq  %rax, %rax
    0x555555558a98 <+204>: js     0x555555558aa1            ; <+213> at vector_algorithms.cpp:82:32
    0x555555558a9a <+206>: vcvtsi2ss %rax, %xmm0, %xmm0
    0x555555558a9f <+211>: jmp    0x555555558ab6            ; <+234> at vector_algorithms.cpp:82:32
    0x555555558aa1 <+213>: movq   %rax, %rdx
    0x555555558aa4 <+216>: shrq   %rdx
    0x555555558aa7 <+219>: andl   $0x1, %eax
    0x555555558aaa <+222>: orq    %rax, %rdx
    0x555555558aad <+225>: vcvtsi2ss %rdx, %xmm0, %xmm0
    0x555555558ab2 <+230>: vaddss %xmm0, %xmm0, %xmm0
    0x555555558ab6 <+234>: vmovss %xmm0, -0xdc(%rbp)

   892  _mm_set1_ps (float __F)
   893  {
** 894    return __extension__ (__m128)(__v4sf){ __F, __F, __F, __F };
   895  }
   896

    0x555555558abe <+242>: vbroadcastss -0xdc(%rbp), %xmm0
    0x555555558ac7 <+251>: vmovaps %xmm0, %xmm1
    0x555555558acb <+255>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558ad3 <+263>: vmovaps %xmm0, -0x20(%rbp)
    0x555555558ad8 <+268>: vmovaps %xmm1, -0x10(%rbp)

   202  _mm_div_ps (__m128 __A, __m128 __B)
   203  {
** 204    return (__m128) ((__v4sf)__A / (__v4sf)__B);
   205  }
   206

    0x555555558add <+273>: vmovaps -0x20(%rbp), %xmm0
    0x555555558ae2 <+278>: vdivps -0x10(%rbp), %xmm0, %xmm0

** 82       __m128 divided = _mm_div_ps(sum, _mm_set1_ps(static_cast<float>(size)));

    0x555555558ae7 <+283>: vmovaps %xmm0, -0xb0(%rbp)
    0x555555558aef <+291>: vmovaps -0xb0(%rbp), %xmm0
    0x555555558af7 <+299>: vmovaps %xmm0, -0x40(%rbp)
    0x555555558afc <+304>: vmovaps -0xb0(%rbp), %xmm0
    0x555555558b04 <+312>: vmovaps %xmm0, -0x30(%rbp)

   57   _mm_hadd_ps (__m128 __X, __m128 __Y)
   58   {
** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);
   60   }
   61

    0x555555558b09 <+317>: vmovaps -0x40(%rbp), %xmm0
    0x555555558b0e <+322>: vhaddps -0x30(%rbp), %xmm0, %xmm0
    0x555555558b13 <+327>: nop

** 84       sum = _mm_hadd_ps(divided, divided);

    0x555555558b14 <+328>: vmovaps %xmm0, -0xc0(%rbp)
    0x555555558b1c <+336>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558b24 <+344>: vmovaps %xmm0, -0x60(%rbp)
    0x555555558b29 <+349>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558b31 <+357>: vmovaps %xmm0, -0x50(%rbp)

** 59     return (__m128) __builtin_ia32_haddps ((__v4sf)__X, (__v4sf)__Y);

    0x555555558b36 <+362>: vmovaps -0x60(%rbp), %xmm0
    0x555555558b3b <+367>: vhaddps -0x50(%rbp), %xmm0, %xmm0
    0x555555558b40 <+372>: nop

** 85       sum = _mm_hadd_ps(sum, sum);
   86
   87       return _mm_cvtss_f32(sum);

    0x555555558b41 <+373>: vmovaps %xmm0, -0xc0(%rbp)
    0x555555558b49 <+381>: vmovaps -0xc0(%rbp), %xmm0
    0x555555558b51 <+389>: vmovaps %xmm0, -0x70(%rbp)

   967  _mm_cvtss_f32 (__m128 __A)
   968  {
** 969    return ((__v4sf)__A)[0];
   970  }
   971

    0x555555558b56 <+394>: vmovaps -0x70(%rbp), %xmm0

** 88   }
   89
   90   float averageVector(std::vector<int>& vec) {

    0x555555558b5b <+399>: leave
    0x555555558b5c <+400>: retq