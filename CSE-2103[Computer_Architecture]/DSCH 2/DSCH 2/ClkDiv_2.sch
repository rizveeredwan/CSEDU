DSCH 2.6i
VERSION 4/28/2003 10:52:34 AM
BB(-70,-10,244,185)
SYM  #button1
BB(-69,56,-60,64)
TITLE -65 60  #button
MODEL 59
PROP                                                                                                                                                                                                            
REC(-68,57,6,6,r)
VIS 1
PIN(-60,60,0.000,0.000)Enable
LIG(-61,60,-60,60)
LIG(-69,64,-69,56)
LIG(-61,64,-69,64)
LIG(-61,56,-61,64)
LIG(-69,56,-61,56)
LIG(-68,63,-68,57)
LIG(-62,63,-68,63)
LIG(-62,57,-62,63)
LIG(-68,57,-62,57)
FSYM
SYM  #button2
BB(-69,111,-60,119)
TITLE -65 115  #button
MODEL 59
PROP                                                                                                                                                                                                            
REC(-68,112,6,6,r)
VIS 1
PIN(-60,115,0.000,0.000)Reset
LIG(-61,115,-60,115)
LIG(-69,119,-69,111)
LIG(-61,119,-69,119)
LIG(-61,111,-61,119)
LIG(-69,111,-61,111)
LIG(-68,118,-68,112)
LIG(-62,118,-68,118)
LIG(-62,112,-62,118)
LIG(-68,112,-62,112)
FSYM
SYM  #and2
BB(-25,135,10,155)
TITLE -13 146  #&
MODEL 402
PROP                                                                                                                                                                                                            
REC(0,10,0,0,)
VIS 0
PIN(-25,150,0.000,0.000)b
PIN(-25,140,0.000,0.000)a
PIN(10,145,0.090,0.140)s
LIG(-25,150,-17,150)
LIG(-17,135,-17,155)
LIG(3,145,10,145)
LIG(2,147,-1,151)
LIG(3,145,2,147)
LIG(2,143,3,145)
LIG(-1,139,2,143)
LIG(-6,136,-1,139)
LIG(-1,151,-6,154)
LIG(-6,154,-17,155)
LIG(-17,135,-6,136)
LIG(-25,140,-17,140)
VLG       and and2(out,a,b);
FSYM
SYM  #ClkBascT
BB(40,50,70,100)
TITLE 50 48  #ClkBascT
MODEL 6000
PROP                                                                                                                                                                                                            
REC(45,55,20,40,r)
VIS 5
PIN(40,60,0.000,0.000)T
PIN(40,80,0.000,0.000)~SClear
PIN(40,70,0.000,0.000)Reset
PIN(55,100,0.000,0.000)Clock
PIN(70,60,0.060,0.350)Q
PIN(70,70,0.060,0.070)ClkOut
LIG(40,60,45,60)
LIG(40,80,45,80)
LIG(40,70,45,70)
LIG(55,95,55,100)
LIG(65,60,70,60)
LIG(65,70,70,70)
LIG(45,55,45,95)
LIG(45,55,65,55)
LIG(65,55,65,95)
LIG(65,95,45,95)
VLG      module ClkBascT( T,~SClear,Reset,Clock,Q,ClkOut);
VLG       input T,~SClear,Reset,Clock;
VLG       output Q,ClkOut;
VLG       xor #(16) xor2(w6,Q,T);
VLG       and #(16) and2(ClkOut,Q,T);
VLG       dreg #(12) dreg1(Q,w9,w8,Reset,Clock);
VLG       and #(16) and2(w8,~SClear,w6);
VLG      endmodule
FSYM
SYM  #clock1
BB(-70,102,-55,108)
TITLE -65 105  #clock
MODEL 69
PROP   10.000 10.000                                                                                                                                                                                                        
REC(-68,103,6,4,r)
VIS 1
PIN(-55,105,1.000,0.140)Clock
LIG(-60,105,-55,105)
LIG(-65,103,-67,103)
LIG(-61,103,-63,103)
LIG(-60,102,-60,108)
LIG(-70,108,-70,102)
LIG(-65,107,-65,103)
LIG(-63,103,-63,107)
LIG(-63,107,-65,107)
LIG(-67,107,-69,107)
LIG(-67,103,-67,107)
LIG(-60,108,-70,108)
LIG(-60,102,-70,102)
FSYM
SYM  #inv
BB(185,165,220,185)
TITLE 200 175  #~
MODEL 101
PROP                                                                                                                                                                                                            
REC(0,0,0,0,)
VIS 0
PIN(185,175,0.000,0.000)in
PIN(220,175,0.030,0.070)out
LIG(185,175,195,175)
LIG(195,165,195,185)
LIG(195,165,210,175)
LIG(195,185,210,175)
LIG(212,175,212,175)
LIG(214,175,220,175)
VLG       not not1(out,in);
FSYM
SYM  #button3
BB(-69,146,-60,154)
TITLE -65 150  #button
MODEL 59
PROP                                                                                                                                                                                                            
REC(-68,147,6,6,r)
VIS 1
PIN(-60,150,0.000,0.000)~Clear
LIG(-61,150,-60,150)
LIG(-69,154,-69,146)
LIG(-61,154,-69,154)
LIG(-61,146,-61,154)
LIG(-69,146,-61,146)
LIG(-68,153,-68,147)
LIG(-62,153,-68,153)
LIG(-62,147,-62,153)
LIG(-68,147,-62,147)
FSYM
SYM  #Disp2
BB(90,-10,115,25)
TITLE 90 11  #digit
MODEL 89
PROP                                                                                                                                                                                                            
REC(95,-5,15,21,r)
VIS 2
PIN(95,25,0.000,0.000)Disp23
PIN(100,25,0.000,0.000)Disp22
PIN(105,25,0.000,0.000)Disp21
PIN(110,25,0.000,0.000)Disp20
LIG(90,-10,90,20)
LIG(115,-10,90,-10)
LIG(115,20,115,-10)
LIG(90,20,115,20)
LIG(95,20,95,25)
LIG(100,20,100,25)
LIG(105,20,105,25)
LIG(110,20,110,25)
FSYM
SYM  #light1
BB(238,160,244,174)
TITLE 240 174  #light
MODEL 49
PROP                                                                                                                                                                                                            
REC(239,161,4,4,r)
VIS 1
PIN(240,175,0.000,0.000)Equ2
LIG(243,166,243,161)
LIG(243,161,242,160)
LIG(239,161,239,166)
LIG(242,171,242,168)
LIG(241,171,244,171)
LIG(241,173,243,171)
LIG(242,173,244,171)
LIG(238,168,244,168)
LIG(240,168,240,175)
LIG(238,166,238,168)
LIG(244,166,238,166)
LIG(244,168,244,166)
LIG(240,160,239,161)
LIG(242,160,240,160)
FSYM
SYM  #nand2
BB(140,130,175,150)
TITLE 163 141  #&
MODEL 202
PROP                                                                                                                                                                                                           
REC(310,60,0,0,)
VIS 0
PIN(175,145,0.000,0.000)b
PIN(175,135,0.000,0.000)a
PIN(140,140,0.060,0.140)s
LIG(175,145,167,145)
LIG(167,130,167,150)
LIG(148,142,151,146)
LIG(147,140,148,142)
LIG(148,138,147,140)
LIG(151,134,148,138)
LIG(156,131,151,134)
LIG(151,146,156,149)
LIG(156,149,167,150)
LIG(167,130,156,131)
LIG(175,135,167,135)
LIG(143,140,140,140)
LIG(145,140,145,140)
VLG  nand nand2(out,a,b);
FSYM
SYM  #ClkBascT
BB(-10,50,20,100)
TITLE 0 48  #ClkBascT
MODEL 6000
PROP                                                                                                                                                                                                            
REC(-5,55,20,40,r)
VIS 5
PIN(-10,60,0.000,0.000)T
PIN(-10,80,0.000,0.000)~SClear
PIN(-10,70,0.000,0.000)Reset
PIN(5,100,0.000,0.000)Clock
PIN(20,60,0.060,0.280)Q
PIN(20,70,0.060,0.210)ClkOut
LIG(-10,60,-5,60)
LIG(-10,80,-5,80)
LIG(-10,70,-5,70)
LIG(5,95,5,100)
LIG(15,60,20,60)
LIG(15,70,20,70)
LIG(-5,55,-5,95)
LIG(-5,55,15,55)
LIG(15,55,15,95)
LIG(15,95,-5,95)
VLG      module ClkBascT( T,~SClear,Reset,Clock,Q,ClkOut);
VLG       input T,~SClear,Reset,Clock;
VLG       output Q,ClkOut;
VLG       xor #(16) xor2(w6,Q,T);
VLG       and #(16) and2(ClkOut,Q,T);
VLG       dreg #(12) dreg1(Q,w9,w8,Reset,Clock);
VLG       and #(16) and2(w8,~SClear,w6);
VLG      endmodule
FSYM
CNC(130 140)
CNC(-40 60)
CNC(-40 60)
CNC(-15 115)
CNC(5 105)
CNC(10 110)
CNC(105 60)
LIG(175,145,180,145)
LIG(5,100,5,105)
LIG(110,25,110,40)
LIG(-55,105,5,105)
LIG(-40,60,-40,165)
LIG(-40,60,-60,60)
LIG(180,145,180,165)
LIG(185,175,130,175)
LIG(-30,140,-25,140)
LIG(10,145,10,110)
LIG(-30,120,130,120)
LIG(-15,115,35,115)
LIG(-10,110,10,110)
LIG(105,60,180,60)
LIG(-10,80,-10,110)
LIG(140,140,130,140)
LIG(10,110,40,110)
LIG(30,60,40,60)
LIG(105,25,105,60)
LIG(130,120,130,140)
LIG(-10,60,-40,60)
LIG(-15,70,-15,115)
LIG(175,135,180,135)
LIG(20,70,30,70)
LIG(20,40,110,40)
LIG(-15,70,-10,70)
LIG(20,40,20,60)
LIG(-40,165,180,165)
LIG(130,140,130,175)
LIG(30,70,30,60)
LIG(35,70,35,115)
LIG(220,175,240,175)
LIG(-60,150,-25,150)
LIG(-60,115,-15,115)
LIG(180,60,180,135)
LIG(70,60,105,60)
LIG(40,80,40,110)
LIG(-30,120,-30,140)
LIG(55,100,55,105)
LIG(35,70,40,70)
LIG(5,105,55,105)
FFIG C:\Documents and Settings\Administrator\My Documents\Dsch2\Book on CMOS\ClkDiv_2.sch
