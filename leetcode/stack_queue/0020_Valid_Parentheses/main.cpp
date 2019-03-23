//
// Created by colin on 2018-12-11.
//

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。
//
//示例 1:
//
//输入: "()"
//输出: true
//示例 2:
//
//输入: "()[]{}"
//输出: true
//示例 3:
//
//输入: "(]"
//输出: false
//示例 4:
//
//输入: "([)]"
//输出: false
//示例 5:
//
//输入: "{[]}"
//输出: true

#include "leetcode.h"

class Solution {
public:
    bool isValid(string s) {
        unordered_map<int, int> symbol_map = {
                {'(', 1},
                {')', -1},
                {'[', 2},
                {']', -2},
                {'{', 3},
                {'}', -3},
        };
        stack<int> s_stack;
        for (auto c : s) {
            int v = symbol_map[c];
            if (v > 0) {
                s_stack.push(v);
            } else if (v < 0) {
                if (s_stack.empty()) return false;
                if (s_stack.top() != -v) return false;
                s_stack.pop();
            }
        }
        if (!s_stack.empty()) return false;
        return true;
    }
};

int main() {

    assert(Solution().isValid("()") == true);
    assert(Solution().isValid("()[]{}") == true);
    assert(Solution().isValid("(]") == false);
    assert(Solution().isValid("([)]") == false);
    assert(Solution().isValid("{[]}") == true);
}