#include "rhomb.h"

Rhomb::Rhomb(int a, int A, int B) : Parallelogram(a, b, A, B) {
    this->a = this->b = this->c = this->d = a;
    this->A = this->C = A;
    this->B = this->D = B;
    name = "Ромб";
}

bool Rhomb::check(){
    if(Quadrangle::check() && (A == C) && (B == D) && ((a == b)
                                                        && (b == c) && (c == d) && (d == a))) return true;
    else return false;
}
void Rhomb::print() {
    Quadrangle::print();
}
