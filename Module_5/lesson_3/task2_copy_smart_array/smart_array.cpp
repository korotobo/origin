#include "smart_array.h"

SmartArray::SmartArray(const int size) {
    size_array = size;
    smart_array = new int[size] {};
}

SmartArray::SmartArray(const SmartArray& other){
    this->size_array = other.size_array;
    this->count = other.count;

    smart_array = new int[other.size_array];
    for(int i = 0; i < other.size_array; i++) {
        this->smart_array[i] = other.smart_array[i];
    }
}

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
    if ((index >= count) || (index < 0))
    {
        throw std::out_of_range("Некорректный индекс элемента.");
    }
    return smart_array[index];
};

SmartArray& SmartArray::operator=(const SmartArray& other){
    if(this==&other) {return *this;}    //исключаем самоприсваивание
    delete[] smart_array;               //освобождение памяти
    this->size_array = other.size_array;
    this->count = other.count;

    smart_array = new int[other.size_array];
    for(int i = 0; i < other.size_array; i++) {
        this->smart_array[i] = other.smart_array[i];
    }
    return *this;
};

void SmartArray::printSmartArray()
{
    for (int i = 0; i < size_array; i++)
        std::cout << smart_array[i] << " ";

    std::cout << std::endl;
};

SmartArray::~SmartArray() {
    delete[] smart_array;
}
