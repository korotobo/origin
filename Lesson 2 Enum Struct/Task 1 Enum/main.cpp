#include <iostream>

enum  Month {
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

int main()
{
    int choice;
    Month month;

    do {
        std::cout << "Введите номер месяца: ";
        std::cin >> choice;


        if(!(choice < 0 || choice > 12)) {

            month = static_cast<Month>(choice);

            switch(month) {
            case Month::january:
                std::cout << "Январь" << std::endl;
                break;
            case Month::february:
                std::cout << "Февраль" << std::endl;
                break;
            case Month::march:
                std::cout << "Март" << std::endl;
                break;
            case Month::april:
                std::cout << "Апрель" << std::endl;
                break;
            case Month::may:
                std::cout << "Май" << std::endl;
                break;
            case Month::june:
                std::cout << "Июнь" << std::endl;
                break;
            case Month::july:
                std::cout << "Июль" << std::endl;
                break;
            case Month::august:
                std::cout << "Август" << std::endl;
                break;
            case Month::september:
                std::cout << "Сентябрь" << std::endl;
                break;
            case Month::october:
                std::cout << "Октябрь" << std::endl;
                break;
            case Month::november:
                std::cout << "Ноябрь" << std::endl;
                break;
            case Month::december:
                std::cout << "Декабрь" << std::endl;
                break;
            }
        } else std::cout << "Вы ввели неправильный номер!" << std::endl;

    } while (choice != 0);

    if(choice == 0)
        std::cout << "До свидания" << std::endl;

    return 0;
}
