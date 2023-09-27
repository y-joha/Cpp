/*********************************
 * Author: Yohai Azoulai
 * File Name: SharedPointer.hpp
 * ******************************/

#pragma once

#include <cstddef> /* NULL definition */


template<typename T>
class SharedPointer
{
public:
	explicit SharedPointer(T* ptr = NULL);
	~SharedPointer();
    SharedPointer(const SharedPointer& other);
	SharedPointer& operator=(const SharedPointer& other);
    T& operator *() const;
	T* operator->() const;

    template<typename R>
    friend class SharedPointer;

private:
	/* Option A 
	class SPData;

	SPData<T> *m_sp;*/

	/* Option B */
	T* m_ptr;
	std::size_t* m_counter;
	
}; // class SharedPointer


// CTOR
template <typename T>
inline SharedPointer<T>::SharedPointer(T *ptr) : m_ptr(ptr) , m_counter(new size_t) {}

// DTOR
template <typename T>
inline SharedPointer<T>::~SharedPointer()
{
    *m_counter -= 1;
    if(!(*m_counter))
    {
        delete m_counter;
        delete m_ptr;
        m_ptr = NULL;
    }
}

// CCTOR
template <typename T>
inline SharedPointer<T>::SharedPointer(const SharedPointer &other) :m_ptr(other.m_ptr) , m_counter(++*(other.m_counter)) {}

// Assignment Operator
template <typename T>
inline SharedPointer<T> &SharedPointer<T>::operator=(const SharedPointer &other)
{
    // if you are last, finish up what was allocated
    *m_counter -= 1;
    if(!(*m_counter))
    {
        delete m_counter;
        delete m_ptr;
        m_ptr = NULL;
    }
    m_counter = other.m_counter;
    m_ptr = other.m_ptr;
    ++m_counter;
    
}

// Dereferrance Operator
template <typename T>
inline T &SharedPointer<T>::operator*() const
{
    return *this;
}

// Arrow -> Operator
template <typename T>
inline T *SharedPointer<T>::operator->() const
{
    return m_ptr;
}



