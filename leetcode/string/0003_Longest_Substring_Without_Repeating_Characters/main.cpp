//
// Created by colin on 2018/11/29.
//

//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//示例 1:
//
//输入: "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//示例 2:
//
//输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//示例 3:
//
//输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

#include "../leetcode.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int checker[256] = {0, };
        int l = 0, r = -1;
        int ret = 0;

        while (r + 1 < s.size()) {
            if (checker[s[r + 1]] == 0) {
                checker[s[++r]] = 1;
            } else if (checker[s[r + 1]] == 1) {
                checker[s[l++]] = 0;
            }

            ret = std::max(ret, r - l + 1);
        }
        return ret;
    }

    //另一种思路
    int lengthOfLongestSubstring2(string s) {
        vector<int> m(256, -1);
        int res = 0, left = -1;
        for (int i = 0; i < s.size(); i++) {
            left = max(left, m[s[i]]);
            res = max(res, i - left);
            m[s[i]] = i;
        }
        return res;
    }
};

int main() {
    string s1 = "abcabcbb";
    string s2 = "bbbbb";
    string s3 = "pwwkew";
    cout << Solution().lengthOfLongestSubstring(s1) << endl;
    cout << Solution().lengthOfLongestSubstring(s2) << endl;
    cout << Solution().lengthOfLongestSubstring(s3) << endl;
}