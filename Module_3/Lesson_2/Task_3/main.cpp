#include <iostream>

struct Address
{
    std::string city;
    std::string street;
    unsigned short houseNum;
    unsigned short apartNum;
    unsigned int index;
};

void printAddress(Address address) {
    std::cout << "Город: " << address.city << std::endl;
    std::cout << "Улица: " << address.street << std::endl;
    std::cout << "Номер дома: " << address.houseNum << std::endl;
    std::cout << "Номер квартиры: " << address.apartNum << std::endl;
    std::cout << "Индекс: " << address.index << std::endl;
    std::cout << std::endl;
}

int main()
{
    Address address1 = {"Тюмень", "Ватутина", 16, 12, 629320};
    Address address2 = {"Ижевск", "Бабушкина", 5, 14, 428059};

    printAddress(address1);
    printAddress(address2);

    return 0;
}
