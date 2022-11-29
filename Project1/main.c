#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "operations.h"
int Interface(struct Matrix Matrix1, struct Matrix Matrix2)
{
	struct Matrix Multip = MultiplicationMatrix(Matrix1, Matrix2);
	char cmd;
	scanf_s("%c", &cmd);
	switch (cmd)
	{
	case '1':
		PrintSumMatrix(Matrix1, Matrix1);
		break;
	case '2':
		PrintSubtractionMatrix(Matrix1, Matrix1);
		break;
	case '3':
		PrintMatrix(Matrix1, Matrix2);
		break;
	case '4':
		PrintTransposedMatrix(Matrix1, Matrix1);
		break;
	case '5':
		FreeMatrix(Matrix1);
		FreeMatrix(Matrix2);
		printf_s("Good Bye\n");
		exit(1);

	default:
		break;
	}
}
int main(void)
{
	struct Matrix FirstMatrix = ÑreationMatrix(MatrixFromFile("matrix-A.txt"));
	struct Matrix SecondMatrix = ÑreationMatrix(MatrixFromFile("matrix-B.txt"));
	printf_s("It's calculator for matrix!\nWhat dou you want?\n");
	printf_s("1)Sum matrix\n2)Subtraction matrix\n3)Multiplication matrix\n4)Transposed matrix\n5)Exit from programm\n");
	while (Interface(FirstMatrix, SecondMatrix));
	return 0;
}
