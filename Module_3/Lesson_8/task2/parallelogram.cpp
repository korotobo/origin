#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
    name = "Параллелограм";
    if(!((a == c) && (b == d))) throw MyException("стороны а и с, b и d попарно не равны");
    if(!((A == C) && (B == D))) throw MyException("углы А и С, B и D попарно не равны");
}

void Parallelogram::print()  {
    Quadrangle::print();
}
