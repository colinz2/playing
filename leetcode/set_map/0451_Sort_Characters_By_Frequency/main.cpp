//
// Created by colin on 2018-12-05.
//

//给定一个字符串，请将字符串里的字符按照出现的频率降序排列。
//
//示例 1:
//
//输入:
//"tree"
//
//输出:
//"eert"
//
//解释:
//'e'出现两次，'r'和't'都只出现一次。
//因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
//示例 2:
//
//输入:
//"cccaaa"
//
//输出:
//"cccaaa"
//
//解释:
//'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
//注意"cacaca"是不正确的，因为相同的字母必须放在一起。
//示例 3:
//
//输入:
//"Aabb"
//
//输出:
//"bbAa"
//
//解释:
//此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
//注意'A'和'a'被认为是两种不同的字符。

#include "leetcode.h"

class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        priority_queue <pair<int, char>> q;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto a : m) q.push({a.second, a.first});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            res.append(t.first, t.second);
        }
        return res;
    }

    string frequencySort1(string s) {
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        sort(s.begin(), s.end(), [&](char &a, char &b) {
            return m[a] > m[b] || (m[a] == m[b] && a < b);
        });
        return s;
    }
};


int main() {
    cout << Solution().frequencySort("cccaaa") << endl;
    cout << Solution().frequencySort("tree") << endl;
    cout << Solution().frequencySort("Aabb") << endl;
}