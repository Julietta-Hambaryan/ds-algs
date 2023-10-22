#include <iostream>
#include "arrayDeque.h"

ArrayDeque::ArrayDeque() : front(-1), rear(-1) {
}

void ArrayDeque::enqueueFront(int item) {
    if (isFull()) {
        std::cerr << "Deque is full" << std::endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE; /* if front has become - 1 it will be MAX_SIZE - 1 
                                                   otherwise it will be front - 1*/ 
    }
    data[front] = item;
}

void ArrayDeque::enqueueRear(int item) {
    if (isFull()) {
        std::cerr << "Deque is full" << std::endl;
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX_SIZE; /* if rear has become MAX_SIZE it will be 0
                                      otherwise rear + 1
                                      */
    }
    data[rear] = item;
}

int ArrayDeque::dequeueFront() {
    if (isEmpty()) {
        std::cerr << "Deque is empty" << std::endl;
        return -1;
    }

    int item = data[front];

    if (front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
    }

    return item;
}

int ArrayDeque::dequeueRear() {
    if (isEmpty()) {
        std::cerr << "Deque is empty" << std::endl;
        return -1;
    }

    int item = data[rear];

    if (front == rear) {
        front = rear = -1;
    }
    else {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    }

    return item;
}

bool ArrayDeque::isEmpty() const {
    return front == -1;
}

int ArrayDeque::size() const {
    if (isEmpty()) {
        return 0;
    }

    return (rear - front + 1 + MAX_SIZE) % MAX_SIZE;
}

bool ArrayDeque::isFull() const {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}
