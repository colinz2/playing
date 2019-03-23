//
// Created by colin on 2018/11/28.
//


//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//
//说明：本题中，我们将空字符串定义为有效的回文串。
//
//示例 1:
//
//输入: "A man, a plan, a canal: Panama"
//输出: true
//示例 2:
//
//输入: "race a car"
//输出: false

#include "leetcode.h"

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            }

            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            if (toupper(s[l]) != toupper(s[r])) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }
};

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    assert(Solution().isPalindrome(s1) == true);
    string s2 = "0P";
    assert(Solution().isPalindrome(s2) == false);
}

