#include <iostream>
#include "BigReal.h"
#include "BigReal.cpp"
#include "BigDecimalIntClass.cpp"

using namespace std;

int main()
{
    BigReal a(146.0);
    BigReal b("179.0");
    BigDecimalInt c("123");
    BigReal d(c);
    BigReal e = a;
    BigReal f = move(a);
    BigReal g;
    g = b;
    BigReal h;
    h = move(b);
    a.getNum();
    b.getNum();
    d.getNum();
    e.getNum();
    f.getNum();
    g.getNum();
    h.getNum();
    return 0;
}