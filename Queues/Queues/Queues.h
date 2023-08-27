#pragma once
#include <iostream>

using namespace std;

template<typename T>
class ListQueues
{
public:
	struct Node;

public:
	static Node* Create(T** data)
	{
		Node* node = new Node();
		node->Data = *data;
		node->Next = NULL;

		return node;
	}

public:
	void Push_Back(Node* node)
	{
		if (m_Head == NULL)
		{
			node->Next = NULL;
			m_Head = node;
			return;
		}

		Node* end = m_Head;
		while (end->Next != NULL)
		{
			end = end->Next;
		}
		end->Next = node;
		node->Next = NULL;
	}

	Node* Pop_Front()
	{
		if (m_Head == NULL)
		{
			return NULL;
		}

		Node* firstNode = m_Head;
		Node* secondNode = m_Head->Next;
		if (secondNode == NULL)
		{
			m_Head = NULL;
			return firstNode;
		}

		m_Head = secondNode;
		return firstNode;
	}

	void RemoveAll()
	{
		if (m_Head == NULL)
		{
			return;
		}

		if (m_Head->Next == NULL)
		{
			delete m_Head;
			m_Head = NULL;
			return;
		}

		Node* end = m_Head;
		while (end->Next != NULL)
		{
			Node* Temp = end;
			end = end->Next;

			delete Temp;
		}

		m_Head = NULL;
	}

	int GetSize()
	{
		if (m_Head == NULL)
		{
			return 0;
		}

		Node* end = m_Head;
		int count = 1;

		while (end->Next != NULL)
		{
			end = end->Next;
			count++;
		}

		return count;
	}

	//Print Node <Àç±Í ÇÔ¼ö>
	void Print(Node* node = NULL)
	{
		if (node == NULL)
		{
			if (m_Head != NULL)
			{
				cout << *m_Head->Data;
				if (m_Head->Next != NULL)
				{
					cout << " -> ";
					Print(m_Head->Next);
				}
			}
			return;
		}
		cout << *node->Data;
		if (node->Next != NULL)
		{
			cout << " -> ";
			Print(node->Next);
		}
		else
		{
			cout << endl;
		}
	}

public:
	struct Node
	{
		T* Data;
		Node* Next;
	};

private:
	Node* m_Head = NULL;
};