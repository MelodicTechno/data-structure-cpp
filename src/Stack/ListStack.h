#pragma once

#include <vector>

class ListStack {
public:
    std::vector<int> data;
    int top;
    int cap;

    ListStack(int cap) : data(cap), top(-1) {}

    bool push(int val);
    int pop();
    int size();
    int peek();
    bool isEmpty();
    int capacity();
};