//============================================================================
// Name        : Circular_Buffer.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template Class for a Circular Buffer
//============================================================================

#ifndef CIRCULAR_BUFFER_CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_CIRCULAR_BUFFER_H_

#include <iostream>

template<typename T, size_t N>
class CircularBuffer
{
private:
	T* m_buffer;
	size_t m_size;

	// Points to data
	size_t m_head, m_tail;

public:
	// Constructor
	CircularBuffer()
	{
		m_buffer = new T[N];
		m_size = 0;

		m_head = 0;
		m_tail = 0;
	}

	bool insert(T data)
	{
		if (m_head == N)
		{
			m_head = 0;
		}
		m_buffer[m_head++] = data;
		m_size++;

		return true;
	}

	T pop()
	{
		if (m_size == 0)
			return -1;

		if (m_tail == N)
		{
			m_tail = 0;
		}

		return m_buffer[m_tail++];
	}

	size_t size()
	{
		return N;
	}

	~CircularBuffer()
	{
		delete[] m_buffer;
	}
};


#endif /* CIRCULAR_BUFFER_CIRCULAR_BUFFER_H_ */

