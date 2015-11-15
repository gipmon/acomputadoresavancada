    .data
a:  .double 3.14159265358979
x:  .double 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
    .double  17,18,19,20,21,22,23,24,25,26
xtop:  .double  27

y:   .double 10,20,30,40,50,60,70,80,90,100,110,120,130,140 .double 150,160,170,180,190,200,210,220,230,240,250,260
ytop:.double  270
     .text

     ld f8, a(r0)
     add r5, r0, a
     add r2, r0, xtop
     add r3, r0, ytop
loop:
     ld f10, 0(r2)
     ld f4, 0(r3)
     multd f2, f10, f8
     addd f6, f2, f4
     sd 0(r2), f6
     sub r3, r3, 8
     sub r2, r2, 8
     sub r4, r2, r5
     bnez r4, loop
     trap 0
