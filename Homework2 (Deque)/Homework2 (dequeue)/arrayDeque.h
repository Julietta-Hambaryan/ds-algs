#pragma once

#include "deque.h"

class ArrayDeque : public Deque {

private:
    static const int MAX_SIZE = 10;
    int data[MAX_SIZE];
    int front;
    int rear;
public:
    ArrayDeque();

    void enqueueFront(int item) override;
    void enqueueRear(int item) override;
    int dequeueFront() override;
    int dequeueRear() override;
    bool isEmpty() const override;
    bool isFull() const;
    int size() const override;

};
