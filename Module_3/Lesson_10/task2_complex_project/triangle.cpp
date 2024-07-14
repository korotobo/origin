#include "triangle.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
    name = "Треугольник";
    sides = 3;
}

int Triangle::getSideA(){return a;}
int Triangle::getCornerA(){return A;}
int Triangle::getSideB(){return b;}
int Triangle::getCornerB(){return B;}
int Triangle::getSideC(){return c;}
int Triangle::getCornerC(){return C;}

bool Triangle::check() {
    if(sides == 3 && (A + B + C == 180)) return true;
    else return false;
}
void Triangle::print() {
    Figure::print();
    std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
              << ", c = " << getSideC() << std::endl;
    std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
              << ", C = " << getCornerC() << std::endl;
    std::cout << std::endl;
}
