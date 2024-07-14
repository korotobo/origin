#ifndef RHOMB_H
#define RHOMB_H

#include "parallelogram.h"

class Rhomb  : public Parallelogram {
public:
    Rhomb(int a, int A, int B);
    bool check() override;
    void print() override;
};;

#endif // RHOMB_H
