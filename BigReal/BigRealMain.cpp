#include <iostream>
#include "BigReal.h"
#include "BigReal.cpp"
#include "BigDecimalIntClass.cpp"

using namespace std;

int main()
{
    BigReal a("-5.6");
    BigReal b("-5.2");
    cout << a + b;
}
 