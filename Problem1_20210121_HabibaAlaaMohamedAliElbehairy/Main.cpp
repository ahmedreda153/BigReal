#include<bits/stdc++.h>
#include"SimpleFunction.h"
#include"DerivativeFunction.h"
#include"CompositeFunction.h"
using namespace std;
double (cube) (double n) {
    return( n * n * n);
}

double (second) (double d) {
    return d * d - 5 * d - 4;
}
double (fun) (double d) {
    return d * d - 3 * d - 4;
}
int main()
{
    SimpleFunction f1([](double n) -> double {return n * n;});
    cout<<f1.evaluateAt(5)<<endl;

    DerivativeFunction f2 (second,5);
    cout << f2.evaluateAt(5) << endl;

    CompositeFunction f3 (fun, cube);
    cout << f3.evaluateAt(5) << endl;
 
}


