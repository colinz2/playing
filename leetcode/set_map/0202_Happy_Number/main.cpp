//
// Created by colin on 2018-12-05.
//

//编写一个算法来判断一个数是不是“快乐数”。
//
//一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
// 然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
// 如果可以变为 1，那么这个数就是快乐数。
//
//示例:
//
//输入: 19
//输出: true
//解释:
//1^2 + 9^2 = 82
//8^2 + 2^2 = 68
//6^2 + 8^2 = 100
//1^2 + 0^2 + 0^2 = 1

#include "leetcode.h"

class Solution {
public:
    bool isHappy(int n) {
        int x = n;
        unordered_set<int> check;

        while (x != 1) {
            if (check.find(x) != check.end()) {
                return false;
            } else {
                check.insert(x);
                x = cal(x);
            }
        }
        return true;
    }

private:
    int cal(int n) {
        int ret = 0;
        while (n) {
            ret += (n % 10)*(n % 10);
            n /= 10;
        }
        return ret;
    }
};

int main() {
    cout << Solution().isHappy(19) << endl;
    cout << Solution().isHappy(99) << endl;
}