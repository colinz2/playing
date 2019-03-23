//
// Created by colin on 2018/11/23.
//

//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//
//你可以假设数组中无重复元素。
//
//示例 1:
//
//输入: [1,3,5,6], 5
//输出: 2
//示例 2:
//
//输入: [1,3,5,6], 2
//输出: 1
//示例 3:
//
//输入: [1,3,5,6], 7
//输出: 4
//示例 4:
//
//输入: [1,3,5,6], 0
//输出: 0

#include "../leetcode.h"

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
//        int l = 0, r = nums.size() - 1;
//        int mid = 0;
//        while (l <= r) {
//            mid = l + (r - l)/2;
//            if (nums[mid] == target) {
//                return mid;
//            } else if (target < nums[mid]) {
//                r = mid - 1;
//            } else {
//                l = mid + 1;
//            }
//        }
//        return l;
        //lower_bound「返回大于或等于val的第一个元素位置」
        //upper_bound「返回大于val的第一个元素位置」
        return lower_bound(nums.begin(), nums.end(), target ) - nums.begin();
    }
};

int main() {
    vector<int> t1 = {1,3,5,6};
    vector<int> t2 = {1,3};
    
    cout << Solution().searchInsert(t1, 5) << endl;
    cout << Solution().searchInsert(t1, 2) << endl;
    cout << Solution().searchInsert(t1, 7) << endl;
    cout << Solution().searchInsert(t1, 0) << endl;

    cout << Solution().searchInsert(t2, 0) << endl;
    cout << Solution().searchInsert(t2, 1) << endl;
    cout << Solution().searchInsert(t2, 2) << endl;
    cout << Solution().searchInsert(t2, 4) << endl;
}