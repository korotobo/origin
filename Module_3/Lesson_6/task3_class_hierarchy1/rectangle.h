#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "parallelogram.h"

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b, int A);
    bool check() override;
    void print() override;
};

#endif // RECTANGLE_H
