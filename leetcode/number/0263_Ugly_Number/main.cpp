//
// Created by colin on 2018-12-18.
//

//编写一个程序，找出第 n 个丑数。
//
//丑数就是只包含质因数 2, 3, 5 的正整数。
//
//示例:
//
//输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
//说明:
//
//1 是丑数。
//n 不超过1690。

#include "leetcode.h"

class Solution {
public:
    bool isUgly(int num) {
        if (num < 1) return false;
        while (num % 2 == 0) num >>= 1;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
};

class Solution2 {
private:
    vector<int> seen;
public:
    int nthUglyNumber(int n) {
        int res = 0;
        seen = vector<int>(1000000000, -1);
        seen[0] = 0;
        seen[1] = 1;
        for (int i = 0; i < INT_MAX; i++) {
            if (isUgly(i)) {
                res++;
                seen[i] = true;
            } else {
                seen[i] = false;
            }
            if (res == n) return i;
        }
        return 0;
    }

    bool isUgly(int num) {
        if (seen[num] != -1) {
            return seen[num];
        }
        if (num % 2 == 0) return isUgly(num >>= 1);
        if (num % 3 == 0) return isUgly(num /= 3);
        if (num % 5 == 0) return isUgly(num /= 5);
        return false;
    }
};


int main() {
    cout << Solution2().nthUglyNumber(1343) << endl;
}
