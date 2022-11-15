#ifndef DerivativeFunction_H
#define DerivativeFunction_H

#include "Function.h"

using namespace std;
class DerivativeFunction:public Function
{
private:
    function<double(double)> XFunction;
    double delta_x;
     
public:
    DerivativeFunction(function<double(double)> func,double arg):XFunction(func),delta_x(arg) {}
    double evaluateAt(double x) {
        return (XFunction(x+delta_x)-XFunction(x-delta_x))/(2*delta_x);
    }
   
};
#endif
