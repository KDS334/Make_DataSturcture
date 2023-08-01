#pragma once

template <class T>
struct Node
{
	T* Data = nullptr;
	Node<T> next;
};

template <class T>
class CSingleLinkedList
{
public:
	CSingleLinkedList() { memset(m_Data, 0, sizeof(Node)); }

private:
	Node	m_Data;
};