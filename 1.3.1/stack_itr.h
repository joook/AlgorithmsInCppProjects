#ifndef _STACK_ITR_H_
#define _STACK_ITR_H_

#include "stack.h"

template <typename T>
class StackItr
{
public:
    StackItr() = default;
    StackItr(const Stack<T>& stack, size_t position);
    StackItr(const StackItr<T>& originalItr) = default;
    StackItr(StackItr<T>&& originalItr) = default;
    StackItr& operator=(const StackItr<T>& originalItr) = default;
    StackItr& operator=(StackItr<T>&& originalItr) = default;
    ~StackItr() = default;

    inline T& operator*() { return *(m_ItemsPtr + m_CurrentPosition); }

    StackItr& operator++()
    {
        m_CurrentPosition++;
        return *this;
    }

    StackItr& operator++(int)
    {
        auto tempItr = *this;
        m_CurrentPosition++;
        return tempItr;
    }

    bool operator!= (const StackItr<T>& itr) const { return ((m_ItemsPtr != itr.m_ItemsPtr) || (m_CurrentPosition != itr.m_CurrentPosition)); }
    bool operator== (const StackItr<T>& itr) const { return ((m_ItemsPtr == itr.m_ItemsPtr) && (m_CurrentPosition == itr.m_CurrentPosition)); }

private:
    T* m_ItemsPtr;
    size_t m_CurrentPosition;
};

template <typename T>
StackItr<T>::StackItr(const Stack<T>& stack, size_t position)
    : m_ItemsPtr{const_cast<T*>(stack.m_Items.data())}
    , m_CurrentPosition{position}
{
}

#endif

