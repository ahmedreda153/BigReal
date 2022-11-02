#include "BigReal.h"
#include <iostream>
#include <string>

using namespace std;

void BigReal::getNum()
{
    cout << beforePoint.getNumber() + "." + afterPoint.getNumber() << endl;
}

BigReal::BigReal(double realNumber = 0.0)
{
    cout << "Default constructor" << endl;
    string str = to_string(realNumber);
    int index = str.find('.');
    beforePoint.setNumber(str.substr(0, index));
    afterPoint.setNumber(str.substr(index + 1, str.length() - 1));
}

BigReal::BigReal(string realNumber)
{
    cout << "string default constructor" << endl;
    int index = realNumber.find('.');
    beforePoint.setNumber(realNumber.substr(0, index));
    afterPoint.setNumber(realNumber.substr(index + 1, realNumber.length() - 1));
}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    cout << "BigDecimalInt default constructor" << endl;
    beforePoint = bigInteger;
    afterPoint.setNumber("0");
}

BigReal::BigReal(const BigReal &other) // Copy constructor
{
    cout << "Copy constructor" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
}

BigReal::BigReal(BigReal &&other) // Move constructor
{
    cout << "Move constructor" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
}

BigReal &BigReal::operator=(BigReal &other) // Assignment operator
{
    cout << "Assignment operator" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
    return *this;
}

BigReal &BigReal::operator=(BigReal &&other) // Move assignment operator
{
    cout << "Move assignment operator" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
    return *this;
}