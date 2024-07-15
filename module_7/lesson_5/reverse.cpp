#include <iostream>

void reverse(int *numbers, int size)
{
    for(int i = 0; i < size/2; i++) {
        int tmp = numbers[i];
        numbers[i] = numbers[size - i - 1];
        numbers[size - i - 1] = tmp;
    }
}

void print(int *numbers, int size)
{
    for (int i = 0; i < size; i++){
        std::cout << numbers[i] << ' ';
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    int size, arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};

    size = sizeof(arr)/sizeof(int);

    std::cout << "До функции reverse: ";
    print(arr, size);

    reverse(arr, size);

    std::cout << "После функции reverse: ";
    print(arr, size);

    return 0;
}

