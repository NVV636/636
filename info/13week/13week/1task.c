#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv)
{
	int k = atoi(argv[1]);
	if (k > 1000000)
	{
		printf_s("Write correct number\n");
		exit(1);
	}
	int Array[8] = { 0 };
	for (int i = 0; i < k; i++)
	{
		int randNum = rand() % (RAND_MAX + 1);
		if (randNum % 10 != 0 && randNum % 10 != 1) Array[randNum % 10 - 2]++;
	}
	for (int i = 0; i < 8; i++)
	{
		printf_s("%d: ", i + 2);
		for (int j = 0; j < Array[i]; j++)
		{
			printf_s("|");
		}
		printf_s("\n");
	}
	return 0;
}
