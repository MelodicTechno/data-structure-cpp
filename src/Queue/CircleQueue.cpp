#include "CircleQueue.h"

bool CircleQueue::isFull() {
    return (rear + 1) % maxSize == front;
}

bool CircleQueue::isEmpty() {
    return front == rear;
}

bool CircleQueue::offer(int val) {
    if (isFull()) {
        return false;
    }
    data[rear] = val;
    rear = (rear + 1) % maxSize;
    return true;
}

int CircleQueue::pop() {
    if (isEmpty()) {
        return -1;
    }
    int res = data[front];
    front = (front + 1) % maxSize;
    return res;
}

int CircleQueue::size() {
    return (rear + maxSize - front) % maxSize;
}

int CircleQueue::top() {
    if (isEmpty()) {
        return -1;
    }
    return data[front];
}

int CircleQueue::tail() {
    if (isEmpty()) {
        return -1;
    }
    int idx = (rear - 1 + maxSize) % maxSize;
    return data[idx];
}
