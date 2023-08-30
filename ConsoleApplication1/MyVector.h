#pragma once

template<class T>
class CMyVector
{
public:
	CMyVector() : m_pVector(nullptr), m_iSize(0) {}
	~CMyVector() { Release(); }

public:
	inline void reserve(int size) {
		if (nullptr == m_pVector)
		{
			m_pVector = new T[size];
			memset(m_pVector, 0, _msize(m_pVector));
		}
		else
		{
			auto pTemp = new T[size];
			memset(pTemp, 0, _msize(pTemp));
			memcpy(pTemp, m_pVector, _msize(m_pVector));
			Release();
			m_pVector = new T[size];
			memset(m_pVector, 0, _msize(pTemp));
			memcpy(m_pVector, pTemp, _msize(pTemp));
		}
	}

	inline void push_back(T value) {
		int memsize = capacity();
		if (memsize <= m_iSize++)
			reserve(0 == memsize ? 1 : memsize * 2);

		m_pVector[m_iSize - 1] = value;
	}

	inline void pop_back() {
		memset(&m_pVector[(m_iSize--) - 1], 0, sizeof(T));
	}

	inline const int& capacity() {
		return !m_pVector ? 0 : _msize(m_pVector) / sizeof(T);
	}

	inline const int& size() const {
		return m_iSize;
	}

	inline void clear() const {
		memset(m_pVector, 0, _msize(m_pVector)); m_iSize = 0;
	}

	inline const bool& empty() const {
		return 0 == m_iSize ? true : false;
	}

	inline T& front() const {
		return 0 == m_iSize ? T() : m_pVector[0];
	}

	inline void insert(int insertIndex, T value) const {
		
	}

	inline void erase(int insertIndex, T value) const {

	}

	inline void swap(CMyVector<T>& rhs) {
		CMyVector<T> Temp;
		Temp.m_iSize = rhs.m_iSize;
		Temp.m_pVector = new T[Temp.m_iSize];
		memcpy(Temp.m_pVector, rhs.m_pVector, _msize(rhs.m_pVector));

		rhs = *this;
		*this = Temp;
	}

public:
	inline T& operator[] (int iIndex) const {
		return m_pVector[iIndex];
	}

	inline void operator= (CMyVector<T>& rhs) {
		Release();
		m_iSize = rhs.m_iSize;
		m_pVector = new T[m_iSize];
		memcpy(m_pVector, rhs.m_pVector, _msize(rhs.m_pVector));
	}

private:
	inline void Release()
	{
		if (nullptr != m_pVector)
		{
			if (1 < capacity())
				delete[] m_pVector;
			else
				delete m_pVector;

			m_pVector = nullptr;
		}
	}

private:
	T* m_pVector = nullptr;
	int m_iSize = 0;
};