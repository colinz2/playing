//
// Created by colin on 2018-12-10.
//

//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。
// 返回你可以获得的最大乘积。
//
//示例 1:
//
//输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。
//示例 2:
//
//输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
//说明: 你可以假设 n 不小于 2 且不大于 58。

#include "leetcode.h"

class Solution {
private:
    vector<int> memo;

    int BreakN(int n) {
        if (n == 2 || n == 1) return 1;

        if (memo[n] != -1) return memo[n];

        int max_op = 1;
        for (int i = 1; i < n; i++) {
            int max_t = max(i * (n - i), i * BreakN(n - i));
            max_op = max(max_op, max_t);
        }
        memo[n] = max_op;
        return max_op;
    }

public:
    int integerBreak(int n) {
        memo = vector<int>(n + 1, -1);
        return BreakN(n);
    }

    int integerBreak2(int n) {
        vector<int>memo(n + 1, 1);

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                int max_tmp = max(j * (i - j), j * memo[i - j]);
                memo[i] = max(memo[i], max_tmp);
            }
        }
        return memo[n];
    }
};

int main() {
    cout << Solution().integerBreak(10) << endl;
    cout << Solution().integerBreak2(10) << endl;
}
