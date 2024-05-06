#include "rectangle.h"

Rectangle::Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
    name = "Прямоугольник";
    if(!((A == 90) && (B == 90) && (C == 90) && (D == 90))) throw MyException("углы не равны 90 градусам");
    if(!((a == c) && (b == d))) throw MyException("стороны a, c и b, d попарно не равны.");
}

void Rectangle::print()  {
    Quadrangle::print();
}
