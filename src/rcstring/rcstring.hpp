/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#pragma once
 
#include <ostream> /* ostrem& */
#include <cstddef> /* size_t */


namespace ilrd
{

class RcString;
bool operator==(const RcString& lhs, const RcString& rhs); // symmetric equality
bool operator!=(const RcString& lhs, const RcString& rhs);
bool operator<(const RcString& lhs, const RcString& rhs); 
bool operator>(const RcString& lhs, const RcString& rhs);
std::ostream& operator<<(std::ostream& cout, const RcString& str);



class RcString
{
private : 

class Proxy_Char // Proxy Public
{
public :
    /* non-explicit */ Proxy_Char(RcString& m_str, size_t index);
    void operator=(char a);
    void operator=(const Proxy_Char& p);
    operator char() const;
private :
    RcString& m_str;
    std::size_t m_index;

}; //class Proxy_Char

public: // RCstring Public

    /* non- explicit */RcString(const char *str = "");	//CTOR
    RcString(const RcString& str);				        //CCTOR
    ~RcString(); 								        //Destructor
    RcString& operator=(const RcString& other);         //Assignment
    
    size_t Length() const;
    
    char *Cstr() const;
    Proxy_Char operator[](size_t index);                 //This is the non const func
    const Proxy_Char operator[](size_t index) const;     //This function is for the const parameters

private : // RCstring Private
    class StringData;
    void Setter(char a, int index);
    char Getter(int index);
    StringData *m_data;
public :
    
    
}; //class RcString




}// namespace ilrd

