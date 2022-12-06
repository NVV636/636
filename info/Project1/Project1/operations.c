#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "file.h"
#include "operations.h"
struct Matrix —reationMatrix(char* str)
{
	struct Matrix M;
	M.CountsLines = LineMatrix(str);
	M.Count—olumn = —olumnMatrix(str);
	int** MatrixArr = (int**)calloc(M.CountsLines, sizeof(int));
	for (int i = 0; i < M.CountsLines; i++)
	{
		MatrixArr[i] = (int*)calloc(M.Count—olumn, sizeof(int));
	}
	int i = 0, j = 0;
	for (int a = 0; a < strlen(str); a++)
	{
		if (str[a] = '/') i++, j = 0;
		else if (isdigit(str[a]))
		{
			MatrixArr[i][j] *= 10;
			char c = { str[a] };
			MatrixArr[i][j] += atoi(c);
		}
		else if (str[a] = ' ') j++;
	}
	M.body = MatrixArr;
	return M;
}
void PrintMatrix(struct Matrix A)
{
	for (int i = 0; i < A.CountsLines; i++)
	{
		for (int j = 0; j < A.Count—olumn; j++)
		{
			printf_s("%d", A.body[i][j]);
		}
	}
}
void PrintSumMatrix(struct Matrix A, struct Matrix B)
{
	for (int i = 0; i < A.CountsLines; i++)
	{
		for (int j = 0; j < A.CountsLines; j++)
		{
			printf_s("%d ", A.body[i][j] + B.body[i][j]);
		}
	}
	printf_s("\n");
}
void PrintSubtractionMatrix(struct Matrix A, struct Matrix B)
{
	for (int i = 0; i < A.CountsLines; i++)
	{
		for (int j = 0; j < A.CountsLines; j++)
		{
			printf_s("%d ", A.body[i][j] - B.body[i][j]);
		}
	}
	printf_s("\n");
}
void PrintTransposedMatrix(struct Matrix A)
{
	for (int i = 0; i < A.CountsLines; i++)
	{
		for (int j = 0; j < A.CountsLines; j++)
		{
			printf_s("%d", A.body[j][i]);
		}
	}
	printf_s("\n");
}
struct Matrix CreatingNullMatrix(int CountsLines, int Count—olumn)
{
	struct Matrix Matr;
	Matr.CountsLines = CountsLines;
	Matr.Count—olumn = Count—olumn;
	int** Array = (int**)calloc(sizeof(int), Matr.CountsLines);
	for (int i = 0; i < Matr.CountsLines; i++)
	{
		Array[i] = (int*)calloc(sizeof(int), Matr.Count—olumn);
	}
	Matr.body = Array;
	return Matr;
}
struct Matrix MultiplicationMatrix(struct Matrix A, struct Matrix B)
{
	if (A.CountsLines != B.Count—olumn)
	{
		printf_s("Write correct matrix\n");
	}
	struct Matrix Result = CreatingNullMatrix(A.CountsLines, B.Count—olumn);
	for (int i = 0; i < A.CountsLines; i++)
	{
		for (int j = 0; j < B.Count—olumn; j++)
		{
			int Mult = 0;
			for (int k = 0; k < A.CountsLines; k++)
			{
					Mult += A.body[i][k] * B.body[k][j];
			}
			Result.body[i][j] = Mult;
		}
	}
	return Result;
}
void FreeMatrix(struct Matrix A)
{
	for (int i = 0; i < A.CountsLines; i++)
	{
		free(A.body[i]);
	}
}