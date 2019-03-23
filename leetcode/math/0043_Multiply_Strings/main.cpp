//
// Created by colin on 2018-12-24.
//

//给定两个以字符串形式表示的非负整数 num1 和 num2，
//返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//
//示例 1:
//
//输入: num1 = "2", num2 = "3"
//输出: "6"
//示例 2:
//
//输入: num1 = "123", num2 = "456"
//输出: "56088"
//说明：
//
//num1 和 num2 的长度小于110。
//num1 和 num2 只包含数字 0-9。
//num1 和 num2 均不以零开头，除非是数字 0 本身。
//不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。

#include "leetcode.h"

class Solution {
public:

    string reverse_str(string num) {
        string res = num;
        if (num.size() == 0) return res;
        int l = 0, r = num.size() - 1;
        while (l < r) {
            swap(res[l++], res[r--]);
        }
        return res;
    }
    //我的做法有点丑啊！
    string multiply(string num1, string num2) {
        //mul1是乘法式子中上面的数字，mul2是下面的。
        string mul1 = reverse_str(num1), mul2 = reverse_str(num2);
        if (mul2.size() > mul1.size()) {
            mul1 = mul2;
            mul2 = reverse_str(num1);
        }
        //vector<int> res(0, mul1.size() + mul2.size());
        vector<int> res;

        for (int i = 0; i < mul2.size(); i++) {
            int n2 = mul2[i] - 0x30;
            int carry = 0;
            for (int j = 0; j < mul1.size(); j++) {
                if (i + j >= res.size()) res.push_back(0);
                int n1 = mul1[j] - 0x30;
                int mul_n = (n1 * n2 + carry + res[i + j]) % 10;
                carry = (n1 * n2 + carry + res[i + j]) / 10;
                res[i + j] = mul_n;
            }
            if (carry) {
                res.push_back(carry);
            }
        }

        string s;
        auto it = res.rbegin();
        for (; it != res.rend(); it++) {
            if (*it != 0) break;
        }
        for (auto it_skip_zero = it; it_skip_zero != res.rend(); it_skip_zero++) {
            s += to_string(*it_skip_zero);
        }
        if (s.size() == 0) return "0";
        return s;
    }
};

int main() {
    cout << Solution().multiply("123", "456") << endl;
    cout << Solution().multiply("456", "99") <<  endl;
    cout << Solution().multiply("999", "99") <<  endl;
    cout << Solution().multiply("1", "1") <<  endl;
    cout << Solution().multiply("3", "9") <<  endl;
}
