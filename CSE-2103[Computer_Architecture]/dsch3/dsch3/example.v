// DSCH3
// 4/9/2016 11:56:32 PM
// example

module example( b,H,c,a,D,Cout,Sum);
 input b,H,c,a,D;
 output Cout,Sum;
 wire w4,w6,w7,w11,w12,w13,w14,;
 and #(16) and2_1(w4,H,b);
 and #(16) and2_2(w6,c,H);
 xor #(16) xor2_3(w7,w4,w6);
 xor #(16) xor2_4(Sum,w7,a);
 xor #(16) xor2_5(w11,a,D);
 or #(16) or2_6(w12,c,b);
 and #(16) and2_7(w13,w12,w11);
 and #(16) and2_8(w14,b,c);
 or #(16) or2_9(Cout,w13,w14);
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
