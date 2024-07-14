#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D) {
    this->a = this->c = a;
    this->b = this->d = b;
    this->A = this->C = A;
    this->B = this->D = B;
    name = "Параллелограм";
}
bool Parallelogram::check() {
    if(Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D)) return true;
    else return false;
}
void Parallelogram::print()  {
    Quadrangle::print();
}
