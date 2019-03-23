//
// Created by colin on 2018-12-11.
//

//给定两个字符串, A 和 B。

//A 的旋转操作就是将 A 最左边的字符移动到最右边。
// 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea' 。
//如果在若干次旋转操作之后，A 能变成B，那么返回True。
//
//示例 1:
//输入: A = 'abcde', B = 'cdeab'
//输出: true
//
//示例 2:
//输入: A = 'abcde', B = 'abced'
//输出: false
//注意：
//
//A 和 B 长度不超过 100。

#include "leetcode.h"

class Solution {
public:
    //哈哈
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        return (A + A).find(B) != string::npos;
    }

    bool rotateString1(string A, string B) {
        string cur = A;
        for (int i = 0; i < A.size(); i++) {
            if (cur == B)
                return true;
            cur = cur.substr(1) + cur[0];
        }
        return false;
    }
};

int main() {
    string a = "abcde", b = "cdeab";

    assert(Solution().rotateString(a, b) == true);
    assert(Solution().rotateString1(a, b) == true);
}