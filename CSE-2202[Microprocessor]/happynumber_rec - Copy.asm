;Redwan Ahmed Rizvee
;Roll - 09
;Assignmnet - Find a number Happy or Not Happy

section .data
   
a : dq  20
   
b : dq  10
 
fmt1: db  "Happy Number",10,0
 
fmt2: db  "Not Happy I guess",10,0
 
fmt : db  "Square root value = %ld",10,0

 


section .text
  
extern printf
   
global main



square_root:
  
push rbp
   
mov  rbp,rsp
   
mov  rsp,64
 
  
   
mov  rax,rdi
   
mul  rax
   

   
leave
   
ret



sum_of_digits: 
  
push rbp 
  
mov  rbp,rsp
  
sub  rsp,64

  

cmp  r8,100000
  
  
je   print2
 
 
  
mov  rax,[a]
  
mov  rbx,0
  
mov  rcx,0
  
JMP  LOOP


 
 
LOOP:
 
mov  rbx,rax
  
cmp  rbx,0
  
JE   CND
  
  
  
mov  rdx,0
  
idiv qword[b]
  
mov  [a],rax
  
mov  rdi,rdx
  
call square_root
  
add  rcx,rax
  
mov  rax,[a]
  
JMP  LOOP

 
 
  
CND:
  
mov  rbx,rcx
  
cmp  rbx,1
  
JE   print1
  
inc  r8
  
mov  rbx,r8
  
cmp  rbx,100000
  
JE   print2
  
mov  [a],rcx
  
mov  rcx,0
  
call sum_of_digits
  
leave
  
ret


  
print1:
  
mov rdi,fmt1
  
call printf
  
leave
  
ret

 
 
print2:
  
mov  rdi,fmt2
  
call printf
  
leave
  
ret

 
 
  


main:
   
push  rbp
   
   
mov  r8,1
   
call sum_of_digits
   
  
 
pop rbp
   
mov rax,0
   
ret 
