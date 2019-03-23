//
// Created by colin on 2018-12-08.
//

//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在众数。
//
//示例 1:
//
//输入: [3,2,3]
//输出: 3
//示例 2:
//
//输入: [2,2,1,1,1,2,2]
//输出: 2

#include "leetcode.h"

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    int majorityElement2(vector<int> &nums) {
        assert(nums.size() > 0);
        unordered_map<int, int> records;
        for (int num: nums)
            records[num]++;

        for (pair<int, int> record: records)
            if (record.second > nums.size() / 2)
                return record.first;

        throw invalid_argument("No Solution!");

    }


    //// Boyer-Moore Voting Algorithm
    //// Paper: http://www.cs.rug.nl/~wim/pub/whh348.pdf
    int majorityElement3(vector<int> &nums) {
        assert(nums.size() > 0);

        int count = 0, res = -1;
        for (int num: nums) {
            if (count == 0)
                res = num;

            if (res == num)
                count++;
            else
                count--;
        }

        return res;
    }


};

int main() {
    vector<int> v1 = {2, 3, 32, 22, 3, 3, 3, 3};
    cout << Solution().majorityElement(v1) << endl;
}