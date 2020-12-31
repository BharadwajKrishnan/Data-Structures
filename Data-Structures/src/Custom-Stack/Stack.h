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

public:
	// Constructor
	Stack()
	{
		m_stack = new T[N];
	}

	// Destructor
	virtual ~Stack()
	{
		delete[] m_stack;
	}
};

#endif /* CUSTOM_STACK_STACK_H_ */
