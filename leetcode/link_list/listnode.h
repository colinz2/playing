//
// Created by colin on 2018/11/29.
//

#ifndef PROJECT_LIST_H
#define PROJECT_LIST_H

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}

    static ListNode* MakeList(std::vector<int> nums) {
        ListNode* p = nullptr;
        ListNode* h = nullptr;
        for (auto i = 0; i < nums.size(); i++) {
            ListNode* l = new ListNode(nums[i]);
            if (i == 0) {
                h = p = l;
            }
            p->next = l;
            p = l;
        }
        return h;
    }

    static void PrintList(ListNode* l) {
        assert(l != nullptr);
        while (l) {
            std::cout << l->val << " ";
            l = l->next;
        }
        std::cout << std::endl;
    }
};

#endif //PROJECT_LIST_H
