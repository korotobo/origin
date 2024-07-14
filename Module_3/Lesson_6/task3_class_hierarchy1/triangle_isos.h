#ifndef TRIANGLE_ISOS_H
#define TRIANGLE_ISOS_H

#include "triangle_rect.h"

class TriangleIsosceles  : public TriangleRectangular {
public:
    TriangleIsosceles(int a, int b, int A, int B);
    bool check() override;
    void print() override;
};


#endif // TRIANGLE_ISOS_H
