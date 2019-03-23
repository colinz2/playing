//
// Created by colin on 2018-12-11.
//

//给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
//
//示例:
//
//给定 dummy->1->2->3->4, 你应该返回 2->1->4->3.
//说明:
//
//你的算法只能使用常数的额外空间。
//你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

#include "../listnode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next = head;

        ListNode* pre = &dummy;
        ListNode* curr = pre->next;
        while (curr) {
            ListNode* next = curr->next;
            if (next) {
                pre->next = next;
                curr->next = next->next;
                next->next = curr;

                pre = curr;
                curr = curr->next;
            } else {
                break;
            }
        }
        return dummy.next;
    }
};


int main() {

    ListNode* l1 = ListNode::MakeList({1, 2, 3, 4, 5, 6, 7, 8});
    ListNode* l2 = Solution().swapPairs(l1);
    ListNode::PrintList(l2);
}



