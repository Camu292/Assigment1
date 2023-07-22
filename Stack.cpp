#include "Stack.h"
#include <stdexcept>

// Constructor
template <typename T>
Stack<T>::Stack(int initialSize) : size(initialSize), top(-1)
{
    if (initialSize <= 0)
    {
        throw std::invalid_argument("Stack size must be greater than 0.");
    }

    array = new T[size];
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
    delete[] array;
}

// Push an item onto the stack
template <typename T>
void Stack<T>::Push(T item)
{
    if (top == size - 1)
    {
        throw std::overflow_error("Stack is full.");
    }

    array[++top] = item;
}

// Pop an item from the stack
template <typename T>
T Stack<T>::Pop()
{
    if (top == -1)
    {
        throw std::underflow_error("Stack is empty.");
    }

    return array[top--];
}

// Get the count of items on the stack
template <typename T>
int Stack<T>::GetCount() const
{
    return top + 1;
}

// Peek at the top item of the stack
template <typename T>
T Stack<T>::Peek() const
{
    if (top == -1)
    {
        throw std::underflow_error("Stack is empty.");
    }

    return array[top];
}