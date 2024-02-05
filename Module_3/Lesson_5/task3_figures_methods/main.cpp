#include <iostream>
#include <string>

class Figure {
protected:
    int sides;
    std::string name;
public:
    Figure(){sides = 0;  name = "Фигура";}

    std::string getName(){return name;}

    virtual bool check(){
        if(sides == 0) return true;
        else return false;
    }
    virtual void print(){
        std::cout << name << ":" << std::endl;
        if(this->check()) {std::cout << "Правильная" << std::endl;}
        else {std::cout << "Неправильная" << std::endl;}
        std::cout << "Количество сторон: " << sides << std::endl;
    }
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
        sides = 3;
    }

    int getSideA(){return a;}
    int getCornerA(){return A;}
    int getSideB(){return b;}
    int getCornerB(){return B;}
    int getSideC(){return c;}
    int getCornerC(){return C;}

    bool check() override{
        if(sides == 3 && (A + B + C == 180)) return true;
        else return false;
    }
    void print() override{
        Figure::print();
        std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
                  << ", c = " << getSideC() << std::endl;
        std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
                  << ", C = " << getCornerC() << std::endl;
        std::cout << std::endl;
    }
};

class TriangleRectangular : public Triangle {
public:
    TriangleRectangular(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, C) {
        this->C = 90;
        name = "Прямоугольный треугольник";
    }
    bool check() override{
        if(Triangle::check() && (C == 90)) return true;
        else return false;
    }
    void print() override{
        Triangle::print();
    }
};

class TriangleIsosceles  : public TriangleRectangular {
public:
    TriangleIsosceles(int a, int b, int A, int B) : TriangleRectangular(a, b, c, A, B) {
        this->a = this->c = a;
        this->A = this->C = A;
        this->b = b;
        this->B = B;
        name = "Равнобедренный треугольник";
    }
    bool check() override{
        if(Triangle::check() && (a == c) && (A == C)) return true;
        else return false;
    }
    void print() override{
        Triangle::print();
    }
};

class TriangleEquilateral : public TriangleIsosceles {
public:
    TriangleEquilateral(int a, int A) : TriangleIsosceles(a, b, A, B) {
        this->a = this-> b = this->c = a;
        this->A = this-> B = this->C = A;
        name = "Равносторонний треугольник";
    }
    bool check() override{
        if(Triangle::check() && (a == b == c) && (A == 60) && (B == 60)
            && (C == 60)) return true;
        else return false;
    }
    void print() override{
        Triangle::print();
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
        sides = 4;
    }

    int getSideA(){return a;}
    int getCornerA(){return A;}
    int getSideB(){return b;}
    int getCornerB(){return B;}
    int getSideC(){return c;}
    int getCornerC(){return C;}
    int getSideD(){return d;}
    int getCornerD(){return D;}

    bool check() override {
        if(sides == 4 && ((A + B + C + D) == 360)) return true;
        else return false;
    }
    void print() override {
        Figure::print();
        std::cout << "Стороны: a = " << getSideA() << ", b = " << getSideB()
                  << ", c = " << getSideC() << ", d= " << d << std::endl;
        std::cout << "Углы: A = " << getCornerA() << ", B = " << getCornerB()
                  << ", C = " << getCornerC() << ", D = " << D <<std::endl;
        std::cout << std::endl;
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, c, d, A, B, C, D) {
        this->a = this->c = a;
        this->b = this->d = b;
        this->A = this->C = A;
        this->B = this->D = B;
        name = "Параллелограм";
    }
    bool check() override {
        if(Quadrangle::check() && (a == c) && (b == d) && (A == C) && (B == D)) return true;
        else return false;
    }
    void print() override {
        Quadrangle::print();
    }
};

class Rhomb  : public Parallelogram {
public:
    Rhomb(int a, int A, int B) : Parallelogram(a, b, A, B) {
        this->a = this->b = this->c = this->d = a;
        this->A = this->C = A;
        this->B = this->D = B;
        name = "Ромб";
    }
    bool check() override {
        if(Quadrangle::check() && (A == C) && (B == D) && ((a == b)
            && (b == c) && (c == d) && (d == a))) return true;
        else return false;
    }
    void print() override {
        Quadrangle::print();
    }
};

class Rectangle : public Parallelogram {
public:
    Rectangle(int a, int b, int A) : Parallelogram(a, b, A, B) {
        this->a = this-> c = a;
        this->b = this->d = b;
        this->A = this-> B = this->C = this->D = A;
        name = "Прямоугольник";
    }
    bool check() override {
        if(Quadrangle::check() && (a == c) && (b == d) && ((A == 90)
            && (B == 90) && (C == 90) && (D == 90))) return true;
        else return false;
    }
    void print() override {
        Quadrangle::print();
    }
};

class Square : public Rectangle {
public:
    Square(int a, int A) : Rectangle(a, b, A) {
        this->a = this->b = this->c = this->d = a;
        this->A = this-> B = this->C = this->D = A;
        name = "Квадрат";
    }
    bool check() override {
        if(Quadrangle::check() && (A == 90) && (B == 90) && (C == 90) && (D == 90)
            && ((a == b) && (b == c) && (c == d) && (d == a))) return true;
        else return false;
    }
    void print() override {
        Quadrangle::print();
    }
};


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
