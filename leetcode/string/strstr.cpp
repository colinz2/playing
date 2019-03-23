//
// Created by colin on 2018/11/22.
//
#include "../leetcode.h"

//实现 strStr() 函数。
//
//给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。
//如果不存在，则返回  -1。
//
//示例 1:
//
//输入: haystack = "hello", needle = "ll"
//输出: 2
//示例 2:
//
//输入: haystack = "aaaaa", needle = "bba"
//输出: -1
//说明:
//
//当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
//
//对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。


//错误❌，不能处理重复字符
int strStr(char *haystack, char *needle) {
    const char *hp = haystack;
    const char *np = needle;

    while (*hp != 0x00) {
        if (*np == *hp) {
            np++;
        } else {
            np = needle;
        }
        if (*np == 0x00) {
            return hp - haystack - strlen(needle) + 1;
        }
        hp++;
    }
    return -1;
}

class Solution {
public:
    //正常思路就这样啊
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size())
            return -1;

        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            int j = 0;
            for (j = 0; j < needle.size(); j++)
                if (needle[j] != haystack[j + i])
                    break;
            if (j == needle.size())
                return i;
        }
        return -1;
    }
};

int main() {

    printf("%d \n ", strStr("mississippi", "issip"));

    cout << Solution().strStr("mississippi", "issip") << endl;

}