#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H


#include <stdexcept>

class MyException : public std::domain_error
{
public:

    // using std::domain_error::domain_error;
    MyException(const std::string& message = "фигура не создана");
};

#endif // MY_EXCEPTION_H
