#pragma once

#include "stack.h"
#include <stdexcept>

template <class T>
class LinkedListStack : public Stack<T> {
private:
    struct Node {
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* top_node;

public:
    LinkedListStack() : top_node(nullptr) {}

    ~LinkedListStack() {
        while (top_node) {
            Node* temp = top_node;
            top_node = top_node->next;
            delete temp;
        }
    }

    void push(const T& value) override {
        Node* new_node = new Node(value);
        new_node->next = top_node;
        top_node = new_node;
    }

    T pop() override {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        T value = top_node->data;
        Node* temp = top_node;
        top_node = top_node->next;
        delete temp;
        return value;
    }

    T top() const override {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return top_node->data;
    }

    bool isEmpty() const override {
        return top_node == nullptr;
    }
};

