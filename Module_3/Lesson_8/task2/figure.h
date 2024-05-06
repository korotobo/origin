#ifndef FIGURE_H
#define FIGURE_H

#include "my_exception.h"
#include <string>


class Figure : public MyException {
protected:
    int sides, sumAngles;
    std::string name;
public:
    Figure();

    std::string getName();

    virtual bool check();
    virtual void print();
};


#endif // FIGURE_H
