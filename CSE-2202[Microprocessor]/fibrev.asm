; Name: Muntasir Wahed
; Roll: 07
; nasm -f elf64 fibrev.asm
; gcc -o happy fibrev.o
; This prints the first n fibonacci numbers in reverse order
; It requires the user to push the value of n in the main function
; I have pushed 13
extern printf
section .bss
section .data
	msg db "%ld",10,0
section .text
	global main

main:
	push 	rbp
	mov 	rbp, rsp
	sub 	rsp, 64

	push 	13

	mov 	r8,0
	mov 	r9,1
	mov 	rax,0
	call fibonaccirev

exit:	
	pop 	rax
	leave
	ret

fibonaccirev:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	rcx,[rbp+16]
	
	cmp 	rcx, 0
	je basecase
	
	sub 	rcx,1
	
	push r8
	mov 	rax,r9
	add 	r9,r8
	mov 	r8,rax
	push 	rcx
	call fibonaccirev

	pop 	rcx
	pop 	rax
	push 	r8
	push 	r9

	mov 	rsi,rax
	mov 	rdi,msg
	xor 	rax,rax
	call printf
	pop 	r9
	pop 	r8

basecase:
	leave
	ret

