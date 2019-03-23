//
// Created by colin on 2018-12-05.
//
//
//给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
//
//注意：
//
//num1 和num2 的长度都小于 5100.
//num1 和num2 都只包含数字 0-9.
//num1 和num2 都不包含任何前导零。
//你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

//as same 67. add binary

#include "leetcode.h"

class Solution {
public:
    string addStrings(string num1, string num2) {
        string base = num2, adder = num1;
        int carry = 0;
        if (num1.size() > num2.size()) {
            base = num1;
            adder = num2;
        }
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
                sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 10) + 0x30;
            carry = sum / 10;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }
        return base;
    }
};


int main() {
    cout << Solution().addStrings("8888", "999") << endl;
}