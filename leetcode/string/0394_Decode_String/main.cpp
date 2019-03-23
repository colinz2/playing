//
// Created by colin on 2018-12-05.
//

//给定一个经过编码的字符串，返回它解码后的字符串。
//
//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
//
//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
//
//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
//
//示例:
//
//s = "3[a]2[bc]", 返回 "aaabcbc".
//s = "3[a2[c]]", 返回 "accaccacc".
//s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

#include "leetcode.h"

class Solution {
public:
    //双栈push/pop同步
    //👌 ？
    string decodeString(string s) {
        string res;
        stack<int> num;
        stack<string> str;
        str.push("");

        for (int i = 0, b = 0; i < s.size();) {
            if (isdigit(s[i])) {
                b = i;
                while (isdigit(s[++i]));
                int n = stoi(s.substr(b, i - b));
                num.push(n);
                str.push("");
            } else if (isalpha(s[i])) {
                str.top() += s[i++];
            } else if (s[i] == ']') {
                int cnt = num.top(); num.pop();
                string s = str.top(); str.pop();
                while (cnt--) {
                    str.top() += s;
                }
                i++;
            } else {
                i++;
            }
        }
        return str.top();
    }
};

class Solution2 {
public:
    string decodeString(string s) {
        int end;
        return dfs(s, 0, end);
    }

private:
    //s = "3[a]2[bc]", 返回 "aaabcbc".
    //s = "3[a2[c]]", 返回 "accaccacc".
    //s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
    //👌？,
    //🐱啊
    string dfs(string s, int start, int& end) {
        string res = "";
        for (int i = start, b = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int e, n;
                for (b = i; isdigit(s[i]); i++);
                n = stoi(s.substr(b, i - b));
                string sub = dfs(s, i, e);
                //cout << "sub = " << sub << endl;
                while (n--) res += sub;
                i = e;
            } else if (isalpha(s[i])) {
                res += s[i++];
            } else if (s[i] == ']') {
                i++;
                end = i;
                return res;
            } else {
                i++;
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().decodeString("3[ax]2[bc]") << endl;
    cout << Solution2().decodeString("3[ax]2[bc]") << endl;

    cout << Solution().decodeString("3[a2[c]]") << endl;
    cout << Solution2().decodeString("3[a2[c]]") << endl;

    cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
    cout << Solution2().decodeString("2[abc]3[cd]ef") << endl;
}