#pragma once

template<class T>
class CMyQueue
{
public:
	CMyQueue() : m_pQueue(nullptr), m_iSize(0) {}
	~CMyQueue() { Release(); }

public:
	inline void Enqueue(T value)
	{
		if (nullptr == m_pQueue)
		{
			m_pQueue = new T[++m_iSize];
			memset(m_pQueue, 0, sizeof(T));
		}
		else
		{
			auto pTemp = new T[++m_iSize];
			memset(pTemp, 0, m_iSize * sizeof(T));
			memcpy(pTemp, m_pQueue, (m_iSize - 1) * sizeof(T));
			Release();
			m_pQueue = new T[m_iSize];
			memcpy(m_pQueue, pTemp, m_iSize * sizeof(T));
		}

		m_pQueue[m_iSize - 1] = value;
	}

	inline T Dnqueue() {
		T Value = T();

		if (nullptr != m_pQueue)
			Value = m_pQueue[0];

		if (0 != m_iSize - 1)
		{
			auto pTemp = new T[--m_iSize];
			memcpy(pTemp, &m_pQueue[1], m_iSize * sizeof(T));
			Release();
			m_pQueue = new T[m_iSize];
			memcpy(m_pQueue, pTemp, m_iSize * sizeof(T));
		}
		else
		{
			Release();
			m_iSize = 0;
		}

		return Value;
	}

	inline const T& operator[] (int idx) const {
		if (m_iSize <= idx)
			return T();

		return m_pQueue[idx];
	}

	inline const int& size() const { return m_iSize; }

	inline const bool& empty() const { return m_iSize == 0 ? true : false; }

private:
	inline void Release() {
		if (nullptr != m_pQueue)
		{
			if (1 < m_iSize)
				delete[] m_pQueue;
			else
				delete m_pQueue;

			m_pQueue = nullptr;
		}
	}

private:
	T* m_pQueue = nullptr;
	int m_iSize = 0;
};