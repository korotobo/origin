#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <set>

template<class T>
void print(const T& mPar, const std::string* letPar)
{
    std::cout << "[IN]: " << *letPar << std::endl;

    std::cout << "[OUT]:" << std::endl;
    for (const auto& m : mPar)
    {
        std::cout << m.second << ": " << m.first << '\n';
    }
}

int main()
{
    size_t numberOfRepeat = 0;
    std::string letters = "Hello world!!";
    std::multimap<size_t, char, std::greater<size_t>> m;

    std::set<char> s;

    for (size_t i = 0; i < letters.length(); i++)
    {
        s.insert(letters[i]);
    }

    for (const auto& i : s)
    {
        numberOfRepeat = std::count(letters.begin(), letters.end(), i);
        m.emplace(numberOfRepeat, i);
    }

    print(m, &letters);

    return 0;
}
