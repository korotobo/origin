#include <iostream>

#define MODE 1

int main(int argc, char **argv)
{
#ifndef MODE
#error "Символьная константа MODE не определена!"
#endif

#if MODE == 0
    std::cout << "Работаю в режиме тренировки" << std::endl;

#elif MODE == 1
    #include "add.h"
    int a, b;
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите первое число: ";
    std::cin >> a;
    std::cout << "Введите второе число: ";
    std::cin >> b;
    std::cout << "Результат сложения: " << add(a, b) << std::endl;

#else
    std::cout << "Неизвестный режим. Завершение работы." << std::endl;

#endif

    return 0;
}
