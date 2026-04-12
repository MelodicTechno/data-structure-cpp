#include "Stack.h"
#include "common/ListNode.h"

bool Stack::push(int val) {
    ListNode* elementNew = new ListNode(val);
    ListNode* nxt = sentinel->next;
    sentinel->next = elementNew;
    elementNew->next = nxt;
    ++length;
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
    ListNode* topNode = sentinel->next;
    if (!topNode) {
        return -1;
    }
    int res = topNode->val;
    sentinel->next = topNode->next;
    --length;
    delete topNode;
    return res;
}

bool Stack::isEmpty() {
    return sentinel->next == nullptr;
}

int Stack::size() {
    return length;
}
