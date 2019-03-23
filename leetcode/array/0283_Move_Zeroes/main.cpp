//
// Created by colin on 2018/11/27.
//

//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//
//示例:
//
//输入: [0,1,0,3,12]
//输出: [1,3,12,0,0]
//说明:
//
//必须在原数组上操作，不能拷贝额外的数组。
//尽量减少操作次数。


#include "leetcode.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        int target = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) {
                nums[j++] = nums[i];
            }
        }

        for ( ; j < nums.size(); j++) {
            nums[j] = target;
        }
    }
};

int main() {
    vector<int> t1 = {0,1,2,2,3,0,4,2};
    PrintVector(t1);

    Solution().moveZeroes(t1);
    PrintVector(t1);
}