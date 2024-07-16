//
// Created by dev on 2024/7/15.
//

#include "Solution.h"


ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {

    auto     *head = new ListNode(-1);
    ListNode *h    = head;
    int      sum   = 0;
    bool     carry = false;
    while (l1 != nullptr || l2 != nullptr) {
        sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (carry) {
            sum++;
        }
        h->next = new ListNode(sum % 10);
        h     = h->next;
        carry = sum >= 10;
    }
    if (carry) {
        h->next = new ListNode(1);
    }
    return head->next;
}


ListNode *Solution::addTwoNumbers2(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(-1);
    ListNode *head      = dummyNode;
    int      sum        = 0;
    bool     isCarry    = false;
    while (l1 != nullptr || l2 != nullptr) {
        sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        // 判断是否需要再次进位
        if (isCarry) {
            sum++;
        }
        head->next = new ListNode(sum % 10);
        head = head->next;

        isCarry = sum >= 10;
    }
    if (isCarry) {
        head->next = new ListNode(1);
    }


    return dummyNode->next;


}

ListNode *Solution::addTwoNumbers3(ListNode *l1, ListNode *l2) {
    auto     *dummyNode = new ListNode(-1);
    ListNode *head      = dummyNode;
    bool     isCarry    = false;
    int      sum        = 0;
    while (l1 != nullptr || l2 != nullptr) {
        sum = 0;
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }
        if (isCarry) {
            sum++;
        }
        head->next = new ListNode(sum % 10);
        head = head->next;

        isCarry = sum >= 10;
    }
    if (isCarry) {
        head->next = new ListNode(1);
    }

    return dummyNode->next;
}
