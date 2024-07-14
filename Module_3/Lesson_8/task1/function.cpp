#include "function.h"
#include "utf8.h" //для поддержки кириллицы в UTF-8 с github sheredom/utf8.h

size_t function(std::string str, int forbidden_length)
{
    const char *cStr = str.c_str();

    size_t str_size = utf8len(cStr);

    if (forbidden_length == str_size)
    {
        throw std::exception();
    };

    return str_size;

}
