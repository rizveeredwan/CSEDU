; Name: Muntasir Wahed
; Roll: 07
; nasm -f elf64 fib.asm
; gcc -o fib fib.o
; This prints the first n fibonacci numbers
; It requires the user to push the value of n in the main function
; I have pushed 20
extern printf
section .bss
section .data
	msg 	db 	"%ld", 10, 0
section .text
	global main

main:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	push 	20
	mov 	rax,0
	call fibonacci
exit:
	pop 	rax
	leave
	ret

fibonacci:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	rcx,[rbp+16]
	
	cmp 	rcx,0
	jle basecase
	
	sub 	rcx,1
	push 	rcx
	mov 	rax,0
	call fibonacci

	push 	rbx
	push 	rax
	mov 	rsi,rbx
	mov 	rdi,msg
	mov 	rax,0
	call printf

	pop 	rax
	pop 	rbx

	mov 	rcx,rax
	add 	rcx,rbx
	mov 	rbx,rax
	mov 	rax,rcx

	pop 	rcx
	leave
	ret
basecase:
	mov 	rax,1
	mov 	rbx,0
	leave
	ret

