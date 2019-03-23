//
// Created by colin on 2018/11/13.
//

//给定一个 32 位有符号整数，将整数中的数字进行反转。
//
//示例 1:
//
//输入: 123
//输出: 321
//示例 2:
//
//输入: -123
//输出: -321
//示例 3:
//
//输入: 120
//输出: 21
//注意:
//
//假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。

#include "../leetcode.h"

class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        //不用处理正负号，因为乘法/加法/除法不影响正负。
        while (x != 0) {
            int mod = x % 10;
            ret = ret * 10 + mod;
            x /= 10;
        }
        return (ret < INT_MAX && ret > INT_MIN) ? (int)ret : 0;
    }
};


int main() {
    cout << Solution().reverse(-985) << endl;
    cout << Solution().reverse(1998) << endl;
}