#!/bin/env python3
#coding:utf-8

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

    def Print(self):
        curr = self
        s = ""
        while curr:
            s += "%d->" % (curr.val)
            curr = curr.next
        print(s) 


class Solution:
    def reverseBetween(self, head, m, n):
        dummy = ListNode(0)
        dummy.next = head
        Head = dummy
        for i in range(m - 1):
            Head = Head.next
        pre = Head.next
        node = pre.next
        while node and m < n:
            pre.next = node.next
            node.next = Head.next
            Head.next = node
            node = pre.next
            m += 1
        return dummy.next

if __name__ == '__main__':
    a = ListNode(1)
    b = ListNode(2)
    c = ListNode(3)
    d = ListNode(4)
    e = ListNode(5)

    a.next = b;
    b.next = c; 
    c.next = d; 
    d.next = e

    a.Print()
    Solution().reverseBetween(a, 2, 4).Print()



