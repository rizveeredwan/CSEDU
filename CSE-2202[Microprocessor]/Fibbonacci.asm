section .data
   a : dq 0
   b : dq 1
   n : dq 30
  fmt: db  "%ld th Fibbonacci = %ld",10,0


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
   call printf

   add  rbx,1

   call findfib
   pop  rbp
   ret

break:
  pop rbp
  ret
   

main:
  push rbp
  mov rbp,rsp
  

  mov rdi,fmt
  mov rsi,1
  mov rdx,[a]
  call printf ;1st Fib

  mov rdi,fmt
  mov rsi,2
  mov rdx,[b]
  call printf; 2nd Fib
  
  mov rbx,3
  call findfib
   
  pop rbp
  mov rax,0
  ret

