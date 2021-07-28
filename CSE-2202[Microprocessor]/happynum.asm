section .data
   a : dq  78
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
   
   mov  rax,[a]
   mul  rax
   
   leave
   ret


main:
   push  rbp
   
   call square_root
   mov  rdi,fmt
   mov  rsi,rax
   call printf

   pop rbp
   mov rax,0
   ret 
