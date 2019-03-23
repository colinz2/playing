//
// Created by colin on 2018-12-20.
//

//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
//说明：解集不能包含重复的子集。
//
//示例:
//
//输入: nums = [1,2,3]
//输出:
//[
//    [3],
//    [1],
//    [2],
//    [1,2,3],
//    [1,3],
//    [2,3],
//    [1,2],
//    []
//]

#include "leetcode.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        vector<int> one;
        FindSubsets(nums, 0, one, res);
        return res;
    }

private:
    void FindSubsets(vector<int>& nums, int index, vector<int>& one, vector<vector<int>>& res) {
        res.push_back(one);
        for (int i = index; i < nums.size(); i++) {
            one.push_back(nums[i]);
            FindSubsets(nums, i + 1, one, res);
            one.pop_back();
        }
    }
};

int main() {
    vector<int> v1 = {1,2,3};
    vector<vector<int>> res = Solution().subsets(v1);
    for (auto v : res) {
        PrintVector(v);
    }
}