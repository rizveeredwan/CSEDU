DSCH 2.7a
VERSION 8/10/2004 6:43:37 PM
BB(-34,-15,104,85)
SYM  #xor2
BB(30,-15,65,5)
TITLE 47 -5  #^
MODEL 602
PROP                                                                                                                                                                                                           
REC(0,5,0,0,)
VIS 0
PIN(30,-10,0.000,0.000)a
PIN(30,0,0.000,0.000)b
PIN(65,-5,0.090,0.070)out
LIG(38,2,34,5)
LIG(42,2,38,5)
LIG(58,-5,65,-5)
LIG(57,-3,54,1)
LIG(58,-5,57,-3)
LIG(57,-7,58,-5)
LIG(54,-11,57,-7)
LIG(49,-14,54,-11)
LIG(54,1,49,4)
LIG(49,4,38,5)
LIG(38,-15,49,-14)
LIG(44,-2,42,2)
LIG(38,-15,42,-12)
LIG(42,-12,44,-8)
LIG(44,-8,45,-5)
LIG(45,-5,44,-2)
LIG(34,-15,38,-12)
LIG(38,-12,40,-8)
LIG(40,-8,41,-5)
LIG(41,-5,40,-2)
LIG(40,-2,38,2)
LIG(30,-10,39,-10)
LIG(30,0,39,0)
VLG  xor xor2(out,a,b);
FSYM
SYM  #xor2
BB(65,-10,100,10)
TITLE 82 0  #^
MODEL 602
PROP                                                                                                                                                                                                           
REC(0,0,0,0,)
VIS 0
PIN(65,-5,0.000,0.000)a
PIN(65,5,0.000,0.000)b
PIN(100,0,0.090,0.070)out
LIG(73,7,69,10)
LIG(77,7,73,10)
LIG(93,0,100,0)
LIG(92,2,89,6)
LIG(93,0,92,2)
LIG(92,-2,93,0)
LIG(89,-6,92,-2)
LIG(84,-9,89,-6)
LIG(89,6,84,9)
LIG(84,9,73,10)
LIG(73,-10,84,-9)
LIG(79,3,77,7)
LIG(73,-10,77,-7)
LIG(77,-7,79,-3)
LIG(79,-3,80,0)
LIG(80,0,79,3)
LIG(69,-10,73,-7)
LIG(73,-7,75,-3)
LIG(75,-3,76,0)
LIG(76,0,75,3)
LIG(75,3,73,7)
LIG(65,-5,74,-5)
LIG(65,5,74,5)
VLG  xor xor2(out,a,b);
FSYM
SYM  #or3
BB(60,35,100,65)
TITLE 75 55  #|
MODEL 503
PROP                                                                                                                                                                                                           
REC(5,0,0,0,)
VIS 0
PIN(60,40,0.000,0.000)a
PIN(60,50,0.000,0.000)b
PIN(60,60,0.000,0.000)c
PIN(100,50,0.120,0.070)s
LIG(60,60,74,60)
LIG(60,50,76,50)
LIG(60,40,74,40)
LIG(74,60,70,65)
LIG(85,61,80,64)
LIG(89,53,85,61)
LIG(80,36,85,39)
LIG(70,35,80,36)
LIG(90,50,89,53)
LIG(89,47,90,50)
LIG(70,65,80,64)
LIG(85,39,89,47)
LIG(70,35,74,40)
LIG(74,40,76,50)
LIG(76,50,74,60)
LIG(90,50,100,50)
VLG  or or3(s,a,b,c);
FSYM
SYM  #and2
BB(25,15,60,35)
TITLE 37 26  #&
MODEL 402
PROP                                                                                                                                                                                                           
REC(0,-15,0,0,)
VIS 0
PIN(25,30,0.000,0.000)b
PIN(25,20,0.000,0.000)a
PIN(60,25,0.090,0.070)s
LIG(25,30,33,30)
LIG(33,15,33,35)
LIG(53,25,60,25)
LIG(52,27,49,31)
LIG(53,25,52,27)
LIG(52,23,53,25)
LIG(49,19,52,23)
LIG(44,16,49,19)
LIG(49,31,44,34)
LIG(44,34,33,35)
LIG(33,15,44,16)
LIG(25,20,33,20)
VLG  and and2(out,a,b);
FSYM
SYM  #and2
BB(25,40,60,60)
TITLE 37 51  #&
MODEL 402
PROP                                                                                                                                                                                                           
REC(0,0,0,0,)
VIS 0
PIN(25,55,0.000,0.000)b
PIN(25,45,0.000,0.000)a
PIN(60,50,0.090,0.070)s
LIG(25,55,33,55)
LIG(33,40,33,60)
LIG(53,50,60,50)
LIG(52,52,49,56)
LIG(53,50,52,52)
LIG(52,48,53,50)
LIG(49,44,52,48)
LIG(44,41,49,44)
LIG(49,56,44,59)
LIG(44,59,33,60)
LIG(33,40,44,41)
LIG(25,45,33,45)
VLG  and and2(out,a,b);
FSYM
SYM  #and2
BB(25,65,60,85)
TITLE 37 76  #&
MODEL 402
PROP                                                                                                                                                                                                           
REC(0,5,0,0,)
VIS 0
PIN(25,80,0.000,0.000)b
PIN(25,70,0.000,0.000)a
PIN(60,75,0.090,0.070)s
LIG(25,80,33,80)
LIG(33,65,33,85)
LIG(53,75,60,75)
LIG(52,77,49,81)
LIG(53,75,52,77)
LIG(52,73,53,75)
LIG(49,69,52,73)
LIG(44,66,49,69)
LIG(49,81,44,84)
LIG(44,84,33,85)
LIG(33,65,44,66)
LIG(25,70,33,70)
VLG  and and2(out,a,b);
FSYM
SYM  #button1
BB(-34,-14,-25,-6)
TITLE -30 -10  #button
MODEL 59
PROP                                                                                                                                                                                                           
REC(-33,-13,6,6,r)
VIS 1
PIN(-25,-10,0.000,0.000)A
LIG(-26,-10,-25,-10)
LIG(-34,-6,-34,-14)
LIG(-26,-6,-34,-6)
LIG(-26,-14,-26,-6)
LIG(-34,-14,-26,-14)
LIG(-33,-7,-33,-13)
LIG(-27,-7,-33,-7)
LIG(-27,-13,-27,-7)
LIG(-33,-13,-27,-13)
FSYM
SYM  #button2
BB(-34,-4,-25,4)
TITLE -30 0  #button
MODEL 59
PROP                                                                                                                                                                                                           
REC(-33,-3,6,6,r)
VIS 1
PIN(-25,0,0.000,0.000)B
LIG(-26,0,-25,0)
LIG(-34,4,-34,-4)
LIG(-26,4,-34,4)
LIG(-26,-4,-26,4)
LIG(-34,-4,-26,-4)
LIG(-33,3,-33,-3)
LIG(-27,3,-33,3)
LIG(-27,-3,-27,3)
LIG(-33,-3,-27,-3)
FSYM
SYM  #button3
BB(-34,6,-25,14)
TITLE -30 10  #button
MODEL 59
PROP                                                                                                                                                                                                           
REC(-33,7,6,6,r)
VIS 1
PIN(-25,10,0.000,0.000)C
LIG(-26,10,-25,10)
LIG(-34,14,-34,6)
LIG(-26,14,-34,14)
LIG(-26,6,-26,14)
LIG(-34,6,-26,6)
LIG(-33,13,-33,7)
LIG(-27,13,-33,13)
LIG(-27,7,-27,13)
LIG(-33,7,-27,7)
FSYM
SYM  #light1
BB(98,-15,104,-1)
TITLE 100 -1  #light
MODEL 49
PROP                                                                                                                                                                                                           
REC(99,-14,4,4,r)
VIS 1
PIN(100,0,0.000,0.000)S
LIG(103,-9,103,-14)
LIG(103,-14,102,-15)
LIG(99,-14,99,-9)
LIG(102,-4,102,-7)
LIG(101,-4,104,-4)
LIG(101,-2,103,-4)
LIG(102,-2,104,-4)
LIG(98,-7,104,-7)
LIG(100,-7,100,0)
LIG(98,-9,98,-7)
LIG(104,-9,98,-9)
LIG(104,-7,104,-9)
LIG(100,-15,99,-14)
LIG(102,-15,100,-15)
FSYM
SYM  #light2
BB(98,35,104,49)
TITLE 100 49  #light
MODEL 49
PROP                                                                                                                                                                                                           
REC(99,36,4,4,r)
VIS 1
PIN(100,50,0.000,0.000)Cout
LIG(103,41,103,36)
LIG(103,36,102,35)
LIG(99,36,99,41)
LIG(102,46,102,43)
LIG(101,46,104,46)
LIG(101,48,103,46)
LIG(102,48,104,46)
LIG(98,43,104,43)
LIG(100,43,100,50)
LIG(98,41,98,43)
LIG(104,41,98,41)
LIG(104,43,104,41)
LIG(100,35,99,36)
LIG(102,35,100,35)
FSYM
CNC(25 -10)
CNC(20 0)
CNC(20 30)
CNC(15 10)
CNC(15 55)
CNC(5 -10)
LIG(60,25,60,40)
LIG(60,60,60,75)
LIG(-25,-10,5,-10)
LIG(-25,0,20,0)
LIG(-25,10,15,10)
LIG(65,5,65,10)
LIG(25,-10,25,20)
LIG(25,-10,30,-10)
LIG(20,0,20,30)
LIG(20,0,30,0)
LIG(20,30,25,30)
LIG(20,30,20,45)
LIG(20,45,25,45)
LIG(15,10,15,55)
LIG(15,10,65,10)
LIG(15,55,25,55)
LIG(15,55,15,70)
LIG(15,70,25,70)
LIG(5,-10,5,80)
LIG(5,-10,25,-10)
LIG(5,80,25,80)
FFIG C:\Documents and Settings\All Users\Documents\Softwares\VLSI Softwares\Export dsch2\adderjar.sch
