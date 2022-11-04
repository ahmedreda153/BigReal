#include <iostream>
#include "BigReal.h"
#include "BigReal.cpp"
#include "BigDecimalIntClass.cpp"

using namespace std;

int main()
{
    BigReal a(-500.2333);
    BigReal b(+200.301);
    BigDecimalInt c("123");
    BigReal d;
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
    BigReal i = b;
    cin>>d;
    cout<<d<<endl;
    // i.getNum();
    // i.size();
    return 0;
}
//add number to left side in afterpoint
//  