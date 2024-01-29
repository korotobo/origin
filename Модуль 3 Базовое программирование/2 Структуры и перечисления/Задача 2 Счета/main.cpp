#include <iostream>

struct bankAccount {
    int numAccount;
    std::string ownerName;
    unsigned int balance;
};

void changeBalance(bankAccount &pers, unsigned int newBalance) {
    pers.balance = newBalance;
}

int main()
{
    bankAccount p1;
    unsigned int newBalance;

    std::cout << "Введите номер счёта: ";
    std::cin >> p1.numAccount;

    std::cout << "Введите имя владельца счёта: ";
    std::cin >> p1.ownerName;

    std::cout << "Введите баланс: ";
    std::cin >> p1.balance;

    std::cout << "Введите новый баланс: ";
    std::cin >> newBalance;

    changeBalance(p1, newBalance);

    std::cout << "Ваш счёт: " << p1.ownerName << ", " << p1.numAccount << ", " << p1.balance << std::endl;

    return 0;
}
