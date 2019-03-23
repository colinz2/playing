#!/bin/env python3
#coding:utf-8


class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        len1 = len(nums)
        nums = [x for x in nums if x != 0]
        len2 = len(nums)
        for i in range(len1 - len2):
            nums.append(0)

        return nums


if __name__ == '__main__':
    r = Solution().moveZeroes([0,1,2,2,3,0,4,2])
    print(r)