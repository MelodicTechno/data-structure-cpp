#include "LinkedList.h"
#include "ListNode.h"

class LinkedList {
public:
    ListNode* head;
    int length;

    LinkedList() {}
    LinkedList(ListNode* head) : head(head) {}
    LinkedList(int length) : length(length) {
        ListNode head(0);
    }
};