//
// Created by dev on 2024/7/16.
//

#include "Solution.h"

ListNode *Solution::reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNode *temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}


ListNode *Solution::reverseList2(ListNode *head) {
    ListNode *pre  = nullptr;
    ListNode *curr = head;
    while (curr != nullptr) {
        ListNode *temp = curr->next;
        curr->next = pre;
        pre  = curr;
        curr = temp;
    }
    return pre;
}
