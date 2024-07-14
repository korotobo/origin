#include <iostream>
#include <vector>
#include <set>
#include <list>

template<class T>
void PrintContainer(const T& Container)
{
    for (auto& i : Container)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}


int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four"};
    PrintContainer(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four"};
    PrintContainer(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four"};
    PrintContainer(test_vector);

    return 0;
}
