#pragma once

class Deque {
public:
    virtual void enqueueFront(int item) = 0;
    virtual void enqueueRear(int item) = 0;
    virtual int dequeueFront() = 0;
    virtual int dequeueRear() = 0;
    virtual bool isEmpty() const = 0;
    virtual int size() const = 0;
};

