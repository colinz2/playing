//
// Created by colin on 2018-12-07.
//

//给定一个链表，判断链表中是否有环。
//
//进阶：
//你能否不使用额外空间解决此题？


#include "../listnode.h"

#include <unordered_set>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> node_set;
        ListNode *curr = head;

        while (curr) {
            if (node_set.find(curr) != node_set.end()) {
                return true;
            }
            node_set.insert(curr);
            curr = curr->next;
        }
        return false;
    }

    bool hasCycle2(ListNode *head) {

        if (head == NULL)
            return false;

        if (head->next == NULL)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != slow) {
            if (fast->next == NULL)
                return false;
            if (fast->next->next == NULL)
                return false;

            fast = fast->next->next;
            slow = slow->next;
        }

        return true;
    }
};

int main() {

    return 0;
}
