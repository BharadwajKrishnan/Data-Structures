#include "pch.h"
#include "CBuffer.h"
#include <vector>
#include <algorithm>

TEST(Test_Buffer_Size, CircularBufferTesting)
{
	CircularBuffer<int, 10> buffer;

	EXPECT_EQ(10, buffer.size());
}

TEST(Succesfully_Insert_An_Element, CircularBufferTesting)
{
	CircularBuffer<int, 10> buffer;

	EXPECT_TRUE(buffer.insert(3));
	EXPECT_TRUE(buffer.insert(-1));
	EXPECT_TRUE(buffer.insert(0));
	EXPECT_TRUE(buffer.insert(29));
	EXPECT_TRUE(buffer.insert(300));
}

TEST(Insert_More_Elements_Than_Buffer_Size, CircularBufferTesting)
{
	CircularBuffer<int, 10> buffer;

	for (int i = 0; i < 100; i++)
	{
		if (i < 10)
		{
			EXPECT_TRUE(buffer.insert(i));
		}
		else
		{
			EXPECT_TRUE(buffer.insert(i));
		}
	}
}

TEST(Pop_from_empty_Buffer, CircularBufferTesting)
{
	CircularBuffer<int, 10> buffer;

	EXPECT_EQ(-1, buffer.pop());
}

TEST(Insert_and_Pop_Testing, CircularBufferTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10};

	CircularBuffer<int, 10> buffer;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(buffer.insert(num));
	}

	// Pop Test
	for (int num : random_array)
	{
		EXPECT_EQ(num, buffer.pop());
	}
}

TEST(Too_many_pop_commands, CircularBufferTesting)
{
	std::vector<int> random_array = { 2, -10, 4, 100, 23, 11, 56, 0, 99, 10 };

	CircularBuffer<int, 10> buffer;

	// Insert Test
	for (int num : random_array)
	{
		EXPECT_TRUE(buffer.insert(num));
	}

	// Pop Test
	for (int i = 0; i < 100; i++)
	{
		EXPECT_EQ(random_array[i%10], buffer.pop());
	}
}