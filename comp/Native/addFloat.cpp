0x555555559070 <+0>:   endbr64
    0x555555559074 <+4>:   pushq  %rbp
    0x555555559075 <+5>:   movq   %rsp, %rbp
    0x555555559078 <+8>:   pushq  %rbx
    0x555555559079 <+9>:   subq   $0xb8, %rsp
    0x555555559080 <+16>:  movq   %rdi, -0xa8(%rbp)
    0x555555559087 <+23>:  movq   %rsi, -0xb0(%rbp)
    0x55555555908e <+30>:  movq   %rdx, -0xb8(%rbp)

   147  }
   148
** 149  std::vector<float> vectorAddition(std::vector<float>& a, std::vector<float>& b) {

    0x555555559095 <+37>:  movq   %fs:0x28, %rax
    0x55555555909e <+46>:  movq   %rax, -0x18(%rbp)
    0x5555555590a2 <+50>:  xorl   %eax, %eax

-> 150      std::vector<float> result(a.size());
-> 151

->  0x5555555590a4 <+52>:  leaq   -0x9d(%rbp), %rax
    0x5555555590ab <+59>:  movq   %rax, %rdi
    0x5555555590ae <+62>:  callq  0x555555555854            ; std::allocator<float>::allocator at allocator.h:156:7
    0x5555555590b3 <+67>:  movq   -0xb0(%rbp), %rax
    0x5555555590ba <+74>:  movq   %rax, %rdi
    0x5555555590bd <+77>:  callq  0x555555559466            ; std::vector<float, std::allocator<float> >::size at stl_vector.h:918:7
    0x5555555590c2 <+82>:  movq   %rax, %rcx
    0x5555555590c5 <+85>:  leaq   -0x9d(%rbp), %rdx
    0x5555555590cc <+92>:  movq   -0xa8(%rbp), %rax
    0x5555555590d3 <+99>:  movq   %rcx, %rsi
    0x5555555590d6 <+102>: movq   %rax, %rdi
    0x5555555590d9 <+105>: callq  0x555555558134            ; std::vector<float, std::allocator<float> >::vector at stl_vector.h:510:7
    0x5555555590de <+110>: leaq   -0x9d(%rbp), %rax
    0x5555555590e5 <+117>: movq   %rax, %rdi
    0x5555555590e8 <+120>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7

** 152      for (int i = 0; i < a.size(); i += 4) {

    0x5555555590ed <+125>: movl   $0x0, -0x9c(%rbp)
    0x5555555590f7 <+135>: jmp    0x5555555591c7            ; <+343> at vector_algorithms.cpp:152:21

** 153          __m128 vecA = _mm_loadu_ps(&a[i]);

    0x5555555590fc <+140>: movl   -0x9c(%rbp), %eax
    0x555555559102 <+146>: movslq %eax, %rdx
    0x555555559105 <+149>: movq   -0xb0(%rbp), %rax
    0x55555555910c <+156>: movq   %rdx, %rsi
    0x55555555910f <+159>: movq   %rax, %rdi
    0x555555559112 <+162>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555559117 <+167>: movq   %rax, -0x88(%rbp)

   932  _mm_loadu_ps (float const *__P)
   933  {
** 934    return *(__m128_u *)__P;
   935  }
   936

    0x55555555911e <+174>: movq   -0x88(%rbp), %rax
    0x555555559125 <+181>: vmovups (%rax), %xmm0

** 153          __m128 vecA = _mm_loadu_ps(&a[i]);

    0x555555559129 <+185>: vmovaps %xmm0, -0x80(%rbp)

** 154          __m128 vecB = _mm_loadu_ps(&b[i]);
   155

    0x55555555912e <+190>: movl   -0x9c(%rbp), %eax
    0x555555559134 <+196>: movslq %eax, %rdx
    0x555555559137 <+199>: movq   -0xb8(%rbp), %rax
    0x55555555913e <+206>: movq   %rdx, %rsi
    0x555555559141 <+209>: movq   %rax, %rdi
    0x555555559144 <+212>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x555555559149 <+217>: movq   %rax, -0x90(%rbp)

** 934    return *(__m128_u *)__P;

    0x555555559150 <+224>: movq   -0x90(%rbp), %rax
    0x555555559157 <+231>: vmovups (%rax), %xmm0

** 154          __m128 vecB = _mm_loadu_ps(&b[i]);

    0x55555555915b <+235>: vmovaps %xmm0, -0x70(%rbp)
    0x555555559160 <+240>: vmovaps -0x80(%rbp), %xmm0
    0x555555559165 <+245>: vmovaps %xmm0, -0x40(%rbp)
    0x55555555916a <+250>: vmovaps -0x70(%rbp), %xmm0
    0x55555555916f <+255>: vmovaps %xmm0, -0x30(%rbp)

   184  _mm_add_ps (__m128 __A, __m128 __B)
   185  {
** 186    return (__m128) ((__v4sf)__A + (__v4sf)__B);
   187  }
   188

    0x555555559174 <+260>: vmovaps -0x40(%rbp), %xmm0
    0x555555559179 <+265>: vaddps -0x30(%rbp), %xmm0, %xmm0

** 156          __m128 sum = _mm_add_ps(vecA, vecB);

    0x55555555917e <+270>: vmovaps %xmm0, -0x60(%rbp)

** 157          _mm_storeu_ps(&result[i], sum);
   158      }
   159

    0x555555559183 <+275>: movl   -0x9c(%rbp), %eax
    0x555555559189 <+281>: movslq %eax, %rdx
    0x55555555918c <+284>: movq   -0xa8(%rbp), %rax
    0x555555559193 <+291>: movq   %rdx, %rsi
    0x555555559196 <+294>: movq   %rax, %rdi
    0x555555559199 <+297>: callq  0x5555555581d6            ; std::vector<float, std::allocator<float> >::operator[] at stl_vector.h:1043:7
    0x55555555919e <+302>: movq   %rax, -0x98(%rbp)
    0x5555555591a5 <+309>: vmovaps -0x60(%rbp), %xmm0
    0x5555555591aa <+314>: vmovaps %xmm0, -0x50(%rbp)

   981  _mm_storeu_ps (float *__P, __m128 __A)
   982  {
** 983    *(__m128_u *)__P = __A;

    0x5555555591af <+319>: vmovaps -0x50(%rbp), %xmm0
    0x5555555591b4 <+324>: movq   -0x98(%rbp), %rax
    0x5555555591bb <+331>: vmovups %xmm0, (%rax)

** 984  }
   985
   986  /* Store the lower SPFP value across four words.  */

    0x5555555591bf <+335>: nop

** 152      for (int i = 0; i < a.size(); i += 4) {

    0x5555555591c0 <+336>: addl   $0x4, -0x9c(%rbp)
    0x5555555591c7 <+343>: movl   -0x9c(%rbp), %eax
    0x5555555591cd <+349>: movslq %eax, %rbx
    0x5555555591d0 <+352>: movq   -0xb0(%rbp), %rax
    0x5555555591d7 <+359>: movq   %rax, %rdi
    0x5555555591da <+362>: callq  0x555555559466            ; std::vector<float, std::allocator<float> >::size at stl_vector.h:918:7
    0x5555555591df <+367>: cmpq   %rax, %rbx
    0x5555555591e2 <+370>: setb   %al
    0x5555555591e5 <+373>: testb  %al, %al
    0x5555555591e7 <+375>: jne    0x5555555590fc            ; <+140> at vector_algorithms.cpp:153:40

** 160      return result;

    0x5555555591ed <+381>: jmp    0x555555559210            ; <+416> at vector_algorithms.cpp:161:1
    0x5555555591ef <+383>: endbr64
    0x5555555591f3 <+387>: movq   %rax, %rbx
    0x5555555591f6 <+390>: leaq   -0x9d(%rbp), %rax
    0x5555555591fd <+397>: movq   %rax, %rdi
    0x555555559200 <+400>: callq  0x555555555874            ; std::allocator<float>::~allocator at allocator.h:174:7
    0x555555559205 <+405>: movq   %rbx, %rax
    0x555555559208 <+408>: movq   %rax, %rdi
    0x55555555920b <+411>: callq  0x5555555551d0            ; ___lldb_unnamed_symbol234 + 192

** 161  }
   162
   163  std::vector<int> vectorAddition(std::vector<int>& a, std::vector<int>& b) {

    0x555555559210 <+416>: movq   -0x18(%rbp), %rax
    0x555555559214 <+420>: subq   %fs:0x28, %rax
    0x55555555921d <+429>: je     0x555555559224            ; <+436> at vector_algorithms.cpp:161:1
    0x55555555921f <+431>: callq  0x5555555551a0            ; ___lldb_unnamed_symbol234 + 144
    0x555555559224 <+436>: movq   -0xa8(%rbp), %rax
    0x55555555922b <+443>: movq   -0x8(%rbp), %rbx
    0x55555555922f <+447>: leave
    0x555555559230 <+448>: retq