//
// Created by colin on 2018/11/19.
//
//https://leetcode-cn.com/problems/longest-common-prefix/description/
//14. 最长公共前缀
//编写一个函数来查找字符串数组中的最长公共前缀。
//
//如果不存在公共前缀，返回空字符串 ""。
//
//示例 1:
//
//输入: ["flower","flow","flight"]
//输出: "fl"
//示例 2:
//
//输入: ["dog","racecar","car"]
//输出: ""
//解释: 输入不存在公共前缀。
#include "../leetcode.h"

class Solution {
public:
    string CommonPrefix(string& a, string& b) {
        //string cp;
        int j = 0;
        for (j = 0; j < a.size() && j < b.size(); j++) {
            if (a[j] == b[j]) {
                //cp.append(1, a[j]);
            } else {
                break;
            }
        }
        //return cp;
        return a.substr(0, j);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string lcp = strs[0];
        for (auto i = 0; i < strs.size() - 1; i++) {
            string cp = CommonPrefix(strs[i], strs[i+1]);
            if (cp.size() == 0) {
                return "";
            }
            if (cp.size() < lcp.size()) {
                lcp = cp;
            }
        }
        return  lcp;
    }
};

int main()
{
    vector<string> t1 = {"flower","flow","flight"};
    vector<string> t2 = {"dog","racecar","car"};
    vector<string> t3 = {"dog"};
    vector<string> t4 = {"dog", "dogs"};
    cout << Solution().longestCommonPrefix(t1) << endl;
    cout << Solution().longestCommonPrefix(t2) << endl;
    cout << Solution().longestCommonPrefix(t3) << endl;
    cout << Solution().longestCommonPrefix(t4) << endl;
}