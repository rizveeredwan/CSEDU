// DSCH3
// 4/11/2016 9:47:24 AM
// E:\Computure Architecture Lab\dsch3\dsch3\Bcell.sch

module Bcell( b,H,c,a,D,sum,Carry,Hout,
 Dout);
 input b,H,c,a,D;
 output sum,Carry,Hout,Dout;
 wire w4,w6,w7,w11,w12,w13,w14,w16;
 wire w18,;
 and #(16) and2_1(w4,H,b);
 and #(16) and2_2(w6,c,H);
 xor #(16) xor2_3(w7,w4,w6);
 xor #(16) xor2_4(sum,w7,a);
 xor #(16) xor2_5(w11,a,D);
 or #(16) or2_6(w12,c,b);
 and #(16) and2_7(w13,w12,w11);
 and #(16) and2_8(w14,b,c);
 or #(16) or2_9(Carry,w13,w14);
 not #(10) inv_10(w16,H);
 not #(10) inv_11(Hout,w16);
 not #(10) inv_12(w18,D);
 not #(10) inv_13(Dout,w18);
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
