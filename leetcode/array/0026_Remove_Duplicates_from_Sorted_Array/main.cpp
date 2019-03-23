//
// Created by colin on 2018/11/27.
//


#include "leetcode.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        if (nums.size() == 0) {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[j - 1]) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }

    int removeDuplicates2(vector<int>& nums) {
        int m = INT_MIN;
        int k = 0;
        for (int n : nums) {
            if (n > m) {
                nums[k++] = n;
                m = n;
            }
        }
        return k;
    }
};

int main() {
    vector<int> t1 = {1,1,2};

    vector<int> t2 = {1,1,1, 1};
    vector<int> t3 = {1,1,1, 2,2, 3,4,5, 5,5,6,6};

    cout << Solution().removeDuplicates(t1) << endl;
    cout << Solution().removeDuplicates(t2) << endl;
    cout << Solution().removeDuplicates2(t3) << endl;
    PrintVector(t1);
    PrintVector(t2);
    PrintVector(t3);
}