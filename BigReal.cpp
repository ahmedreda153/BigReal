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

BigReal BigReal::operator+(BigReal other)
{
    BigDecimalInt c("2");
    BigReal result;
        int x = beforePoint.sign();
    int y = other.beforePoint.sign();
    int carry = 0;
    BigDecimalInt a("1");
    result.afterPoint = afterPoint + other.afterPoint;
    result.beforePoint = beforePoint + other.beforePoint;
    if (result.afterPoint.getNumber().length() > afterPoint.getNumber().length() && result.afterPoint.getNumber().length() > other.afterPoint.getNumber().length())
    {
        cout << "\n1" << endl;
        result.beforePoint = beforePoint + other.beforePoint + a;
        result.afterPoint.setNumber(result.afterPoint.getNumber().substr(1, result.afterPoint.getNumber().length() - 1));
    }

    else if (afterPoint.getNumber().length() == other.afterPoint.getNumber().length())
    {
        if (result.afterPoint < afterPoint && result.afterPoint < other.afterPoint)
        {
            cout << "\n2" << endl;
            result.beforePoint = beforePoint + other.beforePoint + a;
            result.afterPoint.setNumber(result.afterPoint.getNumber().substr(0, result.afterPoint.getNumber().length() - 1));
        }
        else
        {
            cout << "\n3" << endl;
            result.beforePoint = beforePoint + other.beforePoint;
        }
    }
    else
    {
        cout << "\n4" << endl;
        result.beforePoint = beforePoint + other.beforePoint;
    }
    // if (x == y && x == 1)
    // {
    //     cout << '-';
    //     result.beforePoint = result.beforePoint - c;
    // }
    // if (x != y && x == 1)
    // {
    //     cout << '-';
    //     result.afterPoint = afterPoint - other.afterPoint;
    //     result.beforePoint = result.beforePoint - a;
    // }
    // if (x != y && y == 1)
    // {
    //     result.afterPoint = other.afterPoint - afterPoint;
    //     result.beforePoint = result.beforePoint - a;
    // }
    return result;
}
BigReal BigReal::operator-(BigReal other)
{
    BigReal result;
    BigDecimalInt a("10");
    BigDecimalInt b("1");

    int borrow = 0;
    // big decimal float subtract
    // borrow

    if (beforePoint < other.beforePoint)
    {
        result.beforePoint = other.beforePoint - beforePoint;
        result.afterPoint = other.afterPoint - afterPoint;
        if (result.afterPoint < BigDecimalInt("0"))
        {
            result.beforePoint = result.beforePoint - b;
            result.afterPoint = result.afterPoint + a;
        }
        result.beforePoint.setNumber("-" + result.beforePoint.getNumber());
        cout << '-';
    }
    else if (afterPoint < other.afterPoint)
    {
        afterPoint.setNumber("1" + afterPoint.getNumber());
        result.beforePoint = beforePoint - other.beforePoint - b;
        result.afterPoint = afterPoint - other.afterPoint;
    }

    else
    {
        result.beforePoint = beforePoint - other.beforePoint;
        result.afterPoint = afterPoint - other.afterPoint;
    }
    return result;
}

bool BigReal:: operator< (BigReal other){
    if(beforePoint<other.beforePoint){
      return true;
    }
    else if(beforePoint==other.beforePoint){
      if(afterPoint<other.afterPoint){
         return true;
      }
      else{
         return false;
      }
    }
    else{
      return false;
    }
}
bool BigReal:: operator>(BigReal other){
    if(beforePoint>other.beforePoint){
      return true;
    }
    else if(beforePoint==other.beforePoint){
      if(afterPoint>other.afterPoint){
         return true;
      }
      else{
         return false;
      }
    }
    else{
      return false;
    }
}
bool BigReal::operator==(BigReal other){
    if(beforePoint==other.beforePoint && afterPoint==other.afterPoint){
      return true;
    }
    else{
      return false;
    }
}
// int BigReal::size(){
//     return beforePoint.size()+afterPoint.size();

// }


int BigReal::sign(){
    if(beforePoint.sign()==1){
      return 1;
    }
    else{
      return 0;
    }
}
ostream& operator << (ostream& out, BigReal num){
    out << num.beforePoint << "." << num.afterPoint;
    return out;
}
istream& operator >> (istream& in, BigReal& num){
    string realNumber;
    in >> realNumber;
    int index = realNumber.find('.');
    num.beforePoint.setNumber(realNumber.substr(0, index));
    num.afterPoint.setNumber(realNumber.substr(index + 1, realNumber.length() - 1));
    return in;
}

