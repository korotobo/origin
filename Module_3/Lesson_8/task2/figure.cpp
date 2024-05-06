#include "figure.h"
#include <iostream>
#include "my_exception.h"

Figure::Figure() : MyException ()
{
    sides = 0;
    sumAngles = 0;
    name = "Фигура";
}

std::string Figure::getName(){return name;}

bool Figure::check(){
    if(sides > 0) return true;
    else return false;
}
void Figure::print(){
    std::cout << name << " создан:" << std::endl;
}


