#include "triangle_equil.h"

TriangleEquilateral::TriangleEquilateral(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    name = "Равносторонний треугольник";

    if(!((a == b) && (b == c) && (c == a))) throw MyException("стороны не равны");
    if(!((A == 60) && (B == 60) && (C == 60))) throw MyException("углы не равны 60 градусам");
}

void TriangleEquilateral::print() {
    Triangle::print();
}
