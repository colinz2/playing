//
// Created by colin on 2018-12-05.
//

//给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，
//使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
//
//示例 1:
//
//输入: nums = [1,2,3,3,1], k = 3
//输出: true
//示例 2:
//
//输入: nums = [1,0,1,1], k = 1
//输出: true
//示例 3:
//
//输入: nums = [1,2,3,1,2,3], k = 2
//输出: false

#include "leetcode.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if(nums.size() <= 1)
            return false;

        if(k <= 0)
            return false;

        unordered_set<int> record;
        for(int i = 0 ; i < nums.size() ; i ++){

            if(record.find(nums[i]) != record.end())
                return true;

            record.insert(nums[i]);

            // 保持record中最多有k个元素
            // 因为在下一次循环中会添加一个新元素,使得总共考虑k+1个元素
            if(record.size() == k + 1)
                record.erase(nums[i - k]);
        }

        return false;
    }


    bool containsNearbyDuplicate2(vector<int> &nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];
            if (m.count(c) > 0) {
                if (i - m[c] <= k ) return true;
            }
            m[c] = i;
        }
        return false;
    }
};


int main() {
    cout << "[1]" << endl;

    vector<int> v1 = {1, 2, 3, 1};
    vector<int> v2 = {1, 0, 1, 1};
    vector<int> v3 = {1, 2, 3, 1, 2, 3};

    cout << Solution().containsNearbyDuplicate(v1, 3) << endl;
    cout << Solution().containsNearbyDuplicate(v2, 1) << endl;
    cout << Solution().containsNearbyDuplicate(v3, 2) << endl;

}