/*********************************
 * Reviewer: 				
 * Author: Yohai Azoulai			
 * File: stack_v4_test.cpp				
 * ******************************/

#include "stack.hpp" 
/*******Defines******/

#define NO_USE(A)  ((void)(A))

/*******Structs******/



/*******Service Funcs******/

static size_t GetSize(Stack x);


/*******Funcs Funcs******/

int main(int argc, char *argv[])
{
    int peeked_number = 0;
    int nums_to_push[10] = {10,11,12,13,14,15,16,17,19,18};
    Stack stack_to_use(10);
    Stack stack_to_use2;

    for (size_t i = 0; i < 10 ; ++i)
    {
        stack_to_use << (nums_to_push[i]);
    }
    
    stack_to_use >> peeked_number;
    std :: cout << peeked_number;
    std :: cout << "\n";

    -- -- --stack_to_use;
    
    stack_to_use >> peeked_number;
    std :: cout << peeked_number;
    std :: cout << "\n";

    if(16 != peeked_number)
    {
        std :: cout << peeked_number;
        std :: cout << " - peek failed\n";
    }
    std :: cout << peeked_number;
    std :: cout << " - peek is\n";


    if(7 != stack_to_use.Size())
    {
        std :: cout << "size failed\n";
    }

    GetSize(stack_to_use);

    NO_USE(argc);
    NO_USE(argv);
    
    return 0;
}




static size_t GetSize(Stack x)
{
    return x.Size();
}
