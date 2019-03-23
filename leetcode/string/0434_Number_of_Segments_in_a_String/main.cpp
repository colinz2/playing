//
// Created by colin on 2018-12-05.
//

//
//统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
//
//请注意，你可以假定字符串里不包括任何不可打印的字符。
//
//示例:
//
//输入: "Hello, my name is John"
//输出: 5

#include "leetcode.h"

class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        string temp;
        int count = 0;

        while (getline(ss, temp, ' ')) {
            if (!temp.empty())
                count++;
        }
        return count;
    }
};

int main() {
    cout << Solution().countSegments("Hello, my name is John") << endl;
}