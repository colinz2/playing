//
// Created by colin on 2018-12-11.
//

//反转一个单链表。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//        输出: 5->4->3->2->1->NULL
//        进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

#include "../listnode.h"

class Solution {
public:

    ListNode* reverseList1(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;

        while (cur != NULL) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }


    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        ListNode* curr = NULL;

        if (pre) {
            curr = pre->next;
            pre->next = NULL;
        }

        while (curr) {
            ListNode* next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        return pre;
    }

    //递归方式，从新链表的头开始
    ListNode* reverseList3(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* rhead = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;

        return rhead;
    }


};

int main() {
    ListNode* l1 = ListNode::MakeList({1, 2, 3, 4, 5, 6, 7, 8});
    ListNode* l2 = ListNode::MakeList({1, 2, 3, 4, 5, 6, 7, 8});

    ListNode::PrintList(Solution().reverseList1(l1));
    ListNode::PrintList(Solution().reverseList(l2));
}
