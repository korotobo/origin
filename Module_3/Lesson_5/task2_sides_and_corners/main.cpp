#include <iostream>
#include <string>

class Figure {
protected:
    int sides;
    std::string name;
public:
    Figure(){sides = 0;  name = "Фигура";}
    std::string getName(){return name;}
};

class Triangle : public Figure {
protected:
    int a, b, c, A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) : Figure() {
        this->a = a;
        this->b = b;
        this->c = c;
        this->A = A;
        this->B = B;
        this->C = C;
        name = "Треугольник";
    }
    int getSideA(){return a;}
    int getCornerA(){return A;}
    int getSideB(){return b;}
    int getCornerB(){return B;}
    int getSideC(){return c;}
    int getCornerC(){return C;}

    void print(){
        std::cout << getName() << std::endl;
        std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
                  << ", c = " << getSideC() << std::endl;
        std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
                  << ", C = " << getCornerC() << std::endl;
        std::cout << std::endl;
    }
};

class TriangleRectangular : public Triangle {
protected:
public:
    TriangleRectangular(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C) {
        this->C = 90;
        name = "Прямоугольный треугольник";
    }
};

class TriangleIsosceles  : public TriangleRectangular {
protected:
public:
    TriangleIsosceles(int a, int b, int A, int B) : TriangleRectangular(a, b, c, A, B) {
        this->a = this->c = a;
        this->A = this->C = A;
        this->b = b;
        this->B = B;
        name = "Равнобедренный треугольник";
    }
};

class TriangleEquilateral : public TriangleIsosceles {
protected:
public:
    TriangleEquilateral(int a, int A) : TriangleIsosceles(a, b, A, B) {
        this->a = this-> b = this->c = a;
        this->A = this-> B = this->C = A;
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d, A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure() {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->A = A;
        this->B = B;
        this->C = C;
        this->D = D;
        name = "Четырёхугольник";
    }

    int getSideA(){return a;}
    int getCornerA(){return A;}
    int getSideB(){return b;}
    int getCornerB(){return B;}
    int getSideC(){return c;}
    int getCornerC(){return C;}
    int getSideD(){return d;}
    int getCornerD(){return D;}

    void print(){
        std::cout << getName() << std::endl;
        std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
                  << ", c = " << getSideC() << ", d= " << d << std::endl;
        std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
                  << ", C = " << getCornerC() << ", D = " << D <<std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
protected:
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D) {
        this->a = this->c = a;
        this->b = this->d = b;
        this->A = this->C = A;
        this->B = this->D = B;
        name = "Параллелограм ";
    }
};

class Rhomb  : public Parallelogram {
protected:
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, b, A, B) {
        this->a = this->b = this->c = this->d = a;
        this->A = this->C = A;
        this->B = this->D = B;
        name = "Ромб";
    }
};

class Rectangle : public Parallelogram {
protected:
public:
    Rectangle(int a, int b, int A) : Parallelogram(a, b, A, B) {
        this->a = this-> c = a;
        this->b = this->d = b;
        this->A = this-> B = this->C = this->D = A;
        name = "Прямоугольник";
    }
};

class Square : public Rectangle {
protected:
public:
    Square(int a, int A) : Rectangle(a, b, A) {
        this->a = this->b = this->c = this->d = a;
        this->A = this-> B = this->C = this->D = A;
        name = "Квадрат";
    }
};


int main()
{    
    Triangle t1(10, 20, 30, 50, 60, 70);
    TriangleRectangular t2(10, 20, 30, 50, 60);
    TriangleIsosceles t3(10, 20, 50, 60);
    TriangleEquilateral t4(30, 60);

    Quadrangle s1(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle s2(10, 20, 90);
    Square s3(20, 90);
    Parallelogram s4(20, 30, 30, 40);
    Rhomb s5(30, 30, 40);

    t1.print();
    t2.print();
    t3.print();
    t4.print();

    s1.print();
    s2.print();
    s3.print();
    s4.print();
    s5.print();

    return 0;
}
