//
// Created by colin on 2018/11/27.
//

//给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，
// 使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//
//此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
//
//注意:
//不能使用代码库中的排序函数来解决这道题。
//
//示例:
//
//输入: [2,0,2,1,1,0]
//输出: [0,0,1,1,2,2]
//进阶：
//
//一个直观的解决方案是使用计数排序的两趟扫描算法。
//首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
//你能想出一个仅使用常数空间的一趟扫描算法吗？

#include "leetcode.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> cnt(3);
        for (int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }

        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                nums[k++] = i;
            }
        }
    }

    //👌，三路快排
    void sortColors2(vector<int>& nums) {
        int zero = -1;
        int two = nums.size();
        //[0, zero],闭区间全为0
        //[zero+ 1, two - 1] 为1
        //[two, nums.size() - 1], 全为2

        for (int i = 0; i < two; ) {
            if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                std::swap(nums[i], nums[two - 1]);
                two--;
            } else {
                assert(nums[i] == 0);
                std::swap(nums[i], nums[zero + 1]);
                zero++;
                i++;
            }
        }
    }
};


int main() {
    vector<int> t1 = {2,0,2,1,1,0};
    vector<int> t2 = {2,0,2,1,1,0};

    Solution().sortColors(t1);
    Solution().sortColors2(t2);
    PrintVector(t1);
    PrintVector(t2);
}

