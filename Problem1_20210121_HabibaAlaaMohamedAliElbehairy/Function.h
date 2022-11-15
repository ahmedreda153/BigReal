#ifndef Function_H
#define Function_H
#include<bits/stdc++.h>
class Function
{
public:
    virtual double evaluateAt(double value) = 0;
    friend double (cube) (double n);
    friend double (second) (double d);
    friend double (fun) (double d);
};
#endif