#ifndef RHOMB_H
#define RHOMB_H

#include "quadrangle.h"

class Rhomb  : public Quadrangle {
public:
    Rhomb(int a, int b, int c, int d, int A, int B, int C, int D);

    void print() override;
};;

#endif // RHOMB_H
