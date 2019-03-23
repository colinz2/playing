//
// Created by colin on 2018-12-23.
//

//给定一个非负整数数组，你最初位于数组的第一个位置。
//数组中的每个元素代表你在该位置可以跳跃的最大长度。
//判断你是否能够到达最后一个位置。
//
//示例 1:
//输入: [2,3,1,1,4]
//输出: true
//解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
//
//示例 2:
//输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。
//但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。

#include "leetcode.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0) return true;
        int max_step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max_step < i || i >= nums.size() - 1) break;
            max_step = max(max_step, i + nums[i]);
        }
        return max_step >= nums.size() - 1;
    }
};

int main() {
    vector<int> v1 = {2,3,1,1,4};
    vector<int> v2 = {3,2,1,0,4};
    vector<int> v3 = {3,2,1,0,4};
    cout << Solution().canJump(v1) << endl;
    cout << Solution().canJump(v2) << endl;
    cout << Solution().canJump(v3) << endl;
}
