#pragma once 
#include <stdio.h>
#include <stdlib.h>
typedef struct Matrices
{
	unsigned line;
	unsigned column;
	double** Mat;
}Matrices;
Matrices* CreationMatrix(unsigned L, unsigned C);
Matrices* SumMatrix(Matrices* M1, Matrices M2);
void PrintM(Matrices* M);
void F(Matrices* M);