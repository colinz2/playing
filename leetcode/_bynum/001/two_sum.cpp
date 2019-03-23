//
// Created by colin on 2018/11/13.
//
//给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
//
//你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
//
//示例:
//
//给定 nums = [2, 7, 11, 15], target = 9
//
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回 [0, 1]

#include "../leetcode.h"


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> tested;
        vector<int> res;

        for (auto i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = tested.find(complement);
            if (it != tested.end()) {
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
            tested[nums[i]] = i;
        }
        return res;
    }
};

int main()
{
    vector<int> test_data = {2, 7, 11, 15};
    int target = 9;

    auto r = Solution().twoSum(test_data, target);

    copy(r.begin(), r.end(), ostream_iterator<int>(cout, "\n"));

}