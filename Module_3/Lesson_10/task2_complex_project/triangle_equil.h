#ifndef TRIANGLE_EQUIL_H
#define TRIANGLE_EQUIL_H

#include "triangle_isos.h"

class TriangleEquilateral : public TriangleIsosceles {
public:
    TriangleEquilateral(int a, int A);
    bool check() override;
    void print() override;
};


#endif // TRIANGLE_EQUIL_H
