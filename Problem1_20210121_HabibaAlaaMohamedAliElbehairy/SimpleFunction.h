#ifndef SimpleFunction_H
#define SimpleFunction_H
#include "Function.h"
using namespace std;
class SimpleFunction:public Function { 
    private:
    function<double(double)> function_h;

public:

    SimpleFunction(function<double(double)> h):function_h(h) {}
    double evaluateAt(double value) {
        return function_h(value);
    }
};
#endif
