#include "func.h"
int SearchSubStringInString(char* str1, char* str2)
{
	for (int i = 0; i < StrLen(str1); i++)
	{
		for (int j = i, k = 0; k < StrLen(str2) && str1[j] == str2[k]; j++, k++)
		{
			if (k = StrLen(str2) - 1)
			{
				i++;
				return i;
			}
		}
	}
}

int StrLen(char* str)
{
	unsigned count = 0;
	for (int i = 0; str[i] != '\0'; i++)
		count++;
	return count;
}

int CountSubstring(char* str1, char* str2)
{
	int count = 0;
	while (SearchSubStringInString(str1, str2))
	{
		count++;
		str1 += SearchSubStringInString(str1, str2);
	}
	return count;
}
char* SubstringReplacement(char* str1, char* str2, char* str3)
{
	unsigned Len = StrLen(str1) + StrLen(str3) - StrLen(str2);
	char* NewString = (char*)malloc(sizeof(char) * (Len + 1));
	int Occurrence = SearchSubStringInString(str1, str2);
	for (int i = 0; i < Occurrence; i++)
	{
		NewString[i] = str1[i];
	}
	int tmp = 0;
	for (int i = Occurrence; i < Occurrence + StrLen(str3); i++)
	{
		NewString[i] = str3[tmp];
		tmp++;
	}
	for (int i = Occurrence + StrLen(str2); i < Len; i++)
	{
		NewString[i + StrLen(str2) - StrLen(str3)] = str1[i];
	}
	NewString[Len] = '\0';
	return NewString;
}