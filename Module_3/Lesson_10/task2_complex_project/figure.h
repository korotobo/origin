#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure {
protected:
    int sides;
    std::string name;
public:
    Figure();

    std::string getName();

    virtual bool check();
    virtual void print();
};


#endif // FIGURE_H
