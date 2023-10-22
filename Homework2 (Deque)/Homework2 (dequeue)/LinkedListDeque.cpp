#include <iostream>
#include "linkedListDeque.h"

LinkedListDeque::LinkedListDeque() : front(nullptr), rear(nullptr), size(0) {}

LinkedListDeque::~LinkedListDeque() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void LinkedListDeque::enqueueFront(int item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    size++;
}

void LinkedListDeque::enqueueRear(int item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int LinkedListDeque::dequeueFront() {
    if (isEmpty()) {
        std::cerr << "Deque is empty" << std::endl;
    }

    int item = front->data;
    Node* temp = front;
    front = front->next;
    if (front) {
        front->prev = nullptr;
    }
    else {
        rear = nullptr;
    }
    delete temp;
    size--;
    return item;
}

int LinkedListDeque::dequeueRear() {
    if (isEmpty()) {
        std::cerr << "Deque is empty" << std::endl;
    }

    int item = rear->data;
    Node* temp = rear;
    rear = rear->prev;
    if (rear) {
        rear->next = nullptr;
    }
    else {
        front = nullptr;
    }
    delete temp;
    size--;
    return item;
}

bool LinkedListDeque::isEmpty() const {
    return size == 0;
}

int LinkedListDeque::getSize() const {
    return size;
}
