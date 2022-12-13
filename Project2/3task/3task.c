#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	if (N == 1 && M == 1) return 0;
	int S;
	S = N - 1 + N * (M - 1);
	printf_s("%d", S);
	return 0;
}