//
// Created by colin on 2018-12-10.
//

//给定一个文档 (Unix-style) 的完全路径，请进行路径简化。
//
//例如，
//path = "/home/", => "/home"
//path = "/a/./b/../../c/", => "/c"
//
//边界情况:
//
//你是否考虑了 路径 = "/../" 的情况？
//在这种情况下，你需返回 "/" 。
//此外，路径中也可能包含多个斜杠 '/' ，如 "/home//foo/" 。
//在这种情况下，你可忽略多余的斜杠，返回 "/home/foo" 。

#include "leetcode.h"

class Solution {
public:
    //TODO
    string simplifyPath(string path) {
        int old = 0;
        string ret = "/";
        vector<string> stack;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                string seg = path.substr(old, i - old);
                old = i;
                if (seg.size() > 1) {
                    string x = seg.substr(1, seg.size() - 1);
                    if (x == "." || "") {
                        continue;
                    } else if (x == ".." && stack.size() > 0) {
                            stack.pop_back();
                    } else {
                        stack.push_back(x);
                    }
                }
            }
        }

        for (auto it = stack.begin(); it != stack.end(); it++) {
            if (it + 1 != stack.end()) {
                ret += *it + "/";
            } else {
                ret += *it;
            }
        }
        return ret;
    }
};

int main() {

    cout << Solution().simplifyPath("/a/./b/../../c/") << endl;
    cout << Solution().simplifyPath("/../") << endl;
}