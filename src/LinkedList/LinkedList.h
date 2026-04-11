#pragma once

#include "ListNode.h"

class LinkedList {
public:
    ListNode* sentinel = nullptr;
    int length = 0;

    LinkedList() {
        sentinel = new ListNode(-1);
    }

    bool add(int val);
    bool addBack(int val);
    int get(int idx);
    int size();
};
