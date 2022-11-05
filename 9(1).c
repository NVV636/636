#include <stdio.h>
#include <stdlib.h>
int F(int N)
{
	if (N <= 1) return 0;
	else if (N == 2) return 1;
	else return F(N - 1) + F(N - 2);
}
int main()
{
	printf_s("Enter a number:\n");
	int n;
	scanf_s("%d", &n);
	int tmp = F(n);
	printf_s("%d", tmp);
	return 0;
}
