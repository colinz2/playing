//
// Created by colin on 2018-12-18.
//

//给定一个包含 n 个整数的数组 nums，
//判断 nums 中是否存在三个元素 a，b，c ，
//使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
//
//注意：答案中不可以包含重复的三元组。
//
//例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//    [-1, 0, 1],
//    [-1, -1, 2]
//]

#include "leetcode.h"

class Solution {
public:
    //使用双指针的方法
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if (nums.size() == 0) return ret;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                    //哈哈😄
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (nums[l] + nums[r] > target) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ret;
    }
};


int main() {
    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
    auto res =  Solution().threeSum(v1);
    for (auto v : res) {
        PrintVector(v);
    }
}