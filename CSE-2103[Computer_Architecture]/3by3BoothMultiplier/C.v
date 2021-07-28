// DSCH3
// 4/11/2016 9:25:08 PM
// E:\Computure Architecture Lab\dsch3\dsch3\C.sch

module C( xi,xi_1,D,H);
 input xi,xi_1;
 output D,H;
 wire w6;
 xor #(16) xor2_1(H,xi,xi_1);
 not #(10) inv_2(w6,xi_1);
 and #(16) and2_3(D,xi,w6);
endmodule

// Simulation parameters in Verilog Format
always
#1000 xi=~xi;
#2000 x(i-1)=~x(i-1);

// Simulation parameters
// xi CLK 10 10
// x(i-1) CLK 20 20
