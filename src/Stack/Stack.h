#pragma once

#include "../LinkedList/ListNode.h"

class Stack {
public:
    ListNode* sentinel;
    int top;
    int length;

    Stack() {
        sentinel = new ListNode(-1);
    }

    bool push(int val);
    int pop();
    int peek();
    bool isEmpty();
    int size();
};