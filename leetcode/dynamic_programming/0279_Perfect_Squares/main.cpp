//
// Created by colin on 2018-12-10.
//

//给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）
//使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
//
//示例 1:
//
//输入: n = 12
//输出: 3
//解释: 12 = 4 + 4 + 4.

//示例 2:
//输入: n = 13
//输出: 2
//解释: 13 = 4 + 9.

#include "leetcode.h"

class Solution {
public:
    //DP, 可以走一步，步长为 i*i
    int numSquares(int n) {
        vector<int> mem(n + 1, INT_MAX);
        mem[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; n - j*j >= 0; j++) {
                mem[i] = min(mem[i], 1 + mem[n - j*j]);
            }
        }
        return mem[n];
    }

    //BFS广度优先遍历，最短路径
    int numSquares2(int n) {
        int res = 0;
        if (n < 1) {
            return res;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        while (!q.empty()) {
            int num = q.front().first;
            int level = q.front().second;
            q.pop();

            int r = 0;
            for (int i = 1; r >=0; i++) {
                r = num - i*i;
                //判断r是否访问过。TODO
                if (r == 0) return level + 1;
                q.push(make_pair(r, level + 1));
            }
        }
        return res;
    }
};

int main() {
    int t = 17;
    int res = Solution().numSquares2(t);
    cout << t << " -> " << res << endl;
}