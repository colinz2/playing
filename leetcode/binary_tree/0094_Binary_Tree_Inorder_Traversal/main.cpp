//
// Created by colin on 2018-12-12.
//

//二叉树的中序遍历


#include "../binary_tree.h"
#include "leetcode.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root) {
            vector<int> l = inorderTraversal(root->left);
            vector<int> r = inorderTraversal(root->right);
            ret.insert(ret.end(), l.begin(), l.end());
            ret.push_back(root->val);
            ret.insert(ret.end(), r.begin(), r.end());
        }
        return ret;
    }

    //👌， 在循环中压栈
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }

        stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur != NULL || !stack.empty()) {
            if (cur != NULL) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};




int main() {

    TreeNode* root = stringToTreeNode("1,2,3,4,5,6,7,9");
    TreeNode* root2 = stringToTreeNode("1,2,3,4,5,6,7,9");

    vector<int> ret = Solution().inorderTraversal(root);
    vector<int> ret2 = Solution().inorderTraversal2(root2);

    cout << integerVectorToString(ret) << endl;
    cout << integerVectorToString(ret2) << endl;
    return 0;
}
