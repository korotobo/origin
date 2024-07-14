#include "square.h"

Square::Square(int a, int A) : Rectangle(a, b, A) {
    this->a = this->b = this->c = this->d = a;
    this->A = this-> B = this->C = this->D = A;
    name = "Квадрат";
}
bool Square::check(){
    if(Quadrangle::check() && (A == 90) && (B == 90) && (C == 90) && (D == 90)
        && ((a == b) && (b == c) && (c == d) && (d == a))) return true;
    else return false;
}
void Square::print()  {
    Quadrangle::print();
}
