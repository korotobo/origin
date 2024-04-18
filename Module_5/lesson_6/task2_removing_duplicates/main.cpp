#include <iostream>
#include <set>

template<class T>
void print(const T& s)
{
    std::cout << "[OUT]:" << std::endl;
    for (const auto& i : s)
    {
        std::cout << i << std::endl;
    }
}

int main()
{
    int numberOfElements = 0;
    int elements = 0;
    std::set<int, std::greater<>> s;

    std::cout << "[IN]:" << std::endl;
    std::cin >> numberOfElements;

    while (numberOfElements)
    {
        std::cin >> elements;
        s.insert(elements);
        numberOfElements--;
    }

    print(s);

    return 0;
}
