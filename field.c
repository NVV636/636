#include <stdlib.h>
#include <stdio.h>
#include "field.h"

Field* createField(int rows, int columns) {
    Field* f = (Field*)malloc(sizeof(Field));
    if (f == NULL) {
        printf("Memmory allocation error\n");
        exit(1);
    }
    f->field = (float**)malloc(sizeof(float*) * rows);
    if (f->field == NULL) {
        printf("Memmory allocation error\n");
        exit(1);
    }
    for (int i = 0; i < rows; i++) {
        f->field[i] = (float*)malloc(sizeof(float) * columns);
        if (f->field[i] == NULL) {
            printf("Memmory allocation error\n");
            exit(1);
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            f->field[i][j] = 0.0;
        }
    }
    f->rows = rows;
    f->columns = columns;
    return f;
}

void freeField(Field* f) {
    for (int i = 0; i < f->rows; i++) {
        free(f->field[i]);
    }
    free(f->field);
    free(f);
}