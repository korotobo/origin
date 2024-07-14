#include "triangle_rect.h"

TriangleRectangular::TriangleRectangular(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C) {
    this->C = 90;
    name = "Прямоугольный треугольник";
}
bool TriangleRectangular::check() {
    if(Triangle::check() && (C == 90)) return true;
    else return false;
}
void TriangleRectangular::print() {Triangle::print();}
