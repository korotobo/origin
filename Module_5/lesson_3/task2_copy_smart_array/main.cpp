#include <iostream>
#include "smart_array.h"

int main()
{
    try {
        SmartArray arr1(5);
        arr1.addElement(1);
        arr1.addElement(4);
        arr1.addElement(155);
        arr1.addElement(14);
        arr1.addElement(15);

        SmartArray arr2(2);
        arr2.addElement(44);
        arr2.addElement(34);

        std::cout << "arr1: ";
        arr1.printSmartArray();
        std::cout << "Получим второй элемент массива: " << arr1.getElement(1) << std::endl;

        std::cout << "arr2: ";
        arr2.printSmartArray();
        std::cout << "Получим второй элемент массива: " << arr2.getElement(1) << std::endl;

        arr1 = arr2;

        std::cout << "arr1 после копирования arr2: ";
        arr1.printSmartArray();
        std::cout << "Получим второй элемент массива: " << arr1.getElement(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
