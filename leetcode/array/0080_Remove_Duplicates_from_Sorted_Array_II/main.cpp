//
// Created by colin on 2018/11/27.
//

#include "leetcode.h"

class Solution {
public:
    //厉害了
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])
                nums[i++] = n;
        return i;
    }
};

int main() {
    vector<int> t1 = {1,1,2};

    vector<int> t2 = {1,1,1, 1};
    vector<int> t3 = {1,1,1, 2,2, 3,4,5, 5,5,6,6};

    cout << Solution().removeDuplicates(t1) << endl;
    cout << Solution().removeDuplicates(t2) << endl;
    cout << Solution().removeDuplicates(t3) << endl;
    PrintVector(t1);
    PrintVector(t2);
    PrintVector(t3);
}