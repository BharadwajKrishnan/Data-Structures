#include "pch.h"
#include "Queue.h"
#include <vector>
#include <algorithm>

TEST(Test_Queue_Size, QueueTesting)
{
	Queue_Costly_deQueue::Queue<int, 10> queue;

	EXPECT_EQ(10, queue.size());
}

TEST(Succesfully_Insert_An_Element, QueueTesting)
{
	Queue_Costly_deQueue::Queue<int, 10> queue;

	EXPECT_TRUE(queue.insert(3));
	EXPECT_TRUE(queue.insert(-1));
	EXPECT_TRUE(queue.insert(0));
	EXPECT_TRUE(queue.insert(29));
	EXPECT_TRUE(queue.insert(300));
}

TEST(Insert_More_Elements_Than_Queue_Size, QueueTesting)
{
	Queue_Costly_deQueue::Queue<int, 10> queue;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			EXPECT_TRUE(queue.insert(i));
		}
		else
		{
			EXPECT_FALSE(queue.insert(i));
		}
	}
}

TEST(Pop_from_empty_Queue, QueueTesting)
{
	Queue_Costly_deQueue::Queue<int, 10> queue;

	EXPECT_EQ(-1, queue.pop());
}

TEST(Insert_and_Pop_Testing, QueueTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10};

	Queue_Costly_deQueue::Queue<int, 10> queue;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(queue.insert(num));
	}

	// Pop Test
	for (int num : random_array)
	{
		EXPECT_EQ(num, queue.pop());
	}
}

TEST(Too_many_pop_commands, QueueTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10 };

	Queue_Costly_deQueue::Queue<int, 10> queue;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(queue.insert(num));
	}

	// Pop Test
	for (int i = 0; i < 100; i++)
	{
		if(i < 10)
			EXPECT_EQ(random_array[i], queue.pop());
		else
			EXPECT_EQ(-1, queue.pop());
	}
}