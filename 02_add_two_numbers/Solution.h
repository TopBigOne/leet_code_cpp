//
// Created by dev on 2024/7/15.
//

#ifndef INC_02_ADD_TWO_NUMBERS_SOLUTION_H
#define INC_02_ADD_TWO_NUMBERS_SOLUTION_H

#include <memory>

/**
 * https://leetcode.cn/problems/add-two-numbers/solutions/4375/liang-shu-xiang-jia-by-gpe3dbjds1/
 */
typedef struct ListNode {
    int      val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
} ListNode;

using  namespace  std;
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2);

};


#endif //INC_02_ADD_TWO_NUMBERS_SOLUTION_H
