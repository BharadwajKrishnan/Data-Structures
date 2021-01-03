#include "Stack.h"

namespace Queue_Costly_enQueue
{
	template<typename U, size_t N>
	class Queue
	{
	private:
		Stack<U, N> m_stack_1;
		Stack<U, N> m_stack_2;

		int m_size;

	public:
		// Constructor
		Queue()
		{
			m_size = 0;
		}

		// Insert data to the queue
		bool insert(U data)
		{
			bool ret = false;

			if (m_size >= N)
				return false;

			// Add all data from stack 1 to stack 2
			while (!m_stack_1.empty())
			{
				m_stack_2.insert(m_stack_1.pop());
			}

			// Add data to stack_1
			m_stack_1.insert(data);
			ret = true;
			m_size++;



			// Get all data from stack 2 to stack 1
			while (!m_stack_2.empty())
			{
				m_stack_1.insert(m_stack_2.pop());
			}

			return ret;
		}

		// Get data from the queue
		U pop()
		{
			if (!m_stack_1.empty())
			{
				return m_stack_1.pop();
			}
			else
			{
				return -1;
			}
		}

		// Returns queue size
		size_t size()
		{
			return N;
		}

		// Destructor
		~Queue()
		{

		}
	};

}

namespace Queue_Costly_deQueue
{
	template<typename U, size_t N>
	class Queue
	{
	private:
		Stack<U, N> m_stack_1;
		Stack<U, N> m_stack_2;

		int m_size;

	public:
		// Constructor
		Queue()
		{
			m_size = 0;
		}

		// Insert data to queue
		bool insert(U data)
		{
			bool ret = false;

			// Add data to stack_1
			if (m_size < N)
			{
				m_stack_1.insert(data);
				ret = true;
				m_size++;
			}

			return ret;
		}

		// Returns queue size
		size_t size()
		{
			return N;
		}

		// Get data from the queue
		U pop()
		{
			// Add all data from stack 1 to stack 2
			while (!m_stack_1.empty())
			{
				m_stack_2.insert(m_stack_1.pop());
			}

			return m_stack_2.pop();
		}

		// Destructor
		~Queue()
		{

		}
	};
}
