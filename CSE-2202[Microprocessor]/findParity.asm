;Redwan Ahmed Rizvee
;Roll - 09
;Assignment - Pairity of a number

section .data
  
a  : dq  7
  
b  : dq  2
 
msg1 : db  "Even parity",10,0
 
msg2: db  "Odd parity",10,0
 
fmt : db   "vl = %ld",10,0



section .text
  
extern printf
  
global main



find_parity:
  
push  rbp
  
mov   rbp,rsp
  
sub   rsp,32

  

cmp   rbx,0
  
je    break

  
mov   rdx,0
  
mov   rax,rbx
  
idiv  qword[b]
  
 
add   rcx,rdx
  
mov   rbx,rax
  
call find_parity
  
  
leave
  
ret



break:
  
leave
  
ret



p1:  
  
mov rdi,msg1
  
call printf

pop rbp
mov rax,0
ret


main:
  
push rbp
  
  
mov  rbx,[a]
  
mov  rcx,0
  
call find_parity 

 
 
mov  rdx,0
 
mov  rax,rcx
  
idiv qword[b]
  
cmp  rdx,0
  
je   p1
  

mov  rdi,msg2
  
call printf
 
 
  
pop rbp
  
mov rax,0
  
ret  
  
