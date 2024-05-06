#ifndef TRIANGLE_RECT_H
#define TRIANGLE_RECT_H

#include "triangle.h"

class TriangleRectangular : public Triangle {
public:
    TriangleRectangular(int a, int b, int c, int A, int B, int C);

    void print() override;
};


#endif // TRIANGLE_RECT_H
