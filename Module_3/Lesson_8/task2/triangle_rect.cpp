#include "triangle_rect.h"

TriangleRectangular::TriangleRectangular(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    name = "Прямоугольный треугольник";
    sides = 3;
    if(!(C == 90)) throw MyException("угол C не равен 90 градусов");
}

void TriangleRectangular::print() {Triangle::print();}
