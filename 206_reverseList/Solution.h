//
// Created by dev on 2024/7/16.
//

#ifndef INC_206_REVERSELIST_SOLUTION_H
#define INC_206_REVERSELIST_SOLUTION_H


struct ListNode {
    int      val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}


    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * 反转链表：
 * https://leetcode.cn/problems/reverse-linked-list/
 */
class Solution {
    ListNode *reverseList(ListNode *head);

    ListNode *reverseList2(ListNode *head);

};


#endif //INC_206_REVERSELIST_SOLUTION_H
