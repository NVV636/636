#ifndef _DYN_ARRAY_H
#define _DYN_ARRAY_H

#include <stdint.h>

typedef char* String;

typedef struct Str {
    String* elems;
    unsigned capacity;
    unsigned size;
} Str;

Str* NewArray();

String GetElem(Str* arr, unsigned index);
unsigned GetLength(Str* arr);

#endif

