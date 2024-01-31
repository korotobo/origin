#include <iostream>

class Counter {
private:
    int count;
public:
    Counter() {this->count = 1;}
    Counter(int count) {this->count = count;}

    Counter counterWithParam() {
        int count;
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> count;
        Counter counter(count);
        return counter;
    }

    int resultCount() {return count;}

    int addCount() {count = ++count; return count;}
    int subCount() {count = --count; return count;}
};

int main()
{
    char command;
    std::string choiceInit;
    Counter counter;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите \"да\" или \"нет\": ";
    std::cin >> choiceInit;

    if(choiceInit == "да") counter = counter.counterWithParam();

    do {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        if (command == '+') counter.addCount();
        else if (command == '-') counter.subCount();
        else if(command == '=') std::cout << counter.resultCount() << std::endl;

    } while (!(command == 'x'));

    if (command == 'x') std::cout << "До свидания!" << std::endl;

    return 0;
}
