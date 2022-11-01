#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define COUNT_BITS 32
#define MAX_NAME_FILE 101
void PrintSumNum(int num)// сумма цифр числа
{
	int sum = 0;
	while (abs(num) > 0)
	{
		sum += num % 10;
		num /= 10;
	}
	printf_s("%d\n", abs(sum));
}
int countbindig(int num)//число двоичных разрядов
{
	int tmp = 0;
	while (abs(num) != 0)
	{
		num /= 2;
		tmp++;
	}
	return tmp;
}
int* BinNum(int num)//преобразование в двоичный код
{
	int absNum = abs(num);//6
	int CountBinDig = countbindig(num);//6 110
	int* binnum = (int*)calloc(CountBinDig, sizeof(int));//3
	if (!(binnum))
	{
		printf_s("MEM_ALL_ERR");
		exit(1);
	}
	for (int i = CountBinDig - 1; i >= 0; i--)
	{
		if (abs(num) % 2 == 0)
		{
			binnum[i] = 0;
		}
		else
		{
			binnum[i] = 1;
		}
		absNum /= 2;
	}
	return binnum;
}
void shiftinmemory(int* IntArrayWithZeros, int* DoubleNum, int num)
{
	int tmp = countbindig(num);
	for (int i = 0; i < tmp; i++)
	{
		IntArrayWithZeros[i + COUNT_BITS - tmp] = DoubleNum[i];
	}
	if (num < 0)
	{
		for (int i = 0; i < COUNT_BITS; i++)
		{
			if (IntArrayWithZeros[i] == 0)
			{
				IntArrayWithZeros[i] = 1;
				break;
			}
			else
			{
				IntArrayWithZeros[i] = 0;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	char* inputfile = argv[1];
	char* outputfile = argv[2];
	if (strlen(inputfile) >= MAX_NAME_FILE)
	{
		printf_s("TETYA LUSYA, NAME INPUT FILE VERY BIG");
		exit(1);
	}
	if (strlen(outputfile) >= MAX_NAME_FILE)
	{
		printf_s("TETYA LUSYA, NAME OUTPUT FILE VERY BIG");
		exit(1);
	}
	FILE* input, * output;
	if (fopen_s(&input, "input.txt", "r"))
	{ 
		printf_s("TETYA LUSYA, NOT OPEN FILE");
		_fcloseall();
		exit(1);
	}
	if (fopen_s(&output, "output.txt", "w"))
	{
		printf_s("TETYA LUSYA, NOT OPEN FILE");
		_fcloseall();
		exit(1);
	}
	int N;
	if (!(fscanf_s(input, "%d", &N)))
	{
		printf_s("TETYA LUSYA, NO NUMBERS IN FILE");
		exit(1);
	}
	PrintSumNum(N);
	printf_s("%d\n", N);
	char* numN = (char*)malloc(13 * sizeof(char));
	char* IntMin = "-2147483648";//INT_MIN из limits.h
	char* IntMax = "2147483647";//INT_MAX из limits.h
	if (fgets(numN, 13, input))
	{
		if (numN[0] == '-')
		{
			if (strlen(IntMin) < strlen(numN))
			{
				printf_s("TETYA LUSYA, VERY SMALL NUMBER");
				exit(1);
			}
			else if (strlen(IntMin) == strlen(numN))
			{
				for (int i = 1; i < strlen(numN); i++)
				{
					if (strlen(IntMin) < strlen(numN))
					{
						printf_s("TETYA LUSYA, VERY SMALL NUMBER");
						exit(1);
					}
				}
			}
		}
		else
		{
			if (strlen(IntMax) < strlen(numN))
			{
				printf_s("TETYA LUSYA, VERY BIG NUMBER");
				exit(1);
			}
			else if (strlen(IntMax) == strlen(numN))
			{
				for (int i = 1; i < strlen(numN); i++)
				{
					if (strlen(IntMax) < strlen(numN))
					{
						printf_s("TETYA LUSYA, VERY BIG NUMBER");
						exit(1);
					}
					
				}
			}
		}
	}
	fseek(input, 0, 0);
	int* binNumber = BinNum(N);
	if (!(binNumber))
	{
		printf_s("MEM_ALL_ERR");
		exit(1);
	}
	int* binNumberWithZeros = (int*)calloc(COUNT_BITS, sizeof(int));
	if (!(binNumberWithZeros))
	{
		printf_s("MEM_ALL_ERR");
		exit(1);
	}
	shiftinmemory(binNumberWithZeros,binNumber, N);
	for (int i = 0; i < COUNT_BITS; i++)
	{
		fprintf_s(output, "%d", binNumberWithZeros[i]);
		printf_s("%d", binNumberWithZeros[i]);
	}
	fclose(input);
	fclose(output);
}
