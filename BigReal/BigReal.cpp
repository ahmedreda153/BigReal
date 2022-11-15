#include "BigReal.h"
#include <iostream>
#include <string>

using namespace std;
void BigReal::getNum()
{
    cout << beforePoint.getNumber() + "." + afterPoint.getNumber() << endl;
}

bool BigReal::checkValidity(string input)
{
    regex validInput("[-+]?[0-9]*[.][0-9]*");
    return regex_match(input, validInput);
}

BigReal::BigReal(double realNumber = 0.0)
{
    // cout << "Default constructor" << endl;
    string str = to_string(realNumber);
    while (str[str.length() - 1] == '0')
    {
        str.erase(str.length() - 1);
    }
    int index = str.find('.');
    beforePoint.setNumber(str.substr(0, index));
    afterPoint.setNumber(str.substr(index + 1, str.length() - 1));
}

BigReal::BigReal(string realNumber)
{
    // cout << "string default constructor" << endl;
    if (checkValidity(realNumber))
    {
        int index = realNumber.find('.');
        beforePoint.setNumber(realNumber.substr(0, index));
        afterPoint.setNumber(realNumber.substr(index + 1, realNumber.length() - 1));
        if (afterPoint.getNumber() == "")
        {
            afterPoint.setNumber("0");
        }
        else if(beforePoint.getNumber()==""){
            beforePoint.setNumber("0");
        }
    }
    else
    {
        cout << "Invalid input" << endl;
        exit(1);
    }
}

BigReal::BigReal(BigDecimalInt bigInteger)
{
    // cout << "BigDecimalInt default constructor" << endl;
    beforePoint = bigInteger;
    afterPoint.setNumber("0");
}

BigReal::BigReal(const BigReal &other) // Copy constructor
{
    // cout << "Copy constructor" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
}

BigReal::BigReal(BigReal &&other) // Move constructor
{
    // cout << "Move constructor" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
}

BigReal &BigReal::operator=(BigReal &other) // Assignment operator
{
    // cout << "Assignment operator" << endl;
    beforePoint = other.beforePoint;
    afterPoint = other.afterPoint;
    return *this;
}

BigReal &BigReal::operator=(BigReal &&other) // Move assignment operator
{
    // cout << "Move assignment operator" << endl;
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
        if(x==1)
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
    result.beforePoint = beforePoint - other.beforePoint;
    result.afterPoint = afterPoint - other.afterPoint;
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
            cout << "-";
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
    BigDecimalInt a("1");
    BigReal result;
    if (res.afterPoint.getNumber().length() > afterPoint.getNumber().length() && res.afterPoint.getNumber().length() > other.afterPoint.getNumber().length())
    {
        res.beforePoint = beforePoint + other.beforePoint + a;
        res.afterPoint.setNumber(res.afterPoint.getNumber().substr(1, res.afterPoint.getNumber().length() - 1));
    }
    else if (afterPoint.getNumber().length() == other.afterPoint.getNumber().length())
    {

        if (res.afterPoint < afterPoint && res.afterPoint < other.afterPoint)
        {
            res.beforePoint = beforePoint + other.beforePoint + a;
            res.afterPoint.setNumber(res.afterPoint.getNumber().substr(0, res.afterPoint.getNumber().length() - 1));
        }
        else
        {
            res.beforePoint = beforePoint + other.beforePoint;
        }
    }
}

bool BigReal::operator<(BigReal other)
{
    if (beforePoint < other.beforePoint)
    {
        return true;
    }
    else if (beforePoint == other.beforePoint)
    {
        if (afterPoint < other.afterPoint)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool BigReal::operator>(BigReal other)
{
    if (beforePoint > other.beforePoint)
    {
        return true;
    }
    else if (beforePoint == other.beforePoint)
    {
        if (afterPoint > other.afterPoint)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool BigReal::operator==(BigReal other)
{
    if (beforePoint == other.beforePoint && afterPoint == other.afterPoint)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BigReal::size()
{
    cout << beforePoint << endl
         << afterPoint << endl; // test
    return beforePoint.size() + afterPoint.size();
}

int BigReal::sign()
{
    if (beforePoint.sign() == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
ostream &operator<<(ostream &out, BigReal num)
{
    out << num.beforePoint << "." << num.afterPoint;
    return out;
}
istream &operator>>(istream &in, BigReal &num)
{
    string realNumber;
    in >> realNumber;
    int index = realNumber.find('.');
    num.beforePoint.setNumber(realNumber.substr(0, index));
    num.afterPoint.setNumber(realNumber.substr(index + 1, realNumber.length() - 1));
    return in;
}