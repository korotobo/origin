#include <iostream>
#include "math_func.h"

int main()
{
    double x, y;
    int choice;

    std::cout << "Введите первое число: ";
    std::cin >> x;
    std::cout << "Введите второе число: ";
    std::cin >> y;

    std::cout << "Выберите операцию: (1 - сложение; 2 - вычитание; 3 - умножение; 4 - деление; 5 - возведение в степень): ";
    std::cin >> choice;

    switch(choice){
    case 1:
        std::cout << x << " плюс " << y << " равно = " << funcAdd(x, y) << std::endl;
        break;
    case 2:
        std::cout << x << " вычесть " << y << " равно = " << funcSub(x, y) << std::endl;
        break;
    case 3:
        std::cout << x << " умножить на " << y << " равно = " << funcMult(x, y) << std::endl;
        break;
    case 4:
        std::cout << x << " разделить на " << y << " равно = " << funcDiv(x, y) << std::endl;
        break;
    case 5:
        std::cout << x << " в степени " << y << " равно = " << funcExp(x, y) << std::endl;
        break;
    }

    return 0;
}
