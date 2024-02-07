#include "math_func.h"

double funcAdd (double a, double b) {return a + b;}
double funcSub (double a, double b) {return a - b;}
double funcMult (double a, double b) {return a * b;}
double funcDiv (double a, double b) {
    if(b !=0) return a / b;
    else return 1;
}
double funcExp (double a, double b) {
    double result = 1.0;
    for(int i = 1; i <=b; i++) {
        result = result * a;
    }
    return result;
}
