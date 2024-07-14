#include <iostream>
#include <string>
#include "figure.h"
#include "triangle.h"
#include "triangle_rect.h"
#include "triangle_isos.h"
#include "triangle_equil.h"
#include "quadrangle.h"
#include "parallelogram.h"
#include "rhomb.h"
#include "rectangle.h"
#include "square.h"


int main()
{
    Figure a;
    Triangle t1(10, 20, 30, 50, 60, 70);
    Triangle t11(10, 20, 30, 50, 70, 70);
    TriangleRectangular t2(10, 20, 30, 50, 40);
    TriangleIsosceles t3(10, 20, 50, 80);
    TriangleEquilateral t4(30, 70);

    Quadrangle s1(10, 20, 30, 40, 50, 60, 70, 80);
    Quadrangle s11(10, 20, 30, 40, 150, 60, 70, 80);
    Rectangle s2(10, 20, 90);
    Square s3(20, 90);
    Square s33(20, 80);
    Parallelogram s4(20, 30, 30, 40);
    Rhomb s5(30, 30, 40);
    Rhomb s55(50, 80, 100);

    Figure *p;

    p = &a;
    p->print();

    std::cout << "\nКласс треугольников:\n"  << std::endl;

    p = &t1;
    p->print();
    p = &t11;
    p->print();

    p = &t2;
    p->print();

    p = &t3;
    p->print();

    p = &t4;
    p->print();

    std::cout << "\nКласс четырёхугольников:\n" << std::endl;

    p = &s1;
    p->print();
    p = &s11;
    p->print();

    p = &s2;
    p->print();

    p = &s3;
    p->print();
    p = &s33;
    p->print();

    p = &s4;
    p->print();

    p = &s5;
    p->print();
    p = &s55;
    p->print();

    return 0;
}
