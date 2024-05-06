#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "figure.h"


class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);

    int getSideA();
    int getCornerA();
    int getSideB();
    int getCornerB();
    int getSideC();
    int getCornerC();
    int getSideD();
    int getCornerD();

    void print() override;
};

#endif // QUADRANGLE_H
