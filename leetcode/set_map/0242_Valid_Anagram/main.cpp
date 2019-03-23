//
// Created by colin on 2018-12-05.
//

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
//
//示例 1:
//
//输入: s = "anagram", t = "nagaram"
//输出: true
//示例 2:
//
//输入: s = "rat", t = "car"
//输出: false

#include "leetcode.h"

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;

        for (int i = 0; i < t.size(); i++) {
            freq[t[i] - 'a']--;
            if (freq[t[i] - 'a'] < 0)
                return false;
        }
        return true;
    }


    bool isAnagram1(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram2(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> m;
        for (auto &c : s) {
            m[c]++;
        }
        for (auto &c : t) {
            if (m.find(c) == m.end()) return false;
            if (--m[c] < 0) return false;
        }
        return true;
    }
};

int main() {
    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    cout << Solution().isAnagram("rat", "car") << endl;
}

