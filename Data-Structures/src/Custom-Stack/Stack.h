//============================================================================
// Name        : Data-Structures.cpp
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template Class for a Stack
//============================================================================

#ifndef CUSTOM_STACK_STACK_H_
#define CUSTOM_STACK_STACK_H_

#include <iostream>

template<typename T, size_t N>
class Stack
{
private:
	T* m_stack;
	int m_sp;

public:
	// Constructor
	Stack()
	{
		m_stack = new T[N];
		m_sp = 0;
	}

	// Add data to the stack
	bool insert(T data)
	{
		bool ret = false;

		// Check if stack is full
		if(m_sp < N)
		{
			m_stack[m_sp++] = data;

			ret = true;
		}

		return ret;
	}

	// Get data from the stack
	T pop()
	{
		T ret = -1;	// Default return value

		// Check if stack is empty
		if(m_sp)
		{
			ret = m_stack[--m_sp];
		}

		return ret;
	}

	// Returns stack size
	size_t size()
	{
		return N;
	}

	// Destructor
	virtual ~Stack()
	{
		delete[] m_stack;
	}
};

#endif /* CUSTOM_STACK_STACK_H_ */
