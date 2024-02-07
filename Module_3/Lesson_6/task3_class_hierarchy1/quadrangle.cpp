#include "quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
    this->A = A;
    this->B = B;
    this->C = C;
    this->D = D;
    name = "Четырёхугольник";
    sides = 4;
}

int Quadrangle::getSideA(){return a;}
int Quadrangle::getCornerA(){return A;}
int Quadrangle::getSideB(){return b;}
int Quadrangle::getCornerB(){return B;}
int Quadrangle::getSideC(){return c;}
int Quadrangle::getCornerC(){return C;}
int Quadrangle::getSideD(){return d;}
int Quadrangle::getCornerD(){return D;}

bool Quadrangle::check() {
    if(sides == 4 && ((A + B + C + D) == 360)) return true;
    else return false;
}
void Quadrangle::print() {
    Figure::print();
    std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
              << ", c = " << getSideC() << ", d= " << d << std::endl;
    std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
              << ", C = " << getCornerC() << ", D = " << D <<std::endl;
    std::cout << std::endl;
}
