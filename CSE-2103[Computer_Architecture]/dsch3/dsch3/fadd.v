// DSCH3
// 3/3/2006 1:15:37 PM
// D:\Documents and Settings\AhsanReza\Desktop\vlsi simulator\dsch3\fadd.sch

module fadd( C,B,A,Carry,Sum);
 input C,B,A;
 output Carry,Sum;
 wire w5,w6,w8,w10;
 xor #(16) xor2_1(w5,A,B);
 nand #(16) nand2_2(w6,A,C);
 nand #(16) nand2_3(w8,B,A);
 xor #(16) xor2_4(Sum,w5,C);
 nand #(16) nand3_5(Carry,w8,w10,w6);
 nand #(16) nand2_6(w10,B,C);
endmodule

// Simulation parameters in Verilog Format
always
#1000 C=~C;
#2000 B=~B;
#4000 A=~A;

// Simulation parameters
// C CLK 10 10
// B CLK 20 20
// A CLK 40 40
