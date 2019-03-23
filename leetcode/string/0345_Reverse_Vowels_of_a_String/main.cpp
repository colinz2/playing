//
// Created by colin on 2018/11/28.
//

//编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
//
//示例 1:
//
//输入: "hello"
//输出: "holle"
//示例 2:
//
//输入: "leetcode"
//输出: "leotcede"
//说明:
//元音字母不包含字母"y"

#include "leetcode.h"

class Solution {
public:
    string reverseVowels(string s) {
        int dict[256] = {0};
        dict['a'] = 1, dict['A'] = 1;
        dict['e'] = 1, dict['E'] = 1;
        dict['i'] = 1, dict['I'] = 1;
        dict['o'] = 1, dict['O'] = 1;
        dict['u'] = 1, dict['U'] = 1;
        int start = 0, end = s.size() - 1;
        while (start < end) {
            while (start < end && !dict[s[start]]) start++;
            while (start < end && !dict[s[end]]) end--;
            swap(s[start], s[end]);
            start++;
            end--;
        }
        return s;
    }
};

int main() {
    string s1 = "hello";

    string s2 = Solution().reverseVowels(s1);

    cout << s2 << endl;
}