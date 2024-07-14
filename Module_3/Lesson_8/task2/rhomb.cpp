#include "rhomb.h"

Rhomb::Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
    name = "Ромб";
    if(!((a == b) && (b == c) && (c == d) && (d == a))) throw MyException("стороны ромба не равны");
    if(!((A == C) && (B == D))) throw MyException("углы А, С и B, D попарно не равны");
}

void Rhomb::print() {
    Quadrangle::print();
}
