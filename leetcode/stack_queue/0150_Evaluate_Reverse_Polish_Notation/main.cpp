//
// Created by colin on 2018-12-12.
//

//有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
//说明：
//
//整数除法只保留整数部分。
//给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
//示例 1：
//
//输入: ["2", "1", "+", "3", "*"]
//输出: 9
//解释: ((2 + 1) * 3) = 9
//示例 2：
//
//输入: ["4", "13", "5", "/", "+"]
//输出: 6
//解释: (4 + (13 / 5)) = 6
//示例 3：
//
//输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
//输出: 22
//解释:
//((10 * (6 / ((9 + 3) * -11))) + 17) + 5
//= ((10 * (6 / (12 * -11))) + 17) + 5
//= ((10 * (6 / -132)) + 17) + 5
//= ((10 * 0) + 17) + 5
//= (0 + 17) + 5
//= 17 + 5
//= 22


#include "leetcode.h"

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        set<string> operators = {"+", "-", "*", "/"};
        int res = 0;
        stack<int> nums;

        for (string &c : tokens) {
            if (operators.find(c) != operators.end()) {
                int a = nums.top();
                int b = nums.top();
                nums.pop();
                nums.pop();
                if (c == "+") nums.push(a + b);
                else if (c == "-") nums.push(b - a);
                else if (c == "*") nums.push(b * a);
                else if (c == "/") nums.push(b / a);
            } else {
                nums.push(stoi(c));
            }
        }

        return nums.top();
    }
};

int main() {
    vector<string> v1 = {"2", "1", "+", "3", "*"};

    assert(Solution().evalRPN(v1) == 9);
}