#pragma once

#include "../LinkedList/ListNode.h"

class Stack {
public:
    ListNode* sentinel = nullptr;
    int length = 0;

    Stack() : sentinel(new ListNode(-1)) {}

    bool push(int val);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};
