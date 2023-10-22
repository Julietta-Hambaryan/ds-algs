#pragma once

class LinkedListDeque {
private:
    class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    LinkedListDeque();
    ~LinkedListDeque();

    void enqueueFront(int item);
    void enqueueRear(int item);
    int dequeueFront();
    int dequeueRear();
    bool isEmpty() const;
    int getSize() const;
};

