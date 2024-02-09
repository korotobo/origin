#include "triangle_equil.h"

TriangleEquilateral::TriangleEquilateral(int a, int A) : TriangleIsosceles(a, b, A, B) {
    this->a = this-> b = this->c = a;
    this->A = this-> B = this->C = A;
    name = "Равносторонний треугольник";
}
bool TriangleEquilateral::check() {
    if(Triangle::check() && (a == b == c) && (A == 60) && (B == 60)
        && (C == 60)) return true;
    else return false;
}
void TriangleEquilateral::print() {
    Triangle::print();
}
