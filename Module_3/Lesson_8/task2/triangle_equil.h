#ifndef TRIANGLE_EQUIL_H
#define TRIANGLE_EQUIL_H

#include "triangle.h"

class TriangleEquilateral : public Triangle {
public:
    TriangleEquilateral(int a, int b, int c, int A, int B, int C);

    void print() override;
};


#endif // TRIANGLE_EQUIL_H
