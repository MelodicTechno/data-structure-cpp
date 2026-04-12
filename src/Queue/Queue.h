#pragma once

#include "common/DListNode.h"

class Queue {
public:
    DListNode* sentinelHead;
    DListNode* sentinelTail;
    int length;

    Queue() : length(0), sentinelHead(new DListNode(-1)), sentinelTail(new DListNode(-1)) {
        sentinelHead->next = sentinelTail;
        sentinelTail->prev = sentinelHead;
    }

    bool offer(int val);
    int pop();
    int top();
    int tail();
    int size();
    bool isEmpty();
};