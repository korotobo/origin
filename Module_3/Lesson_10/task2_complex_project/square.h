#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle {
public:
    Square(int a, int A);
    bool check() override;
    void print() override;
};

#endif // SQUARE_H
