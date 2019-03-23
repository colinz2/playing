//
// Created by colin on 2018/11/27.
//

#include "leetcode.h"

//给定一个单词，你需要判断单词的大写使用是否正确。
//
//我们定义，在以下情况时，单词的大写用法是正确的：
//
//全部字母都是大写，比如"USA"。
//单词中所有字母都不是大写，比如"leetcode"。
//如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
//否则，我们定义这个单词没有正确使用大写字母。
//
//示例 1:
//
//输入: "USA"
//输出: True
//        示例 2:
//
//输入: "FlaG"
//输出: False

//标签：字符串

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_lower = false, all_upper = false, first_upper = false;
        if (isupper(word[0])) {
            all_upper = true;
            first_upper = true;
        } else if (islower(word[0])) {
            all_lower = true;
        }

        for (int i = 1; i < word.size(); i++) {
            int c = word[i];
            if (isupper(c)) {
                all_upper = all_upper & true;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            } else if (islower(c)) {
                all_upper = all_upper & false;
                all_lower = all_lower & true;
                first_upper = first_upper & true;
            } else {
                all_upper = all_upper & false;
                all_lower = all_lower & false;
                first_upper = first_upper & false;
            }
        }

        return all_lower || all_upper || first_upper;
    }
};

int main() {
    cout << Solution().detectCapitalUse("USA") << endl;
    cout << Solution().detectCapitalUse("FlaG") << endl;
    cout << Solution().detectCapitalUse("hello") << endl;
    cout << Solution().detectCapitalUse("World") << endl;
}