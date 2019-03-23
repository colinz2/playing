//
// Created by colin on 2018-12-06.
//

//报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//1 被读作  "one 1"  ("一个一") , 即 11。
//11 被读作 "two 1s" ("两个一"）, 即 21。
//21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
//
//给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
//
//注意：整数顺序将表示为一个字符串。
//
//示例 1:
//
//输入: 1
//输出: "1"
//示例 2:
//
//输入: 4
//输出: "1211"

#include "leetcode.h"

class Solution {
public:
    string countAndSay(int n) {
        //递归
        if (n == 1) {
            return to_string(n);
        }

        string s = countAndSay(n - 1);
        string s2;
        int cnt = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] != s[i]) {
                s2.append(to_string(cnt));
                s2.append(1, s[i - 1]);
                cnt = 1;
            } else {
                cnt++;
            }
        }
        return s2;
    }
};


int main() {
//    string s = "11223333";
//    assert(s[s.size()] == 0x00);
//    string s2;
//    int cnt = 1;
//    for (int i = 1; i <= s.size(); i++) {
//        if (s[i - 1] != s[i]) {
//            s2.append(to_string(cnt));
//            cnt = 1;
//            s2.append(1, s[i - 1]);
//        } else {
//            cnt++;
//        }
//    }
//    cout << s2 << endl;

    cout << Solution().countAndSay(4) << endl;
    cout << Solution().countAndSay(5) << endl;
    cout << Solution().countAndSay(6) << endl;
}