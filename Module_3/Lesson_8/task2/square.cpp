#include "square.h"

Square::Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
    name = "Квадрат";
    if(!((A == 90) && (B == 90) && (C == 90) && (D == 90))) throw MyException("углы не равны 90");
    if(!((a == b) && (b == c) && (c == d) && (d == a))) throw MyException("стороны не равны друг другу");
}

void Square::print()  {
    Quadrangle::print();
}
