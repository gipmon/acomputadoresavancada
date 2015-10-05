        .text

main:
        multf f2,f4,f5
        addf   f2,f3,f4
        multf  f6,f6,f6
        addf   f1,f3,f5
        addf   f2,f3,f4

        trap   0
