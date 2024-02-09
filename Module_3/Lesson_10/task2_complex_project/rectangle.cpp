#include "rectangle.h"

Rectangle::Rectangle(int a, int b, int A)
    : Parallelogram(a, b, A, B) {
    this->a = this-> c = a;
    this->b = this->d = b;
    this->A = this-> B = this->C = this->D = A;
    name = "Прямоугольник";
}
bool Rectangle::check() {
    if(Quadrangle::check() && (a == c) && (b == d) && ((A == 90)
                                                        && (B == 90) && (C == 90) && (D == 90))) return true;
    else return false;
}
void Rectangle::print()  {
    Quadrangle::print();
}
