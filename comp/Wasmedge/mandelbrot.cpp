Mandelbrot - WasmEdge

00000000001f4b40 <mandelbrot>:
  1f4b40:	55                   	push   %rbp
  1f4b41:	41 57                	push   %r15
  1f4b43:	41 56                	push   %r14
  1f4b45:	41 55                	push   %r13
  1f4b47:	41 54                	push   %r12
  1f4b49:	53                   	push   %rbx
  1f4b4a:	48 83 ec 18          	sub    $0x18,%rsp
  1f4b4e:	49 89 fd             	mov    %rdi,%r13
  1f4b51:	48 8b 07             	mov    (%rdi),%rax
  1f4b54:	48 8b 7f 08          	mov    0x8(%rdi),%rdi
  1f4b58:	41 89 f4             	mov    %esi,%r12d
  1f4b5b:	48 8b 37             	mov    (%rdi),%rsi
  1f4b5e:	48 89 7c 24 10       	mov    %rdi,0x10(%rsp)
  1f4b63:	8b 3e                	mov    (%rsi),%edi
  1f4b65:	8d af 70 f8 ff ff    	lea    -0x790(%rdi),%ebp
  1f4b6b:	48 89 7c 24 08       	mov    %rdi,0x8(%rsp)
  1f4b70:	4c 89 ef             	mov    %r13,%rdi
  1f4b73:	89 2e                	mov    %ebp,(%rsi)
  1f4b75:	44 89 e6             	mov    %r12d,%esi
  1f4b78:	48 8b 18             	mov    (%rax),%rbx
  1f4b7b:	44 89 a4 1d 7c 01 00 	mov    %r12d,0x17c(%rbp,%rbx,1)
  1f4b82:	00
  1f4b83:	89 94 1d 78 01 00 00 	mov    %edx,0x178(%rbp,%rbx,1)
  1f4b8a:	89 8c 1d 74 01 00 00 	mov    %ecx,0x174(%rbp,%rbx,1)
  1f4b91:	44 89 84 1d 70 01 00 	mov    %r8d,0x170(%rbp,%rbx,1)
  1f4b98:	00
  1f4b99:	c6 84 1d 6f 01 00 00 	movb   $0x0,0x16f(%rbp,%rbx,1)
  1f4ba0:	00
  1f4ba1:	8b 94 1d 78 01 00 00 	mov    0x178(%rbp,%rbx,1),%edx
  1f4ba8:	0f af 94 1d 74 01 00 	imul   0x174(%rbp,%rbx,1),%edx
  1f4baf:	00
  1f4bb0:	e8 6b 0f 00 00       	call   1f5b20 <f7>
  1f4bb5:	c5 fa 2a 84 1d 78 01 	vcvtsi2ssl 0x178(%rbp,%rbx,1),%xmm0,%xmm0
  1f4bbc:	00 00
  1f4bbe:	c5 fa 10 0d 1a e0 e0 	vmovss -0x1f1fe6(%rip),%xmm1        # 2be0 <version-0x10>
  1f4bc5:	ff
  1f4bc6:	c5 f2 5e c0          	vdivss %xmm0,%xmm1,%xmm0
  1f4bca:	c5 fa 11 84 1d 68 01 	vmovss %xmm0,0x168(%rbp,%rbx,1)
  1f4bd1:	00 00
  1f4bd3:	c5 fa 10 84 1d 68 01 	vmovss 0x168(%rbp,%rbx,1),%xmm0
  1f4bda:	00 00
  1f4bdc:	c5 fa 11 84 1d 94 01 	vmovss %xmm0,0x194(%rbp,%rbx,1)
  1f4be3:	00 00
  1f4be5:	c5 fa 10 84 1d 94 01 	vmovss 0x194(%rbp,%rbx,1),%xmm0
  1f4bec:	00 00
  1f4bee:	c5 fa 11 84 1d ec 03 	vmovss %xmm0,0x3ec(%rbp,%rbx,1)
  1f4bf5:	00 00
  1f4bf7:	c4 e2 79 18 84 1d ec 	vbroadcastss 0x3ec(%rbp,%rbx,1),%xmm0
  1f4bfe:	03 00 00
  1f4c01:	c5 f8 11 84 1d d0 03 	vmovups %xmm0,0x3d0(%rbp,%rbx,1)
  1f4c08:	00 00
  1f4c0a:	48 8b 84 1d d0 03 00 	mov    0x3d0(%rbp,%rbx,1),%rax
  1f4c11:	00
  1f4c12:	48 8b 8c 1d d8 03 00 	mov    0x3d8(%rbp,%rbx,1),%rcx
  1f4c19:	00
  1f4c1a:	48 89 8c 1d 58 01 00 	mov    %rcx,0x158(%rbp,%rbx,1)
  1f4c21:	00
  1f4c22:	48 89 84 1d 50 01 00 	mov    %rax,0x150(%rbp,%rbx,1)
  1f4c29:	00
  1f4c2a:	c5 ea 2a 84 1d 74 01 	vcvtsi2ssl 0x174(%rbp,%rbx,1),%xmm2,%xmm0
  1f4c31:	00 00
  1f4c33:	c5 f2 5e c0          	vdivss %xmm0,%xmm1,%xmm0
  1f4c37:	c5 fa 11 84 1d 4c 01 	vmovss %xmm0,0x14c(%rbp,%rbx,1)
  1f4c3e:	00 00
  1f4c40:	c7 84 1d 90 01 00 00 	movl   $0xc0000000,0x190(%rbp,%rbx,1)
  1f4c47:	00 00 00 c0
  1f4c4b:	c5 fa 10 84 1d 90 01 	vmovss 0x190(%rbp,%rbx,1),%xmm0
  1f4c52:	00 00
  1f4c54:	c5 fa 11 84 1d 0c 04 	vmovss %xmm0,0x40c(%rbp,%rbx,1)
  1f4c5b:	00 00
  1f4c5d:	c4 e2 79 18 84 1d 0c 	vbroadcastss 0x40c(%rbp,%rbx,1),%xmm0
  1f4c64:	04 00 00
  1f4c67:	c5 f8 11 84 1d f0 03 	vmovups %xmm0,0x3f0(%rbp,%rbx,1)
  1f4c6e:	00 00
  1f4c70:	48 8b 84 1d f0 03 00 	mov    0x3f0(%rbp,%rbx,1),%rax
  1f4c77:	00
  1f4c78:	48 8b 8c 1d f8 03 00 	mov    0x3f8(%rbp,%rbx,1),%rcx
  1f4c7f:	00
  1f4c80:	48 89 8c 1d 38 01 00 	mov    %rcx,0x138(%rbp,%rbx,1)
  1f4c87:	00
  1f4c88:	48 89 84 1d 30 01 00 	mov    %rax,0x130(%rbp,%rbx,1)
  1f4c8f:	00
  1f4c90:	c7 84 1d 8c 01 00 00 	movl   $0xbfc00000,0x18c(%rbp,%rbx,1)
  1f4c97:	00 00 c0 bf
  1f4c9b:	c5 fa 10 84 1d 8c 01 	vmovss 0x18c(%rbp,%rbx,1),%xmm0
  1f4ca2:	00 00
  1f4ca4:	c5 fa 11 84 1d 2c 04 	vmovss %xmm0,0x42c(%rbp,%rbx,1)
  1f4cab:	00 00
  1f4cad:	c4 e2 79 18 84 1d 2c 	vbroadcastss 0x42c(%rbp,%rbx,1),%xmm0
  1f4cb4:	04 00 00
  1f4cb7:	c5 f8 11 84 1d 10 04 	vmovups %xmm0,0x410(%rbp,%rbx,1)
  1f4cbe:	00 00
  1f4cc0:	48 8b 84 1d 10 04 00 	mov    0x410(%rbp,%rbx,1),%rax
  1f4cc7:	00
  1f4cc8:	48 8b 8c 1d 18 04 00 	mov    0x418(%rbp,%rbx,1),%rcx
  1f4ccf:	00
  1f4cd0:	48 89 8c 1d 28 01 00 	mov    %rcx,0x128(%rbp,%rbx,1)
  1f4cd7:	00
  1f4cd8:	48 89 84 1d 20 01 00 	mov    %rax,0x120(%rbp,%rbx,1)
  1f4cdf:	00
  1f4ce0:	c7 84 1d 88 01 00 00 	movl   $0x40800000,0x188(%rbp,%rbx,1)
  1f4ce7:	00 00 80 40
  1f4ceb:	c5 fa 10 84 1d 88 01 	vmovss 0x188(%rbp,%rbx,1),%xmm0
  1f4cf2:	00 00
  1f4cf4:	c5 fa 11 84 1d 4c 04 	vmovss %xmm0,0x44c(%rbp,%rbx,1)
  1f4cfb:	00 00
  1f4cfd:	c4 e2 79 18 84 1d 4c 	vbroadcastss 0x44c(%rbp,%rbx,1),%xmm0
  1f4d04:	04 00 00
  1f4d07:	c5 f8 11 84 1d 30 04 	vmovups %xmm0,0x430(%rbp,%rbx,1)
  1f4d0e:	00 00
  1f4d10:	48 8b 84 1d 30 04 00 	mov    0x430(%rbp,%rbx,1),%rax
  1f4d17:	00
  1f4d18:	48 8b 8c 1d 38 04 00 	mov    0x438(%rbp,%rbx,1),%rcx
  1f4d1f:	00
  1f4d20:	48 89 8c 1d 18 01 00 	mov    %rcx,0x118(%rbp,%rbx,1)
  1f4d27:	00
  1f4d28:	48 89 84 1d 10 01 00 	mov    %rax,0x110(%rbp,%rbx,1)
  1f4d2f:	00
  1f4d30:	c7 84 1d 9c 01 00 00 	movl   $0x1,0x19c(%rbp,%rbx,1)
  1f4d37:	01 00 00 00
  1f4d3b:	8b 84 1d 9c 01 00 00 	mov    0x19c(%rbp,%rbx,1),%eax
  1f4d42:	89 84 1d ac 04 00 00 	mov    %eax,0x4ac(%rbp,%rbx,1)
  1f4d49:	c4 e2 79 18 84 1d ac 	vbroadcastss 0x4ac(%rbp,%rbx,1),%xmm0
  1f4d50:	04 00 00
  1f4d53:	c5 f8 11 84 1d 90 04 	vmovups %xmm0,0x490(%rbp,%rbx,1)
  1f4d5a:	00 00
  1f4d5c:	48 8b 84 1d 90 04 00 	mov    0x490(%rbp,%rbx,1),%rax
  1f4d63:	00
  1f4d64:	48 8b 8c 1d 98 04 00 	mov    0x498(%rbp,%rbx,1),%rcx
  1f4d6b:	00
  1f4d6c:	48 89 8c 1d 08 01 00 	mov    %rcx,0x108(%rbp,%rbx,1)
  1f4d73:	00
  1f4d74:	48 89 84 1d 00 01 00 	mov    %rax,0x100(%rbp,%rbx,1)
  1f4d7b:	00
  1f4d7c:	c7 84 1d 98 01 00 00 	movl   $0xffffffff,0x198(%rbp,%rbx,1)
  1f4d83:	ff ff ff ff
  1f4d87:	8b 84 1d 98 01 00 00 	mov    0x198(%rbp,%rbx,1),%eax
  1f4d8e:	89 84 1d cc 04 00 00 	mov    %eax,0x4cc(%rbp,%rbx,1)
  1f4d95:	c4 e2 79 18 84 1d cc 	vbroadcastss 0x4cc(%rbp,%rbx,1),%xmm0
  1f4d9c:	04 00 00
  1f4d9f:	c5 f8 11 84 1d b0 04 	vmovups %xmm0,0x4b0(%rbp,%rbx,1)
  1f4da6:	00 00
  1f4da8:	48 8b 84 1d b0 04 00 	mov    0x4b0(%rbp,%rbx,1),%rax
  1f4daf:	00
  1f4db0:	48 8b 8c 1d b8 04 00 	mov    0x4b8(%rbp,%rbx,1),%rcx
  1f4db7:	00
  1f4db8:	48 89 8c 1d f8 00 00 	mov    %rcx,0xf8(%rbp,%rbx,1)
  1f4dbf:	00
  1f4dc0:	48 89 84 1d f0 00 00 	mov    %rax,0xf0(%rbp,%rbx,1)
  1f4dc7:	00
  1f4dc8:	c7 84 1d 84 01 00 00 	movl   $0x40000000,0x184(%rbp,%rbx,1)
  1f4dcf:	00 00 00 40
  1f4dd3:	c5 fa 10 84 1d 84 01 	vmovss 0x184(%rbp,%rbx,1),%xmm0
  1f4dda:	00 00
  1f4ddc:	c5 fa 11 84 1d 6c 04 	vmovss %xmm0,0x46c(%rbp,%rbx,1)
  1f4de3:	00 00
  1f4de5:	c4 e2 79 18 84 1d 6c 	vbroadcastss 0x46c(%rbp,%rbx,1),%xmm0
  1f4dec:	04 00 00
  1f4def:	c5 f8 11 84 1d 50 04 	vmovups %xmm0,0x450(%rbp,%rbx,1)
  1f4df6:	00 00
  1f4df8:	48 8b 84 1d 50 04 00 	mov    0x450(%rbp,%rbx,1),%rax
  1f4dff:	00
  1f4e00:	48 8b 8c 1d 58 04 00 	mov    0x458(%rbp,%rbx,1),%rcx
  1f4e07:	00
  1f4e08:	48 89 8c 1d e8 00 00 	mov    %rcx,0xe8(%rbp,%rbx,1)
  1f4e0f:	00
  1f4e10:	48 89 84 1d e0 00 00 	mov    %rax,0xe0(%rbp,%rbx,1)
  1f4e17:	00
  1f4e18:	c7 84 1d dc 00 00 00 	movl   $0x0,0xdc(%rbp,%rbx,1)
  1f4e1f:	00 00 00 00
  1f4e23:	8b 84 1d dc 00 00 00 	mov    0xdc(%rbp,%rbx,1),%eax
  1f4e2a:	3b 84 1d 74 01 00 00 	cmp    0x174(%rbp,%rbx,1),%eax
  1f4e31:	0f 8d a0 0c 00 00    	jge    1f5ad7 <f6+0xf97>
  1f4e37:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  1f4e3c:	8d 41 90             	lea    -0x70(%rcx),%eax
  1f4e3f:	81 c1 60 ff ff ff    	add    $0xffffff60,%ecx
  1f4e45:	41 89 c6             	mov    %eax,%r14d
  1f4e48:	41 89 cf             	mov    %ecx,%r15d
  1f4e4b:	eb 1e                	jmp    1f4e6b <f6+0x32b>
  1f4e4d:	0f 1f 00             	nopl   (%rax)
  1f4e50:	ff 84 2b dc 00 00 00 	incl   0xdc(%rbx,%rbp,1)
  1f4e57:	8b 84 2b dc 00 00 00 	mov    0xdc(%rbx,%rbp,1),%eax
  1f4e5e:	3b 84 2b 74 01 00 00 	cmp    0x174(%rbx,%rbp,1),%eax
  1f4e65:	0f 8d 6c 0c 00 00    	jge    1f5ad7 <f6+0xf97>
  1f4e6b:	48 8b 84 2b 20 01 00 	mov    0x120(%rbx,%rbp,1),%rax
  1f4e72:	00
  1f4e73:	48 8b 8c 2b 28 01 00 	mov    0x128(%rbx,%rbp,1),%rcx
  1f4e7a:	00
  1f4e7b:	c5 ea 2a 84 2b dc 00 	vcvtsi2ssl 0xdc(%rbx,%rbp,1),%xmm2,%xmm0
  1f4e82:	00 00
  1f4e84:	c5 fa 59 84 2b 4c 01 	vmulss 0x14c(%rbx,%rbp,1),%xmm0,%xmm0
  1f4e8b:	00 00
  1f4e8d:	c5 fa 11 84 2b 80 01 	vmovss %xmm0,0x180(%rbx,%rbp,1)
  1f4e94:	00 00
  1f4e96:	c5 fa 10 84 2b 80 01 	vmovss 0x180(%rbx,%rbp,1),%xmm0
  1f4e9d:	00 00
  1f4e9f:	c5 fa 11 84 2b 8c 04 	vmovss %xmm0,0x48c(%rbx,%rbp,1)
  1f4ea6:	00 00
  1f4ea8:	c4 e2 79 18 84 2b 8c 	vbroadcastss 0x48c(%rbx,%rbp,1),%xmm0
  1f4eaf:	04 00 00
  1f4eb2:	c5 f8 11 84 2b 70 04 	vmovups %xmm0,0x470(%rbx,%rbp,1)
  1f4eb9:	00 00
  1f4ebb:	48 8b 94 2b 70 04 00 	mov    0x470(%rbx,%rbp,1),%rdx
  1f4ec2:	00
  1f4ec3:	48 8b b4 2b 78 04 00 	mov    0x478(%rbx,%rbp,1),%rsi
  1f4eca:	00
  1f4ecb:	48 89 8c 2b 38 02 00 	mov    %rcx,0x238(%rbx,%rbp,1)
  1f4ed2:	00
  1f4ed3:	48 89 84 2b 30 02 00 	mov    %rax,0x230(%rbx,%rbp,1)
  1f4eda:	00
  1f4edb:	48 89 b4 2b 28 02 00 	mov    %rsi,0x228(%rbx,%rbp,1)
  1f4ee2:	00
  1f4ee3:	48 89 94 2b 20 02 00 	mov    %rdx,0x220(%rbx,%rbp,1)
  1f4eea:	00
  1f4eeb:	48 8b 84 2b 30 02 00 	mov    0x230(%rbx,%rbp,1),%rax
  1f4ef2:	00
  1f4ef3:	48 8b 8c 2b 38 02 00 	mov    0x238(%rbx,%rbp,1),%rcx
  1f4efa:	00
  1f4efb:	48 8b 94 2b 20 02 00 	mov    0x220(%rbx,%rbp,1),%rdx
  1f4f02:	00
  1f4f03:	48 8b b4 2b 28 02 00 	mov    0x228(%rbx,%rbp,1),%rsi
  1f4f0a:	00
  1f4f0b:	48 89 8c 2b e8 04 00 	mov    %rcx,0x4e8(%rbx,%rbp,1)
  1f4f12:	00
  1f4f13:	48 89 84 2b e0 04 00 	mov    %rax,0x4e0(%rbx,%rbp,1)
  1f4f1a:	00
  1f4f1b:	48 89 b4 2b d8 04 00 	mov    %rsi,0x4d8(%rbx,%rbp,1)
  1f4f22:	00
  1f4f23:	48 89 94 2b d0 04 00 	mov    %rdx,0x4d0(%rbx,%rbp,1)
  1f4f2a:	00
  1f4f2b:	c5 f8 10 84 2b e0 04 	vmovups 0x4e0(%rbx,%rbp,1),%xmm0
  1f4f32:	00 00
  1f4f34:	c5 f8 58 84 2b d0 04 	vaddps 0x4d0(%rbx,%rbp,1),%xmm0,%xmm0
  1f4f3b:	00 00
  1f4f3d:	c5 f8 11 84 2b c0 00 	vmovups %xmm0,0xc0(%rbx,%rbp,1)
  1f4f44:	00 00
  1f4f46:	c7 84 2b bc 00 00 00 	movl   $0x0,0xbc(%rbx,%rbp,1)
  1f4f4d:	00 00 00 00
  1f4f51:	eb 77                	jmp    1f4fca <f6+0x48a>
  1f4f53:	66 66 66 66 2e 0f 1f 	data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
  1f4f5a:	84 00 00 00 00 00
  1f4f60:	8b 94 2b dc 00 00 00 	mov    0xdc(%rbx,%rbp,1),%edx
  1f4f67:	4c 89 ef             	mov    %r13,%rdi
  1f4f6a:	44 89 e6             	mov    %r12d,%esi
  1f4f6d:	0f af 94 2b 78 01 00 	imul   0x178(%rbx,%rbp,1),%edx
  1f4f74:	00
  1f4f75:	03 94 2b bc 00 00 00 	add    0xbc(%rbx,%rbp,1),%edx
  1f4f7c:	e8 7f 0c 00 00       	call   1f5c00 <f8>
  1f4f81:	48 8b 4c 2b 70       	mov    0x70(%rbx,%rbp,1),%rcx
  1f4f86:	48 8b 54 2b 78       	mov    0x78(%rbx,%rbp,1),%rdx
  1f4f8b:	89 84 2b cc 03 00 00 	mov    %eax,0x3cc(%rbx,%rbp,1)
  1f4f92:	48 89 94 2b b8 03 00 	mov    %rdx,0x3b8(%rbx,%rbp,1)
  1f4f99:	00
  1f4f9a:	48 89 8c 2b b0 03 00 	mov    %rcx,0x3b0(%rbx,%rbp,1)
  1f4fa1:	00
  1f4fa2:	48 8b 84 2b b0 03 00 	mov    0x3b0(%rbx,%rbp,1),%rax
  1f4fa9:	00
  1f4faa:	48 8b 8c 2b b8 03 00 	mov    0x3b8(%rbx,%rbp,1),%rcx
  1f4fb1:	00
  1f4fb2:	8b 94 2b cc 03 00 00 	mov    0x3cc(%rbx,%rbp,1),%edx
  1f4fb9:	48 89 4c 13 08       	mov    %rcx,0x8(%rbx,%rdx,1)
  1f4fbe:	48 89 04 13          	mov    %rax,(%rbx,%rdx,1)
  1f4fc2:	83 84 2b bc 00 00 00 	addl   $0x4,0xbc(%rbx,%rbp,1)
  1f4fc9:	04
  1f4fca:	8b 84 2b bc 00 00 00 	mov    0xbc(%rbx,%rbp,1),%eax
  1f4fd1:	3b 84 2b 78 01 00 00 	cmp    0x178(%rbx,%rbp,1),%eax
  1f4fd8:	0f 8d 72 fe ff ff    	jge    1f4e50 <f6+0x310>
  1f4fde:	4c 8b 84 2b 30 01 00 	mov    0x130(%rbx,%rbp,1),%r8
  1f4fe5:	00
  1f4fe6:	48 8b 8c 2b 38 01 00 	mov    0x138(%rbx,%rbp,1),%rcx
  1f4fed:	00
  1f4fee:	8b 94 2b bc 00 00 00 	mov    0xbc(%rbx,%rbp,1),%edx
  1f4ff5:	8d 72 03             	lea    0x3(%rdx),%esi
  1f4ff8:	8d 42 01             	lea    0x1(%rdx),%eax
  1f4ffb:	c5 da 2a c6          	vcvtsi2ss %esi,%xmm4,%xmm0
  1f4fff:	8d 72 02             	lea    0x2(%rdx),%esi
  1f5002:	c5 da 2a ce          	vcvtsi2ss %esi,%xmm4,%xmm1
  1f5006:	c5 da 2a d0          	vcvtsi2ss %eax,%xmm4,%xmm2
  1f500a:	c5 da 2a da          	vcvtsi2ss %edx,%xmm4,%xmm3
  1f500e:	c5 fa 11 84 2b ec 02 	vmovss %xmm0,0x2ec(%rbx,%rbp,1)
  1f5015:	00 00
  1f5017:	c5 fa 11 8c 2b e8 02 	vmovss %xmm1,0x2e8(%rbx,%rbp,1)
  1f501e:	00 00
  1f5020:	c5 fa 11 94 2b e4 02 	vmovss %xmm2,0x2e4(%rbx,%rbp,1)
  1f5027:	00 00
  1f5029:	c5 fa 11 9c 2b e0 02 	vmovss %xmm3,0x2e0(%rbx,%rbp,1)
  1f5030:	00 00
  1f5032:	c5 fa 10 84 2b e0 02 	vmovss 0x2e0(%rbx,%rbp,1),%xmm0
  1f5039:	00 00
  1f503b:	c5 fa 10 8c 2b e4 02 	vmovss 0x2e4(%rbx,%rbp,1),%xmm1
  1f5042:	00 00
  1f5044:	c5 fa 10 94 2b e8 02 	vmovss 0x2e8(%rbx,%rbp,1),%xmm2
  1f504b:	00 00
  1f504d:	c5 fa 10 9c 2b ec 02 	vmovss 0x2ec(%rbx,%rbp,1),%xmm3
  1f5054:	00 00
  1f5056:	c5 fa 11 84 2b 2c 06 	vmovss %xmm0,0x62c(%rbx,%rbp,1)
  1f505d:	00 00
  1f505f:	c5 fa 11 8c 2b 28 06 	vmovss %xmm1,0x628(%rbx,%rbp,1)
  1f5066:	00 00
  1f5068:	c5 fa 11 94 2b 24 06 	vmovss %xmm2,0x624(%rbx,%rbp,1)
  1f506f:	00 00
  1f5071:	c5 fa 11 9c 2b 20 06 	vmovss %xmm3,0x620(%rbx,%rbp,1)
  1f5078:	00 00
  1f507a:	c5 fa 10 84 2b 28 06 	vmovss 0x628(%rbx,%rbp,1),%xmm0
  1f5081:	00 00
  1f5083:	c5 fa 10 8c 2b 24 06 	vmovss 0x624(%rbx,%rbp,1),%xmm1
  1f508a:	00 00
  1f508c:	c5 fa 10 94 2b 20 06 	vmovss 0x620(%rbx,%rbp,1),%xmm2
  1f5093:	00 00
  1f5095:	c5 fa 10 9c 2b 2c 06 	vmovss 0x62c(%rbx,%rbp,1),%xmm3
  1f509c:	00 00
  1f509e:	c4 e3 61 21 c0 10    	vinsertps $0x10,%xmm0,%xmm3,%xmm0
  1f50a4:	c4 e3 79 21 c1 20    	vinsertps $0x20,%xmm1,%xmm0,%xmm0
  1f50aa:	c4 e3 79 21 c2 30    	vinsertps $0x30,%xmm2,%xmm0,%xmm0
  1f50b0:	c5 f8 11 84 2b 10 06 	vmovups %xmm0,0x610(%rbx,%rbp,1)
  1f50b7:	00 00
  1f50b9:	48 8b 94 2b 10 06 00 	mov    0x610(%rbx,%rbp,1),%rdx
  1f50c0:	00
  1f50c1:	48 8b b4 2b 18 06 00 	mov    0x618(%rbx,%rbp,1),%rsi
  1f50c8:	00
  1f50c9:	48 8b bc 2b 50 01 00 	mov    0x150(%rbx,%rbp,1),%rdi
  1f50d0:	00
  1f50d1:	48 8b 84 2b 58 01 00 	mov    0x158(%rbx,%rbp,1),%rax
  1f50d8:	00
  1f50d9:	48 89 b4 2b d8 02 00 	mov    %rsi,0x2d8(%rbx,%rbp,1)
  1f50e0:	00
  1f50e1:	48 89 94 2b d0 02 00 	mov    %rdx,0x2d0(%rbx,%rbp,1)
  1f50e8:	00
  1f50e9:	48 89 84 2b c8 02 00 	mov    %rax,0x2c8(%rbx,%rbp,1)
  1f50f0:	00
  1f50f1:	48 89 bc 2b c0 02 00 	mov    %rdi,0x2c0(%rbx,%rbp,1)
  1f50f8:	00
  1f50f9:	48 8b 84 2b d0 02 00 	mov    0x2d0(%rbx,%rbp,1),%rax
  1f5100:	00
  1f5101:	48 8b 94 2b d8 02 00 	mov    0x2d8(%rbx,%rbp,1),%rdx
  1f5108:	00
  1f5109:	48 8b b4 2b c0 02 00 	mov    0x2c0(%rbx,%rbp,1),%rsi
  1f5110:	00
  1f5111:	48 8b bc 2b c8 02 00 	mov    0x2c8(%rbx,%rbp,1),%rdi
  1f5118:	00
  1f5119:	48 89 94 2b 88 05 00 	mov    %rdx,0x588(%rbx,%rbp,1)
  1f5120:	00
  1f5121:	48 89 84 2b 80 05 00 	mov    %rax,0x580(%rbx,%rbp,1)
  1f5128:	00
  1f5129:	48 89 bc 2b 78 05 00 	mov    %rdi,0x578(%rbx,%rbp,1)
  1f5130:	00
  1f5131:	48 89 b4 2b 70 05 00 	mov    %rsi,0x570(%rbx,%rbp,1)
  1f5138:	00
  1f5139:	c5 f8 10 84 2b 80 05 	vmovups 0x580(%rbx,%rbp,1),%xmm0
  1f5140:	00 00
  1f5142:	c5 f8 59 84 2b 70 05 	vmulps 0x570(%rbx,%rbp,1),%xmm0,%xmm0
  1f5149:	00 00
  1f514b:	48 89 8c 2b 18 02 00 	mov    %rcx,0x218(%rbx,%rbp,1)
  1f5152:	00
  1f5153:	4c 89 84 2b 10 02 00 	mov    %r8,0x210(%rbx,%rbp,1)
  1f515a:	00
  1f515b:	c5 f8 11 84 2b 00 02 	vmovups %xmm0,0x200(%rbx,%rbp,1)
  1f5162:	00 00
  1f5164:	48 8b 84 2b 10 02 00 	mov    0x210(%rbx,%rbp,1),%rax
  1f516b:	00
  1f516c:	48 8b 8c 2b 18 02 00 	mov    0x218(%rbx,%rbp,1),%rcx
  1f5173:	00
  1f5174:	48 8b 94 2b 00 02 00 	mov    0x200(%rbx,%rbp,1),%rdx
  1f517b:	00
  1f517c:	48 8b b4 2b 08 02 00 	mov    0x208(%rbx,%rbp,1),%rsi
  1f5183:	00
  1f5184:	48 89 8c 2b 08 05 00 	mov    %rcx,0x508(%rbx,%rbp,1)
  1f518b:	00
  1f518c:	48 89 84 2b 00 05 00 	mov    %rax,0x500(%rbx,%rbp,1)
  1f5193:	00
  1f5194:	48 89 b4 2b f8 04 00 	mov    %rsi,0x4f8(%rbx,%rbp,1)
  1f519b:	00
  1f519c:	48 89 94 2b f0 04 00 	mov    %rdx,0x4f0(%rbx,%rbp,1)
  1f51a3:	00
  1f51a4:	c5 f8 10 84 2b 00 05 	vmovups 0x500(%rbx,%rbp,1),%xmm0
  1f51ab:	00 00
  1f51ad:	c5 f8 58 84 2b f0 04 	vaddps 0x4f0(%rbx,%rbp,1),%xmm0,%xmm0
  1f51b4:	00 00
  1f51b6:	c5 f8 11 84 2b a0 00 	vmovups %xmm0,0xa0(%rbx,%rbp,1)
  1f51bd:	00 00
  1f51bf:	c7 84 2b 4c 06 00 00 	movl   $0x0,0x64c(%rbx,%rbp,1)
  1f51c6:	00 00 00 00
  1f51ca:	c7 84 2b 48 06 00 00 	movl   $0x0,0x648(%rbx,%rbp,1)
  1f51d1:	00 00 00 00
  1f51d5:	c7 84 2b 44 06 00 00 	movl   $0x0,0x644(%rbx,%rbp,1)
  1f51dc:	00 00 00 00
  1f51e0:	c7 84 2b 40 06 00 00 	movl   $0x0,0x640(%rbx,%rbp,1)
  1f51e7:	00 00 00 00
  1f51eb:	c5 fa 10 84 2b 48 06 	vmovss 0x648(%rbx,%rbp,1),%xmm0
  1f51f2:	00 00
  1f51f4:	c5 fa 10 8c 2b 44 06 	vmovss 0x644(%rbx,%rbp,1),%xmm1
  1f51fb:	00 00
  1f51fd:	c5 fa 10 94 2b 40 06 	vmovss 0x640(%rbx,%rbp,1),%xmm2
  1f5204:	00 00
  1f5206:	c5 fa 10 9c 2b 4c 06 	vmovss 0x64c(%rbx,%rbp,1),%xmm3
  1f520d:	00 00
  1f520f:	c4 e3 61 21 c0 10    	vinsertps $0x10,%xmm0,%xmm3,%xmm0
  1f5215:	c4 e3 79 21 c1 20    	vinsertps $0x20,%xmm1,%xmm0,%xmm0
  1f521b:	c4 e3 79 21 c2 30    	vinsertps $0x30,%xmm2,%xmm0,%xmm0
  1f5221:	c5 f8 11 84 2b 30 06 	vmovups %xmm0,0x630(%rbx,%rbp,1)
  1f5228:	00 00
  1f522a:	48 8b 84 2b 30 06 00 	mov    0x630(%rbx,%rbp,1),%rax
  1f5231:	00
  1f5232:	48 8b 8c 2b 38 06 00 	mov    0x638(%rbx,%rbp,1),%rcx
  1f5239:	00
  1f523a:	48 89 8c 2b 98 00 00 	mov    %rcx,0x98(%rbx,%rbp,1)
  1f5241:	00
  1f5242:	48 89 84 2b 90 00 00 	mov    %rax,0x90(%rbx,%rbp,1)
  1f5249:	00
  1f524a:	c7 84 2b 6c 06 00 00 	movl   $0x0,0x66c(%rbx,%rbp,1)
  1f5251:	00 00 00 00
  1f5255:	c7 84 2b 68 06 00 00 	movl   $0x0,0x668(%rbx,%rbp,1)
  1f525c:	00 00 00 00
  1f5260:	c7 84 2b 64 06 00 00 	movl   $0x0,0x664(%rbx,%rbp,1)
  1f5267:	00 00 00 00
  1f526b:	c7 84 2b 60 06 00 00 	movl   $0x0,0x660(%rbx,%rbp,1)
  1f5272:	00 00 00 00
  1f5276:	c5 fa 10 84 2b 68 06 	vmovss 0x668(%rbx,%rbp,1),%xmm0
  1f527d:	00 00
  1f527f:	c5 fa 10 8c 2b 64 06 	vmovss 0x664(%rbx,%rbp,1),%xmm1
  1f5286:	00 00
  1f5288:	c5 fa 10 94 2b 60 06 	vmovss 0x660(%rbx,%rbp,1),%xmm2
  1f528f:	00 00
  1f5291:	c5 fa 10 9c 2b 6c 06 	vmovss 0x66c(%rbx,%rbp,1),%xmm3
  1f5298:	00 00
  1f529a:	c4 e3 61 21 c0 10    	vinsertps $0x10,%xmm0,%xmm3,%xmm0
  1f52a0:	c4 e3 79 21 c1 20    	vinsertps $0x20,%xmm1,%xmm0,%xmm0
  1f52a6:	c4 e3 79 21 c2 30    	vinsertps $0x30,%xmm2,%xmm0,%xmm0
  1f52ac:	c5 f8 11 84 2b 50 06 	vmovups %xmm0,0x650(%rbx,%rbp,1)
  1f52b3:	00 00
  1f52b5:	48 8b 84 2b 50 06 00 	mov    0x650(%rbx,%rbp,1),%rax
  1f52bc:	00
  1f52bd:	48 8b 8c 2b 58 06 00 	mov    0x658(%rbx,%rbp,1),%rcx
  1f52c4:	00
  1f52c5:	48 89 8c 2b 88 00 00 	mov    %rcx,0x88(%rbx,%rbp,1)
  1f52cc:	00
  1f52cd:	48 89 84 2b 80 00 00 	mov    %rax,0x80(%rbx,%rbp,1)
  1f52d4:	00
  1f52d5:	48 c7 84 2b 88 06 00 	movq   $0x0,0x688(%rbx,%rbp,1)
  1f52dc:	00 00 00 00 00
  1f52e1:	48 c7 84 2b 80 06 00 	movq   $0x0,0x680(%rbx,%rbp,1)
  1f52e8:	00 00 00 00 00
  1f52ed:	c5 fb 10 84 2b 80 06 	vmovsd 0x680(%rbx,%rbp,1),%xmm0
  1f52f4:	00 00
  1f52f6:	c5 fb 10 8c 2b 88 06 	vmovsd 0x688(%rbx,%rbp,1),%xmm1
  1f52fd:	00 00
  1f52ff:	c5 f0 16 c0          	vmovlhps %xmm0,%xmm1,%xmm0
  1f5303:	c5 f8 11 84 2b 70 06 	vmovups %xmm0,0x670(%rbx,%rbp,1)
  1f530a:	00 00
  1f530c:	48 8b 84 2b 70 06 00 	mov    0x670(%rbx,%rbp,1),%rax
  1f5313:	00
  1f5314:	48 8b 8c 2b 78 06 00 	mov    0x678(%rbx,%rbp,1),%rcx
  1f531b:	00
  1f531c:	48 89 4c 2b 78       	mov    %rcx,0x78(%rbx,%rbp,1)
  1f5321:	48 89 44 2b 70       	mov    %rax,0x70(%rbx,%rbp,1)
  1f5326:	c7 44 2b 6c 00 00 00 	movl   $0x0,0x6c(%rbx,%rbp,1)
  1f532d:	00
  1f532e:	66 90                	xchg   %ax,%ax
  1f5330:	8b 44 2b 6c          	mov    0x6c(%rbx,%rbp,1),%eax
  1f5334:	3b 84 2b 70 01 00 00 	cmp    0x170(%rbx,%rbp,1),%eax
  1f533b:	0f 8d 1f fc ff ff    	jge    1f4f60 <f6+0x420>
  1f5341:	48 8b 84 2b 90 00 00 	mov    0x90(%rbx,%rbp,1),%rax
  1f5348:	00
  1f5349:	48 8b 8c 2b 98 00 00 	mov    0x98(%rbx,%rbp,1),%rcx
  1f5350:	00
  1f5351:	48 89 8c 2b b8 02 00 	mov    %rcx,0x2b8(%rbx,%rbp,1)
  1f5358:	00
  1f5359:	48 89 84 2b b0 02 00 	mov    %rax,0x2b0(%rbx,%rbp,1)
  1f5360:	00
  1f5361:	48 89 8c 2b a8 02 00 	mov    %rcx,0x2a8(%rbx,%rbp,1)
  1f5368:	00
  1f5369:	48 89 84 2b a0 02 00 	mov    %rax,0x2a0(%rbx,%rbp,1)
  1f5370:	00
  1f5371:	48 8b 84 2b b0 02 00 	mov    0x2b0(%rbx,%rbp,1),%rax
  1f5378:	00
  1f5379:	48 8b 8c 2b b8 02 00 	mov    0x2b8(%rbx,%rbp,1),%rcx
  1f5380:	00
  1f5381:	48 8b 94 2b a0 02 00 	mov    0x2a0(%rbx,%rbp,1),%rdx
  1f5388:	00
  1f5389:	48 8b b4 2b a8 02 00 	mov    0x2a8(%rbx,%rbp,1),%rsi
  1f5390:	00
  1f5391:	48 89 8c 2b a8 05 00 	mov    %rcx,0x5a8(%rbx,%rbp,1)
  1f5398:	00
  1f5399:	48 89 84 2b a0 05 00 	mov    %rax,0x5a0(%rbx,%rbp,1)
  1f53a0:	00
  1f53a1:	48 89 b4 2b 98 05 00 	mov    %rsi,0x598(%rbx,%rbp,1)
  1f53a8:	00
  1f53a9:	48 89 94 2b 90 05 00 	mov    %rdx,0x590(%rbx,%rbp,1)
  1f53b0:	00
  1f53b1:	c5 f8 10 84 2b a0 05 	vmovups 0x5a0(%rbx,%rbp,1),%xmm0
  1f53b8:	00 00
  1f53ba:	c5 f8 59 84 2b 90 05 	vmulps 0x590(%rbx,%rbp,1),%xmm0,%xmm0
  1f53c1:	00 00
  1f53c3:	c5 f8 11 44 2b 50    	vmovups %xmm0,0x50(%rbx,%rbp,1)
  1f53c9:	48 8b 84 2b 80 00 00 	mov    0x80(%rbx,%rbp,1),%rax
  1f53d0:	00
  1f53d1:	48 8b 8c 2b 88 00 00 	mov    0x88(%rbx,%rbp,1),%rcx
  1f53d8:	00
  1f53d9:	48 89 8c 2b 98 02 00 	mov    %rcx,0x298(%rbx,%rbp,1)
  1f53e0:	00
  1f53e1:	48 89 84 2b 90 02 00 	mov    %rax,0x290(%rbx,%rbp,1)
  1f53e8:	00
  1f53e9:	48 89 8c 2b 88 02 00 	mov    %rcx,0x288(%rbx,%rbp,1)
  1f53f0:	00
  1f53f1:	48 89 84 2b 80 02 00 	mov    %rax,0x280(%rbx,%rbp,1)
  1f53f8:	00
  1f53f9:	48 8b 84 2b 90 02 00 	mov    0x290(%rbx,%rbp,1),%rax
  1f5400:	00
  1f5401:	48 8b 8c 2b 98 02 00 	mov    0x298(%rbx,%rbp,1),%rcx
  1f5408:	00
  1f5409:	48 8b 94 2b 80 02 00 	mov    0x280(%rbx,%rbp,1),%rdx
  1f5410:	00
  1f5411:	48 8b b4 2b 88 02 00 	mov    0x288(%rbx,%rbp,1),%rsi
  1f5418:	00
  1f5419:	48 89 8c 2b c8 05 00 	mov    %rcx,0x5c8(%rbx,%rbp,1)
  1f5420:	00
  1f5421:	48 89 84 2b c0 05 00 	mov    %rax,0x5c0(%rbx,%rbp,1)
  1f5428:	00
  1f5429:	48 89 b4 2b b8 05 00 	mov    %rsi,0x5b8(%rbx,%rbp,1)
  1f5430:	00
  1f5431:	48 89 94 2b b0 05 00 	mov    %rdx,0x5b0(%rbx,%rbp,1)
  1f5438:	00
  1f5439:	c5 f8 10 84 2b c0 05 	vmovups 0x5c0(%rbx,%rbp,1),%xmm0
  1f5440:	00 00
  1f5442:	c5 f8 59 84 2b b0 05 	vmulps 0x5b0(%rbx,%rbp,1),%xmm0,%xmm0
  1f5449:	00 00
  1f544b:	c5 f8 11 44 2b 40    	vmovups %xmm0,0x40(%rbx,%rbp,1)
  1f5451:	48 8b 44 2b 50       	mov    0x50(%rbx,%rbp,1),%rax
  1f5456:	48 8b 4c 2b 58       	mov    0x58(%rbx,%rbp,1),%rcx
  1f545b:	48 8b 54 2b 40       	mov    0x40(%rbx,%rbp,1),%rdx
  1f5460:	48 8b 74 2b 48       	mov    0x48(%rbx,%rbp,1),%rsi
  1f5465:	48 89 8c 2b f8 01 00 	mov    %rcx,0x1f8(%rbx,%rbp,1)
  1f546c:	00
  1f546d:	48 89 84 2b f0 01 00 	mov    %rax,0x1f0(%rbx,%rbp,1)
  1f5474:	00
  1f5475:	48 89 b4 2b e8 01 00 	mov    %rsi,0x1e8(%rbx,%rbp,1)
  1f547c:	00
  1f547d:	48 89 94 2b e0 01 00 	mov    %rdx,0x1e0(%rbx,%rbp,1)
  1f5484:	00
  1f5485:	48 8b 84 2b f0 01 00 	mov    0x1f0(%rbx,%rbp,1),%rax
  1f548c:	00
  1f548d:	48 8b 8c 2b f8 01 00 	mov    0x1f8(%rbx,%rbp,1),%rcx
  1f5494:	00
  1f5495:	48 8b 94 2b e0 01 00 	mov    0x1e0(%rbx,%rbp,1),%rdx
  1f549c:	00
  1f549d:	48 8b b4 2b e8 01 00 	mov    0x1e8(%rbx,%rbp,1),%rsi
  1f54a4:	00
  1f54a5:	48 89 8c 2b 28 05 00 	mov    %rcx,0x528(%rbx,%rbp,1)
  1f54ac:	00
  1f54ad:	48 89 84 2b 20 05 00 	mov    %rax,0x520(%rbx,%rbp,1)
  1f54b4:	00
  1f54b5:	48 89 b4 2b 18 05 00 	mov    %rsi,0x518(%rbx,%rbp,1)
  1f54bc:	00
  1f54bd:	48 89 94 2b 10 05 00 	mov    %rdx,0x510(%rbx,%rbp,1)
  1f54c4:	00
  1f54c5:	c5 f8 10 84 2b 20 05 	vmovups 0x520(%rbx,%rbp,1),%xmm0
  1f54cc:	00 00
  1f54ce:	c5 f8 58 84 2b 10 05 	vaddps 0x510(%rbx,%rbp,1),%xmm0,%xmm0
  1f54d5:	00 00
  1f54d7:	c5 f8 11 44 2b 30    	vmovups %xmm0,0x30(%rbx,%rbp,1)
  1f54dd:	48 8b 44 2b 30       	mov    0x30(%rbx,%rbp,1),%rax
  1f54e2:	48 8b 4c 2b 38       	mov    0x38(%rbx,%rbp,1),%rcx
  1f54e7:	48 8b 94 2b 10 01 00 	mov    0x110(%rbx,%rbp,1),%rdx
  1f54ee:	00
  1f54ef:	48 8b b4 2b 18 01 00 	mov    0x118(%rbx,%rbp,1),%rsi
  1f54f6:	00
  1f54f7:	48 89 8c 2b 18 03 00 	mov    %rcx,0x318(%rbx,%rbp,1)
  1f54fe:	00
  1f54ff:	48 89 84 2b 10 03 00 	mov    %rax,0x310(%rbx,%rbp,1)
  1f5506:	00
  1f5507:	48 89 b4 2b 08 03 00 	mov    %rsi,0x308(%rbx,%rbp,1)
  1f550e:	00
  1f550f:	48 89 94 2b 00 03 00 	mov    %rdx,0x300(%rbx,%rbp,1)
  1f5516:	00
  1f5517:	48 8b 84 2b 10 03 00 	mov    0x310(%rbx,%rbp,1),%rax
  1f551e:	00
  1f551f:	48 8b 8c 2b 18 03 00 	mov    0x318(%rbx,%rbp,1),%rcx
  1f5526:	00
  1f5527:	48 8b 94 2b 00 03 00 	mov    0x300(%rbx,%rbp,1),%rdx
  1f552e:	00
  1f552f:	48 8b b4 2b 08 03 00 	mov    0x308(%rbx,%rbp,1),%rsi
  1f5536:	00
  1f5537:	48 89 8c 2b a8 06 00 	mov    %rcx,0x6a8(%rbx,%rbp,1)
  1f553e:	00
  1f553f:	48 89 84 2b a0 06 00 	mov    %rax,0x6a0(%rbx,%rbp,1)
  1f5546:	00
  1f5547:	48 89 b4 2b 98 06 00 	mov    %rsi,0x698(%rbx,%rbp,1)
  1f554e:	00
  1f554f:	48 89 94 2b 90 06 00 	mov    %rdx,0x690(%rbx,%rbp,1)
  1f5556:	00
  1f5557:	c5 f8 10 84 2b a0 06 	vmovups 0x6a0(%rbx,%rbp,1),%xmm0
  1f555e:	00 00
  1f5560:	c5 f8 c2 84 2b 90 06 	vcmpltps 0x690(%rbx,%rbp,1),%xmm0,%xmm0
  1f5567:	00 00 01
  1f556a:	c5 f8 11 84 2b f0 02 	vmovups %xmm0,0x2f0(%rbx,%rbp,1)
  1f5571:	00 00
  1f5573:	48 8b 84 2b f0 02 00 	mov    0x2f0(%rbx,%rbp,1),%rax
  1f557a:	00
  1f557b:	48 8b 8c 2b f8 02 00 	mov    0x2f8(%rbx,%rbp,1),%rcx
  1f5582:	00
  1f5583:	48 89 4c 2b 28       	mov    %rcx,0x28(%rbx,%rbp,1)
  1f5588:	48 89 44 2b 20       	mov    %rax,0x20(%rbx,%rbp,1)
  1f558d:	48 8b 44 2b 20       	mov    0x20(%rbx,%rbp,1),%rax
  1f5592:	48 8b 4c 2b 28       	mov    0x28(%rbx,%rbp,1),%rcx
  1f5597:	48 89 8c 2b 48 03 00 	mov    %rcx,0x348(%rbx,%rbp,1)
  1f559e:	00
  1f559f:	48 89 84 2b 40 03 00 	mov    %rax,0x340(%rbx,%rbp,1)
  1f55a6:	00
  1f55a7:	48 89 8c 2b 38 03 00 	mov    %rcx,0x338(%rbx,%rbp,1)
  1f55ae:	00
  1f55af:	48 89 84 2b 30 03 00 	mov    %rax,0x330(%rbx,%rbp,1)
  1f55b6:	00
  1f55b7:	48 8b 84 2b 40 03 00 	mov    0x340(%rbx,%rbp,1),%rax
  1f55be:	00
  1f55bf:	48 8b 8c 2b 48 03 00 	mov    0x348(%rbx,%rbp,1),%rcx
  1f55c6:	00
  1f55c7:	48 8b 94 2b 30 03 00 	mov    0x330(%rbx,%rbp,1),%rdx
  1f55ce:	00
  1f55cf:	48 8b b4 2b 38 03 00 	mov    0x338(%rbx,%rbp,1),%rsi
  1f55d6:	00
  1f55d7:	48 89 8c 2b e8 06 00 	mov    %rcx,0x6e8(%rbx,%rbp,1)
  1f55de:	00
  1f55df:	48 89 84 2b e0 06 00 	mov    %rax,0x6e0(%rbx,%rbp,1)
  1f55e6:	00
  1f55e7:	48 89 b4 2b d8 06 00 	mov    %rsi,0x6d8(%rbx,%rbp,1)
  1f55ee:	00
  1f55ef:	48 89 94 2b d0 06 00 	mov    %rdx,0x6d0(%rbx,%rbp,1)
  1f55f6:	00
  1f55f7:	48 8b 84 2b e0 06 00 	mov    0x6e0(%rbx,%rbp,1),%rax
  1f55fe:	00
  1f55ff:	48 8b 8c 2b e8 06 00 	mov    0x6e8(%rbx,%rbp,1),%rcx
  1f5606:	00
  1f5607:	48 23 84 2b d0 06 00 	and    0x6d0(%rbx,%rbp,1),%rax
  1f560e:	00
  1f560f:	48 23 8c 2b d8 06 00 	and    0x6d8(%rbx,%rbp,1),%rcx
  1f5616:	00
  1f5617:	48 89 8c 2b 28 03 00 	mov    %rcx,0x328(%rbx,%rbp,1)
  1f561e:	00
  1f561f:	48 89 84 2b 20 03 00 	mov    %rax,0x320(%rbx,%rbp,1)
  1f5626:	00
  1f5627:	48 8b 84 2b 20 03 00 	mov    0x320(%rbx,%rbp,1),%rax
  1f562e:	00
  1f562f:	48 8b 8c 2b 28 03 00 	mov    0x328(%rbx,%rbp,1),%rcx
  1f5636:	00
  1f5637:	48 89 8c 2b 48 07 00 	mov    %rcx,0x748(%rbx,%rbp,1)
  1f563e:	00
  1f563f:	48 89 84 2b 40 07 00 	mov    %rax,0x740(%rbx,%rbp,1)
  1f5646:	00
  1f5647:	c7 84 2b 3c 07 00 00 	movl   $0x0,0x73c(%rbx,%rbp,1)
  1f564e:	00 00 00 00
  1f5652:	48 8b 84 2b 40 07 00 	mov    0x740(%rbx,%rbp,1),%rax
  1f5659:	00
  1f565a:	48 8b 8c 2b 48 07 00 	mov    0x748(%rbx,%rbp,1),%rcx
  1f5661:	00
  1f5662:	48 89 8c 2b 28 07 00 	mov    %rcx,0x728(%rbx,%rbp,1)
  1f5669:	00
  1f566a:	48 89 84 2b 20 07 00 	mov    %rax,0x720(%rbx,%rbp,1)
  1f5671:	00
  1f5672:	8b 84 2b 3c 07 00 00 	mov    0x73c(%rbx,%rbp,1),%eax
  1f5679:	c1 e0 03             	shl    $0x3,%eax
  1f567c:	83 e0 08             	and    $0x8,%eax
  1f567f:	4c 09 f0             	or     %r14,%rax
  1f5682:	48 8b 04 03          	mov    (%rbx,%rax,1),%rax
  1f5686:	48 8b 8c 2b 20 03 00 	mov    0x320(%rbx,%rbp,1),%rcx
  1f568d:	00
  1f568e:	48 8b 94 2b 28 03 00 	mov    0x328(%rbx,%rbp,1),%rdx
  1f5695:	00
  1f5696:	48 89 94 2b 18 07 00 	mov    %rdx,0x718(%rbx,%rbp,1)
  1f569d:	00
  1f569e:	48 89 8c 2b 10 07 00 	mov    %rcx,0x710(%rbx,%rbp,1)
  1f56a5:	00
  1f56a6:	c7 84 2b 0c 07 00 00 	movl   $0x1,0x70c(%rbx,%rbp,1)
  1f56ad:	01 00 00 00
  1f56b1:	48 8b 8c 2b 10 07 00 	mov    0x710(%rbx,%rbp,1),%rcx
  1f56b8:	00
  1f56b9:	48 8b 94 2b 18 07 00 	mov    0x718(%rbx,%rbp,1),%rdx
  1f56c0:	00
  1f56c1:	48 89 94 2b f8 06 00 	mov    %rdx,0x6f8(%rbx,%rbp,1)
  1f56c8:	00
  1f56c9:	48 89 8c 2b f0 06 00 	mov    %rcx,0x6f0(%rbx,%rbp,1)
  1f56d0:	00
  1f56d1:	8b 8c 2b 0c 07 00 00 	mov    0x70c(%rbx,%rbp,1),%ecx
  1f56d8:	c1 e1 03             	shl    $0x3,%ecx
  1f56db:	83 e1 08             	and    $0x8,%ecx
  1f56de:	4c 09 f9             	or     %r15,%rcx
  1f56e1:	48 0b 04 0b          	or     (%rbx,%rcx,1),%rax
  1f56e5:	0f 84 75 f8 ff ff    	je     1f4f60 <f6+0x420>
  1f56eb:	4c 8b 44 2b 70       	mov    0x70(%rbx,%rbp,1),%r8
  1f56f0:	48 8b 4c 2b 78       	mov    0x78(%rbx,%rbp,1),%rcx
  1f56f5:	48 8b 54 2b 20       	mov    0x20(%rbx,%rbp,1),%rdx
  1f56fa:	48 8b 74 2b 28       	mov    0x28(%rbx,%rbp,1),%rsi
  1f56ff:	48 8b bc 2b 00 01 00 	mov    0x100(%rbx,%rbp,1),%rdi
  1f5706:	00
  1f5707:	48 8b 84 2b 08 01 00 	mov    0x108(%rbx,%rbp,1),%rax
  1f570e:	00
  1f570f:	48 89 b4 2b 88 03 00 	mov    %rsi,0x388(%rbx,%rbp,1)
  1f5716:	00
  1f5717:	48 89 94 2b 80 03 00 	mov    %rdx,0x380(%rbx,%rbp,1)
  1f571e:	00
  1f571f:	48 89 84 2b 78 03 00 	mov    %rax,0x378(%rbx,%rbp,1)
  1f5726:	00
  1f5727:	48 89 bc 2b 70 03 00 	mov    %rdi,0x370(%rbx,%rbp,1)
  1f572e:	00
  1f572f:	48 8b 84 2b 80 03 00 	mov    0x380(%rbx,%rbp,1),%rax
  1f5736:	00
  1f5737:	48 8b 94 2b 88 03 00 	mov    0x388(%rbx,%rbp,1),%rdx
  1f573e:	00
  1f573f:	48 8b b4 2b 70 03 00 	mov    0x370(%rbx,%rbp,1),%rsi
  1f5746:	00
  1f5747:	48 8b bc 2b 78 03 00 	mov    0x378(%rbx,%rbp,1),%rdi
  1f574e:	00
  1f574f:	48 89 94 2b c8 06 00 	mov    %rdx,0x6c8(%rbx,%rbp,1)
  1f5756:	00
  1f5757:	48 89 84 2b c0 06 00 	mov    %rax,0x6c0(%rbx,%rbp,1)
  1f575e:	00
  1f575f:	48 89 bc 2b b8 06 00 	mov    %rdi,0x6b8(%rbx,%rbp,1)
  1f5766:	00
  1f5767:	48 89 b4 2b b0 06 00 	mov    %rsi,0x6b0(%rbx,%rbp,1)
  1f576e:	00
  1f576f:	48 8b 84 2b c0 06 00 	mov    0x6c0(%rbx,%rbp,1),%rax
  1f5776:	00
  1f5777:	48 8b 94 2b c8 06 00 	mov    0x6c8(%rbx,%rbp,1),%rdx
  1f577e:	00
  1f577f:	48 23 84 2b b0 06 00 	and    0x6b0(%rbx,%rbp,1),%rax
  1f5786:	00
  1f5787:	48 23 94 2b b8 06 00 	and    0x6b8(%rbx,%rbp,1),%rdx
  1f578e:	00
  1f578f:	48 89 8c 2b 68 03 00 	mov    %rcx,0x368(%rbx,%rbp,1)
  1f5796:	00
  1f5797:	4c 89 84 2b 60 03 00 	mov    %r8,0x360(%rbx,%rbp,1)
  1f579e:	00
  1f579f:	48 89 94 2b 58 03 00 	mov    %rdx,0x358(%rbx,%rbp,1)
  1f57a6:	00
  1f57a7:	48 89 84 2b 50 03 00 	mov    %rax,0x350(%rbx,%rbp,1)
  1f57ae:	00
  1f57af:	48 8b 84 2b 60 03 00 	mov    0x360(%rbx,%rbp,1),%rax
  1f57b6:	00
  1f57b7:	48 8b 8c 2b 68 03 00 	mov    0x368(%rbx,%rbp,1),%rcx
  1f57be:	00
  1f57bf:	48 8b 94 2b 50 03 00 	mov    0x350(%rbx,%rbp,1),%rdx
  1f57c6:	00
  1f57c7:	48 8b b4 2b 58 03 00 	mov    0x358(%rbx,%rbp,1),%rsi
  1f57ce:	00
  1f57cf:	48 89 8c 2b 68 07 00 	mov    %rcx,0x768(%rbx,%rbp,1)
  1f57d6:	00
  1f57d7:	48 89 84 2b 60 07 00 	mov    %rax,0x760(%rbx,%rbp,1)
  1f57de:	00
  1f57df:	48 89 b4 2b 58 07 00 	mov    %rsi,0x758(%rbx,%rbp,1)
  1f57e6:	00
  1f57e7:	48 89 94 2b 50 07 00 	mov    %rdx,0x750(%rbx,%rbp,1)
  1f57ee:	00
  1f57ef:	c5 fa 6f 84 2b 60 07 	vmovdqu 0x760(%rbx,%rbp,1),%xmm0
  1f57f6:	00 00
  1f57f8:	c5 f9 fe 84 2b 50 07 	vpaddd 0x750(%rbx,%rbp,1),%xmm0,%xmm0
  1f57ff:	00 00
  1f5801:	c5 fa 7f 44 2b 70    	vmovdqu %xmm0,0x70(%rbx,%rbp,1)
  1f5807:	48 8b 44 2b 50       	mov    0x50(%rbx,%rbp,1),%rax
  1f580c:	48 8b 4c 2b 58       	mov    0x58(%rbx,%rbp,1),%rcx
  1f5811:	48 8b 54 2b 40       	mov    0x40(%rbx,%rbp,1),%rdx
  1f5816:	48 8b 74 2b 48       	mov    0x48(%rbx,%rbp,1),%rsi
  1f581b:	48 89 8c 2b a8 03 00 	mov    %rcx,0x3a8(%rbx,%rbp,1)
  1f5822:	00
  1f5823:	48 89 84 2b a0 03 00 	mov    %rax,0x3a0(%rbx,%rbp,1)
  1f582a:	00
  1f582b:	48 89 b4 2b 98 03 00 	mov    %rsi,0x398(%rbx,%rbp,1)
  1f5832:	00
  1f5833:	48 89 94 2b 90 03 00 	mov    %rdx,0x390(%rbx,%rbp,1)
  1f583a:	00
  1f583b:	48 8b 84 2b a0 03 00 	mov    0x3a0(%rbx,%rbp,1),%rax
  1f5842:	00
  1f5843:	48 8b 8c 2b a8 03 00 	mov    0x3a8(%rbx,%rbp,1),%rcx
  1f584a:	00
  1f584b:	48 8b 94 2b 90 03 00 	mov    0x390(%rbx,%rbp,1),%rdx
  1f5852:	00
  1f5853:	48 8b b4 2b 98 03 00 	mov    0x398(%rbx,%rbp,1),%rsi
  1f585a:	00
  1f585b:	48 89 8c 2b 88 07 00 	mov    %rcx,0x788(%rbx,%rbp,1)
  1f5862:	00
  1f5863:	48 89 84 2b 80 07 00 	mov    %rax,0x780(%rbx,%rbp,1)
  1f586a:	00
  1f586b:	48 89 b4 2b 78 07 00 	mov    %rsi,0x778(%rbx,%rbp,1)
  1f5872:	00
  1f5873:	48 89 94 2b 70 07 00 	mov    %rdx,0x770(%rbx,%rbp,1)
  1f587a:	00
  1f587b:	c5 f8 10 84 2b 80 07 	vmovups 0x780(%rbx,%rbp,1),%xmm0
  1f5882:	00 00
  1f5884:	c5 f8 5c 84 2b 70 07 	vsubps 0x770(%rbx,%rbp,1),%xmm0,%xmm0
  1f588b:	00 00
  1f588d:	48 8b 84 2b a0 00 00 	mov    0xa0(%rbx,%rbp,1),%rax
  1f5894:	00
  1f5895:	48 8b 8c 2b a8 00 00 	mov    0xa8(%rbx,%rbp,1),%rcx
  1f589c:	00
  1f589d:	c5 f8 11 84 2b d0 01 	vmovups %xmm0,0x1d0(%rbx,%rbp,1)
  1f58a4:	00 00
  1f58a6:	48 89 8c 2b c8 01 00 	mov    %rcx,0x1c8(%rbx,%rbp,1)
  1f58ad:	00
  1f58ae:	48 89 84 2b c0 01 00 	mov    %rax,0x1c0(%rbx,%rbp,1)
  1f58b5:	00
  1f58b6:	48 8b 84 2b d0 01 00 	mov    0x1d0(%rbx,%rbp,1),%rax
  1f58bd:	00
  1f58be:	48 8b 8c 2b d8 01 00 	mov    0x1d8(%rbx,%rbp,1),%rcx
  1f58c5:	00
  1f58c6:	48 8b 94 2b c0 01 00 	mov    0x1c0(%rbx,%rbp,1),%rdx
  1f58cd:	00
  1f58ce:	48 8b b4 2b c8 01 00 	mov    0x1c8(%rbx,%rbp,1),%rsi
  1f58d5:	00
  1f58d6:	48 89 8c 2b 48 05 00 	mov    %rcx,0x548(%rbx,%rbp,1)
  1f58dd:	00
  1f58de:	48 89 84 2b 40 05 00 	mov    %rax,0x540(%rbx,%rbp,1)
  1f58e5:	00
  1f58e6:	48 89 b4 2b 38 05 00 	mov    %rsi,0x538(%rbx,%rbp,1)
  1f58ed:	00
  1f58ee:	48 89 94 2b 30 05 00 	mov    %rdx,0x530(%rbx,%rbp,1)
  1f58f5:	00
  1f58f6:	c5 f8 10 84 2b 40 05 	vmovups 0x540(%rbx,%rbp,1),%xmm0
  1f58fd:	00 00
  1f58ff:	c5 f8 58 84 2b 30 05 	vaddps 0x530(%rbx,%rbp,1),%xmm0,%xmm0
  1f5906:	00 00
  1f5908:	c5 f8 11 44 2b 10    	vmovups %xmm0,0x10(%rbx,%rbp,1)
  1f590e:	4c 8b 84 2b e0 00 00 	mov    0xe0(%rbx,%rbp,1),%r8
  1f5915:	00
  1f5916:	48 8b 8c 2b e8 00 00 	mov    0xe8(%rbx,%rbp,1),%rcx
  1f591d:	00
  1f591e:	48 8b 94 2b 90 00 00 	mov    0x90(%rbx,%rbp,1),%rdx
  1f5925:	00
  1f5926:	48 8b b4 2b 98 00 00 	mov    0x98(%rbx,%rbp,1),%rsi
  1f592d:	00
  1f592e:	48 8b bc 2b 80 00 00 	mov    0x80(%rbx,%rbp,1),%rdi
  1f5935:	00
  1f5936:	48 8b 84 2b 88 00 00 	mov    0x88(%rbx,%rbp,1),%rax
  1f593d:	00
  1f593e:	48 89 b4 2b 78 02 00 	mov    %rsi,0x278(%rbx,%rbp,1)
  1f5945:	00
  1f5946:	48 89 94 2b 70 02 00 	mov    %rdx,0x270(%rbx,%rbp,1)
  1f594d:	00
  1f594e:	48 89 84 2b 68 02 00 	mov    %rax,0x268(%rbx,%rbp,1)
  1f5955:	00
  1f5956:	48 89 bc 2b 60 02 00 	mov    %rdi,0x260(%rbx,%rbp,1)
  1f595d:	00
  1f595e:	48 8b 84 2b 70 02 00 	mov    0x270(%rbx,%rbp,1),%rax
  1f5965:	00
  1f5966:	48 8b 94 2b 78 02 00 	mov    0x278(%rbx,%rbp,1),%rdx
  1f596d:	00
  1f596e:	48 8b b4 2b 60 02 00 	mov    0x260(%rbx,%rbp,1),%rsi
  1f5975:	00
  1f5976:	48 8b bc 2b 68 02 00 	mov    0x268(%rbx,%rbp,1),%rdi
  1f597d:	00
  1f597e:	48 89 94 2b e8 05 00 	mov    %rdx,0x5e8(%rbx,%rbp,1)
  1f5985:	00
  1f5986:	48 89 84 2b e0 05 00 	mov    %rax,0x5e0(%rbx,%rbp,1)
  1f598d:	00
  1f598e:	48 89 bc 2b d8 05 00 	mov    %rdi,0x5d8(%rbx,%rbp,1)
  1f5995:	00
  1f5996:	48 89 b4 2b d0 05 00 	mov    %rsi,0x5d0(%rbx,%rbp,1)
  1f599d:	00
  1f599e:	c5 f8 10 84 2b e0 05 	vmovups 0x5e0(%rbx,%rbp,1),%xmm0
  1f59a5:	00 00
  1f59a7:	c5 f8 59 84 2b d0 05 	vmulps 0x5d0(%rbx,%rbp,1),%xmm0,%xmm0
  1f59ae:	00 00
  1f59b0:	48 89 8c 2b 58 02 00 	mov    %rcx,0x258(%rbx,%rbp,1)
  1f59b7:	00
  1f59b8:	4c 89 84 2b 50 02 00 	mov    %r8,0x250(%rbx,%rbp,1)
  1f59bf:	00
  1f59c0:	c5 f8 11 84 2b 40 02 	vmovups %xmm0,0x240(%rbx,%rbp,1)
  1f59c7:	00 00
  1f59c9:	48 8b 84 2b 50 02 00 	mov    0x250(%rbx,%rbp,1),%rax
  1f59d0:	00
  1f59d1:	48 8b 8c 2b 58 02 00 	mov    0x258(%rbx,%rbp,1),%rcx
  1f59d8:	00
  1f59d9:	48 8b 94 2b 40 02 00 	mov    0x240(%rbx,%rbp,1),%rdx
  1f59e0:	00
  1f59e1:	48 8b b4 2b 48 02 00 	mov    0x248(%rbx,%rbp,1),%rsi
  1f59e8:	00
  1f59e9:	48 89 8c 2b 08 06 00 	mov    %rcx,0x608(%rbx,%rbp,1)
  1f59f0:	00
  1f59f1:	48 89 84 2b 00 06 00 	mov    %rax,0x600(%rbx,%rbp,1)
  1f59f8:	00
  1f59f9:	48 89 b4 2b f8 05 00 	mov    %rsi,0x5f8(%rbx,%rbp,1)
  1f5a00:	00
  1f5a01:	48 89 94 2b f0 05 00 	mov    %rdx,0x5f0(%rbx,%rbp,1)
  1f5a08:	00
  1f5a09:	c5 f8 10 84 2b 00 06 	vmovups 0x600(%rbx,%rbp,1),%xmm0
  1f5a10:	00 00
  1f5a12:	c5 f8 59 84 2b f0 05 	vmulps 0x5f0(%rbx,%rbp,1),%xmm0,%xmm0
  1f5a19:	00 00
  1f5a1b:	48 8b 84 2b c0 00 00 	mov    0xc0(%rbx,%rbp,1),%rax
  1f5a22:	00
  1f5a23:	48 8b 8c 2b c8 00 00 	mov    0xc8(%rbx,%rbp,1),%rcx
  1f5a2a:	00
  1f5a2b:	c5 f8 11 84 2b b0 01 	vmovups %xmm0,0x1b0(%rbx,%rbp,1)
  1f5a32:	00 00
  1f5a34:	48 89 8c 2b a8 01 00 	mov    %rcx,0x1a8(%rbx,%rbp,1)
  1f5a3b:	00
  1f5a3c:	48 89 84 2b a0 01 00 	mov    %rax,0x1a0(%rbx,%rbp,1)
  1f5a43:	00
  1f5a44:	48 8b 84 2b b0 01 00 	mov    0x1b0(%rbx,%rbp,1),%rax
  1f5a4b:	00
  1f5a4c:	48 8b 8c 2b b8 01 00 	mov    0x1b8(%rbx,%rbp,1),%rcx
  1f5a53:	00
  1f5a54:	48 8b 94 2b a0 01 00 	mov    0x1a0(%rbx,%rbp,1),%rdx
  1f5a5b:	00
  1f5a5c:	48 8b b4 2b a8 01 00 	mov    0x1a8(%rbx,%rbp,1),%rsi
  1f5a63:	00
  1f5a64:	48 89 8c 2b 68 05 00 	mov    %rcx,0x568(%rbx,%rbp,1)
  1f5a6b:	00
  1f5a6c:	48 89 84 2b 60 05 00 	mov    %rax,0x560(%rbx,%rbp,1)
  1f5a73:	00
  1f5a74:	48 89 b4 2b 58 05 00 	mov    %rsi,0x558(%rbx,%rbp,1)
  1f5a7b:	00
  1f5a7c:	48 89 94 2b 50 05 00 	mov    %rdx,0x550(%rbx,%rbp,1)
  1f5a83:	00
  1f5a84:	c5 f8 10 84 2b 60 05 	vmovups 0x560(%rbx,%rbp,1),%xmm0
  1f5a8b:	00 00
  1f5a8d:	c5 f8 58 84 2b 50 05 	vaddps 0x550(%rbx,%rbp,1),%xmm0,%xmm0
  1f5a94:	00 00
  1f5a96:	c5 f8 11 04 2b       	vmovups %xmm0,(%rbx,%rbp,1)
  1f5a9b:	48 8b 44 2b 10       	mov    0x10(%rbx,%rbp,1),%rax
  1f5aa0:	48 8b 4c 2b 18       	mov    0x18(%rbx,%rbp,1),%rcx
  1f5aa5:	48 89 8c 2b 98 00 00 	mov    %rcx,0x98(%rbx,%rbp,1)
  1f5aac:	00
  1f5aad:	48 89 84 2b 90 00 00 	mov    %rax,0x90(%rbx,%rbp,1)
  1f5ab4:	00
  1f5ab5:	48 8b 04 2b          	mov    (%rbx,%rbp,1),%rax
  1f5ab9:	48 8b 4c 2b 08       	mov    0x8(%rbx,%rbp,1),%rcx
  1f5abe:	48 89 8c 2b 88 00 00 	mov    %rcx,0x88(%rbx,%rbp,1)
  1f5ac5:	00
  1f5ac6:	48 89 84 2b 80 00 00 	mov    %rax,0x80(%rbx,%rbp,1)
  1f5acd:	00
  1f5ace:	ff 44 2b 6c          	incl   0x6c(%rbx,%rbp,1)
  1f5ad2:	e9 59 f8 ff ff       	jmp    1f5330 <f6+0x7f0>
  1f5ad7:	c6 84 2b 6f 01 00 00 	movb   $0x1,0x16f(%rbx,%rbp,1)
  1f5ade:	01
  1f5adf:	f6 84 2b 6f 01 00 00 	testb  $0x1,0x16f(%rbx,%rbp,1)
  1f5ae6:	01
  1f5ae7:	75 0b                	jne    1f5af4 <f6+0xfb4>
  1f5ae9:	4c 89 ef             	mov    %r13,%rdi
  1f5aec:	44 89 e6             	mov    %r12d,%esi
  1f5aef:	e8 3c 01 00 00       	call   1f5c30 <f9>
  1f5af4:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  1f5af9:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  1f5afe:	48 8b 00             	mov    (%rax),%rax
  1f5b01:	89 08                	mov    %ecx,(%rax)
  1f5b03:	48 83 c4 18          	add    $0x18,%rsp
  1f5b07:	5b                   	pop    %rbx
  1f5b08:	41 5c                	pop    %r12
  1f5b0a:	41 5d                	pop    %r13
  1f5b0c:	41 5e                	pop    %r14
  1f5b0e:	41 5f                	pop    %r15
  1f5b10:	5d                   	pop    %rbp
  1f5b11:	c3                   	ret
  1f5b12:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 cs nopw 0x0(%rax,%rax,1)
  1f5b19:	1f 84 00 00 00 00 00