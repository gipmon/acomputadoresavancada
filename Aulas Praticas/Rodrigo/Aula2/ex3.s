;Adapted from problem 3.2 in H&P's book for running on WinDLX 
      .data
      .align 4
_a:   .double 1.0,10.0,100.0,1000.0
_b:   .double 1.0,2.0,3.0,4.0
      .text
      .global main
main:
      lhi r2, (_a >> 16)
      addui r2, r2, (_a & 0xffff)
      lhi r3, (_b >> 16)
      addui r3, r3, (_b & 0xffff)
      addui r4, r2, 32
loop:
      ld f0, 0(r2)
      ld f4, 0(r3)
      multd f0, f0, f4
      addd f2, f0, f2
      addui r2, r2, 8
      addui r3, r3, 8
      sub r5, r4, r2
      bnez r5, loop
      trap 0
