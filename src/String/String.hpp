/*********************************
 * Author: Yohai Azulai
 * ******************************/

#ifndef __STRING_HPP__ 
#define __STRING_HPP__

#include <ostream> /* ostrem& */
#include <cstddef> /* size_t */



class String;
bool operator==(const String& lhs, const String& rhs); // symmetric equality
bool operator!=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs); 
std::ostream& operator<<(std::ostream& cout, const String& str);



class String
{
public:

    /* non- explicit */String(char *str = "");	    //CTOR
    String(const String& str);				        //CCTOR
    ~String(); 								        //Destructor
    String& operator=(const String& other_);        //Assignment
    size_t Length() const;
    char& operator[](size_t index);                 //This is the non const func
    const char& operator[](size_t index) const;     //This function is for the const parameters
    
		
private:
    char *m_str;
    void DeletingBuffer();
}; // class String



#endif // __STRING_HPP__
