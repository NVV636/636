#ifndef _FIELD_H_
#define _FIELD_H_

typedef struct {
    float** field;
    int rows;
    int columns;
} Field;

Field* createField(int rows, int columns);
void freeField(Field* f);

#endif