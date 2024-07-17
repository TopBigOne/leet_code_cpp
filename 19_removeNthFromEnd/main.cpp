#include <iostream>


struct ListNode {
    int      val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        // fast 再往前走一步，因为需要让slow 指向删除节点的上一个节点
        fast           = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummyNode->next;
    }

    ListNode *removeNthFromEnd2(ListNode *head, int n) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode *slow = dummyHead;
        ListNode *fast = dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast           = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyHead->next;


    }


    ListNode *removeNthFromEnd3(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        // fast 指针向前移动一步，使得它指向要删除的节点。
        fast           = fast->next;
        // 让 fast 指针和 slow 指针同时向前移动，
        // 直到 fast 指针达到链表末尾。
        // 这样，当循环结束时，slow 指针指向要删除的节点的前一个节点。
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        // 修改 slow 指针的 next 指针，将要删除的节点从链表中断开。
        slow->next = slow->next->next;
        return dummyNode->next;
    }

    ListNode *removeNthFromEnd4(ListNode *head, int n) {
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        fast           = fast->next;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummyNode->next;
    }
};

int main() {

    return 0;
}
