#include "ListNode.h"

struct ListNode {
    int val;
    ListNode* next;

    ListNode() {
        this->val = 0;
        this->next = nullptr;
    }

    ListNode(int val) : val(val) {
        this->next = nullptr;
    }

    ListNode(int val, ListNode* next) : val(val), next(next) {}
};