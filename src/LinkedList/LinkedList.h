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
    bool insert(int idx, int val);
    bool remove(int idx);
    void print();
    int get(int idx);
    int size();
};
