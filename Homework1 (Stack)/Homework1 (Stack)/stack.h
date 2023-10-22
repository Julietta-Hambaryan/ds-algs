#pragma once

template <typename T>
class Stack {
public:
    virtual void push(const T& value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
};
