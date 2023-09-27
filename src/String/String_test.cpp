/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include <stdio.h>
#include <iostream>
#include <vector>
#include "String.hpp" 
/*******Defines******/

#define NO_USE(A)  ((void)(A))

/*******Structs******/



/*******Service Funcs******/

String foo()
{
    String res("Hello");
    res[3] = 'x';
    return res;
}

/*******Funcs Funcs******/

int main(int argc, char *argv[])
{
    #if 0
    std::vector<String> v1(30);

    #else
    String str1 = "hello";
    String str2 = "world";
    String str3("Oxy"); // first task
    String str4(str3); // second task
    String str5;
    /* const */ String str6("yohai"); // when adding const to this init this wont compile
    const char *str7 = "nu ma?";
    const char *str8 = "bekitzor";
    const char *str9 = "bekitzor";

    if(str1 != str3)
    {
        puts("Str 1 isnt Str3");
    }
    str5 = str2; // third task
/*     "possiable?" == str7;
 */    if(str1 == str5)
    {
        puts("Str 5 is Str1");
    }
    
    int length_str5 = str5.Length();

    std::cout << str5 << std::endl;
    std::cout << length_str5 << std::endl; // forth task
    std::cout << str3 << std::endl;

    str6 =(&str3[1]);

    if(str1 > str2)
    {
        std::cout << "hello is bigger than world" << std::endl;
    }

    if(str1 < str2)
    {
        std::cout << "world is bigger than hello (w = 119 , h = 104)" << std::endl;
    }

    if(str7 == str8)
    {
        std::cout << "walla hedpis" << std::endl;
    }

    if(str9 == str8)
    {
        std::cout << "walla hedpis 6262626" << std::endl;
    }

    String str = foo();

    std::cout <<(str6) << std::endl;

    NO_USE(argc);
    NO_USE(argv);
    #endif
    return 0;
}
