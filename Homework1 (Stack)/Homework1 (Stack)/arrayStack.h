#pragma once
#include "stack.h"
#include <stdexcept>

template <class T>
class ArrayStack : public Stack<T> {
private:
    static const int INITIAL_CAPACITY = 10;
    T* arr;
    int capacity;
    int top_index;

public:
    ArrayStack() : capacity(INITIAL_CAPACITY), top_index(-1) {
        arr = new T[capacity];
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(const T& value) override {
        if (top_index == capacity - 1) {
            capacity *= 2;
            T* new_arr = new T[capacity];
            for (int i = 0; i <= top_index; ++i) {
                new_arr[i] = arr[i];
            }
            delete[] arr;
            arr = new_arr;
        }
        arr[++top_index] = value;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top_index--];
    }

    T top() const override {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top_index];
    }

    bool isEmpty() const override {
        return top_index == -1;
    }
};
