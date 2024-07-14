#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "quadrangle.h"

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D);

    void print() override;
};

#endif // RECTANGLE_H
