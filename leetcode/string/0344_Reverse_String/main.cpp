//
// Created by colin on 2018/11/28.
//

//编写一个函数，其作用是将输入的字符串反转过来。
//
//示例 1:
//
//输入: "hello"
//输出: "olleh"
//示例 2:
//
//输入: "A man, a plan, a canal: Panama"
//输出: "amanaP :lanac a ,nalp a ,nam A"

#include "leetcode.h"

class Solution {
public:
    string reverseString(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            std::swap(s[l++], s[r--]);
        }
        return s;
    }
};

int main() {
    string s1 = "A man, a plan, a canal: Panama";

    string s2 = Solution().reverseString(s1);

    cout << s2 << endl;
}