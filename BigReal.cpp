#include "BigReal.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

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
    // if(str[0]=='-'){
    // afterPoint+=BigDecimalInt("-");
    // }
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

BigReal BigReal::operator+(BigReal other)
{
    BigReal result;
    int x = beforePoint.sign();
    int y = other.beforePoint.sign();
    int size1 = (afterPoint.getNumber().length() - other.afterPoint.getNumber().length());
    int size2 = (other.afterPoint.getNumber().length() - afterPoint.getNumber().length());
    if (x == y && x == 1)
    {
        beforePoint.setNumber(beforePoint.getNumber().substr(0, beforePoint.getNumber().length()));
        other.beforePoint.setNumber(other.beforePoint.getNumber().substr(0, other.beforePoint.getNumber().length()));
    }
    int carry = 0;
    BigDecimalInt a("1");

    if (afterPoint.getNumber().length() > other.afterPoint.getNumber().length())
    {
        for (size_t i = 0; i < size1; i++)
        {
            other.afterPoint.setNumber(other.afterPoint.getNumber() + "0");
        }
    }
    if (afterPoint.getNumber().length() < other.afterPoint.getNumber().length())
    {
        for (size_t i = 0; i < size2; i++)
        {
            afterPoint.setNumber(afterPoint.getNumber() + "0");
        }
    }
    if (x == y)
    {
        sum(result, other);
    }

    if (x == y && x == 1)
    {
        cout << '-';
    }

    else if (x != y && x == 1)
    {
        beforePoint.setNumber(beforePoint.getNumber().substr(0, beforePoint.getNumber().length()));
        if (beforePoint > other.beforePoint)
        {
            result.beforePoint = beforePoint - other.beforePoint;
            if (other.afterPoint < afterPoint)
            {
                result.afterPoint = afterPoint - other.afterPoint;
                while (result.afterPoint.getNumber().length() < afterPoint.getNumber().length())
                {
                    result.afterPoint.setNumber("0" + result.afterPoint.getNumber());
                }
            }
            else
            {
                afterPoint.setNumber("1" + afterPoint.getNumber());
                result.afterPoint = afterPoint - other.afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            cout << '-';
        }
        if (beforePoint < other.beforePoint)
        {
            result.beforePoint = other.beforePoint - beforePoint;
            if (other.afterPoint < afterPoint)
            {
                other.afterPoint.setNumber("1" + other.afterPoint.getNumber());
                result.afterPoint = other.afterPoint - afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            else
            {

                result.afterPoint = afterPoint - other.afterPoint;
            }
        }
    }

    else if (x != y && y == 1)
    {
        other.beforePoint.setNumber(other.beforePoint.getNumber().substr(0, other.beforePoint.getNumber().length()));
        if (beforePoint > other.beforePoint)
        {
            result.beforePoint = beforePoint - other.beforePoint;
            if (other.afterPoint < afterPoint)
            {
                result.afterPoint = afterPoint - other.afterPoint;
            }
            else
            {
                afterPoint.setNumber("1" + afterPoint.getNumber());
                result.afterPoint = afterPoint - other.afterPoint;

                result.beforePoint = result.beforePoint - a;
            }
        }
        if (beforePoint < other.beforePoint)
        {
            result.beforePoint = other.beforePoint - beforePoint;
            if (other.afterPoint < afterPoint)
            {
                other.afterPoint.setNumber("1" + other.afterPoint.getNumber());
                result.afterPoint = other.afterPoint - afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            else
            {
                result.afterPoint = other.afterPoint - afterPoint;
            }
            cout << '-';
        }
    }
    return result;
}

BigReal BigReal::operator-(BigReal other)
{
    BigReal result;
    BigDecimalInt a("1");
    int x = beforePoint.sign();
    int y = other.beforePoint.sign();
    int size1 = (afterPoint.getNumber().length() - other.afterPoint.getNumber().length());
    int size2 = (other.afterPoint.getNumber().length() - afterPoint.getNumber().length());
    if (afterPoint.getNumber().length() > other.afterPoint.getNumber().length())
    {
        for (size_t i = 0; i < size1; i++)
        {
            other.afterPoint.setNumber(other.afterPoint.getNumber() + "0");
        }
    }
    if (afterPoint.getNumber().length() < other.afterPoint.getNumber().length())
    {
        for (size_t i = 0; i < size2; i++)
        {
            afterPoint.setNumber(afterPoint.getNumber() + "0");
        }
    }
    result.beforePoint = beforePoint - other.beforePoint;
    result.afterPoint = afterPoint - other.afterPoint;
    if (x == y && x == 0)
    {
        if (beforePoint > other.beforePoint)
        {
            result.beforePoint = beforePoint - other.beforePoint;
            if (afterPoint > other.afterPoint)
            {
                result.afterPoint = afterPoint - other.afterPoint;
            }
            else
            {
                afterPoint.setNumber("1" + afterPoint.getNumber());
                result.afterPoint = afterPoint - other.afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
        }
        else if (beforePoint < other.beforePoint)
        {
            result.beforePoint = other.beforePoint - beforePoint;
            if (afterPoint > other.afterPoint)
            {
                other.afterPoint.setNumber("1" + other.afterPoint.getNumber());
                result.afterPoint = other.afterPoint - afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            else
            {
                result.afterPoint = other.afterPoint - afterPoint;
            }
            cout << "-";
        }
    }
    if (x != y && x == 1)
    {
        beforePoint.setNumber(beforePoint.getNumber().substr(0, beforePoint.getNumber().length()));
        sum(result, other);
        cout << '-';
    }
    if (x != y && y == 1)
    {
        other.beforePoint.setNumber(other.beforePoint.getNumber().substr(0, other.beforePoint.getNumber().length()));
        sum(result, other);
    }
    if (x == y && x == 1)
    {
        beforePoint.setNumber(beforePoint.getNumber().substr(0, beforePoint.getNumber().length()));
        other.beforePoint.setNumber(other.beforePoint.getNumber().substr(0, other.beforePoint.getNumber().length()));

        if (beforePoint > other.beforePoint)
        {
            result.beforePoint = beforePoint - other.beforePoint;
            if (afterPoint > other.afterPoint)
            {
                result.afterPoint = afterPoint - other.afterPoint;
            }
            else
            {
                afterPoint.setNumber("1" + afterPoint.getNumber());
                result.afterPoint = afterPoint - other.afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            cout<<"-";
        }
        else if (beforePoint < other.beforePoint)
        {
            result.beforePoint = other.beforePoint - beforePoint;
            if (afterPoint > other.afterPoint)
            {
                other.afterPoint.setNumber("1" + other.afterPoint.getNumber());
                result.afterPoint = other.afterPoint - afterPoint;
                result.beforePoint = result.beforePoint - a;
            }
            else
            {
                result.afterPoint = other.afterPoint - afterPoint;
            }
        }
    }

    return result;
}

void BigReal::sum(BigReal &res, BigReal &other)
{

    res.afterPoint = afterPoint + other.afterPoint;
    res.beforePoint = beforePoint + other.beforePoint;
    int carry = 0;
    BigDecimalInt a("1");
    if (res.afterPoint.getNumber().length() > afterPoint.getNumber().length() && res.afterPoint.getNumber().length() > other.afterPoint.getNumber().length())
    {
        cout << "\n1" << endl;
        res.beforePoint = beforePoint + other.beforePoint + a;
        res.afterPoint.setNumber(res.afterPoint.getNumber().substr(1, res.afterPoint.getNumber().length() - 1));
    }

    else if (afterPoint.getNumber().length() == other.afterPoint.getNumber().length())
    {
        if (res.afterPoint < afterPoint && res.afterPoint < other.afterPoint)
        {
            cout << "\n2" << endl;
            res.beforePoint = beforePoint + other.beforePoint + a;
            res.afterPoint.setNumber(res.afterPoint.getNumber().substr(0, res.afterPoint.getNumber().length() - 1));
        }
        else
        {
            // cout<<afterPoint.sign();
            cout << "\n3" << endl;
            res.beforePoint = beforePoint + other.beforePoint;
        }
    }
    else
    {
        cout << "\n4" << endl;
        res.beforePoint = beforePoint + other.beforePoint;
    }
}