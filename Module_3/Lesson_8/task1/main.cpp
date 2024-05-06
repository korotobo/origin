#include <iostream>
#include <string>
#include <exception>
#include "function.h"

int main()
{
    int str_length = 0;
    int forbidden_length = 0;
    std::string str;
    bool check_forbidden_length = false;

    do
    {
        std::cout << "Введите запретную длину: ";
        std::cin >> forbidden_length;

        if (forbidden_length > 0)
        {
            check_forbidden_length = true;
        }

        if (forbidden_length <= 0)
        {
            std::cout << "Неверная длина. Введите новую." << std::endl;
        }

    } while (!check_forbidden_length);

    try
    {
        do
        {
            std::cout << "Введите слово: ";
            std::cin >> str;

            str_length = function(str, forbidden_length);

            std::cout << "Длина слова \"" << str << "\" равна " << str_length;
            std::cout << std::endl;

        } while (forbidden_length != str_length);
    }
    catch (const std::exception& bad_length)
    {
        std::cout << "Вы ввели слово запретной длины! До свидания!" << std::endl;
    }
}
