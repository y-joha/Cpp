/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#pragma once

#include <iostream>


class Rational;

const Rational operator+(const Rational& lhs, const Rational& rhs);
const Rational operator-(const Rational& lhs, const Rational& rhs);
const Rational operator*(const Rational& lhs, const Rational& rhs);
const Rational operator/(const Rational& lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);

class Rational
{
public:
    /* Non - Explicit*/Rational(int num = 0, int denum = 1);       //CTOR
    /*
    Rational(const Rational& other);                               
    Rational& operator=(const Rational& other);                    
    ~Rational();
    These are to be created by compiler
    */
    inline int GetNumenetor() const {return m_numinator;}
    inline int GetDeNumenetor() const {return m_denuminator;}

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);
    

private:
    int m_numinator;
    int m_denuminator;
};// Class : Rational




