section .data
   a : dq 0
   b : dq 1
   n : dq 30
  fmt: db  "%ld th Fibbonacci = %ld",10,0


section .bss
   array resq 64


section .text
   extern printf
   global main


findfib:
   push rbp

   cmp  rbx,[n]
   JG   break
   
   mov  rax,[a]
   mov  rdx,[b]
   add  rax,rdx
   mov  [a],rdx
   mov  [b],rax
   
   mov  rdi,fmt
   mov  rsi,rbx
   mov  rdx,[b]
   mov  [array+rbx*8],rdx
   call printf

   add  rbx,1

   call findfib
   pop  rbp
   ret

break:
  pop rbp
  ret

finish:
   pop rbp
   mov rax,0
   ret

print_array:
   cmp rbx,-1
   JE  finish
   mov rdi,fmt
   mov rsi,rbx
   mov rdx,[array+8*rbx]
   call printf
   dec  rbx
   JMP print_array
       

main:
  push rbp
  mov rbp,rsp
  
  mov rdx,[a]
  mov [array],rdx
  
  mov rdx,[b]
  mov [array+1*8],rdx
  
  mov rbx,2
  call findfib

  mov rbx,[n]
  JMP print_array
   
  pop rbp
  mov rax,0
  ret

