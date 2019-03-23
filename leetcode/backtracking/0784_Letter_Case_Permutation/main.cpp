//
// Created by colin on 2018-12-20.
//

//给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。
//返回所有可能得到的字符串集合。
//
//示例:
//输入: S = "a1b2"
//输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
//
//输入: S = "3z4"
//输出: ["3z4", "3Z4"]
//
//输入: S = "12345"
//输出: ["12345"]
//注意：
//
//S 的长度不超过12。
//S 仅由数字和字母组成。

#include "leetcode.h"

class Solution {
public:
    void ChangeAndSave(string &S, int i, vector<string>& res) {
        string s_change = S;
        if (isupper(S[i])) {
            s_change[i] = tolower(S[i]);
        } else {
            s_change[i] = toupper(S[i]);
        }
        res.push_back(s_change);
    }

    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        res.push_back(S);
        int size = 1;
        if (S.size() == 0) return res;
        for (int i = S.size(); i >= 0; i--) {
            if (isalpha(S[i])) {
                for (int k = 0; k < size; k++) {
                    ChangeAndSave(res[k], i, res);
                }
                size += size;
            }
        }
        return res;
    }

    //backtracking
    //I think there is no need for the for loop
    vector<string> letterCasePermutation2(string S) {
        vector<string> res;
        if (S.size() == 0) return {S};
        FindLetterCasePermutation(S, 0, "", res);
        return res;
    }
    void FindLetterCasePermutation(string S, int index, string t, vector<string>& res) {
        if (t.size() == S.size()) {
            res.push_back(t);
            return ;
        }

        if (isalpha(S[index])) {
            char c = isupper(S[index]) ? tolower(S[index]) : toupper(S[index]);
            FindLetterCasePermutation(S, index + 1, t + c, res);

        }
        FindLetterCasePermutation(S, index + 1, t + S[index], res);
    }

};

int main() {
    auto res = Solution().letterCasePermutation("a1b2");
    PrintVector(res);

    auto res2 = Solution().letterCasePermutation2("a1b2");
    PrintVector(res2);
}

