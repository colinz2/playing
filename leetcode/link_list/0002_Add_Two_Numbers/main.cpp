//
// Created by colin on 2018/11/28.
//

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
//并且它们的每个节点只能存储 一位 数字。
//
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//示例：
//
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "../listnode.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int v1, v2;
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while (l1 || l2) {
            v1 = l1 == nullptr ? 0 : l1->val;
            v2 = l2 == nullptr ? 0 : l2->val;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) {
            curr->next = new ListNode(1);
        }
        return head->next;
    }
};

int main() {

    ListNode* l1 = ListNode::MakeList({2, 4, 3, 1});
    ListNode* l2 = ListNode::MakeList({5, 6, 4});

    ListNode* l3 = Solution().addTwoNumbers(l1, l2);

    ListNode::PrintList(l3);

    return 0;
}
