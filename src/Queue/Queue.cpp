#include "Queue.h"
#include "common/DListNode.h"

bool Queue::offer(int val) {
    DListNode* headNew = new DListNode(val);
    headNew->next = sentinelHead->next;
    headNew->prev = sentinelHead;
    sentinelHead->next->prev = headNew;
    sentinelHead->next = headNew;
    length++;
    return true;
}

int Queue::top() {
    if (isEmpty()) {
        return -1;
    }
    return sentinelHead->next->val;
}

int Queue::tail() {
    if (isEmpty()) {
        return -1;
    }
    return sentinelTail->prev->val;
}

int Queue::size() {
    return length;
}

bool Queue::isEmpty() {
    return sentinelHead->next == sentinelTail;
}