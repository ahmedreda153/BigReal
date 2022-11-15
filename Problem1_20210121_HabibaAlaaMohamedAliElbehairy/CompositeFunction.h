#ifndef CompositeFunction_H
#define CompositeFunction_H
#include "Function.h"
using namespace std;
class CompositeFunction:public Function
{
private:
    function<double(double)> f1;
    function<double(double)> f2;
    
    public:
    CompositeFunction(function<double(double)> f1,function<double(double)> f2):f1(f1),f2(f2) {
}
    double evaluateAt(double value) {
        return f1(f2(value));
    }
   
};
#endif
