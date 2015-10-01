		.data
vec:	.word 1, 5, 9, 32, 2, 5, 7, 20
		.text
		.global main

main:
		;r1 -> res, r2->p, r4 ->last
		lhi r2, vec >> 16 ;shift para obter apenas 16 bits
		addui r2,r2,vec & 0xFFFF ;fica-se so com os 16 menos significativos int*p = vec
		addui r4,r2, 32 ; int *last = vec + 8, 8*4=32
		xor r1,r1,r1 ; res = 0

do:
		lw r3, 0(r2) ;r3 = *p
		add r1,r1,r3 ;res += *p
		addui r2,r2,4 ;p++
		sub r5,r4,r2
		bnez r5, do
		trap 0