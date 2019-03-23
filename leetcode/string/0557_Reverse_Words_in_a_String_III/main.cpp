//
// Created by colin on 2018-12-15.
//

//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//
//示例 1:
//
//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc"
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

#include "leetcode.h"

class Solution {
private:
    void reverse(string& s, int l, int r) {
        //[l, r]
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }

public:
    //原始思路
    string reverseWords(string s) {
        int b = 0, e = 0;
        for (int i = 0; i < s.size(); i++) {
            while (isblank(s[i])) {
                i++;
                b = i;
            }
            if (i + 1 == s.size() || isblank(s[i + 1])) {
                e = i;
                reverse(s, b, e);
            }
        }
        return s;
    }

    //参考：
    string reverseWords2(string s) {
        int start = 0;
        for (int i = start + 1; i <= s.size(); )
            if (i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
                i = start + 1;
            }
            else
                i ++;
        return s;
    }
};

int main() {
    string s1 = "Let's take LeetCode contest";
    cout << Solution().reverseWords(s1) << endl;
}