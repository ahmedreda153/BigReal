#ifndef BigReal_H
#define BigReal_H

#pragma once

#include "BigDecimalIntClass.h"
#include <iostream>
#include <string>

using namespace std;

class BigReal
{
private:
    BigDecimalInt beforePoint;
    BigDecimalInt afterPoint;

public:
    void getNum();
    BigReal(double realNumber); // Default constructor
    BigReal(string realNumber);
    BigReal(BigDecimalInt bigInteger);
    BigReal(const BigReal &other);      // Copy constructor
    BigReal(BigReal &&other);           // Move constructor
    BigReal &operator=(BigReal &other); // Assignment operator
    BigReal &operator=(BigReal &&other); // Move assignment operator
    BigReal operator+(BigReal other);
    BigReal operator-(BigReal other);
    bool operator<(BigReal other);
    bool operator>(BigReal other);
    bool operator==(BigReal other);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal num);
   // friend istream& operator >> (istream& out, BigReal num);
    friend istream& operator >> (istream& in, BigReal& num);

};

#endif