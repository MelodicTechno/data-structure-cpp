#include "Stack.h"
#include "LinkedList/ListNode.h"

bool Stack::push(int val) {
    ListNode* elementNew = new ListNode(val);
    ListNode* nxt = sentinel->next;
    sentinel->next = elementNew;
    elementNew->next = nxt;
    length++;
    return true;
}

int Stack::peek() {
    ListNode* res = sentinel->next;
    if (res) {
        return res->val;
    }
    return -1;
}

int Stack::pop() {
    if (length <= 0) {
        return -1;
    }
    ListNode* top = sentinel->next;
    sentinel->next = top->next;
    length--;
    return top->val;
}

bool Stack::isEmpty() {
    return sentinel->next == nullptr;
}

int Stack::size() {
    return length;
}