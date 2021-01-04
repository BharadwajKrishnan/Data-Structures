//============================================================================
// Name        : Data-Structures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Using different Data structures
//============================================================================


#include "./Custom-Stack/Stack.h"
#include "./Custom-Queue/Queue.h"
#include "./Circular-Buffer/Circular_Buffer.h"
#include "./Linked-List/Linked_List.h"


int main()
{
	Stack<int, 10> stack;
	Queue_Costly_deQueue::Queue<float, 5> queue_1;
	Queue_Costly_enQueue::Queue<float, 5> queue_2;
	CircularBuffer<float, 6> c_buffer;
	LinkedList<float> list;

	return 0;
}
