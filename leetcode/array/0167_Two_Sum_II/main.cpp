//
// Created by colin on 2018/11/28.
//

//给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
//
//函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
//
//说明:
//
//返回的下标值（index1 和 index2）不是从零开始的。
//你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
//示例:
//
//输入: numbers = [2, 7, 11, 15], target = 9
//输出: [1,2]
//解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

#include "leetcode.h"

//由于是有序的数组，可以使用双指针对撞的方法。
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                return vector<int> {l, r};
            } else if (sum > target) {
                r--;
            } else if (sum < target) {
                l++;
            }
        }
        return vector<int> {};
    }
};

int main() {
    vector<int> v1 = {0, 2, 4, 5, 10, 15};
    vector<int> r = Solution().twoSum(v1, 9);
    PrintVector(r);
}