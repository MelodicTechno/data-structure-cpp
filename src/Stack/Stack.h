#pragma once

#include "common/ListNode.h"

class Stack {
public:
    ListNode* sentinel;
    int length;

    Stack() : length(0), sentinel(new ListNode(-1)) {}

    bool push(int val);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};
