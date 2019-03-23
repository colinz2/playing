//
// Created by colin on 2018/11/22.
//

#include "../leetcode.h"

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = INT_MAX - 1;
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            if (mid * mid <= (long long)x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    cout << Solution().mySqrt(101) << endl;
    cout << Solution().mySqrt(99) << endl;
    cout << Solution().mySqrt(10) << endl;
    cout << Solution().mySqrt(0) << endl;
    cout << Solution().mySqrt(16) << endl;
    cout << Solution().mySqrt(1) << endl;
}
