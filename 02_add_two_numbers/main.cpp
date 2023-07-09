#include <iostream>


using namespace std;

struct ListNode {
    int      val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {};

    ListNode(int x) : val(x), next(nullptr) {};

    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

/**
 * https://leetcode.cn/problems/add-two-numbers/solutions/4375/liang-shu-xiang-jia-by-gpe3dbjds1/
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto     *head = new ListNode(-1);
        ListNode *h    = head;
        // 每个位相加的结果；
        int      sum   = 0;
        // 进位标志
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

    ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
        auto     *dummy = new ListNode(-1);
        ListNode *head  = dummy;

        bool carry = false;
        while (l1 != nullptr || l2 != nullptr) {
            int sum = 0;
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
            head->next = new ListNode(sum % 10);
            head  = head->next;
            carry = sum >= 10;

        }
        if (carry) {
            head->next = new ListNode(1);
        }
        return dummy->next;

    }
};

int main() {
    auto *l1 = new ListNode(9);
    l1->next       = new ListNode(8);
    l1->next->next = new ListNode(7);

    auto *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    // l2->next->next = new ListNode(4);
    Solution solution;
    ListNode *result = solution.addTwoNumbers(l1, l2);
    while (result != nullptr) {

        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
