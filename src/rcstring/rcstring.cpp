/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
 
 /*  */
#include <iostream>
#include <cstddef> /* size_t*/
#include <cstring> /* memcpy*/

#include "rcstring.hpp"
/*******Defines******/



/*******Structs******/



/*******Service Funcs******/



/*******Funcs Funcs******/

namespace ilrd
{


class RcString::StringData
{
public:
    static StringData* Create(const char* str); // factory function
    bool IsShared();
    void Attach();
    void Detach();
    char *Cstr();  //getter for the string


private:
    explicit StringData(const char* str);
    std::size_t m_num_of_members;
    char m_str[1]; // flexable array
}; // Class StringData


RcString::StringData* RcString::StringData::Create(const char *str) 
{
    void * buff = :: operator new(offsetof(StringData, m_str) + strlen(str)+ 1);

    return new (buff) StringData(str); // placment new
}

RcString :: RcString(const char *str) : m_data(StringData::Create(str)) // CTOR RcString
{}

RcString::StringData::StringData(const char *str) : m_num_of_members(1) // CTOR StringData
{
    memcpy(m_str, str, strlen(str) + 1);
}

RcString :: RcString(const RcString& other) : m_data(other.m_data) // CCTOR RcString
{
    m_data->Attach();
}

RcString::~RcString()
{
    m_data->Detach();
}

RcString& RcString::operator=(const RcString& other)
{
    if(*this != other)
    {
        m_data->Detach();
        m_data = other.m_data;
        m_data->Attach();
    }
    return *this;
}

bool RcString::StringData::IsShared()
{
    return (m_num_of_members > 1);
}

void RcString::StringData::Attach()
{
    ++m_num_of_members; 
}

void RcString::StringData::Detach()
{
    --m_num_of_members;
    if(m_num_of_members == 0)
    {
        delete this;
    }
}

char *RcString::StringData::Cstr()
{
    return this->m_str;
}

std::size_t RcString::Length() const
{
    return strlen(m_data->Cstr());
}

char *RcString::Cstr() const
{
    return m_data->Cstr();
}

void RcString::Setter(char a, int index)
{
    m_data->Cstr()[index] = a;
}

char RcString::Getter(int index)
{
    char tmp = Cstr()[index];
    return tmp;
}

RcString::Proxy_Char RcString::operator[](size_t index)
{
    return Proxy_Char(*this, index);
}

const RcString::Proxy_Char RcString::operator[](size_t index) const
{
    return Proxy_Char(const_cast<RcString&>(*this)[index]);
}

bool operator==(const RcString& lhs, const RcString& rhs)
{
    return !(lhs != rhs);
}

bool operator!=(const RcString& lhs, const RcString& rhs)
{
    return strcmp(lhs.Cstr(),rhs.Cstr());
}

bool operator<(const RcString &lhs, const RcString &rhs)
{
    return !(lhs > rhs);
}

bool operator>(const RcString &lhs, const RcString &rhs)
{
    return strcmp(lhs.Cstr(),rhs.Cstr()) > 0;
}

std::ostream &operator<<(std::ostream &cout, const RcString& str)
{
    return cout << str.Cstr();
}



/**********************Proxy***********************/

RcString::Proxy_Char::Proxy_Char(RcString &m_data, size_t index) : m_str(m_data), m_index(index)
{}

void RcString::Proxy_Char::operator=(char a)
{
    if(m_str.m_data->IsShared())
    {
        m_str.m_data->Detach();
        m_str.m_data = m_str.m_data->Create(m_str.m_data->Cstr());
    }
    m_str.Setter(a,m_index);
}
void RcString::Proxy_Char::operator=(const Proxy_Char &p)
{
    char tmp = (p.m_str[p.m_index]);
    this->m_str[m_index] = tmp;
} 
RcString::Proxy_Char::operator char() const
{
    char tmp = m_str.Getter(m_index);
    return tmp;
}

}
