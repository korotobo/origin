#include <iostream>
#include <vector>
#include <random>
#include <future>

void findMin(int begin, std::vector<int>& v, std::promise<int> value);
void choiceSort(std::vector<int>& v);
void printVector(std::vector<int>& v);

int main()
{
    int N = 10;
    std::vector<int> v;
    for (int i = 0; i < N; ++i)
    {
        v.push_back(std::rand() % 100);
    }
    printVector(v);
    choiceSort(v);
    printVector(v);

    return 0;
}

void findMin(int begin, std::vector<int>& v, std::promise<int> value)
{
    int imin = begin;
    for (int j = begin; j < v.size(); ++j)
    {
        if (v.at(j) < v.at(imin))
        {
            imin = j;
        }
    }
    value.set_value(imin);
}

void choiceSort(std::vector<int>& v)
{
    int temp, itemp;
    for (int i = 0; i < v.size(); ++i)
    {
        std::promise<int> value;
        std::future<int> valueFuture = value.get_future();
        std::future<void> fut = std::async(std::launch::async, findMin, i, std::ref(v), std::move(value));
        fut.wait();
        itemp = valueFuture.get();
        temp = v.at(itemp);
        v.at(itemp) = v.at(i);
        v.at(i) = temp;
    }
}

void printVector(std::vector<int>& v)
{
    std::cout << "Вектор: ";
    for (const auto& val : v)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
