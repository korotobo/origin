#ifndef TRIANGLE_ISOS_H
#define TRIANGLE_ISOS_H

#include "triangle.h"

class TriangleIsosceles  : public Triangle {
public:
    TriangleIsosceles(int a, int b, int c, int A, int B, int C);

    void print() override;
};


#endif // TRIANGLE_ISOS_H
