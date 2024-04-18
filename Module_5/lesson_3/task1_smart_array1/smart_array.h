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
    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;

    void addElement(const int value);
    int getElement(const int index);
    void printSmartArray();

    ~SmartArray();
};

#endif // SMART_ARRAY_H
