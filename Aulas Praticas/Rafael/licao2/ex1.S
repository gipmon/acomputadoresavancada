
      .data
vec:  .word 1, 5, 42, 32, 1, 2, 3, 4
      .text
      .global main
main:
      ; r1 - res
      ; la ... of vec address
      lhi r2, vec >> 16 ; parte alta do regiso tipo load upper immidiate
      addui r2, r2, vec & 0xFFFF ;  agora é a parte mais em baixo
      addui r4, r2, 32 ; 4 em 4 bytes

      xor r1, r1, r1 ; res = 0
      ; r2 - p
      ; r4 - last

do:
      lw r3, 0(r2) ; r3 = *p
      add r1, r1, r3 ; res += *p
      addui r2, r2, 4 ; p++
      sub r5, r4, r2
      bnez r5, do
      trap 0
