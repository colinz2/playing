//
// Created by colin on 2018-12-11.
//

//反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
//
//说明:
//1 ≤ m ≤ n ≤ 链表长度。
//
//示例:
//
//输入: 1->9->2->3->4->5->NULL, m = 2, n = 5
//输出: 1->4->3->2->9->5->NULL

#include "../listnode.h"
#include <iostream>

class Solution {
public:
    //不容易
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;
        int idx = 0;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* s = NULL;
        ListNode* p = NULL;

        ListNode* curr = head;
        ListNode* pre = &dummy;

        while (curr) {
            idx++;
            ListNode* next = curr->next;
            if (idx >= m && idx <=n) {
                if (idx == m) {
                    p = pre;
                    s = curr;
                } else if (idx == n) {
                    curr->next = pre;
                    p->next = curr;
                    s->next = next;
                    break;
                }
                curr->next = pre;
            }
            pre = curr; 
            curr = next;
        }
        return dummy.next;
    }
};

int main() {
    ListNode* l1 = ListNode::MakeList({1, 9, 2, 3, 4, 5});
    ListNode* l2 = ListNode::MakeList({1, 9});
    ListNode::PrintList(Solution().reverseBetween(l1, 2, 5));
    ListNode::PrintList(Solution().reverseBetween(l2, 1, 2));
    return 0;
}