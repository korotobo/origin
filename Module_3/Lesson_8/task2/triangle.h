#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"


class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C);

    int getSideA();
    int getCornerA();
    int getSideB();
    int getCornerB();
    int getSideC();
    int getCornerC();

    void print() override;
};

#endif // TRIANGLE_H
