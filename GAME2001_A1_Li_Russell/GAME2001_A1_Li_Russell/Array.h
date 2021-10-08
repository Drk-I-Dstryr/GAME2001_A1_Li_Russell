#pragma once
#include <cassert>

template<class T>
class Array
{
public:
	// Deletion (2 ways)
	// Remove the last item inserted into the array
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; // Reduce the total number of elements by 1. Ignoring the last element.
		}
	}
	// Remove an item given an index
	// (Almost) Brute-force execution -- Big-O = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{
			// I am trying to remove something outside of the bounds of the array
			return; // <-- Maybe could do some form of exception handling
		}

		for (int i = index; i < m_numElements; i++)
		{
			// Start at the index we want to remove.
			// Shift everything after index back by one.
			if (i + 1 < m_numElements) // Confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
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

	T* m_array; // Pointer to the beginning of the array

	int m_maxSize; // Maximum size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Number of items currently in my array
};