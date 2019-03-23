//
// Created by colin on 2018-12-08.
//

#include "leetcode.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        long long x = 1;
        while (x <= n) {
            x = x << 1;
        }
        return x == n;
    }

    bool isPowerOfTwo2(int n) {
        if (n < 0) return false;
        return (n & (n - 1)) == 0;
    }

};

int main() {

    cout << Solution().isPowerOfTwo(1073741825) << endl;
    cout << Solution().isPowerOfTwo2(1073741825) << endl;
    cout << Solution().isPowerOfTwo2(16) << endl;
    cout << Solution().isPowerOfTwo2(16) << endl;
    cout << Solution().isPowerOfTwo2(999) << endl;
    cout << Solution().isPowerOfTwo2(999) << endl;

    return 0;
}