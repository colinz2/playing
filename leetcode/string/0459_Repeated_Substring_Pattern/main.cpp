//
// Created by colin on 2018-12-05.
//

//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
//给定的字符串只含有小写英文字母，并且长度不超过10000。
//
//示例 1:
//
//输入: "abab"
//
//输出: True
//
//        解释: 可由子字符串 "ab" 重复两次构成。
//示例 2:
//
//输入: "aba"
//
//输出: False
//        示例 3:
//
//输入: "abcabcabcabc"
//
//输出: True
//
//解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)

#include "leetcode.h"

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        string nextStr = str;
        int len = str.length();
        if (len < 1) return false;
        for (int i = 1; i <= len / 2; i++) {
            if (len % i == 0) {
                nextStr = leftShift(str, i);
                if (nextStr == str) return true;
            }
        }
        return false;
    }

private:
    string leftShift(string &str, int l) {
        string ret = str.substr(l);
        ret += str.substr(0, l);
        return ret;
    }
};

int main() {
    cout << Solution().repeatedSubstringPattern("abab") << endl;
    cout << Solution().repeatedSubstringPattern("abcabcabcabc") << endl;
    cout << Solution().repeatedSubstringPattern("abc") << endl;
}