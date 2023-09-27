/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
 
 /*  */
#include <iostream>
#include <unistd.h>   /*usleep*/

#include "scopelock.hpp"
/*******Defines******/



/*******Structs******/



/*******Service Funcs******/



/*******Funcs Funcs******/
#ifndef true
unsigned long Fibonacci::NextNum()
{
    PMutexLock PMut1;
    ScopedLock<PMutexLock> bouncer(PMut1,false);

    unsigned long result = 0;
    result = this->m_num1 + this->m_num2;
    this->m_num1 = this->m_num2;    
    this->m_num2 = result;
    return result;
}
#else
unsigned long Fibonacci::NextNum()
{
    SpinLock PMut1;
    ScopedLock<SpinLock> bouncer(PMut1,false);

    unsigned long result = 0;
    result = this->m_num1 + this->m_num2;
    this->m_num1 = this->m_num2;    
    this->m_num2 = result;
    return result;
}
#endif
// PMutexLock CTOR
PMutexLock::PMutexLock() : m_occupied(false) {}
// PMutexLock DTOR
PMutexLock::~PMutexLock()
{
    pthread_mutex_destroy(&m_lock);
}
// PMutexLock Lock
int PMutexLock::lock()
{
    pthread_mutex_lock(&m_lock);
    m_occupied = true;
    return m_occupied;
}
// PMutexLock Unlock
int PMutexLock::unlock()
{
    pthread_mutex_unlock(&m_lock);
    m_occupied = false;
    return m_occupied;
}
// PMutexLock bool operator
PMutexLock::operator bool()
{
    return m_occupied;
}

// SpinLock CTOR
SpinLock::SpinLock() : m_occupied(0) {}
#ifdef false
{
    pthread_cond_init(m_flag,NULL);
}
#endif
// SpinLock DTOR
SpinLock::~SpinLock()
{
    pthread_mutex_destroy(&m_lock);
}
// SpinLock Lock
int SpinLock::lock()
{
    #ifdef false
    while (m_occupied)
    {
        pthread_cond_wait(&flag,&m_lock);
    }
    #endif
    // by puting line 99 out of the loop
    // we allow the Client to use this in a 
    // busy wait fashion
    m_occupied = pthread_mutex_lock(&m_lock);
    if(!m_occupied)
    {
        m_occupied = true;
    }
    return m_occupied;
}
// SpinLock Unlock
int SpinLock::unlock()
{
    pthread_mutex_unlock(&m_lock);
    #ifdef false
    pthread_cond_signal(&flag);
    #endif
    m_occupied = false;
    return m_occupied;
}
// SpinLock bool operator
SpinLock::operator bool()
{
    return m_occupied;
}
