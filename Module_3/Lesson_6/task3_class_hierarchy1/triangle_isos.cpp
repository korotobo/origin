#include "triangle_isos.h"


TriangleIsosceles::TriangleIsosceles(int a, int b, int A, int B) : TriangleRectangular(a, b, c, A, B) {
    this->a = this->c = a;
    this->A = this->C = A;
    this->b = b;
    this->B = B;
    name = "Равнобедренный треугольник";
}
bool TriangleIsosceles::check() {
    if(Triangle::check() && (a == c) && (A == C)) return true;
    else return false;
}
void TriangleIsosceles::print() {Triangle::print();}
