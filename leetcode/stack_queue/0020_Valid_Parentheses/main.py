#!/bin/env python3
#coding:utf-8

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        m = {')':'(', '}':'{', ']':'['}
        for c in s:
            if c in ['(', '{', '[']:
                stack.append(c)
            elif c in [')', '}', ']']:
                if len(stack) == 0:
                    return False
                if (stack[-1] != m[c]):
                    return False
                # stack = stack[0 : len(stack) - 1]
                stack.pop()

        if len(stack) > 0 :
            return False
        return True
        


if __name__ == "__main__":
    assert Solution().isValid('()') == True, "haha"
    assert Solution().isValid('([[{}]])') == True, "haha"
    assert Solution().isValid('(){') == False, "haha"
    assert Solution().isValid('(') == False, "haha"