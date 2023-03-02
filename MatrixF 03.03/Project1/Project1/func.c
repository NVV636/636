#include "func.h"
Matrices* CreationMatrix(unsigned L, unsigned C)
{
	Matrices* Matrix = (Matrices*)malloc(sizeof(Matrices));
	if (Matrix == NULL)
	{
		printf_s("Memory allocation error for struct\n");
		return NULL;
	}
	Matrix->column = C;
	Matrix->line = L;
	Matrix->Mat = (double**)malloc(sizeof(double**) * Matrix->line);
	for (int i = 0; i < Matrix->line; i++)
	{
		for (int j = 0; j < Matrix->column; j++)
		{
			Matrix->Mat = (double*)malloc(sizeof(double*) * Matrix->column);
			if (Matrix->Mat = NULL) 
			{
				printf_s("Memory allocation error for array\n");
				return NULL;
			}
		}
	}
	
	return Matrix;
}
void F(Matrices* M)
{
	for (int i = 0; i < M->line; i++)
	{
		for (int j = 0; j < M->column; j++)
		{
			printf_s("Fill in matrix\n");
			scanf_s("%lf\n", &M->Mat[i][j]);
		}
	}
}
Matrices* SumMatrix(Matrices* M1, Matrices M2)
{
	if (M1->column != M2.column || M1->line != M2.line)
	{
		printf_s("Incorrect filling of the matrix\n");
		return NULL;
	}
	Matrices* ResultMatrix = CreationMatrix(M1->column, M1->line);
	for (int i = 0; i < ResultMatrix->line; i++)
	{
		for (int j = 0; j < ResultMatrix->column; j++)
		{
			ResultMatrix->Mat[i][j] = M1->Mat[i][j] + M1->Mat[i][j];
		}
	}
	return ResultMatrix;
}
void PrintM(Matrices* M)
{
	for (int i = 0; i < M->line; i++)
	{
		for (int j = 0; j < M->column; j++)
		{
			printf_s("%lf ", M->Mat[i][j]);
		}
	}
}