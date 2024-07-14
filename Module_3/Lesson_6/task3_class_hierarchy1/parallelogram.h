#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "quadrangle.h"

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B);
    bool check() override;
    void print() override;
};

#endif // PARALLELOGRAM_H
