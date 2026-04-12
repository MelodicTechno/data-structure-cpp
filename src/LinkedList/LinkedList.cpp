#include "LinkedList.h"
#include "ListNode.h"
#include <iostream>

bool LinkedList::add(int val) {
    ListNode* nxt = sentinel->next;
    ListNode* nodeNew = new ListNode(val);
    sentinel->next = nodeNew;
    nodeNew->next = nxt;
    length++;
    return true;
}

bool LinkedList::addBack(int val) {
    ListNode* cur = sentinel->next;
    ListNode* nodeNew = new ListNode(val);
    while(cur->next) {
        cur = cur->next;
    }
    length++;
    cur->next = nodeNew;
    return true;
}

bool LinkedList::remove(int idx) {
    if (idx > length - 1 || idx < 0) {
        return false;
    }
    ListNode* cur = sentinel;
    for (int i = 0; i < idx; ++i) {
        cur = cur->next;
    }
    ListNode* toDelete = cur->next;
    cur->next = toDelete->next;
    delete toDelete;
    --length;
    return true;
}

int LinkedList::get(int idx) {
    if (idx > length - 1) {
        return get(0);
    }
    int i = 0;
    ListNode* cur = sentinel->next;
    while (i++ != idx) {
        cur = cur->next;
    }
    return cur->val;
}

int LinkedList::size() {
    return length;
}

void LinkedList::print() {
    ListNode* cur = sentinel->next;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}
