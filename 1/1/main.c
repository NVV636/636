#include <stdio.h>
#include "func.h"

int main() {
    Str* arr = NewArray();
    while (1) {
        String newElem;
        int i;
        int res;
        printf_s("Write new elem: ");
        scanf_s("%c", &newElem);
        res = InsertElem(arr, newElem);
        if (res == 0) {
            printf("Realloc error\n");
        }
        for (i = 0; i < GetLength(arr); ++i) {
            printf_s("%u ", GetElem(arr, i));
        }
        printf_s("\n");
    }

}