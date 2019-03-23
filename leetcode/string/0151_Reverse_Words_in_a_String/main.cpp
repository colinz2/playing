//
// Created by colin on 2018/11/27.
//

//给定一个字符串，逐个翻转字符串中的每个单词。
//
//示例:
//
//输入: "the sky is blue",
//输出: "blue is sky the".
//说明:
//
//无空格字符构成一个单词。
//输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
//进阶: 请选用C语言的用户尝试使用 O(1) 空间复杂度的原地解法。


#include "leetcode.h"

class Solution {
public:
    void reverseWords(string &s) {
        vector<string> elems = split(s);
        vector<string>::reverse_iterator r_iter;
        for (r_iter = elems.rbegin(); r_iter != elems.rend(); r_iter++) {
            if (r_iter != elems.rbegin())
                s += " " + *r_iter;
            else s = *r_iter;
        }
    }

private:
    vector<string> split(const string &s) {
        vector<string> res;
        int start = nextNonSpace(s, 0);
        for (int i = start + 1; i <= s.size();)
            if (i == s.size() || s[i] == ' ') {
                res.push_back(s.substr(start, i - start));
                start = nextNonSpace(s, i);
                i = start + 1;
            } else
                i++;
        return res;
    }

    int nextNonSpace(const string &s, int start) {
        int i = start;
        for (; i < s.size(); i++)
            if (s[i] != ' ')
                return i;
        return i;
    };
};

    int main() {
        string s1 = " the  sky  is  blue ";
        Solution().reverseWords(s1);
        cout << s1 << endl;
    }