// DSCH3
// 4/11/2016 9:21:55 PM
// E:\Computure Architecture Lab\dsch3\dsch3\B.sch

module B( b,H,c,a,D,Sum,Carry);
 input b,H,c,a,D;
 output Sum,Carry;
 wire w4,w6,w7,w11,w12,w13,w14,;
 and #(16) and2_1(w4,H,b);
 and #(16) and2_2(w6,c,H);
 xor #(16) xor2_3(w7,w4,w6);
 xor #(16) xor2_4(Sum,w7,a);
 xor #(16) xor2_5(w11,a,D);
 or #(16) or2_6(w12,c,b);
 and #(16) and2_7(w13,w12,w11);
 and #(16) and2_8(w14,b,c);
 or #(16) or2_9(Carry,w13,w14);
endmodule

// Simulation parameters in Verilog Format
always
#1000 b=~b;
#2000 H=~H;
#4000 c=~c;
#8000 a=~a;
#16000 D=~D;

// Simulation parameters
// b CLK 10 10
// H CLK 20 20
// c CLK 40 40
// a CLK 80 80
// D CLK 160 160
