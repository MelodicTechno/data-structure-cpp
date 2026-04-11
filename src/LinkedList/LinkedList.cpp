#include "LinkedList.h"
#include "ListNode.h"

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
    while(cur) {
        cur = cur->next;
    }
    length++;
    return true;
}

int LinkedList::get(int idx) {
    if (idx > length - 1) {
        return get(length - 1);
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
