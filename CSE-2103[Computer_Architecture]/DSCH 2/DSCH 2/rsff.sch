DSCH 2.7a
VERSION 3/15/2004 3:58:46 PM
BB(-9,-10,94,50)
SYM  #nor2
BB(35,-5,70,15)
TITLE 55 5  #|
MODEL 302
PROP                                                                                                                                                                                                           
REC(0,0,0,0,)
VIS 0
PIN(35,0,0.000,0.000)a
PIN(35,10,0.000,0.000)b
PIN(70,5,0.090,0.140)s
LIG(35,10,48,10)
LIG(47,12,43,15)
LIG(62,7,59,11)
LIG(63,5,62,7)
LIG(62,3,63,5)
LIG(59,-1,62,3)
LIG(54,-4,59,-1)
LIG(59,11,54,14)
LIG(54,14,43,15)
LIG(43,-5,54,-4)
LIG(49,8,47,12)
LIG(43,-5,47,-2)
LIG(47,-2,49,2)
LIG(49,2,50,5)
LIG(50,5,49,8)
LIG(35,0,48,0)
LIG(67,5,70,5)
LIG(65,5,65,5)
VLG  nor nor2(s,a,b);
FSYM
SYM  #nor2
BB(35,30,70,50)
TITLE 55 40  #|
MODEL 302
PROP                                                                                                                                                                                                           
REC(0,0,0,0,)
VIS 0
PIN(35,35,0.000,0.000)a
PIN(35,45,0.000,0.000)b
PIN(70,40,0.090,0.140)s
LIG(35,45,48,45)
LIG(47,47,43,50)
LIG(62,42,59,46)
LIG(63,40,62,42)
LIG(62,38,63,40)
LIG(59,34,62,38)
LIG(54,31,59,34)
LIG(59,46,54,49)
LIG(54,49,43,50)
LIG(43,30,54,31)
LIG(49,43,47,47)
LIG(43,30,47,33)
LIG(47,33,49,37)
LIG(49,37,50,40)
LIG(50,40,49,43)
LIG(35,35,48,35)
LIG(67,40,70,40)
LIG(65,40,65,40)
VLG  nor nor2(s,a,b);
FSYM
SYM  #light2
BB(88,25,94,39)
TITLE 90 39  #light
MODEL 49
PROP                                                                                                                                                                                                           
REC(89,26,4,4,r)
VIS 1
PIN(90,40,0.000,0.000)Q'
LIG(93,31,93,26)
LIG(93,26,92,25)
LIG(89,26,89,31)
LIG(92,36,92,33)
LIG(91,36,94,36)
LIG(91,38,93,36)
LIG(92,38,94,36)
LIG(88,33,94,33)
LIG(90,33,90,40)
LIG(88,31,88,33)
LIG(94,31,88,31)
LIG(94,33,94,31)
LIG(90,25,89,26)
LIG(92,25,90,25)
FSYM
SYM  #button2
BB(1,41,10,49)
TITLE 5 45  #button
MODEL 59
PROP                                                                                                                                                                                                           
REC(2,42,6,6,r)
VIS 1
PIN(10,45,0.000,0.000)S
LIG(9,45,10,45)
LIG(1,49,1,41)
LIG(9,49,1,49)
LIG(9,41,9,49)
LIG(1,41,9,41)
LIG(2,48,2,42)
LIG(8,48,2,48)
LIG(8,42,8,48)
LIG(2,42,8,42)
FSYM
SYM  #light1
BB(88,-10,94,4)
TITLE 90 4  #light
MODEL 49
PROP                                                                                                                                                                                                           
REC(89,-9,4,4,r)
VIS 1
PIN(90,5,0.000,0.000)Q
LIG(93,-4,93,-9)
LIG(93,-9,92,-10)
LIG(89,-9,89,-4)
LIG(92,1,92,-2)
LIG(91,1,94,1)
LIG(91,3,93,1)
LIG(92,3,94,1)
LIG(88,-2,94,-2)
LIG(90,-2,90,5)
LIG(88,-4,88,-2)
LIG(94,-4,88,-4)
LIG(94,-2,94,-4)
LIG(90,-10,89,-9)
LIG(92,-10,90,-10)
FSYM
SYM  #button1
BB(-9,-4,0,4)
TITLE -5 0  #button
MODEL 59
PROP                                                                                                                                                                                                           
REC(-8,-3,6,6,r)
VIS 1
PIN(0,0,0.000,0.000)R
LIG(-1,0,0,0)
LIG(-9,4,-9,-4)
LIG(-1,4,-9,4)
LIG(-1,-4,-1,4)
LIG(-9,-4,-1,-4)
LIG(-8,3,-8,-3)
LIG(-2,3,-8,3)
LIG(-2,-3,-2,3)
LIG(-8,-3,-2,-3)
FSYM
CNC(80 5)
CNC(75 40)
LIG(35,45,10,45)
LIG(70,5,80,5)
LIG(75,30,35,30)
LIG(70,40,75,40)
LIG(35,0,0,0)
LIG(75,30,75,40)
LIG(75,40,90,40)
LIG(35,35,25,35)
LIG(25,35,25,20)
LIG(25,20,80,20)
LIG(80,20,80,5)
LIG(80,5,90,5)
LIG(35,30,35,10)
FFIG C:\Export dsch2\RSFF.sch
