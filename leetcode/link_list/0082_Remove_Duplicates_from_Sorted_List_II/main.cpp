//
// Created by colin on 2018-12-20.
//

//给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
//
//示例 1:
//
//输入: dummy-> 1->2->3->3->4->4->5
//输出: 1->2->5
//示例 2:
//
//输入: 1->1->1->2->3
//输出: 2->3

#include "leetcode.h"
#include "../listnode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy, *curr = head;

        while (curr) {
            ListNode* next = curr->next;
            if (next == NULL) break;
            if (curr->val == next->val) {
                while (next && curr->val == next->val) {
                    next = next->next;
                }
                pre->next = next;
                curr = next;
            } else {
                pre = curr;
                curr = next;
            }
        }
        return dummy.next;
    }
};

int main() {

    ListNode* l1 = ListNode::MakeList({1, 2, 3, 3, 4, 4, 5});
    ListNode* l2 = ListNode::MakeList({1, 1, 1, 2, 3});

    ListNode::PrintList(Solution().deleteDuplicates(l1));
    ListNode::PrintList(Solution().deleteDuplicates(l2));

    return 0;
}