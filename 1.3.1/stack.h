#ifndef _STACK_H_
#define _STACK_H_

#include <vector>

template <typename T>
class StackItr;

template <typename T>
class Stack
{
friend class StackItr<T>;

public:
    Stack() = default;
    Stack(const Stack& oriStack) = default;
    Stack(Stack&& oriStack) noexcept = default; 
    Stack& operator= (const Stack& oriStack) = default;
    Stack& operator= (Stack&& oriStack) noexcept = default;
    ~Stack() = default;

    bool isEmpty() const { return m_Items.empty(); }
    size_t size() const { return m_Items.size(); }

    const StackItr<T> begin() const { return StackItr<T>{*this, 0}; }
    StackItr<T> begin() { return StackItr<T>{*this, 0}; }
    const StackItr<T> end() const { return StackItr<T>{*this, size()}; }
    StackItr<T> end() { return StackItr<T>{*this, size()};}

    void push(const T& item) { m_Items.push_back(item); }
    void push(T&& item) { m_Items.push_back(std::move(item)); }

    T pop()
    {
        T tempItem = m_Items.back();
        m_Items.pop_back();
        return std::move(tempItem);
    }

private:
    std::vector<T> m_Items;
};

#endif

