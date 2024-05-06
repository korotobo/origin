#include "my_exception.h"

// #include <stdexcept>

MyException::MyException(const std::string& message) : std::domain_error(message) {

}
