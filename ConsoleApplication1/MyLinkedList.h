#pragma once

template <class T>
class MySingleLinkedList
{
private:
	template <class D>
	struct Node
	{
		D Data = D();
		Node<D>* pNext = nullptr;
	};

public:
	MySingleLinkedList() {}
	~MySingleLinkedList() { Release(); }

public:
	void push_front(T Data) { 
		Node<T>* pNode = new Node<T>();
		pNode->Data = Data;

		if (nullptr == m_pHead)
		{
			m_pHead = pNode;
			m_pTail = pNode;
		}
		else
		{
			pNode->pNext = m_pHead;
			m_pHead = pNode;
		}
	}

	void push_back(T Data) {
		Node<T>* pNode = new Node<T>();
		pNode->Data = Data;

		if (nullptr == m_pHead)
		{
			m_pHead = pNode;
			m_pTail = pNode;
		}
		else
		{
			m_pTail->pNext = pNode;
			m_pTail = pNode;
		}
	}

	void pop_front() {
		if (!m_pHead)
			return;

		Node<T>* pNext = nullptr;
		if (nullptr != m_pHead->pNext)
			pNext = m_pHead->pNext;

		delete m_pHead;
		m_pHead = nullptr;

		if (nullptr != pNext)
			m_pHead = pNext;
		else
			m_pTail = nullptr;
	}

	void pop_back() {
		if (!m_pTail)
			return;

		Node<T>* pNode = m_pHead;
		while (pNode && pNode->pNext != m_pTail)
			pNode = pNode->pNext;

		if (pNode)
		{
			delete pNode->pNext;
			pNode->pNext = nullptr;

			m_pTail = pNode;
		}
		else
		{
			delete m_pTail;
			m_pTail = nullptr;
			m_pHead = nullptr;
		}
	}

	T front() {
		if (nullptr != m_pHead)
			return m_pHead->Data;

		return T();
	}

	T back() {
		if (nullptr != m_pTail)
			return m_pTail->Data;

		return T();
	}

	void insert(int Num, T Data) {
		Node<T>* pNode = m_pHead;
		for (int i = 0; i < Num; ++i)
			pNode = pNode->pNext;

		Node<T>* pNewNode = new Node<T>();
		pNewNode->Data = Data;

		if (!m_pHead)
		{
			m_pHead = pNewNode;
			m_pTail = pNewNode;
		}
		else if (!pNode->pNext)
		{
			m_pTail->pNext = pNewNode;
			m_pTail = pNewNode;
		}
		else
		{
			pNewNode->pNext = pNode->pNext;
			pNode->pNext = pNewNode;
		}
	}

	void erase(int Num) {
		
	}

	T Get_Data(int Num) {
		Node<T>* pNode = m_pHead;
		for (int i = 0; i < Num; ++i)
			pNode = pNode->pNext;

		return pNode->Data;
	}

	int size() {
		if (!m_pHead)
			return 0;

		Node<T>* pNode = m_pHead;
		int Cnt = 1;
		while (pNode->pNext)
		{
			pNode = pNode->pNext;
			++Cnt;
		}

		return Cnt;
	}

private:
	void Release() {
		while (m_pHead)
		{
			Node<T>* pNextNode = nullptr;
			if (m_pHead->pNext)
				pNextNode = m_pHead->pNext;

			delete m_pHead;
			m_pHead = pNextNode;
		}

		m_pTail = nullptr;
	}

private:
	Node<T>* m_pHead = nullptr;
	Node<T>* m_pTail = nullptr;
};