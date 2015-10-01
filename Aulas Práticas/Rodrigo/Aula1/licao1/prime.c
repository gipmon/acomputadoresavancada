
#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
    unsigned long i,p,nprimes;
    int prime;
    double aux;
    clock_t ini, end;

    ini=clock();
    nprimes=1; /* 2 is prime */
    for(p=3;p<1e6;p+=2)
    {
       prime=1; aux=sqrt(p);
       for(i=3;i<=aux && prime;i++)
           if(p%i==0) prime=0;
       if(prime) nprimes++;
    }
    printf("Number of primes = %ld\n",nprimes);
    end=clock();
    printf("CPU time = %f\n",(end-ini)/(1.0*CLOCKS_PER_SEC));

    return 0;
}
          
          


