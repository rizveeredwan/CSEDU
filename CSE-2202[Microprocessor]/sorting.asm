;Redwan Ahmed Rizvee
;Roll - 09
;Assignment -  Sorting an array

section .data
  
fmt: db "The sorted array = %ld",10,0

array: dq 7,6,5,4,32,-10

len  : dq 6



section .text
  
extern printf
  
global main



func:
   
push rbp
   
mov  rbp,rsp
   
sub  rsp,32
 
  
mov  rbx,-1
   
jmp  LOOP1
 
  
  


LOOP1: 
  
inc  rbx
  
cmp  rbx,[len]
  
jge  break
  
mov  r8,rbx
  
jmp  LOOP2

  

LOOP2:
    
inc r8
    
cmp r8,[len] 
    
jge LOOP1
    
mov rax,[array+8*rbx]
    
mov rcx,[array+8*r8]
    
cmp rax,rcx
    
jg  SWAP
    
jmp LOOP2




SWAP:
   
mov [array+8*rbx],rcx
   
mov [array+8*r8],rax
   
jmp LOOP2
 


break: 
   
leave
  
ret



main:
  
push rbp
  
  
call func

  
mov  rbx,-1
  
jmp  LOOP3



LOOP3:
  
inc  rbx
  
cmp  rbx,[len]
  
jge  EXIT

  
mov  rdi,fmt
  
mov  rsi,[array+8*rbx]
  
call printf
  
jmp  LOOP3




EXIT:
  
pop  rbp
  
mov  rax,0
  
ret

  
  

