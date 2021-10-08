#pragma once
#include <cassert>

//template<class T>
class Array
{
public:
	int m_maxSize; // Maximum size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Number of items currently in my array
};