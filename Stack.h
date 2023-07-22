#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
public:
    Stack(int initialSize);
    ~Stack();

    void Push(T item);
    T Pop();
    int GetCount() const;
    T Peek() const;

private:
    T* array;
    int size;
    int top;
};


#endif

