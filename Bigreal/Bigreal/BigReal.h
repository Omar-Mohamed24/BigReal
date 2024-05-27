#pragma once
// File: BigReal.cpp
// Purpose: Create a class to hold bigger real numbers called BigReal.
// Author:  Omar mohamed abdelmelek. 
// Section: S19
// Date: 12 Oct 2023
#ifndef _BIGREAL_HPP
#define _BIGREAL_HPP
#include <iostream>
#include <string.h>
#include <regex>
#include <algorithm>
using namespace std;

class BigReal
{
private:
    char sign = '+';
    string integer = "0", fraction = "0";
    bool isValid = 0;
public:
    BigReal(); // Default constructor.
    BigReal(string realNumber); // Initializing realNumber.
    BigReal(const BigReal& other); // Copy contructor.
    // We dont need an Assignment Operator ( = ) as we are using strings.
    bool operator > (BigReal& other); // Bigger than operator.
    bool operator < (BigReal& other); // Smaller than operator.
    bool operator == (BigReal& other); // equallity operator.



    BigReal operator + (BigReal& other);
    BigReal operator - (BigReal& other);
    friend ostream& operator << (ostream& out, BigReal num);
    void print();
};
#endif
