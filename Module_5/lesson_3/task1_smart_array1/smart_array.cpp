#include "smart_array.h"

SmartArray::SmartArray(const int size) {
    size_array = size;
    smart_array = new int[size] {};
}

void SmartArray::printSmartArray()
{
    for (int i = 0; i < size_array; i++)
        std::cout << smart_array[i] << " ";

    std::cout << std::endl;
};

void SmartArray::addElement(const int value)
{
    if (count >= size_array)
    {
        throw std::out_of_range("Нельзя добавить элемент. Размер массива меньше.");
    }
    smart_array[count++] = value;
};

int SmartArray::getElement(const int index)
{
    if ((index >= size_array) || (index < 0))
    {
        throw std::out_of_range("Некорректный индекс элемента.");
    }
    return smart_array[index];
};

SmartArray::~SmartArray() {
    delete[] smart_array;
}
