//
// Created by colin on 2018-12-15.
//

//给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。
//如果剩余少于 k 个字符，则将剩余的所有全部反转。
//如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。
//
//示例:
//输入: s = "abcdefg", k = 2
//输出: "bacdfeg"
//要求:
//
//该字符串只包含小写的英文字母。
//给定字符串的长度和 k 在[1, 10000]范围内。

#include "leetcode.h"

class Solution {
public:
    string reverseStr1(string s, int k) {

        for (int i = 0; i < s.size(); i += 2 * k)
            reverse(s, i, i + k);
        return s;
    }

private:
    void reverse(string &s, int i, int j) {
        j = min(j, (int) s.size());
        j--;
        while (i < j)
            swap(s[i++], s[j--]);
    }

public:
    //二逼解法
    string reverseStr2(string s, int k) {
        int k2 = 2 * k;
        int r = 0, l = 0, m = 0; //[l,m) [m, r)
        for (int i = 0; i < s.size(); i = r) {
            int last = s.size() - i;
            if (last >= k) {
                m = i + k;
                r = i + min(k2, last);
            } else {
                m = i + last;
                r = i + last;
            }
            l = i;
            while (l + 1 < m) {
                swap(s[l++], s[--m]);
            }
        }
        return s;
    }
};

int main() {
    string s1 = "abcdefg";
    cout << s1 << " -> " << Solution().reverseStr1(s1, 2) << endl;
}