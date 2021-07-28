; Name: Muntasir Wahed
; Roll: 07
; nasm -f elf64 parity.asm
; gcc -o happy parity.o
extern printf
section .bss
section .data
	even	 db 	"%ld has an even parity.",10,0
	odd	 db	"%ld has an odd parity",10,0
	number 	 dq 	7
section .text
	global main
main:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	rax, 7
	push 	rax
	mov  	r9,0
	mov 	rdx,0
	call checkParity

exit:	
	pop 	rax
	leave
	ret

checkParity:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	rax,[rbp+16]

	add 	r9,rdx
	cmp 	rax,0
	je break
	mov 	rdx,0
	mov 	rcx,2
	idiv 	rcx
	push 	rax
	call checkParity
	
	leave 
	ret
break:
	mov 	rdx,0
	mov 	rcx,2
	mov 	rax,r9
	idiv 	rcx
	cmp 	rdx,1
	je 	oddLabel
evenLabel:
	mov 	rdi,even
	mov 	rsi,[number]
	xor 	rax,rax
	call printf
	jmp last

oddLabel:
	mov 	rdi,odd
	mov 	rsi,[number]
	xor 	rax,rax
	call printf
last:
	leave
	ret

