#pragma once
#include <cassert>

template<class T>
class UnorderedArray
{
public:
	// Constructor
	UnorderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // Is this a legal size for an array?
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_maxSize
			memset(m_array, 0, sizeof(T) * m_maxSize); // Explicitly set 0 to all elements in the array

			/*m_growSize = ((growBy > 0) ? growBy : 0);*/
			m_growSize = m_growSize*2;
		}
	}
	// Destructor
	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	// Insertion
	// Fast insertion for UnorderedArrays -- Big-O is O(1)
	void push(T val)
	{
		assert(m_array != nullptr); // Debugging purposes

		if (m_numElements >= m_maxSize) // Check if the array has to expand to accomodate the new data.
		{
			Array::Expand();
		}

		// May array has space for a new value. Lets's add it!
		m_array[m_numElements] = val;
		m_numElements++;
	}
	
	// Searching
	// Linear Search
	int search(T val)
	{
		assert(m_array != nullptr);

		// Brute-force Search
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
			{
				return i; // Return the index of where the item is located in the array
			}
		}

		return -1;
	}

	// Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);
		return m_array[index];
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
private:
// Private functions
	
private:
	// Private Variables
	T* m_array; // Pointer to the beginning of the array

	int m_maxSize; // Maximum size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Number of items currently in my array
};

