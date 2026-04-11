#include "ListNode.h"

ListNode::ListNode() : val(0), next(nullptr) {}

ListNode::ListNode(int val) : val(val), next(nullptr) {}

ListNode::ListNode(int val, ListNode* next) : val(val), next(next) {}
