#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN_OF_FILENAME 101
int main(int argc, char* argv[])
{
	FILE* input;
	int A = atoi(argv[1]);
	int B = atoi(argv[2]);
	int C = atoi(argv[3]);
	char* F = argv[4];
	int linesCount = 1;
	char c;
	c = fgetc(input);
	while (c != EOF)
	{
		c = fgetc(input);
		if (c == '\n')
			linesCount++;
	}
	printf_s("%d points:\n", linesCount);
	int** arr = (int**)malloc(linesCount * sizeof(int*));
	for (int i = 0; i < linesCount; i++)
	{
		arr[i] = (int*)malloc(2 * sizeof(int));
	}
	fseek(input, 0, 0);
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf_s(input, "%d ", &arr[i][j]);
		}
	}
	int x, y;
	for (int i = 0; i < linesCount; i++)
	{
		x = *arr[i];
		y =(*arr[i] + 1);
		if ((A * x) + (B * y) + C == 0)
		{
			printf_s("%d %d: YES\n", x, y);
		}
		else
		{
			printf_s("%d %d: NO\n", x, y);
		}
	}
	for (int i = 0; i < linesCount; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			free(arr[i][j]);
		}
	}
	free(arr);
}
