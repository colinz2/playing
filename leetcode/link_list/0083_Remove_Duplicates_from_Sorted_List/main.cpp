//
// Created by colin on 2018-12-06.
//

//给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
//
//示例 1:
//
//输入: 1->1->2
//输出: 1->2
//示例 2:
//
//输入: 1->1->2->3->3
//输出: 1->2->3

#include "../listnode.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
//一时糊涂，删除下一个更方便啊。
//        ListNode dummyhead(INT_MAX);
//        dummyhead.next = head;
//        ListNode* curr = head, *pre = &dummyhead;
//        while (curr) {
//            if (curr->next == NULL) break;
//            if (curr->val == curr->next->val) {
//                pre->next = curr->next;
//                delete curr;
//                curr = curr->next;
//            } else {
//                pre = curr;
//                curr = curr->next;
//            }
//        }
//        return dummyhead.next;

        ListNode* curr = head;
        while (curr) {
            if (curr->next == nullptr) break;
            if (curr->val == curr->next->val) {
                ListNode* d = curr->next;
                curr->next = curr->next->next;
                delete d;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};

int main() {

    ListNode* l1 = ListNode::MakeList({1, 1, 2, 2});
    ListNode* l2 = ListNode::MakeList({1, 1, 2, 3, 3, 3, 4,4});

    ListNode::PrintList(Solution().deleteDuplicates(l1));
    ListNode::PrintList(Solution().deleteDuplicates(l2));

    return 0;
}