//
// Created by colin on 2018-12-12.
//

//给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
//例如，给出 n = 3，生成结果为：
//
//[
//    "((()))",
//    "(()())",
//    "(())()",
//    "()(())",
//    "()()()"
//]

//REF
//http://www.cnblogs.com/grandyang/p/4444160.html

#include "leetcode.h"

class Solution {

public:

    void generateParenthesisDFS(int left, int right, string s, vector<string>& res) {
        if (left > right) return;
        if (left == 0 && right == 0) {
            res.push_back(s);
        } else {
            if (left)
                generateParenthesisDFS(left - 1, right, s + "(", res);
            if (right)
                generateParenthesisDFS(left, right - 1, s + ")", res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n < 1) return res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
};




int main() {
    auto res = Solution().generateParenthesis(3);

    PrintVector(res);
}