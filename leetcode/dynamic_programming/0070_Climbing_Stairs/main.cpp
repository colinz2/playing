//
// Created by colin on 2018-12-10.
//

//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//注意：给定 n 是一个正整数。
//
//示例 1：
//输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶
//
//示例 2：
//输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶

#include "leetcode.h"

class Solution {
public:
    int climbStairs(int n) {
        vector<uint64_t> stairs(n + 1, 0);
        for (int j = 0; j < 3;  j++) {
            stairs[j] = j;
        }

        for (int i = 3; i <= n; i++) {
            stairs[i] = stairs[i - 1] + stairs[i - 2];
        }

        return stairs[n];
    }
};

int main() {
    cout << Solution().climbStairs(1) << endl;
    cout << Solution().climbStairs(2) << endl;
    cout << Solution().climbStairs(3) << endl;
    cout << Solution().climbStairs(4) << endl;
    cout << Solution().climbStairs(5) << endl;
    cout << Solution().climbStairs(6) << endl;
    cout << Solution().climbStairs(7) << endl;
}