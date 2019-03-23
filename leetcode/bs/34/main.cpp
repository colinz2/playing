//
// Created by colin on 2018-12-25.
//

//34. Find First and Last Position of Element in Sorted Array

//给定一个按照升序排列的整数数组 nums，和一个目标值 target。
//找出给定目标值在数组中的开始位置和结束位置。
//你的算法时间复杂度必须是 O(log n) 级别。
//
//如果数组中不存在目标值，返回 [-1, -1]。
//
//示例 1:
//输入: nums = [5,7,7,8,8,10], target = 8
//输出: [3,4]
//
//示例 2:
//输入: nums = [5,7,7,8,8,10], target = 6
//输出: [-1,-1]

#include "leetcode.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int rt = -1, lt = -1;
        int l = 0, m = 0, r = nums.size() - 1;
        while (l <= r) {
            m = l + ((r - l) >> 1);
            if (nums[m] > target) {
                r = m - 1;
            } else if (nums[m] < target){
                l = m + 1;
            } else {
                rt = m;
                lt = m;
                while (lt >= 0 && nums[lt] == nums[m]) lt--;
                while (rt < nums.size() && nums[rt] == nums[m]) rt++;
                return {lt + 1, rt - 1};
            }
        }
        return {lt, rt};
    }
};

int main() {
    vector<int> v1 = {5,7,8,8,8,8,9,10};
    vector<int> v2 = {8};
    vector<int> res1 = Solution().searchRange(v1, 8);
    vector<int> res2 = Solution().searchRange(v2, 8);
    PrintVector(res1);
    PrintVector(res2);
}
