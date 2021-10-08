#pragma once
#include <cassert>
#include "Array.h"

template<class T>
class OrderedArray : public Array
{
public:
	// Constructor
	OrderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size for an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSixe]; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	// Destructor
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Insertion
	// Fast insertion for UnorderedArrays -- Big-O is O(N)
	void push(T val)
	{
		assert(m_array != nullptr);

		if (m_numElements >= m_maxSize)
		{
			Expand();
		}

		int i, k; // i - Index to be inserted. k - Used for shifting purposes
		// Step 1: Find the index to insert val
		for (i = 0; i < m_numElements; i++)
		{
			if (m_array[i] > val)
			{
				break;
			}
		}

		// Step 2: Shift everything to the right of the index(i) forward by one. Work  backwards
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}

		// Step 3: Insert val into the array at index
		m_array[i] = val;
		m_numElements++;
		return i;
	}
	
	// Searching
	// Linear Search
	int search(T searchKey)
	{
		assert(m_array != nullptr);
		
		// Helper variables.
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while (1) // <-- Replaced with recursion
		{
			current = (lowerBound + upperBound) >> 1; // Preview of bitwise operations. Divides by 2

			// Binary search steps:
			// Step 1: Check if the middle is the value we are lokking for.
			if (m_array[current] == searchKey)
			{
				// Found the item in the middle of the array. Return the index
				return current;
			}
			// Step 2: Check that we've exhausted all options. Can't find the item.
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			// Step 3: Check which half of the array the value is in.
			else
			{
				if (m_array[current] < searchKey)
				{
					lowerBound = current + 1; // Value may be in the upper half
				}
				else
				{
					upperBound == current - 1; // Value may be in the lower half
				}
			}
		}

		return -1; // Catch all return from danger
	}
	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
	}
	// Clear
	void clear()
	{
		m_numElements = 0; // Ignore (or forgets) all current items in the array
	}
	// Gets and Sets
	int GetSize()
	{
		return m_numElements;
	}
	int GetMaxSize()
	{
		return m_maxSize;
	}
	int GetGrowSize()
	{
		return m_growSize;
	}
	int SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	// Private functions
		// Expansion
	bool Expand()
	{
		if (m_growSize <= 0)
		{
			// LEAVE!
			return false;
		}

		// Create the new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		// Copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		// Delete the old array
		delete[] m_array;

		// CLean up variable assignments
		m_array = temp;
		temp = nullptr;
		m_maxSize += m_growSize;

		return true;
	}
private:
	// Private Variables
	T* m_array; // Pointer to the beginning of the array

	int m_maxSize; // Maximum size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Number of items currently in my array
};
