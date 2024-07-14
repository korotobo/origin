#include <iostream>
#include <vector>
#include <algorithm>

template<class T>
void PrintV(const std::vector<T>& v0)
{
    for (auto& i : v0)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

template<class T>
void RemovingDuplicates(std::vector<T>& v0)
{
    std::sort(v0.begin(), v0.end());
    auto last = std::unique(v0.begin(), v0.end());
    v0.erase(last, v0.end());
}

int main()
{
    std::vector<int> v1{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    PrintV(v1);

    RemovingDuplicates(v1);

    std::cout << "[OUT]: ";
    PrintV(v1);

    return 0;
}
