#include <iostream>
#include "my_exception.h"
// #include <string>
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
    try
    {   //треугольник (стороны a, b, c; углы A, B, C)
        Triangle t1(10, 20, 30, 50, 60, 70);
        t1.print();
    }
    catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //треугольник (сумма углов != 180)
        Triangle t11(10, 20, 30, 50, 70, 70);
        t11.print();
    }
    catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //равнобедренный треугольник (a = c = 50; A = C = 50)
        TriangleIsosceles t3(50, 20, 50, 50, 80, 50);
        t3.print();
    }
    catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //прямоугольный треугольник (угол C != 90)
        TriangleRectangular t2(10, 20, 30, 50, 50, 80);
        t2.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //равносторонний треугольник
        TriangleEquilateral t4(30, 30, 30, 60, 60, 60);
        t4.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //четырёхугольник (стороны a, b, c, d; углы A, B, C, D)
        Quadrangle s1(10, 20, 30, 40, 140, 80, 70, 70);
        s1.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //прямоугольник
        Rectangle s2(10, 30, 10, 20, 90, 90, 90, 90);
        s2.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //квадрат (правильный)
        Square s3(20, 20, 20, 20, 90, 90, 90, 90);
        s3.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //квадрат (неправильный)
        Square s33(20, 20, 20, 20, 100, 80, 90, 90);
        s33.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //параллелограм
        Parallelogram s4(20, 30, 20, 30, 130, 50, 130, 50);
        s4.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //ромб (правильный)
        Rhomb s5(30, 30, 30, 30, 130, 50, 130, 50);
        s5.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    try
    {   //ромб (стороны не равны)
        Rhomb s55(30, 30, 20, 30, 150, 30, 150, 30);
        s55.print();
    } catch (MyException &e)
    {
        std::cout << "Ошибка создания фигуры. Причина: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
