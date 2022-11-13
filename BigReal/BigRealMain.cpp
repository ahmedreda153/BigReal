#include <iostream>
#include "BigReal.h"
#include "BigReal.cpp"
#include "BigDecimalIntClass.cpp"

using namespace std;

int main()
{
    BigReal a("2.2");
    BigReal b(".1");
    // BigDecimalInt c("123");
    // BigReal d(c);
    // BigReal e = a;
    // BigReal f = move(a);
    // BigReal g;
    // g = b;
    // BigReal h;
    // h = move(b);
    // a.getNum();
    // b.getNum();
    // d.getNum();
    // e.getNum();
    // f.getNum();
    // g.getNum();
    // h.getNum();
    // BigReal q = a + b;
    cout << a << endl;
    cout << b;
    return 0;
}
//add number to left side in afterpoint
//  