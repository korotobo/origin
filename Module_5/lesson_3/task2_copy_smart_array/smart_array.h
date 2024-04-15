#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <iostream>

class SmartArray
{
private:
    int* smart_array;
    int size_array = 0;
    int count = 0;

public:
    SmartArray(const int size);

    void addElement(const int value);
    int getElement(const int index);
    SmartArray& operator=(const SmartArray& smart_array);
    void printSmartArray();

    ~SmartArray();
};

#endif // SMART_ARRAY_H
