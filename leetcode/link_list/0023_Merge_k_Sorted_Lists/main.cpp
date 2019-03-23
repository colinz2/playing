//
// Created by colin on 2018-12-12.
//

//合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
//
//示例:
//
//输入:
//[
//    1->4->5,
//    1->3->4,
//    2->6
//]
//输出: 1->1->2->3->4->4->5->6

#include "../listnode.h"
#include "leetcode.h"

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        for (auto &l : lists) {

            l = l->next;
        }
    }
};

int main() {
    ListNode* l1 = ListNode::MakeList({1, 4, 5});
    ListNode* l2 = ListNode::MakeList({1, 3, 4});
    ListNode* l3 = ListNode::MakeList({2, 6});
    vector<ListNode*> v1 = {l1, l2, l3};

    ListNode::PrintList(Solution().mergeKLists(v1));
}
