#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"
char* MatrixFromFile(char* file)
{
	FILE* FileName;
	fopen_s(&FileName, file, "r");
	fseek(FileName, 0, SEEK_END);
	int size = ftell(FileName); 
	char* str = (char*)malloc(size * sizeof(char));
	fgets(str, size, FileName);
	fclose(FileName);
	return str;
}
int LineMatrix(char* str)
{
	int c = 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] = '/') c++;
	}
	return c;
}
int ÑolumnMatrix(char* str)
{
	int c = 1;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] = ' ') c++;
		if (str[i] = '/') break;
	}
	return c;
}
