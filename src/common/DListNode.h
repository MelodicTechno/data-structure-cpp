#pragma once

struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;

    DListNode() : val(0), prev(nullptr), next(nullptr) {}
    DListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    DListNode(int val, DListNode* prev, DListNode* next) : val(val), prev(prev), next(next) {}
};
