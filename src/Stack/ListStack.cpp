#include "ListStack.h"

bool ListStack::push(int val) {
    if (top == cap - 1) {
        return false;
    }
    data[++top] = val;
    return true;
}

int ListStack::pop() {
    if (top == -1) {
        return -1;
    }
    return data[top--];
}

int ListStack::size() {
    return top + 1;
}

int ListStack::peek() {
    if (top == -1) {
        return -1;
    }
    return data[top];
}

bool ListStack::isEmpty() {
    return top == -1;
}

int ListStack::capacity() {
    return cap;
}