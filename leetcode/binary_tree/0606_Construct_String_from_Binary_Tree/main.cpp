//
// Created by colin on 2018-12-15.
//

/*
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:
输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。

示例 2:
输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
*/

#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:

    string tree2str(TreeNode* t) {
        if (!t) return "";
        string res = to_string(t->val);
        if (!t->left && !t->right) return res;
        res += "(" + tree2str(t->left) + ")";
        if (t->right) res += "(" + tree2str(t->right) + ")";
        return res;
    }
    //TODO
//    string tree2str2(TreeNode* t) {
//        string res;
//        stack<TreeNode*> stack;
//        TreeNode* curr = t;
//
//        while (curr || stack.size()) {
//            if (curr) {
//                res += to_string(curr->val);
//                stack.push(curr);
//                curr = curr->left;
//            } else {
//                curr = stack.top();
//                stack.pop();
//                curr = curr->right;
//            }
//        }
//        return res;
//    }
};

int main() {

    /*
        "1(2(4)(5))(3(6))"
    */
    TreeNode* tree1 = stringToTreeNode("1,2,3,4,5,6");

    cout << Solution().tree2str(tree1) << endl;
}

