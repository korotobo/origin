#include "triangle_isos.h"

TriangleIsosceles::TriangleIsosceles(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
    name = "Равнобедренный треугольник";

    if(a != c) throw MyException("стороны a и c, углы A и C не равны");
    if(A != C) throw MyException("углы A и C не равны");
}

void TriangleIsosceles::print() {Triangle::print();}
