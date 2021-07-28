// DSCH3
// 4/11/2016 7:57:49 AM
// E:\Computure Architecture Lab\dsch3\dsch3\Ccell.sch

module Ccell( xi,xi_1,D,H);
 input xi,xi_1;
 output D,H;
 wire w5,;
 xor #(16) xor2_1(H,xi,xi_1);
 not #(10) inv_2(w5,xi_1);
 and #(16) and2_3(D,xi,w5);
endmodule

// Simulation parameters in Verilog Format
always
#1000 x(i)=~x(i);
#2000 x(i-1)=~x(i-1);

// Simulation parameters
// x(i) CLK 10 10
// x(i-1) CLK 20 20
