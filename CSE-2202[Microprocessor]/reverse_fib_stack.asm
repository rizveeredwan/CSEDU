;Redwan Ahmed Rizvee
;Roll - 09
;Assignmnet - Print upto nth Fibbonacci in reverse order
section .data
   
n : dq  10
  
fmt: dq  "Fibbonacci = %ld",10,0



section .text
   
extern printf
   
global main



main:
   
push rbp
   
   
push 0
   
push 1
 
  
mov rbx,2
   
mov rcx,2
   
call fib
  
 
pop rbp
   
pop rbp
   
pop rbp
   
mov rax,0
   
ret




fib:
  
push rbp
  
mov  rbp,rsp
  
sub  rsp,64

  

cmp rbx,[n]
  
JE  break

  

mov rax,0
  
mov rcx,[rbp+16]
  
mov rax,[rbp+24]

  
add rax,rcx
 
push rcx
  
push rax
  
inc  rbx
  
call fib

 
 
mov  rdi,fmt
  
mov  rsi,[rbp+16]
  
call printf


  
pop r8
  
pop r9

  

mov rax,0
  
mov rcx,0
 

leave
  
ret



break:
  
leave
  
ret
 

