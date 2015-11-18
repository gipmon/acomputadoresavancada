// ****************************************************************************
// ACA - Lesson 7
//
// sumarray.cpp
// ****************************************************************************

#include <stdio.h>
#include <time.h>

#define SIZE   (1000*4)
#define REPEAT (100000)

/**
 * sumarray using mmx instructions
 * */
void sumarrayMMX( int *a, int *b, int *c, int size )
{
	for (int i=0; i < size; i += 2)
	{
		__asm__ volatile
			( // instruction             comment
			  "\n movq    %1,%%mm0"
			  "\n movq    %2,%%mm1#"
			  "\n paddd   %%mm0,%%mm1"
			  "\n movq    %%mm1,%0"
			  : "=m" (c[i])      // %0
			  : "m"  (a[i]),     // %1
			    "m"  (b[i])      // %2
			);
	}
	__asm__("emms" : : );	// Exit MMX Machine State
}

/**
 * sumarray using sse instructions
 * */
void sumarraySSE( int *a, int *b, int *c, int size )
{
	for (int i=0; i < size; i += 4)
	{
		__asm__ volatile
			( // instruction             comment
			  "\n movdqa    %1,%%xmm0"
			  "\n movdqa    %2,%%xmm1#"
			  "\n paddd   %%xmm0,%%xmm1"
			  "\n movdqa    %%xmm1,%0"
			  : "=m" (c[i])      // %0
			  : "m"  (a[i]),     // %1
			    "m"  (b[i])      // %2
			);
	}
	__asm__("emms" : : );	// Exit SSE Machine State
}

/**
 * sumarray using classic code (only x86 instructions)
 * */
void sumarrayX86( int *a, int *b, int *c, int size )
{
	for (int i=0;i<size;i++)
	{
		c[i]=a[i]+b[i];
	}
}

/**
 * print array
 * */
void printArray(const char *name, int *a, int size)
{
	printf("%s:\t", name);
	for (int i=0; i < size; i++)
	{
		printf("%08X ",a[i]);
	}
	printf("\n");
}

/**
 * init arrays
 * */
void initArrays( int *a, int *b, int *c, int size )
{
	for (int i=0; i < size; i++)
	{
		a[i] = (i << 16) + 1 + ((i & 0xFF) << 9);
		b[i] = 0xFCF8 + (i & 0x0F);
		c[i] = 0;
	}
}

/**
 * test summation functions
 */
int main(void)
{
	int a[SIZE] __attribute__((aligned(16)));
	int b[SIZE] __attribute__((aligned(16)));
	int c[SIZE] __attribute__((aligned(16)));
	int i, n, nelemsum;
	clock_t init, end;

//	printf("Recall: sizeof(int) = %ld bits\n", sizeof(int) * 8);

	//initialize arrays
	nelemsum=SIZE;
	initArrays(a, b, c, nelemsum);

	printf("-------------------------------------------------------------------------------------------\n");
	printArray("A", a, 12);
	printArray("B", b, 12);
	printf("-------------------------------------------------------------------------------------------\n");

	// test MMX code
	init = clock();
	for(n = 0;n < REPEAT; n++)
		sumarrayMMX(a, b, c, nelemsum);
	end = clock();

	printArray("R_MMX", c, 12);
	printf("\nExec time [MMX] = %f [s]\n", (end-init)/(CLOCKS_PER_SEC*1.0));
	printf("-------------------------------------------------------------------------------------------\n");

	// test SSE code
	init = clock();
	for(n = 0; n < REPEAT; n++)
		sumarraySSE(a, b, c, nelemsum);
	end = clock();

	printArray("R_SSE", c, 12);
	printf("\nExec time [SSE] = %f [s]\n", (end-init)/(CLOCKS_PER_SEC*1.0));
	printf("-------------------------------------------------------------------------------------------\n");

	// test classic code (x86 instructions only)
	init = clock();
	for(n = 0; n < REPEAT; n++)
		sumarrayX86(a, b, c, nelemsum);
	end = clock();

	printArray("R_x86", c,12);
	printf("\nExec time [x86] = %f [s]\n", (end-init)/(CLOCKS_PER_SEC*1.0));
	printf("-------------------------------------------------------------------------------------------\n");

	printf("\n");
}
