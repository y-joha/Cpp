/*********************************
 * Reviewer: 				
 * Author: Yohai Azoulai			
 * File: stack_v4.hpp					
 * ******************************/

#ifndef __STACK_H__
#define __STACK_H__

#include <ostream>
#include <iostream>
#include <cstddef>
#include <cstring>



class Stack
{
public:

    explicit Stack(size_t number_of_elments = 60);
    void Push(int element_to_push);
    void Pop();
    int Peek() const; 
    size_t Size() const; 
    Stack(const Stack& other_);
//  type    func_ptr  (type parameter to give to function)    
    Stack& operator<<(int element_to_push);
    void operator>>(int& peeked_element) const;
    Stack& operator--();

    ~Stack();
private:
    int m_size;
    size_t m_capacity;
    int *m_stack;
/*     Stack(const Stack& other_); |by puting this function in Private we obtain 
a way to prevent user from sending by value
 */
};

/* struct Y
{
    Stack m_x;
    int m_i;
};//struct Y */


#endif 


