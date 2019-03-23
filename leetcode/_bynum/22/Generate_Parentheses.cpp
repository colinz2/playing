//
// Created by colin on 2018-12-12.
//

#include "leetcode.h"

class Solution {
private:
    unordered_set<string> gen_set;
public:
    //比较笨的办法：
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> res;
        vector<string> res_nm1 = generateParenthesis(n - 1);

        for (string c : res_nm1) {
            for (int i = 0; i < c.size(); i++) {
                string x = c;
                x.insert(i, "()");
                if (gen_set.find(x) == gen_set.end()) {
                    res.push_back(x);
                    gen_set.insert(x);
                }
            }
        }
        return res;
    }
};

int main() {
    auto res = Solution().generateParenthesis(3);

    PrintVector(res);
}
