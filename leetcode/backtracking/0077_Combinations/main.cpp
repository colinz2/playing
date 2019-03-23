//
// Created by colin on 2018-12-08.
//

//    给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
//
//    示例:
//
//    输入: n = 4, k = 2
//    输出:
//    [
//        [2,4],
//        [3,4],
//        [2,3],
//        [1,2],
//        [1,3],
//        [1,4],
//    ]


#include "leetcode.h"

class Solution {
    void findCombine(int n, int k, int start, vector<int>& one, vector<vector<int>>& res) {
        if (one.size() == k) {
            res.push_back(one);
            return;
        }

        for (int i = start; i <= n; i++) {
            one.push_back(i);
            findCombine(n, k, i + 1, one, res);
            one.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> one;
        if (n <= 0 || k <= 0 || n < k) {
            return res;
        }

        findCombine(n, k, 1, one, res);
        return res;
    }
};


class Solution2 {
    void findCombine(int n, int k, int start, int* one, int size, vector<vector<int>>& res) {
        if (size == k) {
            res.push_back(vector<int>(one, one + k));
            return;
        }

        for (int i = start; i <= n; i++) {
            one[size] = i;
            findCombine(n, k, i + 1, one, size + 1, res);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        int one[k];
        if (n == 0 || k == 0 || n < k) {
            return res;
        }

        findCombine(n, k, 1, one, 0, res);
        return res;
    }
};

int main() {
    vector<vector<int>> vv = Solution2().combine(4, 2);
    for (auto v : vv) {
        PrintVector(v);
    }
}