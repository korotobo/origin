#include "figure.h"
#include <iostream>

Figure::Figure(){sides = 0;  name = "Фигура";}

std::string Figure::getName(){return name;}

bool Figure::check(){
    if(sides == 0) return true;
    else return false;
}
void Figure::print(){
    std::cout << name << ":" << std::endl;
    if(this->check()) {std::cout << "Правильная" << std::endl;}
    else {std::cout << "Неправильная" << std::endl;}
    std::cout << "Количество сторон: " << sides << std::endl;
}
