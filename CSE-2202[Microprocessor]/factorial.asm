
;Redwan Ahmed Rizvee
;Roll - 09
;Problem find factorial of a number



section .data
    
x   : dq  5
    
fmt : db  "fact(%ld) = %ld",10,0


section .text
    
extern printf
    
global main




factorial:
    
push rbp
    
cmp  rdi,1
    
JE   break
    
imul rax,rdi
    
dec  rdi
    
call factorial
    
pop rbp 
    
ret



break:
    
pop rbp 
    
ret




main:
    
push  rbp
    
mov   rbp,rsp
    
mov   rdi,[x]
    
mov   rax,1
    
call  factorial
    
mov   rdi,fmt
    
mov   rsi,[x]
    
mov   rdx,rax
    
call printf
    
pop rbp
    
mov rax,0
    
ret

