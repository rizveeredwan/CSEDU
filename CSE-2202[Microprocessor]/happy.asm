; Name: Muntasir Wahed
; Roll: 07
; nasm -f elf64 happy.asm
; gcc -o happy happy.o
extern printf
section .bss
section .data
	happy 		db 	"%ld is a happy number.",10,0
	unhappy 	db 	"%ld is an unhappy number",10,0
	number	 	dq	 99999997
section .text
	global main
main:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	rax,[number]
	push 	rax
	call checkHappy
exit:
	pop 	rax
	leave
	ret

checkHappy:
	push 	rbp
	mov 	rbp,rsp
	sub 	rsp,64
	mov 	r8,[rbp+16]
	
	mov 	rdx,0
	mov 	rax,r8
	mov 	rcx,10
	idiv 	rcx
	cmp 	rax,0
	je 	printMessage
	mov 	r8,0
loop:
	add 	r8,rdx
	cmp 	rax,0
	je break
	
	mov 	rdx,0
	mov 	rcx,10
	idiv 	rcx
	jmp 	loop
break:
	push 	r8
	call checkHappy
	leave
	ret
printMessage:
	cmp 	rdx,7
	jne unhappyLabel

happyLabel:
	mov 	rsi,[number]
	mov 	rdi,happy
	xor 	rax,rax
	call printf
	jmp last
	
unhappyLabel:
	mov 	rsi,[number]
	mov 	rdi,unhappy
	xor 	rax,rax
	call printf
last:
	leave
	ret

