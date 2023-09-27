/*********************************
 * Author: Yohai Azulai
 * File: Bitarray.hpp
 * ******************************/


#pragma once
#include <iostream>
#include <cstdio>
#include <cstddef>
#include <vector>
#include <algorithm>


/**************************The BitArray Class**********************************/

template<size_t SIZE>
class BitArray
{
private:
    class Proxy;

public:
    explicit BitArray(); // Ctor 

	bool operator==(const BitArray& other);
	bool operator!=(const BitArray& other);
    	Proxy operator[](size_t index); 
   	bool operator[](size_t index) const;
	BitArray& operator<<=(size_t shift);
	BitArray& operator>>=(size_t shift);
	void Set(size_t index, bool value);
	bool Get(size_t index) const;
    	size_t GetLit() const;
	size_t GetSize() const;
/* 	void PrintInBinary();
 */
private:
	static const size_t m_ChunkSize = sizeof(size_t) * __CHAR_BIT__;
	static const size_t m_size = (SIZE + m_ChunkSize - 1)/m_ChunkSize; 
	std::vector<size_t> m_arr;
	size_t m_count_on;
    
};// Class BitArray

/********************Functor Class*************************************/

class Functor
{
public:
	Functor();
    void operator()(const size_t& chunk);
	operator size_t() const;
	

private:
    size_t m_count;

}; // class Functor

/**************************Shift Class**********************************/

class Shift
{
public:
	Shift(size_t elem_shift);
    size_t operator()(size_t lhs, size_t rhs);
					

private:
    size_t m_num_shifts;

}; // class Shift

/*********************************The Proxy Class**************************/

template<size_t SIZE>
class BitArray<SIZE>::Proxy
{
public:
	Proxy(BitArray<SIZE>& ba, size_t index);
	operator bool() const;
	bool operator=(bool var);
	bool operator=(const Proxy& other);

private:
	BitArray<SIZE>& m_ba;
	size_t m_index;
}; // class Proxy


/*************************************************************************/
/***********************Bitarray Functions********************************/

template<size_t SIZE> 
typename BitArray<SIZE>::BitArray& BitArray<SIZE>::operator<<=(size_t shift) 
{
	size_t gd_shift = shift%m_ChunkSize;
	size_t number_of_chunks = shift/m_ChunkSize;
    Shift instance(gd_shift);
	std::transform(m_arr.begin() + number_of_chunks, 
					m_arr.end() - 1, 
					m_arr.begin() + number_of_chunks + 1,
					m_arr.begin(),
					Shift(gd_shift));

	m_arr.at((m_size - 1) - number_of_chunks) = instance(m_arr.at(m_size - 1),0);

	std::fill(m_arr.end() - number_of_chunks, m_arr.end() , 0);

	return *this;
}

template <size_t SIZE>
BitArray<SIZE>::BitArray() : m_arr(m_size,0){}

template <size_t SIZE>
inline size_t BitArray<SIZE>::GetSize() const
{
	return m_ChunkSize;
}

template <size_t SIZE>
bool BitArray<SIZE>::operator==(const BitArray &other)
{
    /* !memcmp(this->m_arr,other.m_arr,this->m_size); */
    return m_arr == other.m_arr;
}

template <size_t SIZE>
bool BitArray<SIZE>::operator!=(const BitArray &other)
{
    return !(m_arr == other.m_arr);
}

template <size_t SIZE>
typename BitArray<SIZE>::Proxy BitArray<SIZE>::operator[](size_t index)
{
    return Proxy(*this,index);
}

template <size_t SIZE>
bool BitArray<SIZE>::operator[](size_t index) const
{
	return Get(index);
}

template <size_t SIZE>
void BitArray<SIZE>::Set(size_t index, bool value)
{
	size_t shift_indx = index % m_ChunkSize;
	size_t arr_indx = m_size - (index / m_ChunkSize) - 1;

	size_t tmp = static_cast<size_t>(value);

	m_arr[arr_indx] &= ~(static_cast<size_t>(1) << shift_indx);
	m_arr[arr_indx] |= (tmp << shift_indx); 
}

template <size_t SIZE>
bool BitArray<SIZE>::Get(size_t index) const
{
    size_t result = static_cast<size_t>(1);
	size_t arr_indx = m_size - (index / m_ChunkSize) -1;
	size_t shift_indx = index % m_ChunkSize;
	
	result <<= shift_indx;
	
	return (0 != (result & m_arr[arr_indx]));
}

template <size_t SIZE>
inline size_t BitArray<SIZE>::GetLit() const
{
    size_t count = std::for_each(m_arr.begin(), m_arr.end(),Functor());
	
	return count;
}


/***********************Proxy Functions********************************/

template<size_t SIZE>
BitArray<SIZE>::Proxy::Proxy(BitArray<SIZE>& ba, size_t index) : m_ba(ba) , m_index(index)
{}

template<size_t SIZE>
BitArray<SIZE>::Proxy::operator bool() const
{
	return m_ba.Get(m_index);
}

template<size_t SIZE> 
bool BitArray<SIZE>::Proxy::operator=(bool var)
{
	m_ba.Set(m_index, var);
	return m_ba.Get(m_index);
}

template<size_t SIZE>
bool BitArray<SIZE>::Proxy::operator=(const Proxy &other) 
{
	return *this = static_cast<bool>(other);
}

/***********************Functor Functions********************************/

Functor::Functor() : m_count(0) {}

void Functor::operator()(const size_t &x)
{
	size_t count_set_on = x; 
	int count = 0;
	while(count_set_on)
	{
		count_set_on = count_set_on & (count_set_on-1);
		++count;
	}
	m_count += count;
}

inline Functor::operator size_t() const { return m_count; }

/***********************Shift Functions********************************/

Shift::Shift(size_t elemnt_shift) : m_num_shifts(elemnt_shift) {}

size_t Shift::operator()(size_t lhs, size_t rhs)
{
	return ((lhs << m_num_shifts) | 
				(rhs >> ((sizeof(size_t) * __CHAR_BIT__) - m_num_shifts)));
}



