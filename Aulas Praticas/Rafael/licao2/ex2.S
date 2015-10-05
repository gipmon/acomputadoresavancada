
     ;Adapted from problem 3.1 in H&P's book to run on WinDLX
          .data
          .align 4
_a:       .word1,10,100,2,4,8,-1,-10
          .text
          .global main
main:
          lhi r2,(_a>>16) ;r2=(_a>>16)<<16
          addui r2, r2,(_a & 0xffff)
          addui r3, r2, 32

     loop:
          lw     r1, 0(r2)
          addui  r2, r2, 4
          addi   r1, r1, 1
          sub    r4, r3, r2
          sw     -4(r2), r1
          bnez   r4, loop

          trap   0
