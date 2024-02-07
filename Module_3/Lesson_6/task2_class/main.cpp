#include <iostream>
#include "class_calculator.h"

int main()
{
    Calculator calc;
    double num1, num2;

    for( ; ; ) {
        do {
            std::cout << "Введите num1: ";
            std::cin >> num1;
            if(num1 == 0) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (!calc.set_num1(num1));
        do {
            std::cout << "Введите num2: ";
            std::cin >> num2;
            if(num2 == 0) {
                std::cout << "Неверный ввод!" << std::endl;
            }
        } while (!calc.set_num2(num2));

        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;

    }
    return 0;
}
