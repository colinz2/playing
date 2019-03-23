//
// Created by colin on 2018-12-05.
//

//给定两个字符串 s 和 t，判断它们是否是同构的。
//
//如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
//
//所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
//
//示例 1:
//
//输入: s = "egg", t = "add"
//输出: true
//示例 2:
//
//输入: s = "foo", t = "bar"
//输出: false
//示例 3:
//
//输入: s = "paper", t = "title"
//输出: true

#include "leetcode.h"

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m;
        unordered_map<char, char> m2;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) != m.end()) {
                if (m[s[i]] != t[i]) return false;
            } else {
                if (m2.find(t[i]) != m2.end()) return false;
                m[s[i]] = t[i];
                m2[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main() {
    cout << Solution().isIsomorphic("egg", "add") << endl;
    cout << Solution().isIsomorphic("paper", "title") << endl;
    cout << Solution().isIsomorphic("foo", "bar") << endl;
    cout << Solution().isIsomorphic("ab", "aa") << endl;
}