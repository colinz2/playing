//
// Created by colin on 2018/11/24.
//
//
//给定两个二进制字符串，返回他们的和（用二进制表示）。
//
//输入为非空字符串且只包含数字 1 和 0。
//
//示例 1:
//
//输入: a = "11", b = "1"
//输出: "100"
//示例 2:
//
//输入: a = "1010", b = "1011"
//输出: "10101"

#include "../leetcode.h"

class Solution {
public:
    string addBinary(string a, string b) {
        string base , adder;
        if (a.size() > b.size()) {
            base = a;
            adder = b;
        } else {
            base = b;
            adder = a;
        }

        int carry = 0;
        for (int i = base.size() - 1, j = adder.size() - 1 ; i >= 0; i--, j--) {
            int sum = 0;
            if (j >= 0) {
               sum = (base[i] - 0x30) + (adder[j] - 0x30) + carry;
            } else {
                sum = base[i] - 0x30 + carry;
            }
            base[i] = (sum % 2) + 0x30;
            carry = sum / 2;
        }

        if (carry) {
            base.insert(base.begin(), '1');
        }

        return base;
    }
};

int main() {
    cout << Solution().addBinary("1010", "111");
}
