//
// Created by colin on 2018-12-17.
//

//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//candidates 中的数字可以无限制重复被选取。
//说明：
//所有数字（包括 target）都是正整数。
//解集不能包含重复的组合。
//
//示例 1:
//输入: candidates = [2,3,6,7], target = 7,
//        所求解集为:
//[
//    [7],
//    [2,2,3]
//]
//
//示例 2:
//输入: candidates = [2,3,5], target = 8,
//        所求解集为:
//[
//    [2,2,2,2],
//    [2,3,3],
//    [3,5]
//]

#include "leetcode.h"
//经典，回溯的起始点要注意，⚠️
class Solution {
private:
    void combinationSum(vector<int>& candidates, int index, int target, vector<int>& one, vector<vector<int>>& res) {
        for (int i = index; i < candidates.size(); i++) {
            if (target < candidates[i]) {
                break;
            } else if (target == candidates[i]) {
                one.push_back(candidates[i]);
                res.push_back(one);
                one.pop_back();
            } else {
                one.push_back(candidates[i]);
                //target 为i，🐱
                combinationSum(candidates, i, target - candidates[i], one, res);
                one.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> one;
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target, one, res);
        return res;
    }
};

int main() {
    vector<vector<int>> res;
    vector<int> v1 = {2,3,5};
    res = Solution().combinationSum(v1, 8);

    for (auto v : res) {
        PrintVector(v);
    }
}