#include <stdio.h>
#include <stdlib.h>
#include "Oper.h"
int main(int argc, char* argv)
{
	unsigned T = atoi(argv[1]);
	unsigned Q = atoi(argv[2]);
	if (T > 84)
	{
		printf_s("T is very big number\n");
		exit(1);
	}
	if (Q > 1000000)
	{
		printf_s("Q is very big number\n");
		exit(1);
	}
	unsigned a = A(T);
	printf_s("%u\n", a);
	unsigned b = B(Q);
	printf_s("%u\n", b);
	unsigned c = C(T);
	printf_s("%u\n", c);
	unsigned d = D(Q);
	printf_s("%u\n", d);
	return 0;
}
