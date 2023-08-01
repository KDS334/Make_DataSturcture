#pragma once

template<typename T>
class CMyStack
{
public:
    CMyStack() {}
    ~CMyStack() { Release(); }

public:
    inline void push(T value)
    {
        if (nullptr == m_pMyStack)
        {
            m_pMyStack = new T[++m_iSize];
            memset(m_pMyStack, 0, sizeof(T));
        }
        else
        {
            auto pTemp = new T[++m_iSize];
            memset(pTemp, 0, m_iSize * sizeof(T));
            memcpy(pTemp, m_pMyStack, (m_iSize - 1) * sizeof(T));
            Release();
            m_pMyStack = new T[m_iSize];
            memcpy(m_pMyStack, pTemp, m_iSize * sizeof(T));
        }

        m_pMyStack[m_iSize - 1] = value;
    }

public:
    inline const T& pop() {
        T Value = T();

        if (nullptr != m_pMyStack)
            Value = m_pMyStack[m_iSize - 1];

        if (0 != m_iSize - 1)
        {
            auto pTemp = new T[--m_iSize];
            memcpy(pTemp, m_pMyStack, m_iSize * sizeof(T));
            Release();
            m_pMyStack = new T[m_iSize];
            memcpy(m_pMyStack, pTemp, m_iSize * sizeof(T));
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

        return m_pMyStack[idx];
    }

    inline const int& size() const { return m_iSize; }

    inline const bool& empty() const { return m_iSize == 0 ? true : false; }

private:
    inline void Release() {
        if (nullptr != m_pMyStack)
        {
            if (1 < m_iSize)
                delete[] m_pMyStack;
            else
                delete m_pMyStack;

            m_pMyStack = nullptr;
        }
    }

private:
    T* m_pMyStack = nullptr;
    int m_iSize = 0;
};

