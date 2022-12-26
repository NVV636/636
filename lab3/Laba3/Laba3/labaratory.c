#include <stdlib.h>
#include <stdio.h>
#include "f.h"
int main()
{
	char* String = "string";
	char* Substring = "str";
	char* StringSubstring = StrSubstr(String, Substring);
	int L1 = StrLen(String);
	int L2 = StrLen(Substring);
	printf_s("%d %d\n", L1, L2);
}