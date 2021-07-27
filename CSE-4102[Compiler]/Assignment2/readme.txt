1. Commands 
	lex Assignment_2_Roll_09.l
	gcc lex.yy.c -o out -ll
	./out
   to make the process easier I have written a script Assignment_2.script. 
   Just running it will perform the whole process.
2. Input and Output 
	To give any type of input just need to write the input in
	input.in file and corresponding output will be saved into
	output.out file. to give input I have considered delimeter as space (" ")
	so to differenciate among valid expression please separate the expressions'
	tokens with space.like Ad1 = 5 +3 
	output will be
	Id Ad1
	AssignOp =
	+3 Signed
