#include <iostream>
#include <string>

class Figure {
protected:
    int sidesCount = 0;
    std::string nameFigure;
public:
    Figure() {sidesCount = 0; nameFigure = "Фигура";}
    int getSidesCount(){return sidesCount;}
    std::string getNameFigure(){return nameFigure;}
};

class Triangle : public Figure {
public:
    Triangle() {sidesCount = 3; nameFigure = "Треугольник";}
};

class Quadrangle : public Figure {
public:
    Quadrangle(){sidesCount = 4; nameFigure = "Четырёхугольник";}
};

int main()
{
    Figure a;
    Triangle b;
    Quadrangle c;

    std::cout << "Количество сторон: " << std::endl;
    std::cout << a.getNameFigure() << ": " << a.getSidesCount() << std::endl;
    std::cout << b.getNameFigure() << ": " << b.getSidesCount() << std::endl;
    std::cout << c.getNameFigure() << ": " << c.getSidesCount() << std::endl;

    return 0;
}
