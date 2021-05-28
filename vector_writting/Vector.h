#pragma once

template <typename T>
class Vector {
public:
	Vector()
	{
		// allocate 2 elements
		ReAlloc(2);
	}

	~Vector()
	{
		delete[] m_Data;

		/*
		clear();
		::operator delete(m_Data, m_Capacity * sizeof(T));
		*/
	}

	void push_back(const T& value)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2); // grow 50%
		}

		m_Data[m_Size] = std::move(value); // move instead of copy for better performance
		m_Size++;
	}

	template <typename... Args>
	T& emplace_back(Args&&... args)
	{
		if (m_Size >= m_Capacity)
		{
			ReAlloc(m_Capacity + m_Capacity / 2); // grow 50%
		}

		// m_Data[m_Size] = T(std::forward<Args>(args)...); // Constructed here, and move into that memory
		new(&m_Data[m_Size]) T(std::forward<Args>(args)...);  // Constructed in-place, without move operation.
		return m_Data[m_Size++];
	}

	void pop_back()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void clear()
	{
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		m_Size = 0;
	}

	// non-const version index operator
	T& operator[](size_t index)
	{
		return m_Data[index];
	}
	// const version index operator
	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}
	// size function
	size_t size() const
	{
		return m_Size;
	}
private:
	void ReAlloc(size_t newCapacity)
	{
		// 1. allocate a new block of memory

		T* newBlock = new T[newCapacity];

		// Actually, we do not need to call the constructor of T here, 
		// what we want to do is just allocating enough memory.

		// T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

		// 2. copy or move old elements to new block
		if (newCapacity < m_Size) // if new capacity is smaller, update the m_size to shrink the vector
			m_Size = newCapacity;
		for (size_t i = 0; i < m_Size; i++)
		{
			newBlock[i] = std::move(m_Data[i]);
		}
		// 3. delete old block
		
		delete[] m_Data;

		// Instead of calling delete like this, we can write like:

		/*
		for (size_t i = 0; i < m_Size; i++)
			m_Data[i].~T();
		::operator delete(m_Data, m_Capacity * sizeof(T));
		*/

		m_Data = newBlock;
		m_Capacity = newCapacity;
	}

	T* m_Data = nullptr;

	size_t m_Size = 0;
	size_t m_Capacity = 0;
};