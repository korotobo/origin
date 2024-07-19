#include <iostream>
#include <vector>
#include <random>
#include <future>

template <typename It, typename F>
void parallelForEach(It begin, It end, F func);
template <typename It>
void printContainer(It begin, It end);

int main()
{
    int N = 10;
    std::vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        v.push_back(std::rand() % 100);
    }
    printContainer(v.cbegin(), v.cend());
    parallelForEach(v.begin(), v.end(), [](int& value) { value++; });
    printContainer(v.cbegin(), v.cend());

    return 0;
}

template<typename It, typename F>
void parallelForEach(It begin, It end, F func)
{
    auto currSize = std::distance(begin, end);
    if (currSize <= 1)
    {
        func(*begin);
        return;
    }
    auto mid = begin;
    std::advance(mid, currSize / 2);
    auto fut = std::async(parallelForEach<It, F>, begin, mid, func);
    parallelForEach(mid, end, func);
}

template <typename It>
void printContainer(It begin, It end)
{
    std::cout << "Контейнер: ";
    for (It i = begin; i < end; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}
