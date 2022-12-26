#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
int Сomp(char* str1, char* str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2) {
            return 0;
        }

        str1++;
        str2++;
    }

    return (*str2 == '\0');
}

// Функция для реализации функции `mystrstr()`
char* StrSubstr(char* str1, char* str2)
{
    while (*str1 != '\0')
    {
        if ((*str1 == *str2) && Сomp(str1, str2)) {
            return str1;
        }
        str1++;
    }

    return NULL;
}

int StrLen(char* str)
{
    int c;
    while (str[c] != '\0') c++;
    return c;
}
void PrintString(char* str)
{
    for (int i = 0; i < StrLen(str); i++)
    {
        printf_s("%c", str[i]);
    }
}