/*********************************
 * Reviewer: Werner Heizenberg				
 * Author: Yohai Azoulai			
 * File: String.cpp					
 * ******************************/
 
 /*  */
#include <ostream> /* ostrem& */
#include <cstddef> /* size_t */
#include <cstring> /* strlen */
#include <cassert> /*assert */

#include "String.hpp"
/*******Defines******/



/*******Structs******/



/*******Service Funcs******/



/*******Funcs Funcs******/

static char* BuildString(const char *str)
{
    char* buff = new char[strlen(str) + 1];

    return strcpy(buff, str);
}

void String::DeletingBuffer()
{
    delete[] m_str;
}

/* String String::Cstr()
{
    return ;
} */

String::String(char *str) : m_str(BuildString(str))  // CTOR
{}

String::String(const String &str) : m_str(BuildString(str.m_str))// CCTOR
{}

String::~String() // Destructor
{
    DeletingBuffer();
}

size_t String::Length() const
{
    return strlen(this->m_str);
}

char &String::operator[](size_t index)
{
    return const_cast<char&>(const_cast<const String&>(*this)[index]);
}

const char& String :: operator[](size_t index) const
{
    return m_str[index];
}

bool operator==(const String& lhs, const String& rhs) // symmetric equality
{
    if(strcmp(&lhs[0],&rhs[0]) == 0)
    {
        return true;
    }
    return false;
}

bool operator!=(const String& lhs, const String& rhs)
{
    if(lhs == rhs)
    {
        return false;
    }
    return true;
}

bool operator>(const String &lhs, const String &rhs)
{
    if(strcmp(&lhs[0],&rhs[0]) > 0)
    {
        return true;
    }
    return false;
}

bool operator<(const String &lhs, const String &rhs)
{
    if(lhs > rhs)
    {
        return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &cout, const String &str)
{
    cout << &str[0];
    return cout;
}

String& String::operator=(const String &other_)
{
    if(this != &other_)
    {
        char *str = BuildString(other_.m_str);
        DeletingBuffer();
        m_str = str;
    }
    return *this;
}


