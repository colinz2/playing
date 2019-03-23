//
// Created by colin on 2018-12-13.
//

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
//
//给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//         2(ABC) 3(DEF)
// 4(GHI)  5(JKL) 6(MNO)
// 7(PQRS) 8(TUV) 9(WXYZ)
//示例:
//
//输入："23"
//输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

#include "leetcode.h"

class Solution {
private:
     const string digit_char[10] = {" ", "*", "abc", "def"
                                      ,"ghi",  "jkl" ,"mno"
                                      ,"pqrs", "tuv" ,"wxyz"};

    void Combinations_(string& digits, int index, string s, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(s);
            return;
        }

        char c = digits[index];
        string chars = digit_char[c - '0'];

        for (auto c : chars) {
            Combinations_(digits, index + 1, s + c, res);
        }
    }

public:
    //回溯发
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0) return res;
        Combinations_(digits, 0, "", res);
        return res;
    }

    //迭代
    vector<string> letterCombinations2(string digits) {
        vector<string> res = {};
        if (digits.size() == 0) return res;
        res.push_back("");
        for (auto d : digits) {
            vector<string> tmp_v = {};
            string chars = digit_char[d - '0'];
            for (auto c : chars) {
                for (auto s : res)
                    tmp_v.push_back(s + c);
            }
            res = tmp_v;
        }
        return res;
    }
};

int main() {
    vector<string> v1 = Solution().letterCombinations("123");
    vector<string> v2 = Solution().letterCombinations2("123");

    PrintVector(v1);
    PrintVector(v2);
}