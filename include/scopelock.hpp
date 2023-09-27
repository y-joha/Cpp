/*********************************
 * Reviewer:
 * Author: Elijaho Hanavi
 * File: ScopedLock.hpp
 * ******************************/
#pragma once

#include <pthread.h>  /*threads*/
#include <iostream>   /* cout */
#include <unistd.h>   /*usleep*/
#include <errno.h>    /*EBUSY Flags*/



template<typename LockMechanism>
class ScopedLock
{

public:
    explicit ScopedLock(LockMechanism &choice, bool defer);
    ~ScopedLock();
    void lock();
    void unlock();
    bool is_locked() const;
    
private:
    ScopedLock &operator=(const ScopedLock &m);
    ScopedLock(const ScopedLock &m);
    LockMechanism &m_lock;
    bool m_defer;
    bool m_owner;

}; // class ScopedLock
// CTOR
template<typename LockMechanism>
ScopedLock<LockMechanism>::ScopedLock(LockMechanism &choice, bool defer) : m_lock(choice), m_defer(defer) , m_owner(0)
{
    if(!defer)
    {
        m_lock.lock();
        m_owner = true;
    }
}
// DTOR
template <typename LockMechanism>
inline ScopedLock<LockMechanism>::~ScopedLock()
{
    if(m_owner) 
    {
        m_lock.unlock();
    }
}
// lock()
template<typename LockMechanism>
void ScopedLock<LockMechanism>::lock()
{
    if(!m_owner) 
    {
        m_lock->lock();
        m_owner = true;
    }
}

template <typename LockMechanism>
inline void ScopedLock<LockMechanism>::unlock()
{
    if(m_owner) 
    {
        m_lock.unlock();
        m_owner = false;
    }
}

template <typename LockMechanism>
inline bool ScopedLock<LockMechanism>::is_locked() const
{
    return m_owner;
}

class SpinLock
{
public:
    
    explicit SpinLock();
    ~SpinLock();
    int lock();
    int unlock();
    operator bool();
private:
    bool m_occupied;
    pthread_mutex_t m_lock = PTHREAD_MUTEX_INITIALIZER;
    SpinLock &operator=(const SpinLock &m); // assignment operator
    SpinLock(const SpinLock &m); // no copy constructor

    #ifdef false
    pthread_cond_t m_flag;
    #endif

}; // Class Spinlock - trylock/unlock

class PMutexLock
{
public:
    PMutexLock();
    ~PMutexLock(); 
    int lock();
    int unlock();
    operator bool();

private:
    bool m_occupied;
    pthread_mutex_t m_lock = PTHREAD_MUTEX_INITIALIZER;
    PMutexLock &operator=(const PMutexLock &m); // no assignment operator
    PMutexLock(const PMutexLock &m); // no copy constructor

}; // Class Mutexlock - lock/unlock

class Fibonacci
{
public:
    Fibonacci() : m_num1(0), m_num2(1) 
    {
        std::cout << "created fib"<< std::endl;
    }
    unsigned long NextNum();

private:
    unsigned long m_num1;
    unsigned long m_num2;
    pthread_mutex_t m_mutex = PTHREAD_MUTEX_INITIALIZER;
}; // class Fibonacci


