//
// Created by colin on 2018-12-17.
//

//给定一个没有重复数字的序列，返回其所有可能的全排列。
//示例:
//
//输入: [1,2,3]
//输出:
//[
//    [1,2,3],
//    [1,3,2],
//    [2,1,3],
//    [2,3,1],
//    [3,1,2],
//    [3,2,1]
//]

#include "leetcode.h"

class Solution {
private:
    //用来锁定索引，防止重复使用元素
    //重要 ！！ 👌 ？
    vector<bool> used;
public:

    void FindPermute(vector<int>& nums, int cnt, vector<int>& one, vector<vector<int>>& res) {
        if (cnt == nums.size()) {
            res.push_back(one);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                one[cnt] = nums[i];
                FindPermute(nums, cnt + 1, one, res);
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;

        vector<int> one(nums.size(), 0);
        used = vector<bool>(nums.size(), false);
        FindPermute(nums, 0, one, res);
        return res;
    }
};

int main() {
    vector<vector<int>> res;
    vector<int> nums = {1,2,3};
    res = Solution().permute(nums);

    for (auto v : res) {
        PrintVector(v);
    }
}
