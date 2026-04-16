#pragma once

#include <vector>

class CircleQueue {
public:
    std::vector<int> data;
    int front;
    int rear;
    int maxSize;

    CircleQueue(int maxSize) : maxSize(maxSize), data(maxSize), front(0), rear(0) {}

    int top();
    int tail();
    int size();
    bool offer(int val);
    int pop();
    bool isEmpty();
    bool isFull();
};