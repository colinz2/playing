//
// Created by colin on 2018/11/21.
//
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//示例：
//
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4

#include "../leetcode.h"
#include "listnode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyH(0);
        ListNode* l3 = &dummyH;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                l3->next = l2;
                l2 = l2->next;
            } else {
                l3->next = l1;
                l1 = l1->next;
            }
            l3 = l3->next;
        }

        if (l1) {
            l3->next = l1;
        }

        if (l2) {
            l3->next = l2;
        }
        return dummyH.next;
    }
};

int main() {
    ListNode* l1 = ListNode::MakeList({10, 14, 16, 129});
    ListNode* l2 = ListNode::MakeList({17, 22, 99, 1229});
    ListNode::PrintList(l1);
    ListNode::PrintList(l2);

    ListNode* l3 = Solution().mergeTwoLists(l1, l2);

    ListNode::PrintList(l3);
}