//
// Created by colin on 2018-12-05.
//

//给定两个数组，编写一个函数来计算它们的交集。
//
//示例 1:
//
//输入: nums1 = [1,2,2,1], nums2 = [2,2]
//输出: [2]
//示例 2:
//
//输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
//输出: [9,4]

#include "leetcode.h"

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end());
        unordered_set<int> n2(nums2.begin(), nums2.end());
        vector<int> ret;

        for (auto c : n2) {
            if (n1.find(c) != n1.end()) {
                ret.push_back(c);
            }
        }
        return ret;
    }
};


int main() {
    vector<int> v1 = {1, 2, 2, 1};
    vector<int> v2 = {2, 2};
    vector<int> v3 = {4, 9, 5};
    vector<int> v4 = {9, 4, 9, 8, 4};

    PrintVector(Solution().intersection(v1, v2));
    PrintVector(Solution().intersection(v3, v4));

}
