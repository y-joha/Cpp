/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
 
 /*  */
#include <ostream>
#include <iostream>
#include <cstddef>
#include <cstring>
#include <cassert>

#include "rational.hpp"
/*******Defines******/



/*******Structs******/



/*******Service Funcs******/


/*******Funcs Funcs******/

    static int GreatestCommonDenum(int n1, int n2);

    Rational::Rational(int num, int denum) : m_numinator(num) , m_denuminator(denum) {}

    const Rational operator+(const Rational &lhs, const Rational &rhs)
    {
        int nums = 0 , denums = 1 , gcd = 0;
        nums = (lhs.GetNumenetor() * rhs.GetDeNumenetor() + rhs.GetNumenetor() * lhs.GetDeNumenetor());
        denums = (lhs.GetDeNumenetor() * rhs.GetDeNumenetor());
        
        gcd = GreatestCommonDenum(nums, denums);
        Rational temp(nums/gcd, denums/gcd);

        return temp;
    }

    const Rational operator-(const Rational &lhs, const Rational &rhs)
    {
        int nums = 0 , denums = 1 , gcd = 0;
        nums = (lhs.GetNumenetor() * rhs.GetDeNumenetor() - rhs.GetNumenetor() * lhs.GetDeNumenetor());
        denums = (lhs.GetDeNumenetor() * rhs.GetDeNumenetor());
        
        gcd = GreatestCommonDenum(nums, denums);
        Rational temp(nums/gcd, denums/gcd);

        return temp;
    }
    const Rational operator*(const Rational &lhs, const Rational &rhs)
    {
        int nums = 0 , denums = 1 , gcd = 1;
        nums = (lhs.GetNumenetor() * rhs.GetNumenetor());
        denums = (lhs.GetDeNumenetor() * rhs.GetDeNumenetor());
        
        gcd = GreatestCommonDenum(nums, denums);
        Rational temp(nums/gcd, denums/gcd);

        return temp;
    }
    const Rational operator/(const Rational &lhs, const Rational &rhs)
    {
        int nums = 0 , denums = 1 , gcd = 0;
        nums = (lhs.GetNumenetor() * rhs.GetDeNumenetor());
        denums = (lhs.GetDeNumenetor() * rhs.GetNumenetor());
        
        gcd = GreatestCommonDenum(nums, denums);
        Rational temp(nums/gcd, denums/gcd);

        return temp;
    }
    bool operator==(const Rational &lhs, const Rational &rhs)
    {
        int lgcd = GreatestCommonDenum(lhs.GetNumenetor(), lhs.GetDeNumenetor());
        int rgcd = GreatestCommonDenum(rhs.GetNumenetor(), rhs.GetDeNumenetor());
        if((lhs.GetNumenetor()/lgcd) == (rhs.GetNumenetor()/rgcd) && (lhs.GetDeNumenetor()/lgcd) == (rhs.GetDeNumenetor()/rgcd))
        {
            return true;    
        }
        return false;
    }
    bool operator!=(const Rational &lhs, const Rational &rhs)
    {
        if(lhs == rhs)
        {
            return false;
        }
        return true;
    }
    
    Rational &Rational::operator+=(const Rational &other)
    {
        /* if(this->m_denuminator == other.GetGetDeNumenetor())
        {
            this->m_numinator += other.GetNumenetor();
            int gcd = GreatestCommonDenum(this->m_numinator, this->GetGetDeNumenetor());
            this->m_numinator/= gcd;
            this->m_denuminator/= gcd;
            return *this;  
        }
        
        
        this->m_numinator += other.GetNumenetor();
        this->m_denuminator += other.GetGetDeNumenetor(); */
        return *this = *this + other;
    }
    
    Rational &Rational::operator-=(const Rational &other)
    {
        return *this = *this - other;
    }
    
    Rational &Rational::operator*=(const Rational &other)
    {
        return *this = *this * other;
    }
    
    Rational &Rational::operator/=(const Rational &other)
    {
        return *this = *this / other;
    }

    static int GreatestCommonDenum(int n1, int n2)
    {
        assert(0 == n2);
        
        int negative_flag = 1;
        if (0 > n1)
        {
            n1 = -n1;
            negative_flag = -1;
        }
        if (0 > n2)
        {
            n2 = -n2;
            negative_flag = -1;
        }
        
        while (n1 != n2)
        {
            if(n1 > n2)
            {
                n1 -= n2;
            }
            else
            {
                n2 -= n1;
            }
        }
        return ((0==n1)?1:n1);
        
    }
    
    static int abs(int a)
    {
        return a -= 2*a;
    }

