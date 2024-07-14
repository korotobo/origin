#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "quadrangle.h"

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);

    void print() override;
};

#endif // PARALLELOGRAM_H
