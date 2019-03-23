//
// Created by colin on 2018/11/27.
//

//在未排序的数组中找到第 k 个最大的元素。
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//
//示例 1:
//
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
//示例 2:
//
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4
//说明:
//
//你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

//快排，😄

#include "leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int r = FindKthLargest_(nums, k - 1, 0, nums.size() - 1);
        return r;
    }

//private:
public:
    int FindKthLargest_(vector<int> &nums, int k, int l, int r) {
        if (l >= r) {
            return nums[l];
        }

        int p = Partition(nums, l, r);
        if (p == k) {
            return nums[p];
        } else if (k < p) {
            return FindKthLargest_(nums, k, l, p - 1);
        } else {
            return FindKthLargest_(nums, k, p + 1, r);
        }
    }

    int Partition(vector<int> &nums, int l, int r) {
        int r_index = random() % (1 + r - l) + l;
        std::swap(nums[l], nums[r_index]);

        int b = nums[l];
        int p = l;

        for (int i = l + 1; i <= r; i++) {
            if (nums[i] > b) {
                p++;
                std::swap(nums[p], nums[i]);
            }
        }
        std::swap(nums[p], nums[l]);
        return p;
    }

    void quitsort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return;
        }
        int p = Partition(nums, l, r);
        quitsort(nums, l, p - 1);
        quitsort(nums, p + 1, r);
    }
};

int main() {
    srand(time(nullptr));
    vector<int> v1 = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(v1, 2) << endl;
    // Solution().quitsort(v1, 0, v1.size() - 1);
    PrintVector(v1);
}