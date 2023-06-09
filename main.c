#include <stdlib.h>
#include <raylib.h>
#include <math.h>
#include "field.h"

void addPointIntoField(Field* f, int x, int y, float c) {
    f->field[y][x] = c;
}

void swap(int* a , int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

float absolute(float x ) {
    if (x < 0) return -x;
    else return x;
}

int intPart(float n) {
    return (int)floor(n);
}

float fPart(float n) {
    return n - (float)intPart(n);
}

void drawWusLine(Field* f, int x1, int y1, int x2, int y2) {
    int steep = absolute(y2-y1) > absolute(x2-x1);

    if (steep) {
        swap(&x1, &y1);
        swap(&x2, &y2);
    }
    if (x1 > x2) {
        swap(&x1, &x2);
        swap(&y1, &y2);
    }
    
    float dx = x2 - x1;
    float dy = y2 - y1;
    float gradient = dy / dx;
    if (dx == 0.0) {
        gradient = 1;
    }

    float xEnd = round(x1);
    float yEnd = y1 + gradient * (xEnd - x1);
    float xgap = 1 - fPart(x1 + 0.5);
    int xpxl1 = (int)xEnd;
    int ypxl1 = intPart(yEnd);
    addPointIntoField(f, xpxl1, ypxl1, (1 - fPart(yEnd))*xgap);
    addPointIntoField(f, xpxl1, ypxl1+1, fPart(yEnd)*xgap);
    float intery = yEnd + gradient;

    xEnd = round(x2);
    yEnd = y2 + gradient *(xEnd-x2);
    xgap = fPart(x2 + 0.5);
    int xpxl2 = (int)xEnd;
    int ypxl2 = intPart(yEnd);
    addPointIntoField(f, xpxl2, ypxl2, (1 - fPart(yEnd))*xgap);
    addPointIntoField(f, xpxl2, ypxl2+1, fPart(yEnd)*xgap);

    for (int i = xpxl1+1; i < xpxl2; i++) {
        addPointIntoField(f, i, intPart(intery), 1-fPart(intery));
        addPointIntoField(f, i, intPart(intery)+1, fPart(intery));
        intery += gradient;
    }
}

void drawField(Field* f, int x, int y) {
    for (int i = 0; i < f->rows; i++) {
        for (int j = 0; j < f->columns; j++) {
            if (f->field[i][j] != 0) {
                Color c = {255*f->field[i][j], 255*f->field[i][j], 255*f->field[i][j], 255};
                DrawRectangle(10*j, 10*i, 10, 10, c);
            }
        }
    }
}

int main() {
    Field* f = createField(200,200);

    drawWusLine(f, 1, 1, 20, 40);
    drawWusLine(f, 1, 1, 15, 15);
    drawWusLine(f, 20, 40, 15, 15);

    const int screenWidth = 900;
    const int screenHeight = 700;
    InitWindow(screenWidth, screenHeight, "Wu's line algorithm");

    while(!WindowShouldClose()) {
        BeginDrawing();
            drawField(f, 10, 10);
            ClearBackground(BLACK);
        EndDrawing();
    }

    freeField(f);
    return 0;
}