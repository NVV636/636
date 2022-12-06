#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
struct Matrix
{
	int** body;
	unsigned CountsLines;
	unsigned Count—olumn;
};
void PrintTransposedMatrix(struct Matrix A);
void PrintSubtractionMatrix(struct Matrix A, struct Matrix B);
void PrintSumMatrix(struct Matrix A, struct Matrix B);
void PrintMatrix(struct Matrix A);
struct Matrix CreatingNullMatrix(int CountsLines, int Count—olumn);
struct Matrix —reationMatrix(char* str);
struct Matrix MultiplicationMatrix(struct Matrix A, struct Matrix B);
void FreeMatrix(struct Matrix A);