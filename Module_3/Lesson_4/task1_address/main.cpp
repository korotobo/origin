#include <iostream>
#include <fstream>


class Address {

private:
    std::string city, street;
    int houseNum, apartNum;

public:
    Address(){}

    Address (std::string city, std::string street, int houseNum, int apartNum) {
        this->city = city;
        this->street = street;
        this->houseNum = houseNum;
        this->apartNum = apartNum;
    }
    std::string getOutputAddress() {
        std::string outputAddress = city + ", " + street + ", " + std::to_string(houseNum) + ", " + std::to_string(apartNum);
        return outputAddress;
    }
};

int main()
{
    std::ifstream addressBef("in.txt");


    if(addressBef.is_open()) {

        int qtyAddress;
        std::string strCity;
        std::string strStreet;
        int houseNum;
        int apartNum;
        std::ofstream addressAft("out.txt");
        Address address(strCity, strStreet, houseNum, apartNum);

        addressBef >> qtyAddress;
        addressAft << qtyAddress << std::endl;

        Address* addressArray = new Address[qtyAddress];

        for(int i = 0; i < qtyAddress; i++) {
            addressBef >> strCity;
            addressBef >> strStreet;
            addressBef >> houseNum;
            addressBef >> apartNum;
            addressArray[i] = Address(strCity, strStreet, houseNum, apartNum);
        }

        for(int i = (qtyAddress - 1); i >= 0; i--) {
            addressAft << addressArray[i].getOutputAddress() << std::endl;
        }

        delete[] addressArray;
        addressAft.close();
        addressBef.close();
    }

    else std::cout << "in.txt не открылся" << std::endl;

    return 0;
}
