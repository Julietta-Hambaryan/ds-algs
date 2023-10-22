#include <iostream>
#include "arrayDeque.h"
#include "linkedListDeque.h"


bool runTest(bool (*testFunction)(), const char* testName) {
    bool result = testFunction();
    if (result) {
        std::cout << "PASSED: " << testName << std::endl;
    }
    else {
        std::cerr << "FAILED: " << testName << std::endl;
    }
    return result;
}


bool testArrayDequeEnqueueFrontAndDequeueFront() {
    ArrayDeque deque;
    deque.enqueueFront(1);
    deque.enqueueFront(2);

    return (deque.dequeueFront() == 2) && (deque.dequeueFront() == 1);
}

bool testArrayDequeEnqueueRearAndDequeueRear() {
    ArrayDeque deque;
    deque.enqueueRear(1);
    deque.enqueueRear(2);

    return (deque.dequeueRear() == 2) && (deque.dequeueRear() == 1);
}

bool testArrayDequeIsEmpty() {
    ArrayDeque deque;
    for (int i = 0; i < 10; i++) {
        deque.enqueueFront(i);
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            deque.dequeueFront();
        }
        else
        {
            deque.dequeueRear();
        }
    }
    return deque.isEmpty();
}

bool testArrayDequeSize() {
    ArrayDeque deque;
    deque.enqueueFront(1);
    deque.enqueueFront(2);

    return deque.size() == 2;
}

bool testLinkedListDequeEnqueueFrontAndDequeueFront() {
    LinkedListDeque deque;
    deque.enqueueFront(1);
    deque.enqueueFront(2);

    return (deque.dequeueFront() == 2) && (deque.dequeueFront() == 1);
}

bool testLinkedListDequeEnqueueRearAndDequeueRear() {
    LinkedListDeque deque;
    deque.enqueueRear(1);
    deque.enqueueRear(2);

    return (deque.dequeueRear() == 2) && (deque.dequeueRear() == 1);
}

bool testLinkedListDequeIsEmpty() {
    LinkedListDeque deque;
    for (int i = 0; i < 10; i++) {
        deque.enqueueFront(i);
    }

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            deque.dequeueFront();
        }
        else
        {
            deque.dequeueRear();
        }
    }
    return deque.isEmpty();
}

bool testLinkedListDequeSize() {
    LinkedListDeque deque;
    deque.enqueueFront(1);
    deque.enqueueFront(2);

    return deque.getSize() == 2;
}

int main() {
    bool allTestsPassed = true;

    allTestsPassed &= runTest(testArrayDequeEnqueueFrontAndDequeueFront, "EnqueueFront and DequeueFront for Array Deque");
    allTestsPassed &= runTest(testArrayDequeEnqueueRearAndDequeueRear, "EnqueueRear and DequeueRear for Array Deque");
    allTestsPassed &= runTest(testArrayDequeIsEmpty, "IsEmpty for Array Deque");
    allTestsPassed &= runTest(testArrayDequeSize, "Size for Array Deque");

    allTestsPassed &= runTest(testLinkedListDequeEnqueueFrontAndDequeueFront, "EnqueueFront and DequeueFront for Linked List Deque");
    allTestsPassed &= runTest(testLinkedListDequeEnqueueRearAndDequeueRear, "EnqueueRear and DequeueRear for Linked List Deque");
    allTestsPassed &= runTest(testLinkedListDequeIsEmpty, "IsEmpty for Linked List Deque");
    allTestsPassed &= runTest(testLinkedListDequeSize, "Size for Linked List Deque");

    if (allTestsPassed) {
        std::cout << "All tests passed!" << std::endl;
    }
    else {
        std::cerr << "Some tests failed." << std::endl;
    }

    return 0;
}
