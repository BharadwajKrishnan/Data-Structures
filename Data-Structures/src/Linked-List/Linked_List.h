//============================================================================
// Name        : Linked_List.h
// Author      : Bharadwaj Krishnan
// Version     : -
// Copyright   : Your copyright notice
// Description : Template Class for a Linked List
//============================================================================

#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

#include <iostream>

template<typename T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node* next;
    };

    Node* m_head;
    Node* m_tail;

    Node* m_curr;
    Node* m_temp;

    int m_size;
public:
    /** Initialize data structure here. */
    LinkedList()
    {
    	m_size = 0;

        m_head = nullptr;
        m_tail = nullptr;
        m_curr = nullptr;
        m_temp = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    T get(int index)
    {
        T ret = -1;
        int loc = 0;

        m_curr = m_head;

        if(m_curr == nullptr)
            return ret;

        while(m_curr != nullptr)
        {
            if(index == loc)
            {
                ret = m_curr->value;
                break;
            }

            // Move to next element
            m_curr = m_curr->next;
            loc++;
        }

        return ret;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(T val)
    {
        if(m_head == nullptr)
        {
            m_head = new Node();

            m_head->value = val;
            m_head->next = nullptr;

            // Update current element to head
            m_curr = m_head;

            m_size++;
        }

        else if(m_head != nullptr)
        {
            addAtIndex(0, val);
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(T val)
    {
       addAtIndex(m_size, val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, T val)
    {
        if(m_size < index)
        {
            return;
        }

        int loc = 0;
        m_curr = m_head;

        Node* previous_node = nullptr;


        if(index == m_size)
        {
            m_temp = new Node();

            if(m_curr == 0)
            {
                m_head = new Node();
                m_head->value = val;
                m_head->next = nullptr;

                m_size++;

                return;
            }

            while(m_curr->next != nullptr)
            {
                m_curr = m_curr->next;
            }

            m_curr->next = m_temp;
            m_temp->value = val;
            m_temp->next = nullptr;

            m_tail = m_temp;

            m_size++;

            return;
        }

        while(m_curr != nullptr)
        {
            if(loc == index)
            {
                m_temp = new Node();

                if(previous_node != nullptr)
                {
                    previous_node->next = m_temp;
                }

                if(loc == 0)
                    m_head = m_temp;

                m_temp->value = val;
                m_temp->next = m_curr;

                m_size++;

                break;
            }

            previous_node = m_curr;

            // Move to next element
            m_curr = m_curr->next;
            loc++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if(m_size < index)
            return;

        m_curr = m_head;

        int loc = 0;

        Node* previous_node = nullptr;

        while(m_curr != nullptr)
        {
            if(loc == index)
            {
                if(previous_node != nullptr)
                    previous_node->next = m_curr->next;

                if(loc == 0)
                    m_head = m_curr->next;

                m_size--;
                break;
            }

            previous_node = m_curr;

            // Move to next element
            m_curr = m_curr->next;
            loc++;

        }
    }

};


#endif /* LINKED_LIST_LINKED_LIST_H_ */
