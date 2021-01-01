#include "pch.h"
#include "Stack.h"
#include <vector>
#include <algorithm>

TEST(Test_Stack_Size, StackTesting)
{
	Stack<int, 10> stack;

	EXPECT_EQ(10, stack.size());
}

TEST(Succesfully_Insert_An_Element, StackTesting)
{
	Stack<int, 10> stack;

	EXPECT_TRUE(stack.insert(3));
	EXPECT_TRUE(stack.insert(-1));
	EXPECT_TRUE(stack.insert(0));
	EXPECT_TRUE(stack.insert(29));
	EXPECT_TRUE(stack.insert(300));
}

TEST(Insert_More_Elements_Than_Stack_Size, StackTesting)
{
	Stack<int, 10> stack;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			EXPECT_TRUE(stack.insert(i));
		}
		else
		{
			EXPECT_FALSE(stack.insert(i));
		}
	}
}

TEST(Pop_from_empty_Stack, StackTesting)
{
	Stack<int, 10> stack;

	EXPECT_EQ(-1, stack.pop());
}

TEST(Insert_and_Pop_Testing, StackTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10};

	Stack<int, 10> stack;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(stack.insert(num));
	}

	// Pop Test
	std::reverse(random_array.begin(), random_array.end());
	for (int num : random_array)
	{
		EXPECT_EQ(num, stack.pop());
	}
}

TEST(Too_many_pop_commands, StackTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10 };

	Stack<int, 10> stack;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(stack.insert(num));
	}

	// Pop Test
	
	for (int i = 0; i < 100; i++)
	{
		if(i < 10)
			EXPECT_EQ(random_array[9-i], stack.pop());
		else
			EXPECT_EQ(-1, stack.pop());
	}
}