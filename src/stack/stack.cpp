/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
 
 /*  */

#include "stack.hpp"

/*******Defines******/



/*******Structs******/



/*******Service Funcs******/



/*******Funcs Funcs******/

Stack::Stack(size_t number_of_elments): m_size(0), 
                                        m_capacity(number_of_elments), 
                                        m_stack(new int[number_of_elments])
{

}

void Stack::Push(int element_to_push)
{
    m_stack[m_size] = element_to_push;
    ++m_size;
}

void Stack::Pop()
{
    --m_size;
}

int Stack::Peek() const
{
    return m_stack[m_size-1];
}

size_t Stack::Size() const
{
    return m_size;
}

Stack::Stack(const Stack &other_): 
                                m_size(other_.m_size), 
                                m_capacity(other_.m_capacity), 
                                m_stack(new int[other_.m_capacity])
{
    memcpy(m_stack, other_.m_stack,sizeof(int) * m_size);
}

Stack::~Stack()
{
    delete[] m_stack;
}



Stack& Stack::operator<<(int element_to_push)
{
    Push(element_to_push);
    return *this;
}

void Stack::operator>>(int& peeked_element) const
{
    peeked_element = Peek();
}

Stack& Stack::operator--()
{
    Pop();
    return *this;
}


