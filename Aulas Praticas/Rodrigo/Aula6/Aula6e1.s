    .data
    .align 4
_x: .float 1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0
_y: .float 10.0,20.0,30.0,40.0,50.0,60.0,70.0,80.0
_z: .space 32
    .align 4
    .text
    .global _main
_main:
    lhi   r3, (_y>>16)
    addui r3, r3, (_y&0xffff)
    lhi   r4, (_x>>16)
    addui r4, r4, (_x&0xffff)
    lhi   r5, (_z>>16)
    addui r5, r5, (_z&0xffff)
    addui r6, r3, 32
L5:
    lf    f4, 0(r3)
    lf    f5, 0(r4)
    addf  f4, f4, f5
    sf    0(r5), f4

    lf    f6, 4(r3)
    lf    f7, 4(r4)
    addf  f6, f6, f7
    sf    4(r5), f6

    lf    f8, 8(r3)
    lf    f9, 8(r4)
    addf  f8, f8, f9
    sf    8(r5), f8

    lf    f10, 12(r3)
    lf    f11, 12(r4)
    addf  f10, f10, f11
    sf    12(r5), f10
    
    add   r3, r3, 16
    add   r4, r4, 16
    add   r5, r5, 16
    sge   r1, r3, r6
    beqz  r1, L5
    trap  0
