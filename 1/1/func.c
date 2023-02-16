#include <stdlib.h>
#include <stdio.h>

#include "func.h"

#define BASE_CAPACITY 5


Str* NewArray() {
    Str* Arr = (Str*)malloc(sizeof(Str));
    if (Arr == NULL) return NULL;
    Arr->elems = (String*)malloc(sizeof(String) * BASE_CAPACITY);
    if (Arr->elems == NULL) {
        free(Arr);
        return NULL;
    }
    Arr->capacity = BASE_CAPACITY;
    Arr->size = 0;
    return Arr;
}

int InsertElem(Str* arr, Str elem) {
    
}
String GetElem(Str* arr, unsigned index) {
    if (index >= arr->size) {
        return 0;
    }
    return arr->elems[index];
}

unsigned GetLength(Str* arr) {
    return arr->size;
}