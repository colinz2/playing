//
// Created by colin on 2018/11/28.
//

//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
//如果不存在符合条件的连续子数组，返回 0。
//
//示例:
//
//输入: s = 7, nums = [2,3,1,2,4,3]
//输出: 2
//解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
//进阶:
//
//如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

#include "leetcode.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int l = 0, r = -1;
        int sum = 0;
        int ret = nums.size() + 1;

        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < s) {
                sum += nums[++r];
            } else {
                sum -= nums[l++];
            }

            if (sum >= s) {
                ret = std::min(ret, r-l+1);
            }
        }
        if (ret > nums.size()) ret = 0;
        return ret;
    }
};

int main() {
    vector<int> v1 = {2, 3, 1, 2, 4, 3};

    cout << Solution().minSubArrayLen(7, v1);
}